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
Ordering ordering("drinks.csv", "foods.csv");
void test1();




int main() {

   // Validate that data loaded correctly
   if (!ordering) {
      std::cout << "Failed to open data files or the data files are corrupted!" << std::endl;
      return 1; // Exit program with error code
   }


   size_t selection{}, select{};
    Menu mainMenu("Seneca Restaurant ", "End Program");
    mainMenu << "Order" << "Print Bill" << "Start a New Bill" << "List Foods" << "List Drinks";
    Menu exit("You have bills that are not saved. Are you sue you want to exit?", "No");
    exit << "Yes";

    do {
      selection = mainMenu.select();
      switch (selection) {
      case 0:
         select = exit.select();
         break;
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
   } while (selection || !select);


   return 0;


   
}


void test1() {
   size_t selection{};
   Menu submenu("Order Menu", "Back to main Menu", 1);
   submenu << "Food" << "Drink";
   do {
      selection = submenu.select();
      switch (selection) {
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




