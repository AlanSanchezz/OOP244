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
I used online resources like Google, official documentation, and even relied on IntelliSense 
for suggestions. However, all the coding was done by myself, except for the code provided by 
my professor for the ‘whatever’ function.
----------------------------------------------------------
*/
#include <cstring>
#include "io.h"
#include <iostream>
using namespace std;
namespace seneca{

    void read(char* name) {
        cout << "Name: ";
        cin >> name;
    }
    
    void print(long long phoneNumber) {
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

    void print(const PhoneRec& pr, size_t& row, const char* substr){
        if (substr == nullptr) {
            cout << row << ": " << pr.FirstName << " " << pr.LastName << " ";
            print(pr.PhoneNumber);
            row++;
        }
        else if(strstr(pr.FirstName, substr) || strstr(pr.LastName, substr)) {
            cout << row << ": " << pr.FirstName << " " << pr.LastName << " ";
            print(pr.PhoneNumber);
            row++;
        }
    }
    
    
    void print(PhoneRec* pr[], size_t size, const char* substr) {
        size_t row = 1;
        for (size_t i = 0; i < size; ++i) {
            print(*pr[i], row, substr);
        }
    }

    void setPointers(PhoneRec* ptrs[], PhoneRec pr[], size_t size) {
        for (size_t i = 0; i < size; ++i) {
            ptrs[i] = &pr[i];
        }
    }
    
    void sort(PhoneRec* pr[], size_t size, bool byLastName) {
        for (size_t i = 0; i < size - 1; ++i) {
            for (size_t j = i + 1; j < size; ++j) {
                if ((byLastName && strcmp(pr[i]->LastName, pr[j]->LastName) > 0) ||
                    (!byLastName && strcmp(pr[i]->FirstName, pr[j]->FirstName) > 0)) {
                    std::swap(pr[i], pr[j]);
                }
            }
        }
    }




}

