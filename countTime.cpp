#include "countTime.h"

countTime::countTime(){
}
countTime::countTime(string f){
  i = 0;
  j = 0;
  file = f;
  setUp(file);
  //t = time(0);
  //timeStart = 0;
  //timeEnd = 0;
}
void countTime::setUp(string f){
  cout << "setup" << endl;
  string line;
  ifstream myfile;
  int lineNum = 0;
  myfile.open(f);
  if (myfile.is_open())
  {
    //read from file
    while (getline(myfile, line)){
      lineNum++;
      //cout << lineNum << ": " << line << endl;
      //first line is size of array
      if (lineNum == 1){
        numSize = stoi(line);
        quickArr = new int[numSize];
        mergeArr = new int[numSize];
        selectArr = new int[numSize];
        insertArr = new int[numSize];
        bubbleArr = new int[numSize];
        //cout << "Size is: " << numSize << endl;
      }
      //if not first line, add number to array
      else {
        quickArr[lineNum-2] = stoi(line);
        mergeArr[lineNum-2] = stoi(line);
        selectArr[lineNum-2] = stoi(line);
        insertArr[lineNum-2] = stoi(line);
        bubbleArr[lineNum-2] = stoi(line);
      }

    }
    //cout << "finished, closing file" << endl;
    myfile.close();
  }
  else cout << "Unable to open file";

  //print(quickArr);
}

void countTime::print(int *nums){
  for (int i = 0; i < numSize; i++){
    //cout << nums[i] << endl;
  }
  cout << "Time Started: " << timeStart << endl;
  cout << "Time Finished: " << timeEnd << endl;
}

int countTime::Partition(int *numbers, int lowIndex, int highIndex) {
   // Pick middle element as pivot
   int midpoint = lowIndex + (highIndex - lowIndex) / 2;
   int pivot = numbers[midpoint];
   int temp;

   bool done = false;
   while (!done) {
      // Increment lowIndex while numbers[lowIndex] < pivot
      while (numbers[lowIndex] < pivot) {
         lowIndex += 1;
      }

      // Decrement highIndex while pivot < numbers[highIndex]
      while (pivot < numbers[highIndex]) {
         highIndex -= 1;
      }

      // If zero or one elements remain, then all numbers are
      // partitioned. Return highIndex.
      if (lowIndex >= highIndex) {
         done = true;
      }
      else {
         // Swap numbers[lowIndex] and numbers[highIndex]
         temp = numbers[lowIndex];
         numbers[lowIndex] = numbers[highIndex];
         numbers[highIndex] = temp;

         // Update lowIndex and highIndex
         lowIndex += 1;
         highIndex -= 1;
      }
   }

   return highIndex;
}

void countTime::quickSort(int lowIndex, int highIndex){
   if (lowIndex >= highIndex) {
      return;
   }

   lowEndIndex = Partition(quickArr, lowIndex, highIndex);
   quickSort(lowIndex, lowEndIndex);
   quickSort(lowEndIndex + 1, highIndex);
}
void countTime::quickSortPrint(){
  //ctime(timeStart);
  timeStart = clock();
  quickSort(0, numSize-1);
  //ctime(timeEnd);
  timeEnd = clock();
  cout << "Quick Sort: " << endl;
  print(quickArr);
}


void countTime::selectSort(){
  //ctime(timeStart);
  timeStart = clock();
  int i = 0;
  int j = 0;
  int indexSmallest = 0;
  int temp = 0;  // Temporary variable for swap

  for (i = 0; i < numSize - 1; ++i) {

    // Find index of smallest remaining element
    indexSmallest = i;
    for (j = i + 1; j < numSize; ++j) {

       if ( selectArr[j] < selectArr[indexSmallest] ) {
          indexSmallest = j;
       }
    }

    // Swap numbers[i] and numbers[indexSmallest]
    temp = selectArr[i];
    selectArr[i] = selectArr[indexSmallest];
    selectArr[indexSmallest] = temp;
   }
   //ctime(timeEnd);
   timeEnd = clock();
   cout << "Select Sort:" << endl;
   print(selectArr);
}

