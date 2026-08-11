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

void bubbleSort(int numbers[], size_t size){

    if(size < 2) return;
    
    size_t lastIndex,
        innerIndex, 
        firstIndex = 0;

    for(size_t lastIndex = size - 1; lastIndex > firstIndex; lastIndex--){
        for(innerIndex = 0; innerIndex < lastIndex; innerIndex++){

            if(numbers[innerIndex] > numbers[innerIndex + 1]){
                
                int temp = numbers[innerIndex];
                numbers[innerIndex] = numbers[innerIndex+1];
                numbers[innerIndex + 1] = temp;
            }
        }
    }
}
