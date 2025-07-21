

#include "Billable.h"
#include "Utils.h"
#include <cstring>
 
namespace seneca {

  // Default constructor
  Billable::Billable() : m_name(nullptr), m_price(0.0) {}

  // Copy constructor
  Billable::Billable(const Billable& src) : m_name(nullptr), m_price(src.m_price) {
    name(src.m_name);
  }

  // Assignment operator
  Billable& Billable::operator=(const Billable& src) {
    if (this != &src) {
      delete[] m_name;
      m_name = nullptr;
      name(src.m_name);
      m_price = src.m_price;
    }
    return *this;
  }

  // Destructor
  Billable::~Billable() {
    delete[] m_name;
  }

  // Protected setter for price
  void Billable::price(double value) {
    m_price = value;
  }

  // Protected setter for name with dynamic allocation
  void Billable::name(const char* name) {
    delete[] m_name;
    m_name = nullptr;
    if (name && name[0]) {
      m_name = ut.alocpy(name);
    }
  }

  // Getter for price
  double Billable::price() const {
    return m_price;
  }

  // Conversion operator
  Billable::operator const char*() const {
    return m_name;
  }

  // Operator overload: double + Billable
  double operator+(double money, const Billable& B) {
    return money + B.price();
  }

  // Operator overload: double += Billable
  double& operator+=(double& money, const Billable& B) {
    money += B.price();
    return money;
  }


  
}