// Billable.h
#ifndef SENECA_BILLABLE_H
#define SENECA_BILLABLE_H

#include <iostream>
#include <fstream>

namespace seneca {

  class Billable {
    char* m_name{};
    double m_price{};

  protected:
    void name(const char* name);   // sets name with dynamic allocation
    void price(double value);      // sets base price

  public:
    Billable();                    // default constructor
    Billable(const Billable&);     // copy constructor
    Billable& operator=(const Billable&); // copy assignment
    virtual ~Billable();           // virtual destructor

    virtual double price() const;  // getter (can be overridden)

    // pure virtuals
    virtual std::ostream& print(std::ostream& ostr = std::cout) const = 0;
    virtual bool order() = 0;
    virtual bool ordered() const = 0;
    virtual std::ifstream& read(std::ifstream& file) = 0;

    // conversion to const char* for name
    operator const char*() const;

    // friend operator overloads
    friend double operator+(double money, const Billable& B);
    friend double& operator+=(double& money, const Billable& B);
  };

}

#endif