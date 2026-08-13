#include <iostream>

using std::cout;
using std::endl;

void insertionSort(int numbers[], size_t size);


int main(){

    constexpr int sz = 6;
    int numbers[sz] = {91, 45, 11, 16, 82, 41};
    insertionSort(numbers, sz);

    for(const int number: numbers)
        cout << number << endl;

    return 0;
}
// Assume the first element is already sorted.
// Pick the next element from the unsorted section (the "key").
// Compare the key with the elements in the sorted section moving backward.
// Shift greater elements to the right to create an available opening.
// Insert the key into its correct, newly cleared position.
// Repeat the sequence for all remaining items until the entire array is aligned.
void insertionSort(int numbers[], size_t size) {
    if(size < 2) return;
    
    for (size_t index = 1; index < size; index++) {
         int temp = numbers[index];
         size_t innerIndex = index;

         while (innerIndex > 0 && temp < numbers[innerIndex - 1]) {
            numbers[innerIndex] = numbers[innerIndex - 1];
            --innerIndex;
         }

         numbers[innerIndex] = temp;
    }
}
