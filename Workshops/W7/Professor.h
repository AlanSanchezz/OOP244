#ifndef SENECA_PROFESSOR_H
#define SENECA_PROFESSOR_H

#include "Employee.h"
#include "Professor.h"
#include <iostream>

namespace seneca {
   class Professor : public Employee {
      char* m_subject{};
      int m_numSections{};
   public:
      Professor();  // No-argument constructor
      Professor(const char* name, const char* subject, int numSections, int empNo, double salary); // 5-argument constructor

      ~Professor();

      double devPay() const;

      std::istream& read(std::istream& istr = std::cin);
      std::ostream& write(std::ostream& ostr = std::cout) const;
      std::ostream& title(std::ostream& ostr = std::cout) const;
   };

   std::istream& operator>>(std::istream& istr, Professor& P);
   std::ostream& operator<<(std::ostream& ostr, const Professor& P);
}

#endif // !SENECA_PROFESSOR_H