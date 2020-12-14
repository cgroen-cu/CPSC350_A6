#include "countTime.h"

int main(int argc, char** argv){
  if(argc != 2){
    cout << "File input needed as argument" << endl;
  }else{
    countTime *c1 = new countTime("test.txt");
    c1->selectSort();
    c1->insertSort();
    c1->quickSortPrint();
    c1->mergePrint();
    c1->bubbleSort();
  }
}
