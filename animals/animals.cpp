#include "animals.h"
#include <cmath>

Animal::Animal(int* weight_): weight(weight_){}
Animal::Animal(char* sound_, int* weight_){
    sound = sound_;
    weight = weight_;
}

Animal:: ~Animal(){
        delete[] sound;
        delete weight;
    }
char* Animal::rargh(){
        return sound;
    }


float Animal::jump(){
    if (weight == nullptr)
        return 0;

    return (*weight) / 2;
    }
    
int* Animal::get_weight(){
    return weight;
}

Cat::Cat(): Animal(new char[4]{'M', 'e', 'o', 'w'}, new int(1)){}
Cat::Cat(int* weight): Animal(new char[4]{'M', 'e', 'o', 'w'}, weight){}

char* Cat::rargh(){
    return Animal::rargh();
}

float Cat::jump(){
    int* weight = Animal::get_weight();

    if (weight == nullptr)
        return 0;

    return (*weight) * 2;
}


Dog::Dog(): Animal(new char[4]{'B', 'a', 'r', 'k'}, new int(5)){}
Dog::Dog(int* weight): Animal(new char[4]{'B', 'a', 'r', 'k'}, weight){}

char* Dog::rargh(){
    return Animal::rargh();
}

float Dog::jump(){
    int* weight = Animal::get_weight();

    if (weight == nullptr)
        return 0;

    return std::log(*weight);
}