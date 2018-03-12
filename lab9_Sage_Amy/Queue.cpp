/****************************************
** Program name: Buffer.cpp
** Author: Amy Sage
** Date: 3/7/2018
** Description:
****************************************
***************************/
#include "Buffer.h"
#include "menu_validate.h"

Buffer::Buffer(){};
int Queue::generate_number(int max_val)//generate random numbers between 1-max_val and return value to add to list
{
  int num = rand() % max_val + 1;
  return num; //number with which list will perform operations on
}

void Buffer::game_queue()
{
  int rounds;
  double user_end_buffer, user_beg_buffer;
  //ask user for how many rounds of simulation
  cout << "How many rounds of simulation would like?: ";
  cin >> rounds;
  menu_validate a_validate;
  rounds = a_validate.validate(rounds);
  while(rounds < 0)
  {
    cout << "Invalid entry. Please enter an integer greater than 0: ";
    cin.clear();
    cin.ignore();
    cin >> rounds;
  }
  //ask user for percentage to put a random number at end of buffer
  cout << "What percentage of chance do you believe there is to put a randomly generated number a the end of the buffer? Enter a number between 1-100: ";
  cin >> user_end_buffer;
  user_end_buffer = a_validate.validate(user_end_buffer);
  user_end_buffer = a_validate.validate_percentage(user_end_buffer);
  //ask user for percentage chance to take out random number at front of buffer
  cout << "What percentage of chance do you believe there is to put a randomly generated number a the beginning of the buffer? Enter a number between 1-100: ";
  cin >> user_beg_buffer;
  user_beg_buffer = a_validate.validate(user_beg_buffer);
  user_beg_buffer = a_validate.validate_percentage(user_beg_buffer);

  //create queue
  std::queue<int> my_queue; //initialize Queue
  std::queue<int> temp_queue; //initialize temp_queue

  double popped1;
  double popped;
  double prev, average = 0.0;
  double N, N2, N3;
  //loop through rounds
  for(int i = 0; i < rounds; i++)
  {
    prev = average;
    //1. generate random number from 1 - 1000, called N
    N = generate_number(1000);
    //2. generate random number from 1 - 100
    N2 = generate_number(100);
    cout << "N2 is: ";
    cout << N2 <<endl;
            //if that number is <= user input number
            if(N2 <= user_beg_buffer)
            {
                //then add N to queue
                my_queue.push(N);
                //testing
                cout << "This is N that was added to the queue: ";
                cout << my_queue.back();
            }
    //3. generate random number from 1 - 100
    N3 = generate_number(100);
    cout << "N3 is: ";
    cout << N3 <<endl;
            //If that number is <= user input number
              if(N3 <= user_end_buffer)
              {
                  //remove a number from front of queue
                  my_queue.pop();
              }
    //TESTING
    cout << "The top of the queue is: ";
    cout << my_queue.back();
    cout << endl;

    //copy the queue
    for(int i=0; i<my_queue.size(); i++)
    {
      popped1 = my_queue.back();
      temp_queue.push(popped1);
    }
    //4. Print values of list(buffer)
    int SIZE = my_queue.size();
    double first_in = 0.0;
    cout << "The values of the buffer are: ";
    for(int i=0; i<SIZE; i++)
    {
      cout << temp_queue.back() << " ";
      temp_queue.pop(); //pop that value
    }
    cout << endl;

    //copy queue again
    for(int i=0; i<my_queue.size(); i++)
    {
      popped = my_queue.back();
      temp_queue.push(popped);
    }

    //5. Print length of list(buffer)
    cout << "The length of the buffer is: " << my_queue.size() << endl;
    //6. Print average length of list(buffer)
              //refer to equation in lab
    cout << "The average length of the buffer is: ";
    average = (prev*(i-1)+my_queue.size());
    cout << average;
    cout << endl;
  }//end for loop of rounds
}

Buffer::~Buffer(){};
