/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

void CaesarDecryption(char expression[100], int key)
{
    char character;

    for(int iter = 0; expression[iter] != '\0'; ++iter){
        character = expression[iter];

        if(character >= 'a' && character <= 'z'){
            character = character - key;

            if(character < 'a'){
                character = character + 'z' - 'a' + 1;
            }

            expression[iter] = character;
        }
        else if(character >= 'A' && character <= 'Z'){
            character = character - key;

            if(character < 'A'){
                character = character + 'Z' - 'A' + 1;
            }

            expression[iter] = character;
        }
    }

    printf("CaesarDecryption %s", expression);
}

void CaesarEncryption(char expression[100], int key)
{
    char character;
    for (int iter = 0; expression[iter] != '\0'; ++iter)
    {
        character = expression[iter];
        if (character >= 'a' && character <= 'z')
        {
            character += key;
            if (character > 'z')
                character = character - 'z' + 'a' - 1;
            expression[iter] = character;
        }
        else if (character >= 'A' && character <= 'Z')
        {
            character = character + key;
            if (character > 'Z')
                character = character - 'Z' + 'A' - 1;
            expression[iter] = character;
        }
    }

    printf("CaesarEncryption: %s", expression);
}

int main()
{
    int key = 7;
    char text1[255] = "securitatea datelor laborator";
    char text2[255] = "zljbypahalh khalsvy shivyhavy";
    CaesarEncryption(text1, key);
    printf("\n");
    CaesarDecryption(text2, key);

    return 0;
}
