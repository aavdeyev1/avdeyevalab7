#ifndef LAB_7
#define LAB_7

#include <stdio.h>
#include <stdlib.h>


int readInitialLength();
int* createAndFill(int length);
int menu();
void printSortedArray(int* myArray, int length);
int* addItem(int* length, int* myArray);
int readValue();
void printIfFound(int value, int* myArray, int length);
void cleanUp(int* myArray);
void selectionSort(int* myArray, int length);

#endif 
