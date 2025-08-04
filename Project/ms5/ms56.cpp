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
int main() {
   // Create Ordering object with the CSV file names
   Ordering ordering("drinks.csv", "foods.csv");

   // Validate that data loaded correctly
   if (!ordering) {
      std::cout << "Failed to open data files or the data files are corrupted!" << std::endl;
      return 1; // Exit program with error code
   }


   size_t selection{};
    Menu mainMenu("Seneca Restaurant", "End Program");
    mainMenu << "Order" << "Print Bill" << "Start a New Bill" << "List Foods" << "List Drinks";
    do {
      selection = mainMenu.select();
      switch (selection) {
      case 0:
         break;
      case 1: 
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
