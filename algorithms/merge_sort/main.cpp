#include <iostream>

using namespace std;

void mergeSort(int numbers[], int leftIndex, int rightIndex);
void merge(int numbers[], int leftIndex, int midIndex, int rightIndex);

int main(){

    constexpr int sz = 8;
    int numbers[sz] = {6, 11, 79, 63, 88, 20, 53, 777};

    mergeSort(numbers, 0, sz - 1);

    for(int number : numbers)
        cout << number << " ";

    cout << flush << "\n";
    
    return 0;
}
// A divide-and-conquer algorithm 
void merge(int numbers[], int leftIndex, int midIndex, int rightIndex){
    //Numbers must be divided into two arrays.
    int leftArraySize = midIndex - leftIndex + 1,
        rightArraySize = rightIndex - midIndex;

    int leftArray[leftArraySize],
        rightArray[rightArraySize];

    int leftArrayStartingIndex = 0;
    // First part of all numbers. Lefst side.
    while (leftArrayStartingIndex < leftArraySize)
    {

        leftArray[leftArrayStartingIndex] = numbers[leftIndex + leftArrayStartingIndex];
        leftArrayStartingIndex++;
    }

    int rightArrayStartingIndex = 0;
    // Second part of all numbers. Right side.
    while(rightArrayStartingIndex < rightArraySize){

        rightArray[rightArrayStartingIndex] = numbers[midIndex + 1 + rightArrayStartingIndex];
        rightArrayStartingIndex++;
    }

    int index = leftIndex,
        i = 0,
        j = 0;

    //Every element from first array is compared with every element in the second and then is added to numbers array in asc order.
    while(i < leftArraySize && j< rightArraySize){

        if(leftArray[i] <= rightArray[j]){

            numbers[index] = leftArray[i];
            index++;
            i++;
        }
        else {

            numbers[index] = rightArray[j];
            index++;
            j++;
        }
    }

    while(i < leftArraySize){

        numbers[index] = leftArray[i];
        index++;
        i++;
    }

    while(j < rightArraySize){

        numbers[index] = rightArray[j];
        index++;
        j++;
    }
}


//Breaks arrays in half.
// Base case is when every array size is 1.
// Calls merge function to combine all arrays in one that was like the fist, but this time is sorted in asc order.
void mergeSort(int numbers[], int leftIndex, int rightIndex){

    if (leftIndex >= rightIndex)
        return;

    int midIndex = leftIndex + ((rightIndex - leftIndex) / 2);
    mergeSort(numbers, leftIndex, midIndex);
    mergeSort(numbers, midIndex + 1, rightIndex);

    merge(numbers, leftIndex, midIndex, rightIndex);
}