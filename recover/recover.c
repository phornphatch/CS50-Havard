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

    // 1. open memory card
    FILE *file = fopen(argv[1], "r"); // r is reading mode

    // check if file exists
    if (file == NULL)
    {
        printf("No such file found.\n");
        return 1;
    }

    // look for beginning of jpeg
    uint16_t buffer[4]; // actual 4

    fread(buffer, 4, 1, file); // (location, size of block to read, how many block to read, location to read from)

    // Check buffer match with JPEG?
    if (buffer[0] == 0xff & buffer[1] == 0xd8 & buffer[2] == 0xff & (buffer[3] & 0xf0) == 0xe0)
    {
        printf("It's jpeg.\n");
        return 0;
    }
    else
    {
        printf("It's not a  jpeg !!!!\n");
    }
    return 0;
    fclose(file); // ****** ถ้าไม่ close จะ leak memory ถ้า run valgrind ./pdf test.pdf ดู
     // --- end of check: JPEG? ---

    // open new jpeg file
    // sprintf(filename, "%03i.jpg", 2);
    // FILE *img = fopen(filename, "w");

    // write 512 bytes until a new jpeg is found
    // fwrite(data, size, number, outptr);

    // find the end of the file
}