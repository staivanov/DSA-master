#include <iostream>
#include <vector>
#include <climits>

using std::cout;
using std::endl;
using std::vector;

class Heap {

    // Formula for left child is |2*index+1| and right child |2*index+2|.
    // root | left child | right child | child of the left child | child of the right child
    private:
        vector<int> heap;

    int parent(int index){
          return (index - 1) / 2;
    }

    int leftChild(int index){
         return 2 * index + 1;
    }

    int rightChild(int index){
          return 2 * index + 2;
    }

    void swap(int indexOne, int indexTwo){

            int temp = heap[indexOne];
            heap[indexOne] = heap[indexTwo];
            heap[indexTwo] = temp;
    }

    ///@brief Inser element of type `int` in the Heap.
    public:
        void insert(int value){

            heap.push_back(value);
            int current = heap.size() - 1;

            while ((current > 0) && (heap[current] > heap[parent(current)]))
            {
                swap(current, parent(current));
                current = parent(current);
            }
        }
    ///@brief Remove and return element of type `int` from the Heap.
        int remove(){

            if(heap.empty()){
                return INT_MIN;
            }

            int maxValue = heap.front();

            if(heap.size() == 1){
                heap.pop_back();
            } else {
                heap[0] = heap.back();
                heap.pop_back();
                sinkDown(0);
            }
            
            return maxValue;
        }

        ///@brief Print all elements in the Heap.
        void printHeap(){

            cout << "\n[";
            int sz = heap.size(),
                index = 0;

            while(index < sz){

                cout << heap[index];

                if (index < heap.size() - 1)
                    cout << ", ";

                index++;
            }

            cout << "]" << endl;
        }

    private:
        ///@brief Compare childres. If someone is bigger than the parent swap till heap is valid.
        void sinkDown(int index){

            int maxIndex = index;
            int sz = heap.size();
            
            while(true){

                int leftIndex = leftChild(index);
                int rightIndex = rightChild(index);

                if((leftIndex < sz && heap[leftIndex] > heap[maxIndex])){
                    maxIndex = leftIndex;
                }

                if (rightIndex < sz && heap[rightIndex] > heap[maxIndex]) {
                    maxIndex = rightIndex;
                }

                if(maxIndex != index){
                    swap(index, maxIndex);
                    index = maxIndex;
                } else {
                    return;
                }
            }
        }
};