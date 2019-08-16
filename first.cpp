#include<iostream>
#include<stdio.h>
using namespace std;

template <class A, class B>
bool make2dArray(A ** &x, B numberOfRows, B numberOfCols){
    try{
        x = new A * [numberOfRows];
        for (int i=0; i<numberOfRows; i++){
            x[i] = new A [numberOfCols];
        }
        return true;
    }catch(bad_alloc){
        return false;
    }
}

template <class A, class B>
void fill2dArray(A ** &x, B numberOfRows, B numberOfCols){
    for (int i=0; i<numberOfRows; i++){
        for (int j=0; j<numberOfCols; j++){
            printf("Please input character of array[%d][%d]: ", i, j);
            scanf("\n%c", &x[i][j]);
        }
    }
}

template <class A, class B>
void show2dArray(A ** &x, B numberOfRows, B numberOfCols){
    printf("This Array is:\n");
    for (int i=0; i<numberOfRows; i++){
        for (int j=0; j<numberOfCols; j++){
            printf("%c\t", x[i][j]);
        }
        printf("\n");
    }
}

template <class A, class B>
void delete2dArray(A ** &x, B numberOfRows){
    for (int i=0; i<numberOfRows; i++){
        delete [] x[i];
    }
    delete [] x;
    x = NULL;
}

int main(){
    printf("Hello, World\n");
    // int *y = new int (10);
    // int array[5][6];
    char**array;
    int m, n;
    printf("Please input number of rows and cols:");
    scanf("%d %d", &m, &n);
    make2dArray(array, m, n);
    fill2dArray(array, m, n);
    show2dArray(array, m, n);
    delete2dArray(array, m);
    return 0;
}