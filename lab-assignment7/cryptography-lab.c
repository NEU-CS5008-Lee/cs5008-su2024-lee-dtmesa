//Dylan Mesa
//mesa.d@northeastern.com

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* function to encrypt the data*/
void encrypt(char text[], int key)
{
    int len = strlen(text);
    int startVal = 'a';
    for(int i = 0; i < len; i++){
        text[i] = (text[i] + key - startVal) % 26 + startVal;
    }
}

/*function to decrypt the data*/
void decrypt(char text[],int key)
{
    int len = strlen(text);
    int startVal = 'a';
    for(int i = 0; i < len; i++){
        text[i] = (text[i] - key - startVal + 26) % 26 + startVal;
    }
}


/*----------- Main program---------------*/
int main()
{
    char text[20] ;
    int keyvalue=3;
    /*Input string */
    printf("Enter the message:  ");
    scanf("%s",text);
    printf("text input   = %s\n",text);
    
    /*call function to encrypt the data*/
    encrypt(text,keyvalue);
    printf("Encrypted value = %s\n",text);
    
    /*call function to decrypt the data*/
    decrypt(text,keyvalue);
    printf("Decrypted value = %s\n",text);
    
    return 0;
}
