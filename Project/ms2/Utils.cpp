/***********************************************************************
// OOP244 Project, Utils Module
//
// File	Utils.h
// Version 0.1
// started by Fardad
// Description
// utility function to be used in the project
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Utils.h"
using namespace std;
namespace seneca {
   Utils ut;

   char* Utils::alocpy(const char* src) const{
      char* des{};
      return alocpy(des, src);
   }

   char* Utils::alocpy(char*& des, const char* src)const {
      delete[] des;
      des = nullptr;
      if (src) {
         des = new char[strlen(src) + 1];
         strcpy(des, src);
      }
      return des;
   }
   char* Utils::strcpy(char* des, const char* src)const {
      int i;
      for (i = 0; src[i]; i++) des[i] = src[i];
      des[i] = char(0);
      return des;
   }
   int Utils::strlen(const char* str)const {
      int len;
      for (len = 0; str[len]; len++);
      return len;
   }

   bool Utils::isspace(char ch)const {
      return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f' || ch == '\r';
   }

   bool Utils::isspace(const char* cstring) const{
      while (cstring && isspace(*cstring)) {
         cstring++;
      }
      return cstring && *cstring == 0;
   }



   int Utils::getInt() const {
      int value{};
      bool done = false;
      while (!done) {
         cin >> value;
         if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid integer: ";
         } else {
            char next = cin.get();
            if (next != '\n') {
               cout << "Only an integer please: ";
               cin.ignore(1000, '\n');
            } else {
               done = true;
            }
         }
         if (cin.peek() == '\n') {
            cin.ignore();
         }
         if (cin.eof()) done = true; // handle EOF gracefully
         if (cin.peek() == '\n' && cin.gcount() == 0) {
            cout << "You must enter a value: ";
         }
      }
      return value;
   }

   int Utils::getInt(int min, int max, const char* prompt) const {
      int value;
      bool done = false;
      while (!done) {
         if (prompt) cout << prompt;
         value = getInt();
         if (value >= min && value <= max) {
            done = true;
         } else {
            cout << "Invalid value: [" << min << " <= value <= " << max << "], try again: ";
         }
      }
      return value;
   }
}