#include <iostream>
#include <vector>

using std::vector;


class Heap {

    private:
        vector<int> heap; 

    // Formula for left child is |2*index+1| and right child |2*index+2|.
    // root | left child | right child | child of the left child | child of the right child

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