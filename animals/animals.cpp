#include "animals.h"
#include <cmath>

// Animal

Animal::Animal(int weight_){
    weight = new int(weight_);
}

Animal:: ~Animal(){
    delete weight;
}

float Animal::jump() const{
    if (weight == nullptr)
        return 0;

    return (*weight) / 2;
    }
    

// Cat

Cat::Cat(): Animal(1){
    sound = new char[4]{'M', 'e', 'o', 'w'};
}

Cat::Cat(int weight_): Animal(weight_){
    sound = new char[4]{'M', 'e', 'o', 'w'};
}

Cat::~Cat(){
    delete[] sound;
}

char* Cat::rargh() const{
    return sound;
}

float Cat::jump() const{
    if (weight == nullptr)
        return 0;

    return (*weight) * 2;
}

// Dog

Dog::Dog(): Animal(5){
    sound = new char[4]{'B', 'a', 'r', 'k'};
}
Dog::Dog(int weight_): Animal(weight_){
    sound = new char[4]{'B', 'a', 'r', 'k'};
}

Dog::~Dog(){
    delete[] sound;
}

char* Dog::rargh() const{
    return sound;
}

float Dog::jump() const{
    if (weight == nullptr)
        return 0;

    return std::log(*weight);
}

// Fabric

Fabric::~Fabric(){
    for (auto x: dog_vector)
        delete x;
    
    for (auto y: cat_vector)
        delete y;
}

Dog* Fabric::add_dog(){
    Dog* dog = new Dog();

    dog_vector.push_back(dog);
    
    return dog;
}

Dog* Fabric::add_dog(int weight){
    Dog* dog = new Dog(weight);
    
    dog_vector.push_back(dog);

    return dog;
}

Cat* Fabric::add_cat(){
    Cat* cat = new Cat();

    cat_vector.push_back(cat);

    return cat;
}

Cat* Fabric::add_cat(int weight){
    Cat* cat = new Cat(weight);

    cat_vector.push_back(cat);

    return cat;
}