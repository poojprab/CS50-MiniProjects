#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
bool only_digits(string s);
int main(int argc, string argv[])
{
    if (argc != 2){
        printf("Usage ./caesar key");
        return 1;
    }

   /*for(int i = 1; i < strlen(argv[i]); i++){
       if(isdigit(argv[1][i]) == 0){
            printf("Usage: ./caesar key");
            return 1;
        }
    }*/

    string key = (argv[1]);
    int keya = 0;

    if(only_digits(key)){
        keya = atoi(key);
    }
    else{
        printf("Usage: ./caesar key");
        return 1;
    }

    string text = get_string("plaintext:  ");
    printf("ciphertext: ");

//encrypts "barfoo" as "yxocll" using 23 as key

    for(int j = 0; j < strlen(text); j++){
        if (isupper(text[j])){
            printf("%c", (text[j] - 65 + keya) % 26 + 65);
        }
        else if (islower(text[j])){
            //printf("%i", ((int)text[j] - 97 + key) % 26 + 97);
            printf("%c", (text[j] - 97 + keya) % 26 + 97);
        }
        else
        {
            printf("%c", text[j]);
        }
    }
    printf("\n");
    return 0;
}
bool only_digits(string s){
    for(int i = 0; i < strlen(s); i++){
       if(isdigit(s[i]) == 0){
            return false;
        }
    }
    return true;
}