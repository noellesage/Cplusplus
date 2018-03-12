/****************************************
** Program name: Algorithms.cpp
** Author: Amy Sage
** Date: 3/4/2018
** Description: Describes 2 searching and 1 sorting algorithm.
* each take the name of an input file, create a stream object, stream values
* to a new array, and search or sort 
****************************************
***************************/
#include "Algorithms.h"
#include <fstream>
#include <iostream>
#include <cstring>
using std::string;

Algorithms::Algorithms()
{
	this->SIZE = 10;
	this->count = 0;
}
void Algorithms::linear_search(string name, int v)
{
  if (strcmp(name.c_str(), "original.txt") == 0)
  {
  	SIZE = 9;
  }
  std::ifstream file; //stream object
  file.open(name.c_str());
  int *array = new int[SIZE];
  //put contents in array
  while(count < SIZE && file >> array[count])
  {
    count++;
  }
  file.close();
  
  //This code is from the week 8 material, the "Searching" video, 
  //and I also used a portion of the if statement part from 
  //http://btechsmartclass.com/DS/U4_T1.html
  //but I basically mixed the two methods
  int i = 0;
  for(i; i<SIZE; i++)
  {
    if(array[i] == v)
    {
      cout << name << ": target value found" << endl;
      break;
    }
  }  
  
  if(i == SIZE)
  {
  	cout << name << ": target value not found" << endl;
  }
  delete [] array;
  count = 0; //reset count
}

string Algorithms::insertion_sort(string name)
{
  if (strcmp(name.c_str(), "original.txt") == 0)
  {
  	SIZE = 9;
  }	
  std::ifstream file; //stream object
  file.open(name.c_str());
  int* array = new int[SIZE]; //dynamic array
  
  //put contents in array
  while(count < SIZE && file >> array[count])
  {
    count++;
  }
 file.close();
  //This code is from week 8 material, the video/lecture "Insertion-sort"
  //insertion sort array
  for(int i=1; i < SIZE; i++)
  {
    int next = array[i];
    int j = i;
    while (j > 0 && array[j-1] > next)
    {
      array[j] = array[j-1];
      j--;
    }
    array[j] = next;
  }

  std::ofstream outFile; //create outFile
  //write to outfile
  string outFileName;
  cout << "Please enter the output filename: ";
  cin >> outFileName;
  outFile.open(outFileName.c_str());
  
  cout << "The sorted array is: ";
  //write data to file
  for(int i=0; i < SIZE; i++)
  {
    cout << array[i] << " "; //write to screen
    outFile << array[i] << " "; //write to file
  }
  //close output file
  outFile.close();
  delete [] array;//delete array
  count = 0; //reset count
  //return outfilename so next function can use
  return outFileName;
}

void Algorithms::binary_search(string newFileName, int v)
{
  if (strcmp(newFileName.c_str(), "original.txt") == 0)
  {
  	SIZE = 9;
  }	
  std::ifstream newFile; //stream object	
  //take sorted data files from sort above
  newFile.open(newFileName.c_str());
  int* array = new int[SIZE]; //dynamic array
  
  while(count < SIZE && newFile >> array[count])
  {
    count++;
  }
  newFile.close();

  //This code is from the week 8 lecture, located in the "Searching" video
	int flag = 0;
	int low = 0;
	int high = SIZE - 1;
	while(low <= high)
	{
		int mid = (low+high)/2;
		int diff = array[mid]-v;
		if(diff == 0)
		{
			cout << newFileName << ": target found" << endl;
			flag = 1;
			break;
		}
		else if (diff < 0) // a[mid] < v
		{
			low = mid+1;
		}
		else
		{
			high = mid-1;
		}
	}	
	
if(flag == 0)
{
	cout << newFileName << ": target not found" << endl;
}
  delete [] array;//delete array
}

Algorithms::~Algorithms()
{
}
