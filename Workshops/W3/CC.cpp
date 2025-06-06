/* 
-----------------------------------------------------------
Workshop W3
Module: CC
Filename: CC.cpp
-----------------------------------------------------------
Author: Alan Sanchez
Student number: 121720247
Email: aygarduno-sanchez@myseneca.ca
Subject: OOP244
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V1.0   2025/06/04  Initial release
V1.1   2025/06/05  Added comments and cleaned up code
-----------------------------------------------------------
All coding was done independently by me, with the support of online resources to deepen my 
understanding of the concepts. The only exceptions are portions of code explicitly supplied by my
professor. 
-----------------------------------------------------------
*/

#include <iostream>
#include "cstr.h"
#include "CC.h"
using namespace std;
namespace seneca {
   // Print the credit card number in a specific format
   // Example: 4000 0000 0000 0000
   void CC::prnNumber(unsigned long long no) const {
      cout << no / 1000000000000ull << " ";
      no %= 1000000000000ull;
      cout.fill('0');
      cout.width(4);
      cout.setf(ios::right);
      cout << no / 100000000ull << " ";
      no %= 100000000ull;
      cout.width(4);
      cout << no / 10000ull << " ";
      no %= 10000ull;
      cout.width(4);
      cout << no;
      cout.unsetf(ios::right);
      cout.fill(' ');
   }
   // Check if the credit card details are valid
   bool CC::validate(const char *name, unsigned long long cardNo, short cvv, short expMon, short expYear) const
   {
      if (name != nullptr && strlen(name) > 2 &&
       cardNo >= 4000000000000000ull && cardNo <= 4099999999999999ull &&
       cvv >= 100 && cvv <= 999 &&
       expMon >= 1 && expMon <= 12 &&
       expYear >= 24 && expYear <= 32) {
       return true;
   }
      return false;
   }
   // Allocate memory for the credit card name and copy the name into it
   void CC::aloCopy(const char *name)
   {
         if (name != nullptr && name[0] != '\0') {
            cc_name = new char[strlen(name) + 1];
            strcpy(cc_name, name);
         } 
         else {
            cc_name = nullptr;
         }

   }
   // Delete old memory
   void CC::deallocate()
   {
      if (cc_name != nullptr) {
         delete[] cc_name;
         cc_name = nullptr;
      }
   }
   // Print the member information on console 
   void CC::display(const char *name, unsigned long long number, short expYear, short expMon, short cvv) const
   {
       char lname[31]{};
       strcpy(lname, name, 30);
       cout << "| ";
       cout.width(30);
       cout.fill(' ');
       cout.setf(ios::left);
       cout << lname << " | ";
       prnNumber(number);
       cout << " | " << cvv << " | ";
       cout.unsetf(ios::left);
       cout.setf(ios::right);
       cout.width(2);
       cout << expMon << "/" << expYear << " |" << endl;
       cout.unsetf(ios::right);
   }
   // Set the credit card object to a default state
   void CC::set() {
      cc_name = nullptr;
      cc_number = 0;
      cc_cvv = 0;
      cc_expMon = 0;
      cc_expYear = 0;
   }
   // Check if the credit card object is empty
   bool CC::isEmpty() const{
      if (cc_name == nullptr || cc_name[0] == '\0' || 
          cc_number == 0 || cc_cvv == 0 || 
          cc_expMon == 0 || cc_expYear == 0) {
         return true;
      }
      return false;
   }
   // Set the credit card information
   void CC::set(const char* name, unsigned long long cc_no, short cvv, short expMon, short expYear) {
      set(); // Set to safe empty state
      if (validate(name, cc_no, cvv, expMon, expYear)) {
        aloCopy(name);
        cc_number = cc_no;
        cc_cvv = cvv;
        cc_expMon = expMon;
        cc_expYear = expYear;
      }
   }
   // Display the credit card information
   // If the object is empty, display an error message
   void CC::display() const{
      if (!isEmpty()) {
         display(cc_name, cc_number, cc_expYear, cc_expMon, cc_cvv);
      } 
      else {
         cout << "Invalid Credit Card Record" << endl;
      }
   }
   CC::CC() {
      set();
   }
   CC::CC(const char* name, unsigned long long cc_no, short cvv, short expMon, short expYear) {
      set();
      if (validate(name, cc_no, cvv, expMon, expYear)) {
         aloCopy(name);
         cc_number = cc_no;
         cc_cvv = cvv;
         cc_expMon = expMon;
         cc_expYear = expYear;
      }
   }
   CC::~CC() {
      deallocate();
   }
}