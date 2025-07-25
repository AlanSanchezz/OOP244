#ifndef SENECA_DYNACOPY_H
#define SENECA_DYNACOPY_H

#include <iostream>

namespace seneca {

    // 1. Two-Argument dynaCopy
    template <typename T>
    T* dynaCopy(const T* source, int size) {
        if (source == nullptr || size <= 0) {
            return nullptr;
        }

        T* newArray = new T[size];
        for (int i = 0; i < size; ++i) {
            newArray[i] = source[i];
        }
        return newArray;
    }
    



    // 2. Three-Argument dynaCopy
    template <typename T>
    T* dynaCopy(T*& dest, const T* source, int size) {
        if (dest) {
            delete[] dest;
            dest = nullptr;
        }

        if (source == nullptr || size <= 0) {
            return nullptr;
        }

        dest = new T[size];
        for (int i = 0; i < size; ++i) {
            dest[i] = source[i];
        }
        return dest;
    }

    // 3. prnArray
    template <typename T>
    void prnArray(const T* array, int size) {
        if (array == nullptr || size <= 0) {
            std::cout << std::endl;
            return;
        }

        for (int i = 0; i < size; ++i) {
            std::cout << array[i];
            if (i < size - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }





    
}


#endif // SDDS_DYNACOPY_H