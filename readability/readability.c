#include <cs50.h>
#include <stdio.h>
#include <string.h>

float cal_grade(string text);
float grade = 0;
float total_letter = 0;
float total_comma = 0;
float total_word = 1;     // count by space + 1 ot start with 1
float total_sentence = 0; // count by . or !
float L = 0;
float S = 0;
float actual_grade = 0;

int main(void)
{
    // get text from user
    string text = get_string("Text: ");

    // print grade with conditions
    actual_grade = cal_grade(text);
    if (actual_grade > 16)
    {
        printf("Grade 16+\n");
    }
    else if (actual_grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %.0f\n", actual_grade);
    }
}

// calculate grade
float cal_grade(string text)
{
    for (int i = 0; i < strlen(text); i++)
    {
        char character = text[i];
        if (character == ',')
        {
            total_comma += 1;
        }

        // printf("%c\n", character);
        if (character == ',' || character == ' ')
        {
            total_word += 1;
        }
        // printf("this is space %i\n", total_word);

        else if (character == '.' || character == '!' || character == ':' || character == '?')
        {
            total_sentence += 1;
        }
        else if (character != 39)
        {
            total_letter += 1;
        }
        // printf("this is dot %i\n", total_sentence);
    }
    // printf("total_letter: %f\n", total_letter);
    // printf("total_word: %f\n", total_word - total_comma);
    // printf("total_sentence: %f\n", total_sentence);
    L = total_letter / (total_word - total_comma) * 100;
    S = total_sentence / (total_word - total_comma) * 100;
    grade = (0.0588 * L) - (0.296 * S) - 15.8;

    // printf("total_grade: %f\n", grade);
    return grade;
}