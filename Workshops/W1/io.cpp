/* 
-----------------------------------------------------------
Workshop 01 
Module:c io
Filename: io.cpp
-----------------------------------------------------------
Author: Alan Yahir Garduno Sanchez
Student number: 121720247
Email: aygarduno-sanchez@myseneca.ca
Subject: OOP244NAA
-----------------------------------------------------------
Revision History
-----------------------------------------------------------
Name            Date            Reason
Alan Yahir Garduno Sanchez 2025-05-19  Created
Alan Yahir Garduno Sanchez 2025-05-19  Last Modified
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#include "io.h"
#include <iostream>
using namespace std;
namespace seneca{

    void read(char* name) {
        cout << "Name: ";
        cin >> name;
    }
    
    void print(long long phoneNumber) {
        cout << "Phone Number: ";
        int areaCode = phoneNumber / 10000000;
        int centralOfficeCode = (phoneNumber / 10000) % 1000;
        int lineNumber = phoneNumber % 10000;
        cout << "(" << areaCode << ") " << centralOfficeCode << "-" << lineNumber << endl;
    }

    bool read(PhoneRec& pr, std::FILE* fptr) {
        if (fscanf(fptr, "%s %s %lld", pr.FirstName, pr.LastName, &pr.PhoneNumber) == 3) {
            pr.PhoneNumber = pr.PhoneNumber;
            return true;
        }
        else {
            return false;
        }
    }

    void print(const PhoneRec& pr, size_t& row, const char* substr= nullptr){
        if (substr != nullptr) {
            

        }

    }




}

