// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{

    bool hasUppercase = false;
    bool hasLowercase = false;
    bool hasNumber = false;
    bool hasSymbol = false;

    for (int i = 0; i < strlen(password); i++)
    {
        // Check if the character is an uppercase letter
        if (isupper(password[i]))
        {
            hasUppercase = true;
        }
        // Check if the character is a lowercase letter
        else if (islower(password[i]))
        {
            hasLowercase = true;
        }
        // Check if the character is a number (Digits)
        else if (isdigit(password[i])) // number  { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }
        {
            hasNumber = true;
        }
        // Check if the character is a symbol (Punctuation characters)
        else if (ispunct(password[i])) //  ! " # $ % & ' ( ) * + , - . / : ; < = > ? @ [ \ ] ^ _ ` { | } ~
        {
            hasSymbol = true;
        }
    }
    // Return true if all criterias are met
    return hasUppercase && hasLowercase && hasNumber && hasSymbol;
}
