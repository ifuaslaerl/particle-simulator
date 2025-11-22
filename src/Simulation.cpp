#include "../include/Simulation.hpp"
#include "../include/Config.hpp"
#include <iostream>
#include <iomanip>

// Define gravity locally or in a physics util, keeping it here for now
Vector gravity_func(Particle p) {
    return p.velocity + Vector(0, -1);
}

Simulation::Simulation() {
    init_default_scenario();
}

void Simulation::init_default_scenario() {
    Field g(gravity_func);
    
    Particle p1(Point(100, 0), 50);
    Particle p2(Point(-100, 0), 50);
    
    RGB red = {1.0f, 0.0f, 0.0f};
    RGB blue = {0.0f, 0.0f, 1.0f};

    p1.set_speed(Vector(10, 30));
    p1.set_color(red);
    p1.set_name("Vermelho");

    p2.set_speed(Vector(-30, 10));
    p2.set_color(blue);
    p2.set_name("Azul");

    forces.push_back(g);
    objects.push_back(p1);
    objects.push_back(p2);
}

void Simulation::resolve_collisions() {
    const int n = objects.size();
    
    for(Particle& p : objects){
        p.check_colision_with_boundaries();
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            objects[i].check_colision_with_particle(objects[j]);
        }
    }
}

void Simulation::update() {
    resolve_collisions();
    
    // Apply forces
    for(Particle &p : objects) {
        for(Field &f : forces) {
            p.set_speed(f.apply(p));
        }
    }

    // Update positions
    for(Particle &p : objects) {
        p.update_pos();
    }

    // Debug output
    #ifdef DEBUG
        std::cout << std::fixed << std::setprecision(0);
        for(Particle &p: objects){
            std::cout << "Particle " << p.id << " - " << p.name << ":\t";
        }
        std::cout << std::endl;
        for(Particle &p: objects){
            std::cout << "\tPosition: " << p.center << "\t";
        }
        std::cout << std::endl;
        for(Particle &p: objects){
            std::cout << "\tVelocity: " << p.velocity << "\t";
        }
        std::cout << std::endl;
    #endif
}

void Simulation::draw() {
    for(Particle &p : objects) {
        p.draw();
    }
}
