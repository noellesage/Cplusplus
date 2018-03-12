/****************************************
** Program name: recursive.cpp
** Author: Amy Sage
** Date: 2/5/2018
** Description: defines 3 recursive functions
****************************************
***************************/
#include <iostream>
#include "recursive.h"
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;
//prints the reverse of a string
void print_reverse(string r)
{
    //base case
    //if string length is 0
    if(r.length() == 0)
    {
      cout << "\n";
    }
    //then print the newline character
    //else
    else
    {
      cout << r[r.length()-1]; //print last char
      r.erase(r.length()-1); //remove last char
      print_reverse(r); //recursive call
    }
}

int sum_array(int* array, int n)
{
  if(n < 0)
  {
    return 0;
  }
  else
  {
    return sum_array(array, n-1) + array[n-1];
  }
}

int triangular_num(int n)
{
  //base
  if(n <= 0)
  {
    return 0;
  }
  else
  {
    return n + triangular_num(n-1);
  }
}

int menu()
{
  while(1)
  {
    int menu_choice = 0; //select 1 of 3 functions
    bool valid_menu = false;
    cout << "Menu" << endl;
    cout << "1) Print the reverse of a string" << endl;
    cout << "2) Find the sum of integers in an array" << endl;
    cout << "3) Find the triangular number of an integer" << endl;
    cout << "4) Exit" << endl;
    do
    {
        cin >> menu_choice;
        if(cin.fail())
        {
                cin.clear();
                cin.ignore();
                cout << "Invalid. Enter a 1, 2, 3, or 4" << endl;
        }
        else
        {
                valid_menu = true;
        }
    } while(valid_menu == false);
     switch(menu_choice)
     {
       case 1:
       {
                bool valid_string = false;
                do
                {
                    string s;
                    cout << "Please enter a string" << endl;
                    getline(cin, s);
                    if(!(getline(cin,s)))
                    {
                      cin.clear();
                      cin.ignore();
                      cout << "Invalid. Enter a valid string." << endl;
                    }
                    else
                    {
                      //call print reverse
                      valid_string = true;
                      cout << "The reverse of the string is ";
                      print_reverse(s);
                    }
                }while(valid_string == false);
              }break;
       case 2:
       {
                bool valid_int = false;
                do
                {
                  int num_int = 0; //number of integers
                  int intake = 0; //user input
                  cout << "Please enter the number of integers in the array" << endl;
                  cin >> num_int;
                  int* array = new int[num_int]; //dynamic array
                  if(cin.fail())
                  {
                    cin.clear();
                    cin.ignore();
                    cout << "Invalid. Enter a valid string." << endl;
                  }
                  else
                  {
                    valid_int = true;
                    cout << "Please enter the integers into the array" << endl;
                    for(int i=0; i < num_int; i++)
                    {
                      cin >> intake;
                      if(cin.fail())
                      {
                        valid_int = false;
                        cin.clear();
                        cin.ignore();
                        cout << "Invalid. Enter a valid integer." << endl;
                      }
                      else
                      {
                        array[i] = intake;
                        valid_int = true;
                      }
                    }
                    // call sum array
                    cout << "The sum is " << sum_array(array, num_int)<< endl;
                    delete [] array; //deallocate
                    array = NULL;
                  }
                }while(valid_int == false);
              }break;
       case 3:
       {
            bool valid_trinum = false;
            do
             {
                int tri_num = 0;
                cout << "Please enter an integer of which the triangular number will be calculated" << endl;
                cin >> tri_num;
                if(cin.fail())
                {
                  cin.clear();
                  cin.ignore();
                  cout << "Invalid. Enter a valid integer." << endl;
                }
                else
                {
                  //call triangular num
                  valid_trinum = true;
                  cout << "The triangular number of " << tri_num << " is " << triangular_num(tri_num) << endl;
                }
              }while(valid_trinum == false);
            }
              break;
       case 4:
              //Exit
              cout << "Goodbye" << endl;
              exit(1);
     }
   }
  return 0;
}
