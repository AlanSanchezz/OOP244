#include <iostream>
#include <iomanip>
#include <cstring>
#include "Drink.h"
#include "Utils.h"
#include "Billable.h"
namespace seneca {

  // Default constructor
  Drink::Drink() : Billable(), m_size('\0') {}

  // Return true if size has been selected
  bool Drink::ordered() const {
    return m_size == 'S' || m_size == 'M' || m_size == 'L' || m_size == 'X';
  }

  // Prompt user to select size
  bool Drink::order() {
    std::cout << "         Drink Size Selection\n"
              << "          1- Small\n"
              << "          2- Medium\n"
              << "          3- Large\n"
              << "          4- Extra Large\n"
              << "          0- Back\n"
              << "   > ";
    int selection = ut.getInt(0, 4);
    switch (selection) {
      case 1: m_size = 'S'; break;
      case 2: m_size = 'M'; break;
      case 3: m_size = 'L'; break;
      case 4: m_size = 'X'; break;
      case 0: m_size = '\0'; return false;
    }
    return true;
  }

  // Adjusted price based on size
  double Drink::price() const {
    double base = Billable::price();
    if (!ordered() || m_size == 'L') return base;
    if (m_size == 'S') return base * 0.5;
    if (m_size == 'M') return base * 0.75;
    if (m_size == 'X') return base * 1.5;
    return base;
  }

  // Read from CSV line: name,price
  std::ifstream& Drink::read(std::ifstream& ifs) {
    char name[100]{};
    double p;
    if (ifs.getline(name, 100, ',') && ifs >> p) {
      ifs.ignore(1000, '\n');
      Billable::name(name);
      Billable::price(p);
      m_size = '\0';
    }
    return ifs;
  }

  // Print name (28 chars, padded with .), size (5), price (7, 2dp)
  std::ostream& Drink::print(std::ostream& ostr) const {
    ostr << std::left << std::setw(28) << std::setfill('.') << static_cast<const char*>(*this);
    std::string sz = ".....";
    if (ordered()) {
      switch (m_size) {
        case 'S': sz = "SML.."; break;
        case 'M': sz = "MID.."; break;
        case 'L': sz = "LRG.."; break;
        case 'X': sz = "XLR.."; break;
      }
    }
    ostr << sz;
    ostr << std::right << std::setw(7) << std::setfill(' ') << std::fixed << std::setprecision(2) << price();
    return ostr;
  }

}