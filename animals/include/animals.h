#ifndef ANIMALS_INCLUDE_ANIMALS_H_20240907
#define ANIMALS_INCLUDE_ANIMALS_H_20240907

#include <vector>

class Animal{
protected:
    int* weight;
public:
    Animal() = default;
    Animal(int weight);

    virtual ~Animal();

    virtual float jump() const;
};


class Cat: public Animal{
    char* sound;
public:
    Cat();
    Cat(int weight_);
    ~Cat();

    char* rargh() const;
    
    float jump() const;
};

class Dog: public Animal{
    int* weight;
    char* sound;
public:
    Dog();
    Dog(int weight_);
    ~Dog();

    char* rargh() const;

    float jump() const;
};


class Fabric{
    std::vector<Dog*> dog_vector;
    std::vector<Cat*> cat_vector;
public:
    Fabric() = default;  
    ~Fabric();  
    Dog* add_dog();
    Dog* add_dog(int weight);

    Cat* add_cat();
    Cat* add_cat(int weight);
};
#endif