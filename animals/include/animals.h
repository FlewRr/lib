#ifndef ANIMALS_INCLUDE_ANIMALS_H_20240907
#define ANIMALS_INCLUDE_ANIMALS_H_20240907

class Animal{
    int* weight;
public:
    Animal() = default;
    Animal(int weight);

    ~Animal();

    virtual float jump() const;

    int* get_weight() const ;
};


class Cat: public Animal{
    char* sound = new char[4]{'M', 'e', 'o', 'w'};
public:
    Cat();
    Cat(int weight);
    ~Cat();

    char* rargh() const;
    
    float jump() const;
};

class Dog: public Animal{
    char* sound = new char[4]{'B', 'a', 'r', 'k'};
public:
    Dog();
    Dog(int weight);
    ~Dog();
    char* rargh() const;

    float jump() const;
};

#endif