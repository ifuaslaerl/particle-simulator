#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Vector.hpp"
#include "Config.hpp"

class Point {
    public:
        Point();
        Point(ld x, ld y);
        Point(Vector);
        
        Vector operator-(const Point&) const;
        friend std::ostream& operator<<(std::ostream&, const Point&);
        
        void draw();
        void set_colour(RGB);
        void update_pos(Vector);
        
        ld x, y;
        RGB colour;
};

#endif
