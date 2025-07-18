#ifndef SENECA_SHAPE_H
#define SENECA_SHAPE_H
#include <iostream>

namespace seneca {

   class Shape {
   public:
      virtual void draw(std::ostream& os) const = 0;
      virtual void getSpecs(std::istream& is) = 0;
      virtual ~Shape() {}
   };

   std::ostream& operator<<(std::ostream& os, const Shape& shape);
   std::istream& operator>>(std::istream& is, Shape& shape);

}

#endif // !SENECA_SHAPE_H
