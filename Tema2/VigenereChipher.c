/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>

void GenerateKey(char newKey[255],char key[255],int keyLen,int msgLen)
{
    int i=0;
    int j=0;
    for(i = 0, j = 0; i < msgLen; ++i, ++j){
        if(j == keyLen)
            j = 0;
        newKey[i] = key[j];
    }
    newKey[i] = '\0';
}
void EcncryptVigenere(char encryptedMsg[255],char newKey[255],char msg[255],int msgLen)
{
    int i=0;
    for(i = 0; i < msgLen; ++i)
        encryptedMsg[i] = ((msg[i] + newKey[i]) % 26) + 'A';
    encryptedMsg[i] = '\0';
}

void DecryptedVigenere(char encryptedMsg[255],char newKey[255],char decryptedMsg[255],int msgLen)
{
    int i=0;
    for(i = 0; i < msgLen; ++i)
        decryptedMsg[i] = (((encryptedMsg[i] - newKey[i]) + 26) % 26) + 'A';
    decryptedMsg[i] = '\0';
}

int main(){
    char msg[255] = "FACULTATEADEAUTOMATICA";
    char key[255] = "CRAIOVA";
    int msgLen = strlen(msg), keyLen = strlen(key);
    char newKey[msgLen], encryptedMsg[msgLen], decryptedMsg[msgLen];
    GenerateKey(newKey,key,keyLen,msgLen);
    EcncryptVigenere(encryptedMsg,newKey,msg,msgLen);
    DecryptedVigenere(encryptedMsg,newKey,decryptedMsg,msgLen);
    printf("Original Message: %s.\n",msg);
    printf("Key:%s.\n",key);
    printf("New Generated Key:%s.\n",newKey);
    printf("Encrypted Message:%s.\n",encryptedMsg);
    printf("Decrypted Message:%s.\n",decryptedMsg);
 
    return 0;
}
