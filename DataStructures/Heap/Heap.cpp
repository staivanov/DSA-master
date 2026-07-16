#include <iostream>
#include <vector>
#include <climits>

using std::cout;
using std::endl;
using std::vector;

class Heap {

    private:
        vector<int> heap; 

    // Formula for left child is |2*index+1| and right child |2*index+2|.
    // root | left child | right child | child of the left child | child of the right child
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

        int remove(){
            if(heap.empty()){
                return INT_MIN;
            }

            int maxValue = heap.front();

            if(heap.size() == 1){
                heap.pop_back();
            }
            else {
                heap[0] = heap.back();
                heap.pop_back();
              
            }

            return maxValue;
        }


    public:
        void printHeap(){
            cout << "\n[";
            
            for(int index = 0; index < heap.size(); index++){
                cout << heap[index];

                if(index < heap.size() -1){
                    cout << ", ";
                }
            }
            cout << "]" << endl;
        }

    private:
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
};