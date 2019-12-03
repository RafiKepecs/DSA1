// THIS IS THE PROVIDED CODE FOR PROGRAM #2, DSA 1, FALL 2019

#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

// A simple class; each object holds four public fields
class Data {
public:
  string lastName;
  string firstName;
  string ssn;
};

// Load the data from a specified input file
void loadDataList(list<Data *> &l, const string &filename) {

  ifstream input(filename);
  if (!input) {
    cerr << "Error: could not open " << filename << "\n";
    exit(1);
  }

  // The first line indicates the size
  string line;
  getline(input, line);
  stringstream ss(line);
  int size;
  ss >> size;

  // Load the data
  for (int i = 0; i < size; i++) {
    getline(input, line);
    stringstream ss2(line);
    Data *pData = new Data();
    ss2 >> pData->lastName >> pData->firstName >> pData->ssn;
    l.push_back(pData);
  }

  input.close();
}

// Output the data to a specified output file
void writeDataList(const list<Data *> &l, const string &filename) {

  ofstream output(filename);
  if (!output) {
    cerr << "Error: could not open " << filename << "\n";
    exit(1);
  }

  // Write the size first
  int size = l.size();
  output << size << "\n";

  // Write the data
  for (auto pData:l) {
    output << pData->lastName << " "
           << pData->firstName << " "
           << pData->ssn << "\n";
  }

  output.close();
}

// Sort the data according to a specified field
// (Implementation of this function will be later in this file)
void sortDataList(list<Data *> &);

// The main function calls routines to get the data, sort the data,
// and output the data. The sort is timed according to CPU time.
int main() {
  string filename;
  cout << "Enter name of input file: ";
  cin >> filename;
  list<Data *> theList;
  loadDataList(theList, filename);

  cout << "Data loaded.\n";

  cout << "Executing sort...\n";
  clock_t t1 = clock();
  sortDataList(theList);
  clock_t t2 = clock();
  double timeDiff = ((double) (t2 - t1)) / CLOCKS_PER_SEC;

  cout << "Sort finished. CPU time was " << timeDiff << " seconds.\n";

  cout << "Enter name of output file: ";
  cin >> filename;
  writeDataList(theList, filename);

  return 0;
}

// -------------------------------------------------
// YOU MAY NOT CHANGE OR ADD ANY CODE ABOVE HERE !!!
// -------------------------------------------------

// You may add global variables, functions, and/or
// class defintions here if you wish.

struct myDataPointer {
  char letter1;
  char letter2;
  const char* restlastName;
  const char* firstName;
  const char* ssn;
  Data* data;
};

const int maxSize = 1010001;
myDataPointer arr[maxSize];
list<Data *>::iterator it;
int i = 0;
int len;
Data* deref;

bool compare(myDataPointer A, myDataPointer B) {
  if(A.letter1 != B.letter1) {return A.letter1 < B.letter1;}
  if(A.letter2 != B.letter2) {return A.letter2 < B.letter2;}
  int res = strcmp(A.restlastName,B.restlastName);
  if(res) {return res<0;}
  int res2 = strcmp(A.firstName,B.firstName);
  if(res2) {return res2<0;}
  int res3 = strcmp(A.ssn, B.ssn);
  if(res3) {return res3<0;}
}

void sortDataList(list<Data *> &l) {
  // Fill this in
  //load elements of the list into the array

  for (it = l.begin(); it != l.end(); it++){
    deref = *it;
    arr[i].letter1 = (deref->lastName)[0];
    arr[i].letter2 = (deref->lastName)[1];
    arr[i].restlastName = ((deref->lastName).data() + 2);
    arr[i].firstName = ((deref)->firstName).data();
    arr[i].ssn = (deref)->ssn.data();
    arr[i].data = deref;
    i++;
  }
  sort(arr, arr+i, compare);
  i = 0;
  for (it = l.begin(); it != l.end(); it++){
    (*it) = arr[i].data;
    i++;
  }
}
