#include "../include/Field.hpp"

Field::Field(FieldFunction f_){f=f_;}

Vector Field::apply(Particle p){
    return f(p);
}
