/***********************************************************************
// OOP244 Workshop 4 lab: Account Module
//
// File	Account.h
// Version 0.5
// Date	2025/06/03
// Partialy implemented by	Fardad Soleimanloo
// to be completed by Alan Sanchez
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad Soleimanloo  2025/06/03  Preliminary implementation
// Alan Sanchez  2025/06/03  Worked on implementation
// Alan Sanchez  2025/06/03  Finalized Constructor and display function
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_ACCOUNT_H_
#define SENECA_ACCOUNT_H_
#include <iostream>

namespace seneca {
   const int NameMaxLen = 30;
   class Account {
      double m_balance;
      int m_number;
      char m_holderName[NameMaxLen + 1];
      void cpyName(const char* src); // copies the src into the m_holderName array
      bool isValidNumber(int number)const; // returns true if number is a valid account number
   public:

      // Constructors
      Account(const char* holderName = nullptr);
      Account(const char* holderName, int number, double balance);
      // Display function
      std::ostream& display()const;
      
      // Operators
      bool operator~() const;
      operator bool() const; // returns true if the account is valid
      operator int() const; // returns the account number.
      operator double() const; // returns the account balance
      operator const char*() const;  // returns the account holder's name


   };
  

}
#endif // SENECA_ACCOUNT_H_