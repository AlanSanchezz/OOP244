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
I used online resources like Google, official documentation, and even relied on IntelliSense 
for suggestions. However, all the coding was done by myself, except for the code provided by 
my professor for the ‘whatever’ function.
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
    //Prints a PhoneRec in the format RowNumber: Name LastName (999) 999-9999
    void print(const PhoneRec& pr, size_t& row, const char* substr = nullptr);
    //Prints an array of PhoneRec pointers, filtering by a substring if provided.
    void print(PhoneRec* pr[], size_t size, const char* substr = nullptr);
    //Sets an array of PhoneRec pointers to point to the original PhoneRec array.
    void setPointers(PhoneRec* ptrs[], PhoneRec pr[], size_t size);
    //Sorts an array of PhoneRec pointers by name or last name.
    void sort(PhoneRec* pr[], size_t size, bool byLastName);

    


}

#endif // SENECA_CSTR_H