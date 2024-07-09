#include "animals.h"
#include <cmath>

Animal::Animal(int weight_): weight(new int(weight_)){}

Animal:: ~Animal(){
        delete weight;
    }



float Animal::jump() const{
    if (weight == nullptr)
        return 0;

    return (*weight) / 2;
    }
    
int* Animal::get_weight() const{
    return weight;
}

Cat::Cat(): Animal(1){
}
Cat::Cat(int weight): Animal(weight){}

char* Cat::rargh() const{
    return sound;
}

float Cat::jump() const{
    int* weight = Animal::get_weight();

    if (weight == nullptr)
        return 0;

    return (*weight) * 2;
}

Cat::~Cat(){
    delete[] sound;
}

Dog::Dog(): Animal(5){}
Dog::Dog(int weight): Animal(weight){}

char* Dog::rargh() const{
    return sound;
}

float Dog::jump() const{
    int* weight = Animal::get_weight();

    if (weight == nullptr)
        return 0;

    return std::log(*weight);
}

Dog::~Dog(){
    delete[] sound;
}