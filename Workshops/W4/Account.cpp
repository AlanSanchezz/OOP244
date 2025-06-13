/***********************************************************************
// OOP244 Workshop 4 lab: Account Module
//
// File	Account.cpp
// Version 0.5
// Date	2025/06/03
// Partially implemented by	Fardad Soleimanloo
// To be completed by Alan Sanchez
// You may modify any code in this file to suit your requirements.
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad Soleimanloo  2025/06/03  Preliminary implementation
// Alan Sanchez        2025/06/03  Worked on implementation
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include "Account.h"

using namespace std;

namespace seneca {

// Helper function to copy the name safely
void Account::cpyName(const char* src) {
    int i;
    for (i = 0; src && src[i] && i < NameMaxLen; i++) {
        m_holderName[i] = src[i];
    }
    m_holderName[i] = '\0';
}

// Validates account number (5-digit)
bool Account::isValidNumber(int number) const {
    return number >= 10000 && number <= 99999;
}

// Constructor for new account (number not assigned yet)
Account::Account(const char* holderName) {
    m_holderName[0] = '\0';
    m_number = -1;
    m_balance = 0.0;
    if (holderName && holderName[0]) {
        cpyName(holderName);
        m_number = 0;  // New account state
    }
}

// Constructor for valid or invalid account based on inputs
Account::Account(const char* holderName, int number, double balance) {
    m_holderName[0] = '\0';
    m_number = -1;
    m_balance = 0.0;
    if (holderName && holderName[0] && isValidNumber(number) && balance >= 0) {
        cpyName(holderName);
        m_number = number;
        m_balance = balance;
    }
}

// Display function outputs account info based on state
ostream& Account::display() const {
    if (*this) {  // Valid account
        cout << " ";
        cout.fill(' ');
        cout.width(NameMaxLen);
        cout.setf(ios::left);
        cout << m_holderName;
        cout.unsetf(ios::left);
        cout << " | ";
        cout << m_number;
        cout << " | ";
        cout.width(12);
        cout.precision(2);
        cout.setf(ios::right);
        cout.setf(ios::fixed);
        cout << m_balance;
        cout.unsetf(ios::right);
        cout << " ";
    } 
    else if (~*this) {  // New account
        cout << " ";
        cout.fill(' ');
        cout.width(NameMaxLen);
        cout.setf(ios::left);
        cout << m_holderName;
        cout.unsetf(ios::left);
        cout << " |  NEW  |         0.00 ";
    } 
    else {  // Invalid account
        cout << " Bad Account                    | ----- | ------------ ";
    }
    return cout;
}

// Unary operator ~: checks if account is new (number == 0)
bool Account::operator~() const {
    return m_number == 0 && m_holderName[0] != '\0';
}

// Prefix increment: adds $1 to balance if valid
Account& Account::operator++() {
    if (*this) {
        m_balance += 1.0;
    }
    return *this;
}

// Postfix increment: adds $1 but returns old state
Account Account::operator++(int) {
    Account temp = *this;
    ++(*this);
    return temp;
}

// Prefix decrement: subtracts $1 if enough balance and valid
Account& Account::operator--() {
    if (*this && m_balance >= 1.0) {
        m_balance -= 1.0;
    }
    return *this;
}

// Postfix decrement: subtracts $1 but returns old state
Account Account::operator--(int) {
    Account temp = *this;
    --(*this);
    return temp;
}

// Conversion to bool: true if valid account
Account::operator bool() const {
    return isValidNumber(m_number) && m_holderName[0] != '\0' && m_balance >= 0.0;
}

// Conversion to int: returns account number
Account::operator int() const {
    return m_number;
}

// Conversion to double: returns balance
Account::operator double() const {
    return m_balance;
}

// Conversion to const char*: returns holder name
Account::operator const char*() const {
    return m_holderName;
}

// Subscription operators for name access with wrap-around
char& Account::operator[](int index) {
    static char dummy = '\0';  // Dummy for invalid access
    if (m_holderName[0] == '\0') {
        return dummy;
    }
    index = index % NameMaxLen;
    return m_holderName[index];
}

const char Account::operator[](int index) const {
    if (m_holderName[0] == '\0') return '\0';
    index = index % NameMaxLen;
    return m_holderName[index];
}

// Assignment operator for int: sets account number if new and valid
Account& Account::operator=(int number) {
    if (~(*this)) {
        if (isValidNumber(number)) {
            m_number = number;
        } else {
            m_holderName[0] = '\0';
            m_number = -1;
            m_balance = 0.0;
        }
    }
    return *this;
}

// Assignment operator for double: sets balance if non-negative
Account& Account::operator=(double value) {
    if (value >= 0.0) {
        m_balance = value;
    } else {
        m_holderName[0] = '\0';
        m_number = -1;
        m_balance = 0.0;
    }
    return *this;
}

// Deposit operator += adds amount to balance if valid and non-negative
Account& Account::operator+=(double value) {
    if (*this && value >= 0.0) {
        m_balance += value;
    }
    return *this;
}

// Withdraw operator -= subtracts amount from balance if valid and sufficient funds
Account& Account::operator-=(double value) {
    if (*this && value >= 0.0 && m_balance >= value) {
        m_balance -= value;
    }
    return *this;
}

// Friend operator << to transfer funds from right account to left account
Account& operator<<(Account& left, Account& right) {
    if (&left != &right && left && right) {
        left.m_balance += right.m_balance;
        right.m_balance = 0.0;
    }
    return left;
}

// Friend operator >> to transfer funds from left account to right account
Account& operator>>(Account& left, Account& right) {
    if (&left != &right && left && right) {
        right.m_balance += left.m_balance;
        left.m_balance = 0.0;
    }
    return left;
}

}  // namespace seneca