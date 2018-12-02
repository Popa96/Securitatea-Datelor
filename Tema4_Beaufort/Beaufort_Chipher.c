/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#define NR 64

char BeaufortEncrypt(char *alphabet, int *positionKey, char text, int position)
{
    int encryptedText;

    for (int i = 0; i < 26; i++)
    {
        if (text == alphabet[i])
        {
            encryptedText = (i + positionKey[position]) % 26;
            return alphabet[encryptedText];
        }
    }
}

char BeaufortDecrypt(char *alphabet, int *positionKey, char text, int position)
{
    int decryptedText;

    for (int i = 0; i < 26; i++)
    {
        if (text == alphabet[i])
        {
            decryptedText = (i - positionKey[position]) % 26;
            return alphabet[decryptedText];
        }
    }
}

int main() {
    char plainText[NR], alphabet[27] = "abcdefghijklmnopqrstuvwxyz", key[NR], encryptedText[NR], decryptedText[NR];
    int positionKey[NR], position = 0;
    printf("plaintext:\n");
    gets(plainText);
    printf("key\n");
    gets(key);

    int textLength = strlen(plainText);
    int keyLength = strlen(key);

    for (int i = 0; i < keyLength; i++) {
        for(int j = 0; j < 26; j++)
        {
            if (key[j] == alphabet[i])
            {
                positionKey[j] = i;
            }
        }
    }

    int x = 1;
    printf("\nChoose:\n1.Encrypt text(Beaufort).\n2.Decrypt text(Beaufort).\n");
    scanf("%d", &x);

    switch (x)
    {
        case 1:
            for(int i = 0; i < textLength; i++)
            {
                encryptedText[i] = BeaufortEncrypt(alphabet, positionKey, plainText[i], position % keyLength);
                ++position;
            }
            encryptedText[textLength] = '\0';
            printf("\nEncrypted text(Beaufort): %s\n", encryptedText);
            break;

        case 2:
            for(int i = 0; i < textLength; i++)
            {
                decryptedText[i] = BeaufortDecrypt(alphabet, positionKey, plainText[i], position % keyLength);
                ++position;
            }
            decryptedText[textLength] = '\0';
            printf("\nDecrypted text(beaufort): %s\n", decryptedText);
            break;

        default:
            printf("Exit");
    }

    return 0;
}