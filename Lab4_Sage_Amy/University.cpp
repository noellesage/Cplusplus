/****************************************
** Program name: University.cpp
** Author: Amy Sage
** Date: 1/29/2018
** Description: defines Tiger class
****************************************
***************************/
#include <iostream>
#include "University.h"
#include <iomanip>
using std::cout;
using std::endl;

University::University(int nn,int mm)
{
   n = nn;
   m = mm;
   b = new Building[n];
   p = new Person[m];
}

void University::building_print()
{
   for(int i = 0; i < n; i++)
   {
	b[i].print_info();
   }	
}

void University::person_print()
{
   for(int i = 0; i < m; i++)
   {
     cout<<"Name: "<<p[i].get_name()<< endl;
     cout<<"Age: "<<p[i].get_age()<< endl;
     if(p[i].type_of_person==0)
     {
       float ga = p[i].get_gpa(); 
       cout<<"GPA: " << ga << endl;
     }
    else if(p[i].type_of_person==1)
    {
       float ra;
       ra = p[i].get_rating();	
      cout<<"Rating: "<< ra << endl;
    }
   }
}
