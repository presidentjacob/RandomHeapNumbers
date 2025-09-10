// Jacob Yepez
// p4.cpp
// This file holds the main program. Random numbers are generated on the heap
// then copies onto another. It then deletes the min and then flushes out
// all of a certain value.

#include <ctime>
#include "heap.h"

using namespace std;

const int HEAPSIZE = 15;
const int MAXVAL = 99;
const int MINVAL = 1;
const int RANDINDEXMIN = 1;
const int RANDINDEXMAX = 20;
const int INSERTTOTAL = 20;
const int TESTFLUSHNUM = 2;
const int REPEATNUMTOTAL = 5;
const int TEST_ARR[] = {1, 15, 2, 16, 15, 2, 3, 17, 18, 15, 19, 3, 2, 3};

int main(){
  Heap firstHeap(HEAPSIZE);
  int repeatedNum[INSERTTOTAL];
  int randIndex;
  int randomNum;
  srand(time(0));
  
  cout << endl << endl;
  
  for(int i = 0; i < INSERTTOTAL; i++){
    randomNum = rand() % MAXVAL + MINVAL;
    repeatedNum[i] = randomNum;
    cout << "Inserting " << randomNum << " into the heap " << endl;
    firstHeap.insert(randomNum);
  }
  
  randIndex = rand() % RANDINDEXMAX + RANDINDEXMIN;
  
  for(int i = 0; i < REPEATNUMTOTAL; i++){
    firstHeap.insert(repeatedNum[randIndex]);
  }
  
  cout << endl << endl;
  cout << "Copying first heap into a second heap." << endl;
  Heap secondHeap(firstHeap);
  cout << "Now deleting minimum of second heap until it is empty." << endl;
  
  while(!secondHeap.isEmpty()){
    cout << secondHeap.deleteMin() << ' ';
  }
  
  cout << endl << "Copying first heap elements back into second heap..."
       << endl;
  secondHeap = firstHeap;
  
  cout << endl << "Now using first original heap: ";
  cout << endl << "Deleting the first value in the heap and printing: "
       << firstHeap.deleteMin();
  
  cout << endl << endl;
  cout << "Flushing " << repeatedNum[randIndex] << " from the heap." << endl;
  cout << "The heap without " << repeatedNum[randIndex] << ": " << endl;
  
  firstHeap.flush(repeatedNum[randIndex]);
  
  while(!firstHeap.isEmpty()){
    cout << firstHeap.deleteMin() << ' ';
  }
  
  cout << endl << endl
       << "Now deleting the min of the second heap until it's empty: " << endl;
  
  while(!secondHeap.isEmpty()){
    cout << secondHeap.deleteMin() << ' ';
  }
  
  cout << endl << endl;
  
  return 0;
}
