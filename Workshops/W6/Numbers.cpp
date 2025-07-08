/***********************************************************************
// OOP244 Workshop 6 lab
// File	Numbers.cpp
// Version 1.0
// Author	Alan Sanchez
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <cstring>
#include "Numbers.h"
using namespace std;

namespace seneca {

    // ************** Partial implementations based on professor's instructions **************

    // Default constructor: initialize object members using member initializer list
    Numbers::Numbers()
        : m_numbers(nullptr), m_filename(nullptr), m_numCount(0), m_isOriginal(false) {
        // No need to call setEmpty() here since members are initialized
    }
 
    // Constructor that takes filename: loads data from the file
    Numbers::Numbers(const char* filename) {
        m_numbers = nullptr;
        m_numCount = 0;
        m_isOriginal = true; // This object is the original, responsible for saving
        if (filename != nullptr && filename[0] != '\0') {
            // Allocate and copy filename string
            m_filename = new char[strlen(filename) + 1];
            strcpy(m_filename, filename);
            // Count how many numbers exist in the file
            m_numCount = numberCount();
            // Load numbers from the file into dynamic array
            if (!load()) {
                // If loading failed, set to safe empty state
                setEmpty();
            }
        } else {
            m_filename = nullptr;
            setEmpty();
        }
    }

    // Set object to safe empty state and free allocated memory
    void Numbers::setEmpty() {
        delete[] m_numbers;    // Free dynamic array memory if any
        m_numbers = nullptr;   // Reset pointer to null
        delete[] m_filename;   // Free filename memory if any
        m_filename = nullptr;  // Reset filename pointer
        m_numCount = 0;        // Reset count to zero
        m_isOriginal = false;  // Mark as not original object
    }

    

    // ************** Your implemented methods below **************

    // Counts how many numbers (lines) are in the file
    int Numbers::numberCount() const {
        int count = 0;
        ifstream file(m_filename);
        if (file.is_open()) {
            char ch;
            while (file.get(ch)) {
                if (ch == '\n') {
                    count++;
                }
            }
            file.close();
        }
        return count;
    }

    // Loads numbers from file into the array m_numbers
    bool Numbers::load() {
        bool success = false;
        if (m_numCount > 0) {
            m_numbers = new double[m_numCount];
            ifstream file(m_filename);
            int i = 0;
            while (file && i < m_numCount) {
                file >> m_numbers[i];
                if (file) {
                    i++;
                }
            }
            if (i == m_numCount) {
                success = true;
            } else {
                // If failed, clean up and set to empty state
                delete[] m_numbers;
                m_numbers = nullptr;
                setEmpty();
            }
        }
        return success;
    }

    // Overload += operator to add a new double to the array, resizing it
    Numbers& Numbers::operator+=(double value) {
        if (!isEmpty()) {
            double* temp = new double[m_numCount + 1];
            for (int i = 0; i < m_numCount; i++) {
                temp[i] = m_numbers[i];
            }
            temp[m_numCount] = value;
            m_numCount++;
            delete[] m_numbers;
            m_numbers = temp;
            sort();
        }
        return *this;
    }

    // Display the Numbers object information and values to the output stream
    ostream& Numbers::display(ostream& os) const {
        if (isEmpty()) {
            os << "Empty list";
        } else {
            os.setf(ios::fixed);
            os.precision(2);
            os << "=========================" << endl;
            if (m_isOriginal) {
                os << m_filename << endl;
            } else {
                os << "*** COPY ***" << endl;
            }
            for (int i = 0; i < m_numCount; i++) {
                os << m_numbers[i];
                if (i < m_numCount - 1) {
                    os << ", ";
                }
            }
            os << endl;
            os << "-------------------------" << endl;
            os << "Total of " << m_numCount << " number(s)" << endl;
            os << "Largest number:  " << max() << endl;
            os << "Smallest number: " << min() << endl;
            os << "Average:         " << average() << endl;
            os << "=========================";
        }
        return os;
    }

    // Overload << operator to print Numbers object
    ostream& operator<<(ostream& os, const Numbers& N) {
        return N.display(os);
    }

    // Overload >> operator to read and add a double value to Numbers object
    istream& operator>>(istream& is, Numbers& N) {
        double value;
        if (is >> value) {
            N += value;
        }
        return is;
    }

    // Copy constructor: create a deep copy of other Numbers object
    Numbers::Numbers(const Numbers& other) {
        m_numbers = nullptr;
        m_numCount = 0;
        m_isOriginal = false;

        if (other.m_filename) {
            m_filename = new char[strlen(other.m_filename) + 1];
            strcpy(m_filename, other.m_filename);
        } else {
            m_filename = nullptr;
        }

        if (!other.isEmpty()) {
            m_numCount = other.m_numCount;
            m_numbers = new double[m_numCount];
            for (int i = 0; i < m_numCount; i++) {
                m_numbers[i] = other.m_numbers[i];
            }
        }
    }

    // Copy assignment operator: deep copy from other to this
    Numbers& Numbers::operator=(const Numbers& other) {
        if (this != &other) {
            delete[] m_numbers;
            m_numbers = nullptr;
            m_numCount = 0;

            delete[] m_filename;
            m_filename = nullptr;
            if (other.m_filename) {
                m_filename = new char[strlen(other.m_filename) + 1];
                strcpy(m_filename, other.m_filename);
            }

            // Keep m_isOriginal unchanged!
            if (!other.isEmpty()) {
                m_numCount = other.m_numCount;
                m_numbers = new double[m_numCount];
                for (int i = 0; i < m_numCount; i++) {
                    m_numbers[i] = other.m_numbers[i];
                }
            }
        }
        return *this;
    }

    // Save the current object's numbers to the file (if original and not empty)
    bool Numbers::save() const {
        if (m_isOriginal && !isEmpty()) {
            ofstream file(m_filename);
            if (!file) {
                return false;
            }
            for (int i = 0; i < m_numCount; i++) {
                file << m_numbers[i] << endl;
            }
            return true;
        }
        return false;
    }

    // Destructor: save data and free allocated memory
    Numbers::~Numbers() {
        save();
        delete[] m_numbers;
        m_numbers = nullptr;
        delete[] m_filename;
        m_filename = nullptr;
    }

    // Set the filename for the Numbers object
    void Numbers::setFilename(const char* filename) {
        delete[] m_filename;
        m_filename = new char[strlen(filename) + 1];
        strcpy(m_filename, filename);
    }

}