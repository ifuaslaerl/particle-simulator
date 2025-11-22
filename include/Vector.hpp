#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "Config.hpp"

class Vector {
    public:
        Vector();
        Vector(ld x, ld y);
        Vector operator+(const Vector&) const;
        Vector operator-(const Vector&) const;
        Vector operator*(const ld&) const;
        ld operator*(const Vector&) const;
        friend std::ostream& operator<<(std::ostream&, const Vector&);
        
        void draw();
        ld module();
        
        ld x, y;
};

#endif
