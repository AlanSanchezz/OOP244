/***********************************************************************
// OOP244 Workshop 5: Mark Module
//
// File	Mark.cpp
// Version 1.0
// Date	2025/06/12
// Author	partially done by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include <cmath> // for round function
#include "Mark.h"
using namespace std;
namespace seneca {
   bool Mark::isValid()const {
      return  (m_value >= 0 && m_value <= 100);
   }
   Mark::Mark(int value, char type) {
      *this = type;
      m_value = double(value);
   }

   Mark::Mark(double value) {
      m_type = MARK;
      m_value = value;
   }

   Mark& Mark::operator+=(const Mark& M) {
      m_value += M.m_value;
      return *this;
   }

   Mark& Mark::operator-=(const Mark& M) {
      m_value -= M.m_value;
      return *this;
   }

   Mark Mark::operator+(const Mark& M) const {
      return Mark(*this) += M;
   }

   Mark Mark::operator-(const Mark& M)const {
      return Mark(*this) -= M;
   }

   Mark& Mark::operator/=(int other) {
      m_value = m_value / other;
      return *this;
   }

   Mark Mark::operator/(int other) const {
      return Mark(m_value / other);
   }

   Mark& Mark::operator=(int value) {
      m_value = value;
      return *this;
   }

   Mark& Mark::operator=(char type) {
      m_type = MARK;
      if (type == GRADE || type == GPA) {
         m_type = type;
      }
      return *this;
   }

   double Mark::raw() const {
      return m_value;
   }

   Mark::operator int() const {
      int value = -1;
      if (isValid()) {
         value = int(std::round(m_value < 0 ? 0 : m_value));
      }
      return value;
   }
   Mark::operator bool() const {
      return isValid();
   }


   // returns the GPA not the m_value!!!
   Mark::operator double() const {
      double gpa = 0;
      if (!isValid()) gpa = -1;
      else gpa = m_value * 0.04;
      return gpa;
   }

   Mark::operator const char* () const {
      // removes the constantness of m_grade!
      // You will learn this at the end of the semester.
      char* grade = const_cast<char*>(m_grade);

      int value = int(*this);
      grade[1] = grade[2] = '\0';
      if (value < 0 || value > 100) grade[0] = 'X';
      else if (value >= 90) grade[0] = 'A', grade[1] = '+';
      else if (value >= 80) grade[0] = 'A';
      else if (value >= 75) grade[0] = 'B', grade[1] = '+';
      else if (value >= 70) grade[0] = 'B';
      else if (value >= 65) grade[0] = 'C', grade[1] = '+';
      else if (value >= 60) grade[0] = 'C';
      else if (value >= 55) grade[0] = 'D', grade[1] = '+';
      else if (value >= 50) grade[0] = 'D';
      else grade[0] = 'F';
      return m_grade;
   }

   // student helper function implementations go here  

   std::ostream& seneca::Mark::display(std::ostream& os) const {
      if (!isValid()) {
          if (m_type == GRADE) {
              os << "**";
          } else {
              os << "***";
          }
      } else {
          os.setf(std::ios::right);
          switch (m_type) {
              case GPA:
                  os.setf(std::ios::fixed);
                  os.precision(1);
                  os.width(3);
                  os << double(*this);
                  break;
              case MARK:
                  os.fill('_');
                  os.width(3);
                  os << int(*this);
                  break;
              case GRADE:
                  os.unsetf(std::ios::right);
                  os.setf(std::ios::left);
                  os.width(3);
                  os.fill(' ');
                  os << (const char*)(*this);
                  break;
              default:
                  os << "***";
                  break;
          }
          os.unsetf(std::ios::right);
      }
      return os;
   }

   std::ostream& display(const Mark& mark, char type, std::ostream& os) {
      // Display first in MARK type
      Mark temp = mark;      // Make a copy to avoid modifying the originaltemp = MARK;
      temp.display(os);
      // If another type is requested, add it with ": "
      if (type != MARK) {
         os << ": ";
         temp = type;        // Change the type
         temp.display(os);
      }
      return os;
   }

   std::ostream& operator<<(std::ostream& os, const Mark& mark) {
      return mark.display(os);
   }

   std::istream& operator>>(std::istream& is, seneca::Mark& mark) {
      int value;
      char newline = '\0';
      bool done = false;
      while (!done) {
         is >> value;
         if (is.fail()) {
            // Failed to read an int
            std::cout << "Invalid integer, try again.\n> ";
            is.clear();
            is.ignore(1000, '\n');
         } 
         else {
            // Check if there are trailing characters
            newline = is.get();
            if (newline != '\n') {
               std::cout << "Invalid trailing characters. Please enter only an integer.\n> ";
               is.ignore(1000, '\n');
            } 
            else if (value < 0 || value > 100) {
               std::cout << "Invalid mark. Enter a value between 0 and 100.\n> ";
            } 
            else {
               // All good
               mark = value;
               done = true;
            }
         }
      }
      return is;
   }

   std::ifstream& operator>>(std::ifstream& is, seneca::Mark& mark) {
      int value;
      char comma, type;
      // Attempt to read: int, comma, type
      is >> value >> comma >> type;
      if (is && comma == ',') {
         mark = value;
         mark = type;
      }
      return is;
   }

   double operator+(double left, const seneca::Mark& right) {
      return left + right.raw();  // uses the raw() method
   }

   int operator+(int left, const seneca::Mark& right) {
      return left + int(right);   // uses the int conversion operator
   }
   // operator- helpers
   double operator-(double left, const seneca::Mark& right) {
      return left - right.raw();  // subtract raw double value
   }
   
   int operator-(int left, const seneca::Mark& right) {
      return left - int(right);   // subtract rounded int value
   }

   // operator/ helpers
   double operator/(double left, const seneca::Mark& right) {
      return left / right.raw();  // divide by raw double value
   }

   int operator/(int left, const seneca::Mark& right) {
      return left / int(right);   // divide by rounded int value
   }

}