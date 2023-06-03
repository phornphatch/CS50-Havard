#include<cs50.h>
#include <stdio.h>

int main(void)
{
    // Get user's name
    string name = get_string("What's your name?\n");
    
    printf("Hello, %s! \n", name);
}