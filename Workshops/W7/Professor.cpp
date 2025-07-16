#include "Professor.h"
#include "Utils.h"
#include <iostream>
using namespace std;

namespace seneca {

   // No-argument constructor
   Professor::Professor() : m_subject(nullptr), m_numSections(0) {}

   // 5-argument constructor
   Professor::Professor(const char* name, const char* subject, int numSections, int empNo, double salary)
      : Employee(name, empNo, salary) {
      m_subject = ut.alocpy(subject);
      m_numSections = numSections;
   }

   // Destructor
   Professor::~Professor() {
      delete[] m_subject;
   }

   // devPay calculation
   double Professor::devPay() const {
      return salary() * 0.01 * m_numSections;
   }

   // title
   ostream& Professor::title(ostream& ostr) const {
      Employee::title(ostr);
      return ostr << " Teaching Subject     | Sec # | $Dev Pay |";
   }

   // read
   istream& Professor::read(istream& istr) {
      char buffer[1024]{};
      if (istr.peek() == '\n') {
         istr.ignore();
      }
      Employee::read(istr);
      if (!istr) return istr;
      istr.ignore();
      istr.getline(buffer, 1024, ',');
      delete[] m_subject;  
      m_subject = ut.alocpy(buffer); 
      istr >> std::ws >> m_numSections; 
      if (!istr) return istr;
      return istr;
   }

   // write
   ostream& Professor::write(ostream& ostr) const {
      Employee::write(ostr);
      ostr << " ";
      ostr.width(20);
      ostr.setf(ios::left);
      if (m_subject) {
          char temp[21]{};
          ut.strcpy(temp, m_subject, 20);
          ostr << temp;
      }
      ostr.unsetf(ios::left);
      ostr << " | ";
      ostr.width(5);
      ostr.setf(ios::right);
      ostr << m_numSections << " | ";
      ostr.width(8);
      ostr.setf(ios::fixed);
      ostr.precision(2);
      ostr << devPay() << " |";
      ostr.unsetf(ios::right | ios::fixed);
      return ostr;
   }

   // operator >>
   istream& operator>>(istream& istr, Professor& P) {
      return P.read(istr);
   }

   // operator <<
   ostream& operator<<(ostream& ostr, const Professor& P) {
      return P.write(ostr);
   }

}
