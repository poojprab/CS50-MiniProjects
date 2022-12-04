// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 10000;
unsigned int numwords = 0;
unsigned int hashnum = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    //hash word
    hashnum = hash(word);
    node *cursor = table[hashnum];
    while (cursor != NULL){
        if(strcasecmp(cursor->word, word) == 0){
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int sum = 0;
    for(int i = 0; i < strlen(word); i++){
        sum = (int)tolower(word[0]) * (i+1) + sum;
    }
    sum = sum%N;
    return sum;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    char word[LENGTH + 1];
    //open dictionary file into c
    FILE *file = fopen(dictionary, "r");
    if(file == NULL){
        return false;
    }
    while (fscanf(file, "%s", word) != EOF){
        node *n = malloc(sizeof(node));
        if (n == NULL){
            return false;
        }
        strcpy(n->word, word);
        hashnum = hash(word);
        n->next = table[hashnum];
        table[hashnum] = n;
        numwords ++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    //"A good way to go about this is to just create a global variable and keep track of # of load iterations, then just return it during size."
    return numwords;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for(int i = 0; i < N; i++){
        node *cursor = table[i];
        node *temp = cursor;
        while(cursor != NULL){
            cursor = cursor->next;
            free(temp);
            temp = cursor;
        }
        free(temp);
    }
    return true;
    //set temp = cursor
    //move cursor
    //free temp
    //if cursor = NULL, stop
}
