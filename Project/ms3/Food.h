#ifndef SDDS_FOOD_H
#define SDDS_FOOD_H

#include "Billable.h"
#include <iostream>
#include <fstream>

namespace seneca {

class Food : public Billable {
    bool m_ordered{ false };
    bool m_child{ false };
    char* m_customize{ nullptr };

public:
    Food();
    Food(const Food&);
    Food& operator=(const Food&);
    ~Food();

    bool ordered() const override;
    bool order() override;
    std::ostream& print(std::ostream& ostr = std::cout) const override;
    std::ifstream& read(std::ifstream& ifs) override;
    double price() const override;
};

}

#endif // SDDS_FOOD_H