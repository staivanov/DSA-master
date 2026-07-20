#include <iostream>

using namespace std;

void selectionSort(int numbers[], unsigned size);


int main(){

    constexpr unsigned sz = 8;
    int numbers[sz] = {9, 15, 3, 55, 4, 100, 28, 100};

    selectionSort(numbers, sz);
    signed index = 0,
            lastIndex = sz - 1;

    while(index < sz){
        if (index == lastIndex) {
            cout << numbers[index] << endl;
            break;
        }

        cout << numbers[index] << ", ";
        index++;
    }


    return 0;
}

void selectionSort(int numbers[], unsigned size){

    int index, 
            innerIndex,
            numbersLen = size;

    for(index = 0; index < numbersLen; index++){
        int minIndex = index;

        for(innerIndex = index + 1; innerIndex < numbersLen; innerIndex++){

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