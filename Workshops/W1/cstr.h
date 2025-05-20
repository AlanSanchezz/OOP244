/* 
-----------------------------------------------------------
Workshop 01 
Module:c cstr
Filename: cstr.h
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
#include <cstddef>
namespace seneca {
    // Concatenates the src string to the end of des string.
    // Assumes des has enough space to hold the result.
    char* strcat(char* des, const char* src);
    // Converts an uppercase ASCII character to lowercase.
    // If ch is not uppercase, returns it unchanged.
    char tolower(char ch);
    // Converts all characters in src to lowercase and copies them into des.
    // Assumes des has enough space. Null-terminated.
    char* tolower(char* des, const char* src);
    // Converts all characters in the input string `str` to lowercase in place.
    // Modifies the original string and returns the same pointer.
    char* tolower(char* str);
    // Compares two C-style strings lexicographically.
    // Returns 0 if equal, <0 if s1 < s2, >0 if s1 > s2.
    int strcmp(const char* s1, const char* s2);
    // Compares up to 'len' characters of two strings lexicographically.
    // Returns 0 if equal up to len, or first differing character diff.
    int strcmp(const char* s1, const char* s2, size_t len);
    // Copies src into des including null terminator.
    // Returns des. Assumes des has enough space.
    char* strcpy(char* des, const char* src);
    // Copies up to 'len' characters from src to des.
    // Always null-terminates des. Safer than std::strncpy.
    // Returns des.
    char* strcpy(char* des, const char* src, size_t len);
    // Copies up to 'len' characters from src to des (like std::strncpy).
    // May not null-terminate if src is longer than len.
    // Returns des.
    char* strncpy(char* des, const char* src, size_t len);
    // Returns the length of the C-style string str (excluding null).
    size_t strlen(const char* str);
    // Finds the first occurrence of toFind in str.
    // Returns pointer to the first match or nullptr if not found.
    const char* strstr(const char* str, const char* toFind);
    // Returns true if ch is an alphabetic character (A-Z or a-z).
    bool isalpha(char ch);
    // Returns true if ch is a whitespace character.
    bool isspace(char ch);

}
#endif // SENECA_CSTR_H