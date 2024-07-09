#include "animals.h"


Animal::Animal(int* weight): weight(weight){}
Animal::Animal(char* sound, int* weight, double type_multiplier=1){
    sound = sound;
    weight = weight;
    type_multiplier = type_multiplier;
}

Animal:: ~Animal(){
        delete[] sound;
        delete weight;
    }
char* Animal::rargh(){
        return sound;
    }


float Animal::jump(){
    if (weight != nullptr){
        float jump_height = (*weight) * type_multiplier;
        
        return jump_height;
    }
    return 0;
    }
    

Cat::Cat(): Animal(sound, new int(1), 3){}
Cat::Cat(int* weight): Animal(sound, weight, 3){}

Dog::Dog(): Animal(sound, new int(5)){}
Dog::Dog(int* weight): Animal(sound, weight, 1.5){}
