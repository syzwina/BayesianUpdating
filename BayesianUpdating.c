#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void main(void) 
{
    printf("\n\nThere are 3 socks in a basket\n");
    printf("i : number of red socks in the basket\n");
    printf("R : event of pulling out a red sock\n");
    printf("B : event of pulling out a black sock\n");

    float assumption0 = 0.25, assumption1 = 0.25, assumption2 = 0.25, assumption3 = 0.25;
    float Rgiven0 = 0, Rgiven1 = 0.333, Rgiven2 = 0.666, Rgiven3 = 3/3;
    float Bgiven0 = 3/3, Bgiven1 = 0.666, Bgiven2 = 0.333, Bgiven3 = 0;
    float R, B;
    char choice[20];

    char red[] = "R";
    char black[] = "B";

    while (true){    
        // Input the Character
        printf("\nEnter the colour of sock(Red[R]/Black[B]) of your choice: ");
        scanf("%c", &choice);
        if (getchar() != '\n') continue;
        printf("\n");

        if (strcmp(choice,red) == 1) {
            printf("You pulled out a red sock\n\n");
            // printf("%f", Rgiven1 * assumption1);
            R =   (Rgiven0 * assumption0) 
                + (Rgiven1 * assumption1) 
                + (Rgiven2 * assumption2) 
                + (Rgiven3 * assumption3);

            printf("P(R): %.3f\n\n", R);
            assumption0 = (Rgiven0 * assumption0) / R;
            assumption1 = (Rgiven1 * assumption1) / R;
            assumption2 = (Rgiven2 * assumption2) / R;
            assumption3 = (Rgiven3 * assumption3) / R;

        }
        else if (strcmp(choice,black) == 1) {
            printf("You pulled out a Black sock\n\n");
            // printf("%f", Rgiven1 * assumption1);
            B =   (Bgiven0 * assumption0) 
                + (Bgiven1 * assumption1) 
                + (Bgiven2 * assumption2) 
                + (Bgiven3 * assumption3);

            printf("P(B): %.3f\n\n", B);
            assumption0 = (Bgiven0 * assumption0) / B;
            assumption1 = (Bgiven1 * assumption1) / B;
            assumption2 = (Bgiven2 * assumption2) / B;
            assumption3 = (Bgiven3 * assumption3) / B;
        }
        else break;

        printf("P(i)\n");
        printf("______________\n");
        printf("P(0): %f\n", assumption0);
        printf("P(1): %f\n", assumption1);
        printf("P(2): %f\n", assumption2);
        printf("P(3): %f\n", assumption3);

    }

}