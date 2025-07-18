#ifndef SDDS_LINE_H
#define SDDS_LINE_H

#include "LblShape.h"

namespace seneca {

    class Line : public LblShape {
        int m_length{};
    public:
        Line(); // Default constructor
        Line(const char* label, int length); // Two-argument constructor

        void getSpecs(std::istream& is) override;
        void draw(std::ostream& os) const override;
    };
    

}

#endif // SDDS_LINE_H