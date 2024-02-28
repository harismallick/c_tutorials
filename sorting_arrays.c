#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void sortCharArr(char array[], int size);

int main() {

    // unsorted array:
    int array[] = {9,1,8,2,7,3,6,4,5};
    int arrLen = sizeof(array)/sizeof(array[0]);
    int temp;
    // Bubble sort O(N^2)
    bool swapped = false;
    for(int i=0; i < arrLen-1; i++) {
        for(int j=0; j < arrLen-i-1; j++) {
            if(array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                swapped = true;
            }
        }
        if(swapped == false) {
            break;
        }
    }
    printf("The sorted array:\n");
    
    for(int i=0; i < arrLen; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    char charArr[] = {'Z', 'F', 'G', 'A', 'B'};
    int charArrLen = sizeof(charArr)/sizeof(charArr[0]);
    sortCharArr(charArr, charArrLen);
    for(int i=0; i < charArrLen; i++) {
        printf("%c ", charArr[i]);
    }
    printf("\n");
}

void sortCharArr(char array[], int size) {
    int temp;
    bool swapped = false;
    for(int i=0; i < size-1; i++) {
        for(int j=0; j < size-i-1; j++) {
            if(array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                swapped = true;
            }
        }
        if(swapped == false) {
            break;
        }
    }
}
