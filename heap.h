// Jacob Yepez
// heap.h
// This file creates the prototypes for each of the functions in the heap

#include <iostream>

using namespace std;

class Heap{
 private:
  int* heapArr;
  int heapSize;
  int numItems;
  void resize();
  void percolateDown(int hole);
 public:
  class emptyHeap{};
  
  Heap(int num);
  Heap(const Heap& h);
  Heap& operator=(const Heap& rhs);
  ~Heap();
  
  void flush(int num);
  void insert(int num);
  bool isEmpty();
  void printHeap();
  int deleteMin();
};
