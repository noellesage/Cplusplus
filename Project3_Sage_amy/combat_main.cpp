/****************************************
** Program name: combat_main.cpp
** Author: Amy Sage
** Date: 2/5/2018
** Description:
****************************************
***************************/
#include <iostream>
#include "Character.h"
#include "Barbarian.h"
#include "HarryPotter.h"
#include "Medusa.h"
#include "BlueMen.h"
#include "Vampire.h"
using std::cin;
using std::endl;
using std::cout;

int attack(Character *c)
{
    int attack = c->attack();
    cout << "Character: " << c->get_name() << endl;
    cout << "Strength: " << c->get_strength() << endl;
    cout << "Armor: " << c->get_armor() << endl;
    cout << "Attack: " << attack << endl;
    return attack;
}

void defense(Character *c, int attack)
{
    int d = c->defense(attack);
    cout << "Character: " << c->get_name() << endl;
    cout << "Strength: " << c->get_strength() << endl;
    cout << "Armor: " << c->get_armor() << endl;
    cout << "Defense: " << d << endl;
}

void my_menu()
{
   Character *c1;
    Character *c2;
    int menu_choice = 0;
    cout << "Select 2 characters to battle." << endl;
    cout << "1) Vampire" << endl;
    cout << "2) Barbarian" << endl;
    cout << "3) Blue Men" << endl;
    cout << "4) Medusa" << endl;
    cout << "5) Harry Potter" << endl;
    for(int i=0; i < 2; i++)
    {
        cin >> menu_choice;
        while(menu_choice > 5 || menu_choice < 1)
        {
           cin.clear();
           cin.ignore();        
           cout << "Invalid. Enter two integers between 1-5. If you only enter one correct integer, that character will be created, and you will be prompted for another input until a second correct integer is input: ";
           cin >> menu_choice;
        };
         if(menu_choice == 1)//create Vampire
         {
            if(i == 0)
            {
              Vampire *v1;
              v1 = new Vampire;
              c1 = v1;
            }
            else if(i == 1)
            {
              Vampire *v2;
              v2 = new Vampire;
              c2 = v2;
            }
         }
          else if(menu_choice == 2) //create Barbarian
          {
            if(i == 0)
            {
              Barbarian *bb1;
              bb1 = new Barbarian;
              c1 = bb1;
            }
            else if(i == 1)
            {
              Barbarian *bb2;
              bb2 = new Barbarian;
              c2 = bb2;
            }
          }
          else if(menu_choice == 3)//create Blue Menu
          {
            if(i == 0)
            {
              BlueMen *bm1;
              bm1 = new BlueMen;
              c1 = bm1;
            }
            else if(i == 1)
            {
              BlueMen *bm2;
              bm2 = new BlueMen;
              c2 = bm2;
            }
          }

          else if(menu_choice == 4)  //create Medusa
          {
            if(i == 0)
            {
              Medusa *m1;
              m1 = new Medusa;
              c1 = m1;
            }
            else if(i == 1)
            {
              Medusa *m2;
              m2= new Medusa;
              c2 = m2;
            }
          }
          else if(menu_choice == 5) //create Harry Potter
          {
            if(i == 0)
            {
              HarryPotter *hp1;
              hp1 = new HarryPotter;
              c1 = hp1;
            }
            else if(i == 1)
            {
              HarryPotter *hp2;
              hp2 = new HarryPotter;
              c2 = hp2;
            }
          }
        }//end of for loop for 2 characters
        //game play
           int start = rand() % 2 + 1;
            int r = 1; //round
          //While both alive
          while (c1->get_strength() && c2->get_strength())
          {
            cout << "Round " << r << ":" << endl;
          
          //attack
          if(start % 2 != 0)
          {
            //c1 attacks, c2 defends
            defense(c2, attack(c1));
          }

          else //c2 attacks, c1 defends
          {
            defense(c1, attack(c2));
          }  
          r++;
          start++;
          //if c1 is alive
          if (c1->get_strength())
          {
            cout << c1->get_name() << " beat " << c2->get_name() << endl;
          }
          else
          {
            cout << c2->get_name() << " beat " << c1->get_name() << endl;
          }
          }//end while
          
          //deallocate memory
          delete c1;
          delete c2;
    }//end of my_menu

int my_menu_2()
{
  //second menu
          int menu_choice2 = 0; //play or exit
          cout << "Menu" << endl;
          cout << "1) Play Again" << endl;
          cout << "2) Exit" << endl;
          cin >> menu_choice2;
          
          while(menu_choice2 != 1 && menu_choice2 !=2){
              cin.clear();
              cin.ignore();
              cout << "Invalid. Enter either 1 or 2: ";
              cin >> menu_choice2;
          };
             switch(menu_choice2)
             {
                   case 1:
                            break;
                   case 2:
                            cout << "Goodbye" << endl;
                            exit(1);
             }
      return 0;       
}
int main()
{
  do
  {
          my_menu();
          my_menu_2();
  }while(cin.good());
  return 0;
}
