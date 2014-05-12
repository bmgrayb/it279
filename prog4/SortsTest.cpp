#include "Sorts.h"
#include "Performance.h"
#include <iostream>
#include <fstream>
using namespace std;
#include <time.h>
#include <cstring>
#include <cstdlib>

Performance perf;

int main(int argc,char *argv[])
{
  if (argc!=3)
  { 
    cout <<"Please enter file name."<<endl;
    return -1;
  }
  double *array;
  double *workArray;
  int length;
  int i,j,k;

  if (strcmp(argv[1],"-o")==0)
  {
      //this generates a random array of the length below and writes it to the provided file name
    length = 10;
    array = new double[length];
    srand(time(NULL));
    for (i=0;i<length;i++)
      array[i] =(double) (-50 + rand()%100)/2.5;
    

    ofstream fout;
    fout.open(argv[2]);
    fout << length<<endl;
    for (i=0;i<length;i++)
      fout << array[i] << endl;
    
    fout.close();
  }
  else if (strcmp(argv[1],"-i")==0)
  {
      //this runs the sorting algorithm on the input file
    fstream fin;

    fin.open(argv[2]);
    if (!fin.is_open())
    {
      cout <<"Could not open file"<<endl;
      return -1;
    }
    
    fin >>length;
    //create an array to hold the values from the file
    array = new double[length];    
    for (i=0;i<length;i++)
    {
      fin >> array[i];
    }
    
    int n[] = {10, 100, 500, 1000, 5000, 10000, 25000, 50000, 75000, length}; 
     
    Sorts newSort;

    
    for(i = 0; i < 10; i++)
    {
      workArray = new double[n[i]];

      for(j = 0; j < n[i]; j++)
	workArray[j] = array[j];

      newSort.mergesort(workArray, n[i]);

      cout << "Length of array: " << n[i] << endl;
      perf.printResults();

      delete [] workArray;
      perf.reset();

    }

    

    /*
    newSort.mergesort(array,length);
    
    cout << "Final sorted array: " << endl;
    
    for (i=0;i<length;i++)
      {
        cout << array[i] << " ";
      }
    cout << endl;

    cout << "Length of array: " << length << endl;
    perf.printResults();
    
    */ 
  }

   


  delete []array;
}