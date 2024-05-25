#define _CRT_SECURE_NO_WARNINGS
#include "ln.h"

int main() {
    printf("Laboratory work or additional task? \n");   
    int M;
    int choice;
    int number;
    scanf("%d", &M);
    if (M == 1) {
        printf("1. Calculation of aircraft braking time.\n");
        printf("2. Calculation of the sum of a series.\n");
        printf("3. Removing words with a prefix.\n");
        printf("4. Array type.\n");
        printf("5. Counting words with vowels.\n");
        printf("6. Editing an Array. \n");
        printf("7. Substitution in long number. \n");
        printf("Enter your choice. \n");
        scanf("%d", &choice);
        while (getchar() != '\n');

        switch (choice) {
        case 1:
            samolet();
            break;
        case 2:
            stroka();
            break;
        case 3:
            string();
            break;
        case 4:
            massiv();
            break;
        case 5:
            glasn();
            break;
        case 6:
            massivny();
            break;
        case 7:
            bitovy();
            break;
        }
    }
    else if(M==2){
        printf("1. Counting words in text.\n");
        printf("2. Counting words without L and l.\n");
        printf("3. Sequence Type Definition.\n"); 
        printf("4. Editing an array with sorting. \n"); 
        scanf("%d", &number);
        while (getchar() != '\n');
        switch (number) {
        case 1:
            slova();
            break;
        case 2:
            slova_lL();
            break;
        case 3:
            posled();
            break;
        case 4:
            sortmass();
            break;
        }
      }

        return 0;
 }

