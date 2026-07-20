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

    public:
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


    public:
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
        //Compare childres if someone is bigger than paren. If it's true swap till heap is valid.
        void sinkDown(int index){

            int maxIndex = index;
            
            while(true){

                int leftIndex = leftChild(index);
                int rightIndex = rightChild(index);

                if(heap[leftIndex] > heap[maxIndex] && (leftIndex < heap.size())){
                    maxIndex = leftIndex;
                }

                if(heap[rightIndex] > (heap[maxIndex] && (rightIndex < heap.size()))){ 
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