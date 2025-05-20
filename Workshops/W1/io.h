/* 
-----------------------------------------------------------
Workshop 01 
Module:c io
Filename: io.h
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
#ifndef SENECA_CSTR_H
#define SENECA_CSTR_H
#include <cstdio>
namespace seneca {
    struct PhoneRec {
        char FirstName[16];
        char LastName[26];
        long long PhoneNumber;
    };
    //Reads a name from console input.
    void read(char* name);
    //Prints a long long phone number in the format: (999) 999-9999
    void print(long long phoneNumber);
    //Reads a PhoneRec from a tab-separated record in a file.
    bool read(PhoneRec& pr, FILE* fptr);


}

#endif // SENECA_CSTR_H