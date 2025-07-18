/***********************************************************************
// OOP244 Workshop 6 lab
// 
// File	Numbers.h
// Version 0.1
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_NUMBERS_H_
#define SENECA_NUMBERS_H_
#include <iostream>

namespace seneca {
   class Numbers {
      double* m_numbers;
      char* m_filename;
      int m_numCount;
      bool m_isOriginal;
      bool isEmpty() const;
      void setEmpty();
      void setFilename(const char* filename);
      void sort();
      int numberCount() const;
      bool load();
   public:
      Numbers();
      Numbers(const char* filename);
      double average() const;
      double max() const;
      double min() const;
      bool save() const;
      ~Numbers();
      Numbers(const Numbers& other);
      Numbers& operator=(const Numbers& other);
      Numbers& operator+=(double value);
      std::ostream& display(std::ostream& os) const;
   };

   std::istream& operator>>(std::istream& istr, Numbers& N);
   std::ostream& operator<<(std::ostream& os, const Numbers& N);
}

#endif // !SENECA_NUMBERS_H_