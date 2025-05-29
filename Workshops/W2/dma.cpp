/* 
-----------------------------------------------------------
Workshop W2
Module: dma
Filename: dma.cpp
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
#include <cstring>
#include "dma.h"
namespace seneca {
    Samples* CreateSamples(const char* title) {
        Samples* S = new Samples;
        S->m_title = new char[strlen(title) + 1];
        strcpy(S->m_title, title);
        S->m_data = nullptr;
        S->m_size = 0;
        return S;
    }

   void add(Samples& S, const int data[], int size) {
    if (size <= 0) return;  
    if (S.m_data == nullptr) {
        S.m_data = new int[size];
        for (int i = 0; i < size; ++i) {
            S.m_data[i] = data[i];
        }
        S.m_size = size;
    }
    else {

        append(S.m_data, S.m_size, data, size);
        S.m_size += size;
    }
}

    void append(int*& data, int size, const int appendedData[], int dataSize) {
        int* temp = new int[size + dataSize];
        for (int i = 0; i < size; ++i) {
            temp[i] = data[i];
        }
        for (int i = 0; i < dataSize; ++i) {
            temp[size + i] = appendedData[i];
        }
        delete[] data;
        data = temp;
    }

    void freemem(Samples*& s) {
        delete[] s->m_title;
        delete[] s->m_data;
        delete s;
        s = nullptr;
    }

}


