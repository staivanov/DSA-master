#include <iostream>

using namespace std;

void bubbleSort(int numbers[], size_t size);

int main(){

    int numbers[5] = {9, 15, 3, 55, 4};
    unsigned sz = sizeof(numbers) / sizeof(numbers[0]);

    bubbleSort(numbers, sz);

    for (int number : numbers)
        cout << number << endl;

    return 0;
}
//Bubble sort is a simple sorting algorithm that works by repeatedly comparing neighboring elements and swapping them if they're in the wrong order.
void bubbleSort(int numbers[], size_t size){
    // Guard again 1 or zero numbers in the array.
    if(size < 2) return;
    
    size_t lastIndex,
        innerIndex, 
        firstIndex = 0;
    // With every iteration from here, the biggest number from the unsorted numbers is found and placed in its place on the right side.
    for(size_t lastIndex = size - 1; lastIndex > firstIndex; lastIndex--){
        // Every iteration finds the biggest number and passes it to the right.
        for(innerIndex = 0; innerIndex < lastIndex; innerIndex++){
            // Swap bigger with smaller number in asc order.
            if(numbers[innerIndex] > numbers[innerIndex + 1]){
                
                int temp = numbers[innerIndex];
                numbers[innerIndex] = numbers[innerIndex+1];
                numbers[innerIndex + 1] = temp;
            }
        }
    }
}
