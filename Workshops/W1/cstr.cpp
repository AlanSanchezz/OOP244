/* 
-----------------------------------------------------------
Workshop 01 
Module:c cstr
Filename: cstr.cpp
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
#include "cstr.h"
#include <cstring> // for strlen

namespace seneca {
    char* strcat(char* des, const char* src) {
        size_t len = strlen(des);
        size_t i = 0;
        while (des && src && src[i]) {
            des[i + len] = src[i];
            i++;
        }
        des[i + len] = char(0); // Null-terminate the result
        return des;
    }
    char tolower(char ch) {
        if (ch >= 'A' && ch <= 'Z') {
            ch += ('a' - 'A');
        }
        return ch;
    }
    char* tolower(char* des, const char* src) {
        size_t i = 0;
        for (; des && src && src[i]; i++) {
            des[i] = tolower(src[i]);
        }
        des[i] = char(0);
        return des;
    }
    char* tolower(char* str) {
        for (size_t i = 0; str && str[i]; i++) {
            str[i] = tolower(str[i]); // Uses the char version of tolower()
        }
        return str;
    }
    int strcmp(const char* s1, const char* s2) {
        size_t i{};
        for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
        return s1[i] - s2[i];
    }
    int strcmp(const char* s1, const char* s2, size_t len) {
        size_t i{};
        while (i < len - 1 && s1[i] && s2[i] && s1[i] == s2[i]) {
            i++;
        }
        return s1[i] - s2[i];
    }
    char* strcpy(char* des, const char* src) {
        size_t i;
        for (i = 0; src[i]; i++) des[i] = src[i];
        des[i] = char(0);
        return des;
    }
    char* strcpy(char* des, const char* src, size_t len) {
        size_t i;
        for (i = 0; i < len && src[i]; i++) {
            des[i] = src[i];
        }
        des[i] = 0; // Ensures null-termination
        return des;
    }
    char* strncpy(char* des, const char* src, size_t len) {
        size_t i = 0;
        while (i < len - 1 && src[i]) {
            des[i] = src[i];
            i++;
        }
        des[i] = src[i]; // Final char copied or null terminator
        return des;
    }
    size_t strlen(const char* str) {
        size_t len{};
        for (len = 0;str &&  str[len]; len++);
        return len;
    }
    const char* strstr(const char* str, const char* toFind) {
        const char* faddress = nullptr;
        size_t
        i,
        flen = strlen(toFind),
        slen = strlen(str);
        for (i = 0; flen <= slen && i <= slen - flen && strcmp(&str[i], toFind, flen); i++);
        if (flen <= slen && i <= slen - flen) {
            faddress = &str[i];
        }
        return faddress;
    }
    bool isalpha(char ch) {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }
    bool isspace(char ch) {
        return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f' || ch == '\r';
    }
}