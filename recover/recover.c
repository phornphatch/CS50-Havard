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
    char* filename = argv[1];        // ดึงเอา 2nd argument
    FILE *file = fopen(argv[1], "r"); // r is reading mode

      // check if file exists
    if (file == NULL)
    {
        printf("No such file found.\n");
        return 1;
    }
    
    // look for beginning of jpeg
    // open new jpeg file
    // write 512 bytes until a new jpeg is found
}