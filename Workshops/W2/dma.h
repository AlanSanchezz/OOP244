/* 
-----------------------------------------------------------
Workshop W2
Module: dma
Filename: dma.h
-----------------------------------------------------------
Author: Alan Sanchez
Student number: 121720247
Email: aygarduno-sanchez@myseneca.ca
Subject: OOP244
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V1.0   2025/05/27  Initial release
V1.1   2025/05/28  Added comments and cleaned up code
-----------------------------------------------------------
All coding was done independently by me, with the support of online resources to deepen my 
understanding of the concepts. The only exceptions are portions of code explicitly supplied by my
professor. 
-----------------------------------------------------------
*/
#ifndef SENECA_CSTR_H
#define SENECA_CSTR_H
namespace seneca{
    struct Samples {
    char* m_title;   // Dynamically allocated title
    int* m_data;     // Dynamically allocated array of integers
    int m_size;   // Number of elements in m_data
};

Samples* CreateSamples(const char* title);

void add(Samples& S, const int data[], int size);

void append(int*& data, int size, const int appendedData[], int dataSize);

void freemem(Samples*& s);
    

}
#endif // !SENECA_CSTR_H
