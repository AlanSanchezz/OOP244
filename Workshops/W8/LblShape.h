#ifndef SENECA_LABELEDSHAPE_H
#define SENECA_LABELEDSHAPE_H

#include "Shape.h"
#include "Utils.h"  

namespace seneca {

   class LblShape : public Shape {
   private:
      char* m_label{nullptr};  // Dynamic label

   protected:
      const char* label() const;

   public:
      // Default constructor
      LblShape();

      // Constructor with label
      LblShape(const char* label);

      // Destructor to deallocate memory
      virtual ~LblShape();

      // Deleted copy constructor and assignment operator
      LblShape(const LblShape&) = delete;
      LblShape& operator=(const LblShape&) = delete;

      // Implementation of getSpecs to read label from input stream
      virtual void getSpecs(std::istream& istr) override;

      // draw() remains pure virtual, keeping this class abstract
      void draw(std::ostream& os) const override = 0;
   };

}

#endif // !SENECA_LABELEDSHAPE_H