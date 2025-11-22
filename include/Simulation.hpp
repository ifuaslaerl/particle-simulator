#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <vector>
#include "Particle.hpp"
#include "Field.hpp"

class Simulation {
public:
    Simulation();
    
    // Core loop methods
    void update();
    void draw();

    // Helper to initialize default scenario
    void init_default_scenario();

private:
    void resolve_collisions();
    
    std::vector<Particle> objects;
    std::vector<Field> forces;
};

#endif
