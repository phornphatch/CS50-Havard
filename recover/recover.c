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
    char *filename = argv[1];         // ดึงเอา 2nd argument
    FILE *file = fopen(argv[1], "r"); // r is reading mode

    // check if file exists
    if (file == NULL)
    {
        printf("No such file found.\n");
        return 1;
    }

    // look for beginning of jpeg
    uint8_t buffer[3]; // actual 4
    uint8_t signature[] = {0xff, 0xd8, 0xff}; // actual 4 : 0xe_

    fread(buffer, 1, 4, file); // (location, size of block to read, how many block to read, location to read from)

    for (int i = 0; i < 3; i++)
    {
        // Check dose the buffer signer match?
        if ( buffer[0] == 0xff & buffer[1] == 0xd8 & buffer[2] == 0xff) {
            printf("It's not jpeg.\n");
            return 0;
        }
        printf("It's a  jpeg !!!!\n");
        fclose(file); // ****** ถ้าไม่ close จะ leak memory ถ้า run valgrind ./pdf test.pdf ดู
        return 0;
    }

    // open new jpeg file
    // write 512 bytes until a new jpeg is found
}