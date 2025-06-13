#ifndef SENECA_ACCOUNT_H_
#define SENECA_ACCOUNT_H_

#include <iostream>

namespace seneca {

   const int NameMaxLen = 30;

   class Account {
      double m_balance;
      int m_number;
      char m_holderName[NameMaxLen + 1];

      // Helper private methods
      void cpyName(const char* src);               // copies src into m_holderName safely
      bool isValidNumber(int number) const;        // validates 5-digit account number

   public:

      // Constructors
      Account(const char* holderName = nullptr);
      Account(const char* holderName, int number, double balance);

      // Display account details
      std::ostream& display() const;

      // Unary operator to check if account is new (number == 0)
      bool operator~() const;

      // Type conversion operators
      operator bool() const;            // true if account is valid
      operator int() const;             // returns account number
      operator double() const;          // returns balance
      operator const char*() const;     // returns account holder name

      // Subscription operators for name access
      char& operator[](int index);               // allows modification
      const char operator[](int index) const;   // read-only access

      // Assignment operators
      Account& operator=(int number);
      Account& operator=(double value);

      // Arithmetic operators
      Account& operator+=(double value);
      Account& operator-=(double value);

      // Increment and decrement operators
      Account& operator++();       // Prefix increment
      Account operator++(int);     // Postfix increment
      Account& operator--();       // Prefix decrement
      Account operator--(int);     // Postfix decrement

      // Friend functions for fund transfer operators
      friend Account& operator<<(Account& left, Account& right);
      friend Account& operator>>(Account& left, Account& right);
   };

} // namespace seneca

#endif // SENECA_ACCOUNT_H_