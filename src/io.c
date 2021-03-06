#include "header.h"


int readFile(char charArray[9][9]) {
    char input[17][10];
    FILE* fp;
    char inputFName[100];
    int valid_file = 0, i;

    while(valid_file == 0) {
        printf("Input the name of the unsolved sudoku text file or CANCEL to stop the program: ");
        scanf("%s", inputFName);

        if(strcmp(inputFName, "CANCEL") == 0){
            return 1;
        }

        /* insert folder name into the front of inputFName */
        for(i = 93; i >= 0; i --) {
            inputFName[i + 6] = inputFName[i];
        }
        inputFName[0] = 'i';
        inputFName[1] = 'n';
        inputFName[2] = 'p';
        inputFName[3] = 'u';
        inputFName[4] = 't';
        inputFName[5] = '/';

        if( access( inputFName, F_OK ) == 0 ) {
            printf("Solving...\n");
            valid_file = 1;
        } else {
            printf("That file does not exist, please try again\n");
        }
    }

    //Read from file
    fp=fopen(inputFName, "r");
    for(int i=0; i<17; i++) {
        fgets(input[i], 10, fp);
    }
    fclose(fp);

    //copy to charArray, reformatted
    for(int i=0; i<17; i=i+2) {
        for(int j=0; j<9; j++) {
            charArray[i/2][j] = input[i][j];
        }
    }
    return 0;
}


void printSudoku(Sudoku * sudoku) {
    for(int i=0; i<9; i++) {
        if(i == 0) {printf("\n┌─────────┬─────────┬─────────┐\n");}
        else if(i%3 == 0) {printf("├─────────┼─────────┼─────────┤\n");}

        for(int j=0; j<9; j++) {
            if(j%3 == 0) {printf("│");}

            /* replaces 0 with . to increase clarity on console*/
            if(sudoku->rows[i][j]->value != 0){
                printf(" %d ", sudoku->rows[i][j]->value);
            } else {
                printf(" . ");

            }
        }
        printf("│\n");
    }
    printf("└─────────┴─────────┴─────────┘\n");
}
