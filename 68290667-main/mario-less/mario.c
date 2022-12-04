#include <cs50.h>
#include <stdio.h>
#include <string.h>
int main(void)
{
    //ask for height of pyramid
    int height;
    do{
        height = get_int("Height: \n");
    }
    while ((height <1) || (height >8));

    for(int row =0; row<height; row++) {
        int col =  0;
        for(col =0;col < height-(row+1); col++) {
            printf("%s", " ");
        }
        for(;col<height;col++) {
            printf("%s", "#");
        }
        printf("%s", "\n");

    }
}