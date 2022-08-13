// NxM matrix calculator
#include <stdio.h>
#include <stdlib.h>

int (*create_matrix(int, int))[];
void print_matrix(int(*)[], int, int);

int horizontal;

int main() {

    printf("Enter vertical dimension size: ");
    int y;
    scanf("%d", &y);

    printf("Enter horizontal dimension size: ");
    int x;
    scanf("%d", &x);
    horizontal = x;

    int(*matrix)[x] = create_matrix(x, y);
//    printf("%d\n", *(*(matrix + 0) + 3)); // y = 0, x = 3
    print_matrix(matrix, x, y);

    free(matrix);
    return 0;
}

int (*create_matrix(int x, int y))[]{
    int i, j, n;
    int(*matrix)[x] = calloc(y, sizeof *matrix); // a pointer to a full array of size x.
    //matrix = address of array
    //*matrix = address of first element of array; *(matrix + 1) = address of first element of second array
    //**matrix = element that exists at the first element of array; *(*(matrix + 1) + 1) = second element of second array = matrix[1][1]
    n = 1;
    for(i = 0; i < y; i++){
        for(j = 0; j < x; j++){
            matrix[i][j] = n;
            n++;
        }
    }
    return matrix;
}


void print_matrix(int (*matrix)[horizontal], int x, int y){
    int i, j;
    for(i = 0; i < y; i++){
        printf("|");
        for(j = 0; j < x; j++){
            if(matrix[i][j] < 10){
                printf("0%d|", matrix[i][j]);
            }
            else{
                printf("%d|", matrix[i][j]);
            }
        }
        printf("\n");
    }
}
