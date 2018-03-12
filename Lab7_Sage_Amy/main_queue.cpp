/****************************************
** Program name: main_queue.cpp
** Author: Amy Sage
** Date: 2/19/2018
** Description: implements user initiated queue
****************************************
***************************/
#include "Queue.h"
#include <iostream>
using std::cin;
using std::endl;
using std::cout;

int main()
{
  Queue my_queue;

  int val;
  while(1)
  {
  bool valid_menu = false;
  int menu_input = 0;
  cout << "Menu" << endl;
  cout << "1) Add a value to the back of the queue" << endl;
  cout << "2) Display the front value" << endl;
  cout << "3) Remove the front node" << endl;
  cout << "4) Display the queue's content" << endl;
  cout << "5) Exit" << endl;
  cin >> menu_input;
  while(menu_input > 5 || menu_input < 1)
  {
    cin.clear();
    cin.ignore();
    cout << "Sorry, invalid input. Please enter an integer between 1-5: ";
    cin >> menu_input;
  }

  switch(menu_input)
  {
    case 1: //add value to back
            cout << "Please enter a value: ";
            cin >> val;
            while(cin.fail())
            {
              cin.clear();
              cin.ignore();
              cout << "Sorry, that's an invalid entry. Please enter an integer: ";
              cin >> val;
            }
            my_queue.addBack(val);
            break;
    case 2: //display front value
            if(my_queue.isEmpty())
            {
                cout << "Sorry, the queue is empty" << endl;
            }
            else
            {
                cout << "The front value is: ";
                cout << my_queue.getFront();
                cout << endl;
            }
            break;
    case 3: //remove front node
            if(my_queue.isEmpty())
            {
                cout << "Sorry, the queue is empty" << endl;
            }
            else
            {
                my_queue.removeFront();
            }
            break;
    case 4: //display contents
            if(my_queue.isEmpty())
            {
                cout << "Sorry, the queue is empty" << endl;
            }
            else
            {
                cout << "The queue is: ";
                my_queue.printQueue();
            }
            break;
    case 5: //Exit
            exit(0);
   }
   cout << endl;
  }//end while
  return 0;
}
