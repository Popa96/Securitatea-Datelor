#include<stdio.h>
#include<string.h>
char* alf = "abcdefghijklmnopqrstuvwxyz";

void Encryption(char text[], char key[])
{
	int i;
	strcat(key, text);
	for (i = 0; i < strlen(text); ++i)
	{
		int charText = tolower(text[i]) - 'a';
		int charKey = tolower(key[i]) - 'a';
		printf("%c", alf[(charText + charKey) % strlen(alf)]);
	}
}

void Decryption(char text[], char key[])
{
	int i;
	int charKey;
	char c;
	for (i = 0; i < strlen(text); ++i)
	{
		int charText = tolower(text[i]) - 'a';
		if (i < strlen(key)) {
			charKey = tolower(key[i]) - 'a';
		}
		else {
			charKey = tolower(c) - 'a';
		}

		c = alf[(charText - charKey + strlen(alf)) % strlen(alf)];
		printf("%c", c);

	}
}

int main()
{
	int option;
	char key[100];
	char text[100];
	while (1)
	{
		printf("\nEnter your choise: \n");
		printf("1.Encryption \n");
		printf("2.Decryption \n");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			printf("Enter your  decryption text: ");
			scanf(" %[^'\n']s", text, sizeof(text));
			printf("Enter the key: ");
			scanf(" %[^'\n']s", key, sizeof(key));
			Encryption(text, key);
			break;
		case 2:
			printf("Enter your  decryption text: ");
			scanf(" %[^'\n']s", text, sizeof(text));
			printf("Enter the key:: ");
			scanf(" %[^'\n']s", key, sizeof(key));
			Decryption(text, key);
			break;
		default:
			printf("Your choise is not valid");
			break;
		}
	}
	return 0;
}