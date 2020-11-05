#include "lab7.h"
//No problems to report

int readInitialLength()
{
    int num = 0;
    do
    {
        printf("Pick Array Size\n");
        num = readValue();

        if(num < 1)
            printf("error: number is less than 1.\n");

    }while(num < 1);

    return num;

}
int *createAndFill(int length)
{
    int x, i;
    int * myArray = (int *) malloc(length * sizeof(int));
    printf("\nFill Array\n");
    for(i = 0; i < length; i++)
    {
        *(myArray + i) = readValue();
    }

    return myArray;

}
int menu()
{
    int choice;

    do
    {
        printf("\nMenu choices are:\n1) Display the sorted array\n2) Add a single value to the array\n3) Find a value in the array\n4) Quit\nChoose: ");
        scanf("%d", &choice);

        if(choice < 1 || choice > 4)
            printf("\nYou entered an invalid menu choice.");

    }while(choice < 1 || choice > 4);

    return choice;
}

void printSortedArray(int* myArray, int length)
{
    int i;
    selectionSort(myArray, length);
    printf("\nDisplay Array\n");
    printf("[");
    for(i = 0; i < length; i++)
    {
        if(i == length-1)
            printf("%d]\n", myArray[i]);
        else
            printf("%d, ", myArray[i]);
    }
}

int *addItem(int* length, int* myArray)
{
    int len = *length;
    int * copy = (int * )malloc((len + 1) * sizeof(int));
    for(int i = 0; i < len; i++)
        *(copy + i) = *(myArray + i);
    
    printf("\nAdd Value to Array\n");
    copy[len] = readValue();

    cleanUp(myArray);
    *length = len + 1;
    return copy;
}

int readValue()
{
    int value=0;
    printf("Enter a number: ");
    scanf("%d", &value);
    return value;
}

void printIfFound(int value, int* myArray, int length)
{
    int flag = 0, i;
    selectionSort(myArray, length);
    for(i = 0; i < length; i++)
    {
        if(myArray[i] == value)
        {
            flag = 1;
            printf("Value found at position %d\n", i);
            i = length;
        }
    }
    if(flag == 0)
        printf("Value NOT found\n");

}

void cleanUp(int* myArray)
{
    free(myArray);
}

void selectionSort(int* myArray, int length)
{
  int start, search, min;
  int temp;

  for(start = 0; start < length - 1; start++)
  {
    min = start;
    for(search = start + 1; search < length; search++)
    {
      if(myArray[search] < myArray[min])
        min = search;
    } // end for search
  
    temp = myArray[min];
    myArray[min] = myArray[start];
    myArray[start] = temp;
  }// end for start
}// end function