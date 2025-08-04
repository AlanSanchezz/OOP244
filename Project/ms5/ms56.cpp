/***************************************************************
// OOP244 Project, milestone 56 : tester program
//
// File  ms56.cpp
// Version 1.0
// Author Fardad
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Menu.h"
#include "Ordering.h"
using namespace std;
using namespace seneca;
void test1();

seneca::Ordering ordering("drinks.csv", "foods.csv");
extern seneca::Ordering ordering;
bool initOrdering();


int main() {
  if (!initOrdering()) {
     return 1;
  }


   size_t selection{};
    Menu mainMenu("Seneca Restaurant ", "End Program");
    mainMenu << "Order" << "Print Bill" << "Start a New Bill" << "List Foods" << "List Drinks";

    Menu confirmation("You have bills that are not saved. Are you sue you want to exit?", "No");
    confirmation << "Yes";

    do {
      selection = mainMenu.select();
      switch (selection) {
      case 0:
         confirmation.select();
      case 1: 
         test1();
         break;
      case 2:
         break;
      case 3:
         break;
      case 4:
         ordering.listFoods();
         break;
      case 5:
         ordering.listDrinks();
         break;
      default:
         cout << "This should never happen!" << endl;
      }
   } while (selection);





   return 0;


}


void test1(){
   size_t selection{};
   Menu submenu("Order Menu", "Back to Main Menu",1);
   submenu << "Food" << "Drink"; 
   do {
      selection = submenu.select();
      switch (selection) {
      case 0:
         break;
      case 1: 
         ordering.orderFood();
         break;
      case 2:
         ordering.orderDrink();
         default:
         break;
      }
   } while (selection);
}
bool initOrdering() {
   if (!ordering) {
      std::cout << "Failed to open data files or the data files are corrupted!" << std::endl;
      return false;
   }
   return true;
}
   








