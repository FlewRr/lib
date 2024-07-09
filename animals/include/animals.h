#ifndef ANIMALS_INCLUDE_ANIMALS_H_20240907
#define ANIMALS_INCLUDE_ANIMALS_H_20240907

class Animal{
    char* sound;
    int* weight;
public:
    Animal() = default;
    Animal(int* weight);
    Animal(char* sound, int* weight);

    ~Animal();

    virtual char* rargh();

    virtual float jump();

    int* get_weight();
};


class Cat: public Animal{
public:
    Cat();
    Cat(int* weight);

    char* rargh();
    
    float jump();
};

class Dog: public Animal{
public:
    Dog();
    Dog(int* weight);

    char* rargh();

    float jump();
};

#endif