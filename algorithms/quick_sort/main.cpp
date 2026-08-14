#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int low, int high);
void quickSort(vector<int> &numbers, int low, int high);

int main(){

   vector<int> numbers {10, 8, 99, 24, 777};
   vector<int>::size_type sz = numbers.size();

   cout << "Unsorted numbers" << endl;

   for(const int& number: numbers) 
   {
        cout << number << " ";
   }
   cout << flush << "\n";

    quickSort(numbers, 0, sz - 1);

   cout << "Sorted numbers" << endl;

   for(const int& number: numbers) 
   {
        cout << number << " ";
   }
   cout << flush << "\n";


   return 0;
}

// Partitions the sub-array around a chosen pivot.
int partition(vector<int> &numbers, int low, int high) {

    int pivot = numbers[high],
        i = low - 1,
        j = low;

    while(j < high){

        if(numbers[j] < pivot){
            i++;
            swap(numbers[i], numbers[j]);
        }

        j++;
    }

    swap(numbers[i+1], numbers[high]);

    return i + 1;
}

 // Quick Sort is a highly efficient, comparison-based,
 // divide-and-conquer sorting algorithm. 
 // On average, it runs in $O(n \log n)$ time, making it one of the fastest general-purpose sorting methods.
 //  Quick Sort explanation
 //  1. Pick a Pivot: Select an element from the array to act as the pivot (commonly the last element, first element, or middle element).
  // 2. Partitioning: Rearrange the array so that all elements smaller than the pivot are placed to its left,
  // and all elements larger than the pivot are placed to its right.
  // 3. Recursion: Recursively apply the same steps to the sub-arrays to the left and right of 
  // the pivot until sub-arrays have 0 or 1 element (which are already sorted).
void quickSort(vector<int> &numbers, int low, int high) {

    if(low < high){
        // pi is the partitioning index; arr[pi] is now in its correct sorted position
        int pi = partition(numbers, low, high);
        // Recursively sort elements before and after partition. 
        quickSort(numbers, low, pi - 1);
        quickSort(numbers, pi + 1, high);
    }

    


}