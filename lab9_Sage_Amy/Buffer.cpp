/****************************************
** Program name: Buffer.cpp
** Author: Amy Sage
** Date: 3/7/2018
** Description:
****************************************
***************************/
#include "Buffer.h"
#include "menu_validate.h"
#include <iomanip>

Buffer::Buffer()
{
};
int Buffer::generate_number(int max_val)//generate random numbers between 1-max_val and return value to add to list
{
  int num = rand() % max_val + 1;
  return num; //number with which list will perform operations on
}


void Buffer::game_queue()
{
  int rounds = -1;
  double user_remove_percentage, user_add_percentage = 0.0;
  //ask user for how many rounds of simulation
  cout << "How many rounds of simulation would like?: ";
  cin >> rounds;
  menu_validate a_validate;
  a_validate.validate(rounds);
  while(rounds <= 0)
  {
    cout << "Invalid entry. Please enter an integer greater than 0: ";
    cin.ignore();
    cin.clear();
    cin >> rounds;
    a_validate.validate(rounds);
  }
  //ask user for percentage to put a random number at end of buffer
  cout << "What percentage chance do you believe there is to put a randomly generated number at the end of the buffer? Enter a number between 1-100: ";
  cin >> user_add_percentage;
  a_validate.validate(user_add_percentage);
  a_validate.validate_percentage(user_add_percentage);
  //ask user for percentage chance to take out random number at back of buffer
  cout << "What percentage chance do you believe there is to remove a randomly generated number at the beginning of the buffer? Enter a number between 1-100: ";
  cin >> user_remove_percentage;
  a_validate.validate(user_remove_percentage);
  a_validate.validate_percentage(user_remove_percentage);

  //create queue
  std::queue<int> my_queue; //initialize Queue
  std::queue<int> temp_queue; //initialize temp_queue

  double prev, average = 0.0;
  int add_percentage, remove_percentage = 0;
  int random_num = 0;
  double the_size = 0.0;
  //loop through rounds
  for(double i = 1.0; i <= rounds; i++)
  {
    cout << "****ROUND " << (int)i << "****";
    cout << endl;
    cout << endl;
    prev = average;
    //1. generate random number from 1 - 1000, called N
    random_num = generate_number(1000);
    //2. generate random number from 1 - 100
    add_percentage = generate_number(100);
    //cout << "User percentage to add is: " << user_add_percentage << endl;//TEST
    //cout << "RANDOM number to compare to user's add is: ";//TEST
    //cout << add_percentage << endl; //TEST
            //if that number is <= user input number
            if(add_percentage <= user_add_percentage)
            {
                //then add N to queue
                my_queue.push(random_num);
                //testing
                //cout << "This is the random number that was added to the queue: ";//TEST
                //cout << my_queue.back();//TEST
                //cout << endl;//TEST
            }
    //3. generate random number from 1 - 100
    remove_percentage = generate_number(100);
    //cout << "User percentage to remove is: " << user_remove_percentage << endl;
    //cout << "RANDOM number to compare to user's remove is: ";
    //cout << remove_percentage <<endl;
            //If that number is <= user input number
              if(remove_percentage <= user_remove_percentage && !my_queue.empty())
              {
                  //cout << "The number removed from the queue is: " << my_queue.front();
                  //remove a number from front of queue
                  my_queue.pop();
                  //cout << endl;
              }
    
    //cout << "The last value added to the buffer is: ";
    /*if(!my_queue.empty())
    {
      cout << my_queue.back();
    }
    cout << endl;*/
    //copy the queue
    temp_queue = my_queue;
    
     //4. Print values of list(buffer)
     cout << "The values of the buffer are: ";
    if(temp_queue.empty() == true)
    {
      cout << "Sorry, the buffer is empty";
    }
    while(!temp_queue.empty())
    {
      cout << temp_queue.front() << " ";
      temp_queue.pop();
    }
    cout << endl;
    
    //5. Print length of list(buffer)
    the_size = (double)my_queue.size();
    cout << "The length of the buffer is: ";
    cout << std::setprecision(4) << std::fixed << the_size << endl;
    //6. Print average length of list(buffer)
              //refer to equation in lab
    cout << "The average length of the buffer is: ";
    average = (prev*(i-1)+my_queue.size())/i;
    cout << std::setprecision(4) << std::fixed << average;
    cout << endl;
    cout << endl;
  }//end for loop of rounds
}

Buffer::~Buffer(){};
