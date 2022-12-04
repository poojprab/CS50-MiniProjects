#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++){
        for(int j = 0; j <width; j++){
            float RED = image[i][j].rgbtRed;
            float GREEN = image[i][j].rgbtGreen;
            float BLUE = image[i][j].rgbtBlue;

            int average = round((RED + GREEN + BLUE)/3);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
     for(int i = 0; i < height; i++){
        for(int j = 0; j <width; j++){
            float RED = image[i][j].rgbtRed;
            float GREEN = image[i][j].rgbtGreen;
            float BLUE = image[i][j].rgbtBlue;

            int Sred = round(0.393 * RED + 0.769 * GREEN + 0.189 * BLUE);
            int Sgreen = round(0.349* RED + 0.686 * GREEN + 0.168 * BLUE);
            int Sblue = round(0.272 * RED + 0.534 * GREEN + 0.131 * BLUE);

            if(Sred > 255){
                Sred = 255;
            }
            if(Sgreen > 255){
                Sgreen = 255;
            }
            if(Sblue > 255){
                Sblue = 255;
            }

            image[i][j].rgbtRed = Sred;
            image[i][j].rgbtGreen = Sgreen;
            image[i][j].rgbtBlue = Sblue;
        }
     }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width/2; j++){
            RGBTRIPLE x = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = x;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
     RGBTRIPLE x[height][width];
     for(int i = 0; i < height; i++){
        for(int j = 0; j <width; j++){
            x[i][j] = image[i][j];
        }
     }

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            int RED, BLUE, GREEN;
            RED = GREEN = BLUE = 0;
            float count = 0.00;

            for (int y = -1; y < 2; y++){
                for(int z = -1; z < 2; z++){
                    int currenty = i + y;
                    int currentz = j + z;

                    if (currenty < 0 || currenty > (height - 1) || currentz < 0 || currentz > (width - 1)){
                        continue;
                    }

                    RED += image[currenty][currentz].rgbtRed;
                    GREEN += image[currenty][currentz].rgbtGreen;
                    BLUE += image[currenty][currentz].rgbtBlue;

                    count++;
                }
                x[i][j].rgbtRed = round(RED / count);
                x[i][j].rgbtGreen = round(GREEN / count);
                x[i][j].rgbtBlue = round(BLUE / count);
            }
        }
    }

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            image[i][j].rgbtRed = x[i][j].rgbtRed;
            image[i][j].rgbtGreen = x[i][j].rgbtGreen;
            image[i][j].rgbtBlue = x[i][j].rgbtBlue;
        }
    }
    return;
}
