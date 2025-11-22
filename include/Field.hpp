#ifndef FIELD_HPP
#define FIELD_HPP

#include "Vector.hpp"
#include "Particle.hpp"

typedef Vector(*FieldFunction)(Particle);

class Field {
    public:
        Field(FieldFunction);
        Vector apply(Particle);
    private:
        FieldFunction f;
};

#endif
