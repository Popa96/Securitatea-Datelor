/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
 
int main()
{
   char yourString[100];
   int iterator = 0, count[26] = {0}, x, maxOccur=0 , value=0 ;
 
   printf("Enter a string\n");
   gets(yourString);
 
   while (yourString[iterator] != '\0') {
 
      if (yourString[iterator] >= 'a' && yourString[iterator] <= 'z') {
         x = yourString[iterator] - 'a';
         count[x]++;
      }
 
      iterator++;
   }
 
   for (iterator = 0; iterator < 26; iterator++)
   {
         printf("%c occurs %d times in your string.\n", iterator + 'a', count[iterator]);
         if(count[iterator]>maxOccur)
         {
             maxOccur=count[iterator];
             value=iterator;
         }
   }
   
        printf("The character %c most occurs %d times in your string.\n", value + 'a', maxOccur);
        
   return 0;
}