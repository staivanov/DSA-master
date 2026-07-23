#include <iostream>

using std::cout;
using std::endl;

void insertionSort(int numbers[], signed size);


int main(){

    constexpr int sz = 6;
    int numbers[sz] = {91, 45, 11, 16, 82, 41};
    insertionSort(numbers, sz);

    int index = 0;

    while(index < sz)
    {
        if(index == sz - 1){
            cout << numbers[index] << endl;
            break;
        }
        cout << numbers[index] << ", ";
        index++;
    }


    return 0;
}

void insertionSort(int numbers[], signed size) {

    int index, 
    innerIndex,
    temp,
    invalidIndex = -1;

    for(index = 1; index < size; index++){

        temp = numbers[index];
        innerIndex = index - 1;

        while((innerIndex > invalidIndex) && (temp < numbers[innerIndex])){

            numbers[innerIndex + 1] = numbers[innerIndex];
            numbers[innerIndex] = temp;
            innerIndex--;
        }
    }
}