/* 
-----------------------------------------------------------
Workshop W3
Module: CC
Filename: CC.h
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
#ifndef SENECA_CC_H_
#define SENECA_CC_H_
#include <iostream>
namespace seneca {
   class CC {
      char* cc_name;
      unsigned long long cc_number;
      short cc_cvv;
      short cc_expMon;
      short cc_expYear;
      void aloCopy (const char* name);
      void deallocate();
      void display(const char* name, unsigned long long number, short expYear, short expMon, short cvv) const;
      void prnNumber(unsigned long long no) const;
      bool validate(const char* name, unsigned long long cardNo, short cvv, short expMon, short expYear)const;
      public:
      CC();CC(const char* name, unsigned long long cc_no, short cvv, short expMon = 12, short expYear = 26);
~CC();
      void set();
      bool isEmpty() const;
      void set(const char* cc_name, unsigned long long cc_no, short cvv, short expMon, short expYear);
      void display() const;
   };

}
#endif // !SENECA_CC_H_


