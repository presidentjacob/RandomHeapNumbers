// Jacob Yepez
// heap.cpp
// This file creates all the code for the functions

#include "heap.h"

// Public functions

Heap::Heap(int size){
  heapArr = new int[size];
  heapSize = size;
  numItems = 0;
}

Heap::Heap(const Heap& h){
  heapSize = h.heapSize;
  numItems = h.numItems;
  heapArr = new int[heapSize];
  
  for(int i = 1; i <= numItems; i++){
    heapArr[i] = h.heapArr[i];
  }
}

Heap& Heap::operator=(const Heap& rhs){
  if(&rhs != this){
    delete [] heapArr;
    
    heapSize = rhs.heapSize;
    numItems = rhs.numItems;
    heapArr = new int[heapSize];
    for(int i = 1; i <= numItems; i++){
      heapArr[i] = rhs.heapArr[i];
    }
  }
  
  return *this;
}

Heap::~Heap(){
  delete [] heapArr;
}

// Inserts into the heap. The heap is a MIN heap
// It does NOT use the 0th element in the array
void Heap::insert(int num){
  if(numItems == heapSize - 1){
    resize();
  }else{
    int hole = ++numItems;
    while(hole > 1 && num < heapArr[hole/2]){
      heapArr[hole] = heapArr[hole/2];
      hole = hole/2;
    }
    heapArr[hole] = num;
  }
}

int Heap::deleteMin(){
  if(isEmpty()){
    throw emptyHeap();
  }else{
    int hole = 1;
    int returnValue = heapArr[hole];
    heapArr[hole] = heapArr[numItems];
    numItems--;
    percolateDown(hole);
    return returnValue;
  }
}

void Heap::flush(int num){
  int index = 1;
  
  while(index <= numItems){
    if(heapArr[index] == num){
      heapArr[index] = heapArr[numItems];
      numItems--;
      percolateDown(index);
    }else{
      index++;
    }
  }
}

void Heap::printHeap(){
  for(int i = 1; i < numItems + 1; i++){
    cout << heapArr[i] << " ";
  }
}

bool Heap::isEmpty(){
  return numItems == 0;
}

// Private functions

void Heap::percolateDown(int hole){
  int temp = heapArr[hole];
  while((hole*2 <= numItems && temp > heapArr[hole*2])
        || (hole*2+1 <= numItems && temp > heapArr[hole*2+1])){
    if(hole*2+1 <= numItems && heapArr[hole*2+1] < heapArr[hole*2]){
      heapArr[hole] = heapArr[hole*2+1];
      hole = hole*2+1;
    }else{
      heapArr[hole] = heapArr[hole*2];
      hole = hole*2;
    }   
  }
  heapArr[hole] = temp;
}

void Heap::resize(){
  int tempSize = heapSize;
  int* tempArray = new int[heapSize];
  for(int i = 0; i < tempSize; i++){
    tempArray[i] = heapArr[i];
  }
  
  delete [] heapArr;
  
  heapSize *= 1.5;

  heapArr = new int[heapSize];
  
  for(int i = 0; i < tempSize; i++){
    heapArr[i] = tempArray[i];
  }
  
  delete [] tempArray;
} 
