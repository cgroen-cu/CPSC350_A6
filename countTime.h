using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <time.h>

class countTime{
  public:
    countTime();
    countTime(string f);
    ~countTime();
    void setUp(string f);
    void quickSort(int lowIndex, int highIndex);
    void quickSortPrint();
    void mergeSort(int *numbers, int i, int k);
    void Merge(int *numbers, int i, int j, int k);
    void mergePrint();
    void selectSort();
    void insertSort();
    void bubbleSort();
    int Partition(int *numbers, int lowIndex, int highIndex);
    void print(int *nums);
    int getSize();
  private:
    int i;
    int j;
    int numSize;
    string file;
    int *quickArr;
    int *mergeArr;
    int *selectArr;
    int *insertArr;
    int *bubbleArr;
    int lowEndIndex;
    //clock_t t;
  //  clock_t f;
    clock_t timeStart;
    clock_t timeEnd;
};
