#include <cs50.h>
#include <stdint.h>
#include <stdio.h>

int main(int argc, string argv[])
{

    if (argc != 2) // check : should have 2nd argument
    {
        printf("add more argc\n");
        return 1;
    }

    // open file
    string filename = argc[1];         // ดึงเอา 2nd argument
    FILE *input = fopen(argv[1], "r"); // r is reading mode

    // check if file exists
    if (file == NULL)
    {
        printf("No such file found.\n");
        return 1;
    }

    uint8_t buffer[4];
    // uint8_t is special type of 'pdf'.
    // uint = unsigned integer. 8 = 8 bits or single byte. _t = all type
    // หมายถึง unsigned interger ทั้งหมด
    // 4 เพราะ pdf จะขึ้นด้วยเลข 4 ตัว 37 80 68 70

    fread(buffer, 1, 4, input); // 

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", buffer[i]);
    }

    fclose(input);
}