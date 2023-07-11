#include <cs50.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    if (argc != 2) // check : should have 2nd argument
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // open memory card
    FILE *raw_file = fopen(argv[1], "r"); // r is reading mode

    // check if file exists./recover card.raw
    if (raw_file == NULL)
    {
        printf("No such file found.\n");
        return 1;
    }

    // look for beginning of jpeg
    typedef uint8_t BYTE;
    BYTE buffer[512];

    int file_number = 0;
    bool jpegStarted = false;
    FILE *img = NULL;
    char filename[8];

    // Check buffer match with JPEG?
    while (fread(buffer, sizeof(BYTE) * 512, 1, raw_file) ==
           1) // (location, size of block to read, how many block to read, location to read from)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) // if buffer matched
        {
            if (jpegStarted == false) // starting point of jpeg = First image
            {
                // เปน jpeg และเป็นจุด start
                jpegStarted = true; // set จุดเริ่มต้นรูป
                sprintf(filename, "%03i.jpg", file_number);
                img = fopen(filename, "w");
                fwrite(buffer, sizeof(BYTE) * 512, 1, img);  // go to else ที่ if (jpegStarted)***
            }
            else // not starting point of jpeg = next image
            {
                // if (img != NULL) // ถ้าก่อนหน้ามีรูปให้ปิดก่อน
                // {
                //     fclose(img);
                // }
                fclose(img);
                // เปน jpeg แต่ไม่ใช่จุด start
                file_number++; // เพิ่มเลขในชื่อไฟล์
                sprintf(filename, "%03i.jpg", file_number);
                // printf("%s", filename);
                img = fopen(filename, "w"); // เปิดและเขียนอันใหม่ เลขไฟล์ใหม่
                fwrite(buffer, sizeof(BYTE) * 512, 1, img);
                // printf("next img here !!!!\n");
            }
        }
        else
        {
            if (jpegStarted) // *** ยังอยู่ในรูปเดียวดัน ไม่ได้่ขึ้นต้นด้วย buffer ที่ matched
            {
                sprintf(filename, "%03i.jpg", file_number); // เขียนต่อๆๆ
                fwrite(buffer, sizeof(BYTE) * 512, 1, img);
            }
        }
    }
    if (img != NULL)
    {
        fclose(img);
    }
    fclose(raw_file); // ****** ถ้าไม่ close จะ leak memory ถ้า run valgrind ./pdf test.pdf ดู
}