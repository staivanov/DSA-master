#include <iostream>

using namespace std;

void bubbleSort(int numbers[], int size);

int main(){

    int numbers[5] = {9, 15, 3, 55, 4};
    unsigned sz = sizeof(numbers) / sizeof(numbers[0]);

    bubbleSort(numbers, sz);
    signed index = 0,
            lastIndex = sz - 1;

    while(index < sz){
        if (index == lastIndex)
            cout << numbers[index] << endl;
        cout << numbers[index] << ", ";
        index++;
    }

    return 0;
}

void bubbleSort(int numbers[], int size){

    size_t lastIndex,
        innerIndex, 
        firstIndex = 0;

    for(lastIndex = size - 1; lastIndex > firstIndex; lastIndex--){
        for(innerIndex = 0; innerIndex < lastIndex; innerIndex++){

            if(numbers[innerIndex] > numbers[innerIndex + 1]){
                
                int temp = numbers[innerIndex];
                numbers[innerIndex] = numbers[innerIndex+1];
                numbers[innerIndex + 1] = temp;
            }
        }
    }
}