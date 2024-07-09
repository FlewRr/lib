#ifndef ANIMALS_INCLUDE_ANIMALS_H_20240907
#define ANIMALS_INCLUDE_ANIMALS_H_20240907

class Animal{
    char* sound;
    int* weight;
    double type_multiplier;
public:
    Animal() = default;
    Animal(int* weight);
    Animal(char* sound, int* weight, double type_multiplier);

    ~Animal();

    char* rargh();

    float jump();
};


class Cat: public Animal{
    char* sound = new char[]{'M', 'e', 'o', 'w'};
public:
    Cat();
    Cat(int* weight);
};

class Dog: public Animal{
    char* sound = new char[]{'B', 'a', 'r', 'k'};
public:
    Dog();
    Dog(int* weight);
};

#endif