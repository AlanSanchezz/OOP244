#include <iostream>
#include "Menu.h"
#include "Ordering.h"
using namespace std;
using namespace seneca;
int main() {
   cout << "Testing Invalid Ordering if bad data is in data file!" << endl;
   Ordering badord("drink.csv", "badfood.csv");
   if (badord) {
      cout << "The ordering should have been invalid" << endl;
   }
   else {
      cout << "Passed!" << endl;
   }
   Ordering ord("drinks.csv", "foods.csv");
   cout << "Testing fool proofing..............................." << endl;
   ord.orderDrink();
   return 0;
}
