#include <iostream>

using namespace std;

void selectionSort(int numbers[], size_t size);

int main() {

    constexpr size_t sz = 8;
    int numbers[sz] = {9, 15, 3, 55, 4, 100, 28, 100};

    selectionSort(numbers, sz);

    for (const int number : numbers)
        cout << number << endl;

    return 0;
};
// Selection Sort is an in-place comparison sorting algorithm. 
// It divides the input array into two parts: a sorted subarray on the left and an unsorted subarray on the right.
// In each iteration, it finds (selects) the smallest element from the unsorted subarray and swaps it with the leftmost unsorted element.
void selectionSort(int numbers[], size_t size){

    size_t index, 
            innerIndex;

    for(index = 0; index < size; index++){
        size_t minIndex = index;

        for(innerIndex = index + 1; innerIndex < size; innerIndex++){

            if(numbers[innerIndex] < numbers[minIndex]){
                minIndex = innerIndex;
            }
        }

        if( index != minIndex){
            int temp = numbers[index];
            numbers[index] = numbers[minIndex];
            numbers[minIndex] = temp;
        }
    }    
}
