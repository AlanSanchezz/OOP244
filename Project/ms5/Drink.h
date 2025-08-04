#ifndef SDDS_DRINK_H
#define SDDS_DRINK_H

#include "Billable.h"
#include <iostream>
#include <fstream>

namespace seneca {

class Drink : public Billable {
    char m_size{ '\0' };
public:
    Drink();
    bool ordered() const override;
    bool order() override;
    std::ostream& print(std::ostream& ostr = std::cout) const override;
    std::ifstream& read(std::ifstream& ifs) override;
    double price() const override;
};

}

#endif // SDDS_DRINK_H