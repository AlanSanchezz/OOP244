/***********************************************************************
// OOP244 Workshop 6 lab
// DO NOT MODIFY THIS FILE
// File	Numbers_prof.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Numbers.h"
using namespace std;
namespace seneca {

   Numbers::Numbers() {
      setEmpty();
      m_isOriginal = false;
   }

   Numbers::Numbers(const char* filename) {
      setEmpty();
      m_isOriginal = true;
      setFilename(filename);
      m_numCount = numberCount();
      if (m_numCount == 0 || !load()) {
         delete[] m_numbers;
         delete[] m_filename;
         setEmpty();
         m_isOriginal = false;
      }
      else {
         sort();
      }
   }

   bool Numbers::isEmpty() const {
      return m_numbers == nullptr;
   }

   void Numbers::setEmpty() {
      m_numbers = nullptr;
      m_filename = nullptr;
      m_numCount = 0;
   }
   void Numbers::setFilename(const char* filename) {
      delete[] m_filename;
      m_filename = new char[strlen(filename) + 1];
      strcpy(m_filename, filename);
   }
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

   double Numbers::average() const {
      double aver = 0.0;
      if (!isEmpty()) {
         for (int i = 0; i < m_numCount; i++)
            aver += m_numbers[i];
         aver = aver / m_numCount;
      }
      return aver;
   }
   double Numbers::min() const {
      double minVal = 0.0;
      if (!isEmpty()) {
         minVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (minVal > m_numbers[i]) minVal = m_numbers[i];
      }
      return minVal;
   }
   double Numbers::max() const {
      double maxVal = 0.0;
      if (!isEmpty()) {
         maxVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
      }
      return maxVal;
   }
   Numbers::~Numbers(){
      save();
      delete[] m_numbers;
      delete[] m_filename;
   }
   
   void Numbers::save(){
      if(m_isOriginal && !isEmpty()){
         ofstream file(m_filename);
         if(file.is_open()){
            for(int i = 0; i < m_numCount; i++){
               file << m_numbers[i] << endl;
            }
            file.close();
         } else {
            cerr << "Error opening file for saving: " << m_filename << endl;
         }
      } else {
         cerr << "Cannot save, either not original or empty." << endl;
      }
   }
   
   Numbers::Numbers(const Numbers& other) {
      setEmpty();
      m_isOriginal = false;
      if (other.m_filename != nullptr) {
         m_filename = new char[strlen(other.m_filename) + 1];
         strcpy(m_filename, other.m_filename);
      }
      if (!other.isEmpty()) {
         m_numCount = other.m_numCount;
         m_numbers = new double[m_numCount];
         for (int i = 0; i < m_numCount; i++) {
            m_numbers[i] = other.m_numbers[i];
         }
      }
   }
   
   Numbers& Numbers::operator=(const Numbers& other) {
      if (this != &other) {
         delete[] m_numbers;
         delete[] m_filename;
      
         m_isOriginal = false;
      
         if (other.m_filename != nullptr) {
            m_filename = new char[strlen(other.m_filename) + 1];
            strcpy(m_filename, other.m_filename);
         } 
         else {
            m_filename = nullptr;
         }

         if (!other.isEmpty()) {
            m_numCount = other.m_numCount;
            m_numbers = new double[m_numCount];
            for (int i = 0; i < m_numCount; i++) {
               m_numbers[i] = other.m_numbers[i];
            }
         } 
         else {
            m_numbers = nullptr;
            m_numCount = 0;
         }
      }
      return *this;
   }


}


   



