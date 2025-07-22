#include <iostream>
#include "Transcript.h"
#include "Utils.h"

using namespace std;
using namespace seneca;

Transcript::Transcript(const char* name, unsigned int studentNumber)
   : m_studentName(nullptr), m_studentNumber(studentNumber) {
   ut.alocpy(m_studentName, name);
}

Transcript::Transcript(const Transcript& other)
   : Marks(other), m_studentName(nullptr), m_studentNumber(other.m_studentNumber) {
   ut.alocpy(m_studentName, other.m_studentName);
}

Transcript& Transcript::operator=(const Transcript& other) {
   if (this != &other) {
      Marks::operator=(other);
      delete[] m_studentName;
      m_studentName = nullptr;
      ut.alocpy(m_studentName, other.m_studentName);
      m_studentNumber = other.m_studentNumber;
   }
   return *this;
}

Transcript::~Transcript() {
   delete[] m_studentName;
}

std::ostream& Transcript::display(std::ostream& os) const {
    os << m_studentName << " (" << m_studentNumber << ")" << endl;
    os << "--------------------------------------------------------------------------" << endl;
    Marks::display(os);
    return os;  
}