void countTime::insertSort(){
  //ctime(timeStart);
  timeStart = clock();
  int i = 0;
  int j = 0;
  int temp = 0;  // Temporary variable for swap

  for (i = 1; i < numSize; ++i) {
    j = i;
    // Insert numbers[i] into sorted part
    // stopping once numbers[i] in correct position
    while (j > 0 && insertArr[j] < insertArr[j - 1]){
      // Swap numbers[j] and numbers[j - 1]
      temp = insertArr[j];
      insertArr[j] = insertArr[j - 1];
      insertArr[j - 1] = temp;
      --j;
    }
  }
  //ctime(timeEnd);
  timeEnd = clock();
  cout << "Insertion Sort:" << endl;
  print(selectArr);
}

void countTime::Merge(int *numbers, int i, int j, int k) {
   int mergedSize = k - i + 1;                // Size of merged partition
   int mergePos = 0;               // Position to insert merged number
   int leftPos = 0;                         // Position of elements in left partition
   int rightPos = 0;                          // Position of elements in right partition
   int *mergedNumbers = new int[mergedSize];   // Dynamically allocates temporary array
                                         // for merged numbers

   leftPos = i;  // Initialize left partition position
   rightPos = j + 1;                      // Initialize right partition position

   // Add smallest element from left or right partition to merged numbers
   while (leftPos <= j && rightPos <= k) {
      if (numbers[leftPos] <= numbers[rightPos]) {
         mergedNumbers[mergePos] = numbers[leftPos];
         ++leftPos;
      }
      else {
         mergedNumbers[mergePos] = numbers[rightPos];
         ++rightPos;

      }
      ++mergePos;
   }

   // If left partition is not empty, add remaining elements to merged numbers
   while (leftPos <= j) {
      mergedNumbers[mergePos] = numbers[leftPos];
      ++leftPos;
      ++mergePos;
   }

   // If right partition is not empty, add remaining elements to merged numbers
   while (rightPos <= k) {
      mergedNumbers[mergePos] = numbers[rightPos];
      ++rightPos;
      ++mergePos;
   }

   // Copy merge number back to numbers
   for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
      numbers[i + mergePos] = mergedNumbers[mergePos];
   }
}

void countTime::mergeSort(int *numbers, int i, int k){
  int j = 0;

   if (i < k) {
      j = (i + k) / 2;  // Find the midpoint in the partition

      // Recursively sort left and right partitions
      mergeSort(numbers, i, j);
      mergeSort(numbers, j + 1, k);

      // Merge left and right partition in sorted order
      Merge(numbers, i, j, k);
   }
}

void countTime::mergePrint(){
  //ctime(timeStart);
  timeStart = clock();
  mergeSort(mergeArr, 0, numSize-1);
  //ctime(timeEnd);
  timeEnd = clock();
  cout << "Merge Sort:" << endl;
  print(mergeArr);
}

void countTime::bubbleSort(){
  //ctime(&timeStart);
  timeStart = clock();
  //cout << timeStart << endl;
  //timeStart = static_cast<int> (t);
  //time(&timeStart);
  bool swapped;
  for (int i = 0; i < numSize-1; i++){
    swapped = false;
    for (int j = 0; j < numSize-i-1; j++)
    {
       if (bubbleArr[j] > bubbleArr[j+1])
       {
          swap(bubbleArr[j], bubbleArr[j+1]);
          swapped = true;
       }
    }

    // IF no two elements were swapped by inner loop, then break
    if (swapped == false)
       break;
  }
  cout << "Bubble Sort:" << endl;
  //ctime(&timeEnd);
  //imeEnd = time(NULL);
  timeEnd = clock();
  //cout << timeEnd << endl;
  print(bubbleArr);
}

int countTime::getSize(){
  return numSize;
}
