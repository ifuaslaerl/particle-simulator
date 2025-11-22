#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <string>
#include "Point.hpp"
#include "Vector.hpp"
#include "Config.hpp"

class Particle {
    public:
        Particle(Point center, ld radius);
        
        void draw();
        void set_speed(Vector);
        void set_color(RGB);
        void set_name(std::string);
        void update_pos();
        
        void check_colision_with_boundaries();
        void check_colision_with_particle(Particle&);
        
        Point center;
        Vector velocity;
        ld mass;
        ld charge;
        int id;
        std::string name;
        
    private:
        ld radius;
        int resolution;
};

#endif
