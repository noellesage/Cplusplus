/****************************************
** Program name: linked_list_main.cpp
** Author: Amy Sage
** Date: 2/5/2018
** Description: Creates list, allows user to input and delete numbers from doubly linked list
****************************************
***************************/
#include "Node.h"
#include "List.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    List my_list;
    int menu_choice = my_list.menu();
    while(cin.good())
    {
    switch(menu_choice)
     {
       case 1://add new head
       {
              bool valid_int = false;
              do
              {
                int n;
                cout << "Please enter a number: ";
                cin >> n;
                if(cin.fail())
                {
                  cin.clear();
                  cin.ignore();
                  cout << "Invalid entry. Please enter a number." << endl;
                }
                else
                {
                  valid_int = true;
                  my_list.add_new_head(n);
                  my_list.traverse();
                  cout << endl;
                  menu_choice = my_list.menu();
                }
              }while(valid_int = false);
        }break;
       case 2://add new tail
       {
             bool valid_int = false;
             do
             {
               int n;
               cout << "Please enter a number: ";
               cin >> n;
               if(cin.fail())
               {
                 cin.clear();
                 cin.ignore();
                 cout << "Invalid entry. Please enter a number." << endl;
               }
               else
               {
                 valid_int = true;
                 my_list.add_new_tail(n);
                 my_list.traverse();
                 cout << endl;
                 menu_choice = my_list.menu();
               }
             }while(valid_int = false);
       }break;
       case 3://delete head
       {
            my_list.delete_first_node();
            my_list.traverse();
            cout << endl;
            menu_choice = my_list.menu();
       }break;
       case 4://delete tail
       {
              my_list.delete_last_node();
              my_list.traverse();
              cout << endl;
              menu_choice = my_list.menu();
       }break;
       case 5://reverse traverse
       {
              my_list.traverse_reverse();
              cout << endl;
              menu_choice = my_list.menu();
       }      
              break;
       case 6://print head value
       {
              my_list.print_head();
              menu_choice = my_list.menu();
       }      
              break;
       case 7://print tail value
       {
              my_list.print_tail();
              menu_choice = my_list.menu();
       }          
              break;
       case 8:
              cout << "Goodbye";
              exit(1);
     }
   }
   return 0;
}
