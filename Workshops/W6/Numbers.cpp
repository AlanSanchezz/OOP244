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

    // Default constructor: initialize object to a safe empty state
    Numbers::Numbers() {
        setEmpty();
        m_isOriginal = false;
    }
 
    // Constructor that takes filename: loads data from the file
    Numbers::Numbers(const char* filename) {
        m_numbers = nullptr;
        m_numCount = 0;
        m_isOriginal = true;
        if (filename != nullptr && filename[0] != '\0') {
            // Allocate memory and copy filename
            m_filename = new char[strlen(filename) + 1];
            strcpy(m_filename, filename);
            // Count numbers in file
            m_numCount = numberCount();
            // Load numbers from file into array
            if (!load()) {
                setEmpty();
            }
        } else {
            m_filename = nullptr;
            setEmpty();
        }
    }

    // Set object to safe empty state and free memory
    void Numbers::setEmpty() {
        m_numbers = nullptr;
        m_filename = nullptr;
        m_numCount = 0;
    }

    // Sort the numbers array in ascending order using simple bubble sort
    void Numbers::sort() {
        int i, j;
        double temp;
        for (i = m_numCount - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (m_numbers[j] > m_numbers[j + 1]) {
                    temp = m_numbers[j];
                    m_numbers[j] = m_numbers[j + 1];
                    m_numbers[j + 1] = temp;
                }
            }
        }
    }
    // Check if the object is empty (safe empty state)
    bool Numbers::isEmpty() const {
        return m_numbers == nullptr;
    }

    // Return the maximum number in the array (assuming not empty)
    double Numbers::max() const {
        double maxVal = 0.0;
        if (!isEmpty()) {
            maxVal = m_numbers[0];
            for (int i = 1; i < m_numCount; i++)
            if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
        }
        return maxVal;
    }

    // Return the minimum number in the array (assuming not empty)
    double Numbers::min() const {
        double minVal = 0.0;
        if (!isEmpty()) {
            minVal = m_numbers[0];
            for (int i = 1; i < m_numCount; i++)
            if (minVal > m_numbers[i]) minVal = m_numbers[i];
        }
        return minVal;
    }

    // Return the average of the numbers (assuming not empty)
    double Numbers::average() const {
        double aver = 0.0;
        if (!isEmpty()) {
            for (int i = 0; i < m_numCount; i++)
            aver += m_numbers[i];
            aver = aver / m_numCount;
        }
        return aver;
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