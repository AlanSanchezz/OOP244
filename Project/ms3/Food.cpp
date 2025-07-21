

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Food.h"
#include "Utils.h"

namespace seneca {

  // Default constructor
  Food::Food() : Billable(), m_ordered(false), m_child(false), m_customize(nullptr) {}

  // Copy constructor
  Food::Food(const Food& src) : Billable(src), m_ordered(src.m_ordered), m_child(src.m_child), m_customize(nullptr) {
    if (src.m_customize) {
      m_customize = ut.alocpy(src.m_customize);
    }
  }

  // Assignment operator
  Food& Food::operator=(const Food& src) {
    if (this != &src) {
      Billable::operator=(src);
      m_ordered = src.m_ordered;
      m_child = src.m_child;
      delete[] m_customize;
      m_customize = nullptr;
      if (src.m_customize) {
        m_customize = ut.alocpy(src.m_customize);
      }
    }
    return *this;
  }

  // Destructor
  Food::~Food() {
    delete[] m_customize;
  }

  // Returns whether the food has been ordered
  bool Food::ordered() const {
    return m_ordered;
  }

  // Order function for portion selection and customization
  bool Food::order() {
    std::cout << "         Food Size Selection\n"
              << "          1- Adult\n"
              << "          2- Child\n"
              << "          0- Back\n"
              << "         > ";
    int selection = ut.getInt(0, 2);
    switch (selection) {
      case 1: m_child = false; m_ordered = true; break;
      case 2: m_child = true;  m_ordered = true; break;
      case 0: m_ordered = false; delete[] m_customize; m_customize = nullptr; return false;
    }

    std::cout << "Special instructions\n   > ";
    char temp[1000]{};
    std::cin.getline(temp, 1000);
    if (std::strlen(temp) == 0) {
      delete[] m_customize;
      m_customize = nullptr;
    } else {
      delete[] m_customize;
      m_customize = ut.alocpy(temp);
    }
    return true;
  }

  // Reads from a CSV line: name,price
  std::ifstream& Food::read(std::ifstream& ifs) {
    char name[100]{};
    double p;
    if (ifs.getline(name, 100, ',') && ifs >> p) {
      ifs.ignore(1000, '\n');
      Billable::name(name);
      Billable::price(p);
      m_ordered = false;
      m_child = false;
      delete[] m_customize;
      m_customize = nullptr;
    }
    return ifs;
  }

  // Prints food information with formatting
  std::ostream& Food::print(std::ostream& ostr) const {
    ostr << std::left << std::setw(28) << std::setfill('.') << (const char*)(*this);

    if (ordered()) {
      ostr << (m_child ? "Child" : "Adult");
    } else {
      ostr << ".....";
    }

    ostr << std::right << std::setw(7) << std::setfill(' ') << std::fixed << std::setprecision(2) << price();

    if (m_customize && &ostr == &std::cout) {
      ostr << " >> ";
      for (int i = 0; i < 30 && m_customize[i] != '\0'; i++) {
        ostr << m_customize[i];
      }
    }
    return ostr;
  }

  // Returns price based on portion size
  double Food::price() const {
    double basePrice = Billable::price();
    if (ordered() && m_child) {
      return basePrice * 0.5;
    }
    return basePrice;
  }

}