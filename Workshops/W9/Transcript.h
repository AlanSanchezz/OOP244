/***************************************************************
// OOP244 workshop 9, Transcript module
//
// File	Transcript.h
// Version 1.0
// started by Fardad
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***************************************************************/
#ifndef SENECA_TRANSCRIPT_H
#define SENECA_TRANSCRIPT_H
#include <iostream>
#include "Marks.h"
namespace seneca {
   class Transcript : public Marks {
      // character pointer student name
      char* m_studentName;
      // unsigned integer or size_t student number
      unsigned int m_studentNumber;

   public:
      // Constructor
      Transcript(const char* name, unsigned int studentNumber);

      // Rule of Three
      Transcript(const Transcript& other);
      Transcript& operator=(const Transcript& other);

      // Destructor
      ~Transcript();

      // Overridden display method
      std::ostream& display(std::ostream& os = std::cout) const override;
   };
}
#endif // !SENECA_TRANSCRIPT_H
