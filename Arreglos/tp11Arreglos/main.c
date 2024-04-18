#include <stdio.h>
#include <stdlib.h>


void showArray(int array[], int validos);
void bubbleSort(int array[], int validos);
int findMaxIndex(int array[], int validos, int firstPos);
int findMinIndex(int array[], int validos, int firstPos);
int main() {

    int array[] = {3, 5, 1, 2, 4};
    int validos = 5;

    showArray(array, validos);

    bubbleSort(array, validos);

    showArray(array, validos);

    return 0;
}



int findMinIndex(int array[], int validos, int firstPos) {
    int minIndex = firstPos; /// seteamos un indice para comparar
    for (int i = firstPos + 1; i < validos; i++)
        if (array[minIndex] > array[i]) // si el menor es mayor algo es mentira
            minIndex = i; // vas a comparar a partir de este valor
    return minIndex;
}


int findMaxIndex(int array[], int validos, int firstPos) {
    int maxIndex = firstPos;
    for (int i = firstPos + 1; i < validos; i++)
        if (array[maxIndex] > array[i])
            maxIndex = i;
    return maxIndex;
}


void bubbleSort(int array[], int validos) {
    for (int i = 0; i < validos - 1; i++) {
        int minPos = findMaxIndex(array, validos, i);

        int temp = array[i]; // no perder referencia al valor
        array[i] = array[minPos];
        array[minPos] = temp;


    }
}

void showArray(int array[], int validos) {
    for (int i = 0; i < validos; i++)
        printf("%d ", array[i]);
    printf("\n");
}
