#ifndef ANIMALS_INCLUDE_ANIMALS_H_20240907
#define ANIMALS_INCLUDE_ANIMALS_H_20240907

class Animal{
    char* sound;
    int weight;
    int type_multiplier;
public:
    Animal() = default;
    
    Animal(int weight): weight(weight){}

    Animal(char* sound, int weight, double type_multiplier=1): sound(sound), weight(weight), type_multiplier(type_multiplier){}

    ~Animal(){
        delete[] sound;
    }

    char* rargh(){
        return sound;
    }
    float jump(){
        float jump_height = weight * type_multiplier;
        
        return jump_height;
    }
};


class Cat: public Animal{
    char* sound = new char[] {'M', 'e', 'o', 'w'};
public:
    Cat(): Animal(sound, 1, 3){
    }

    Cat(int weight): Animal(sound, weight, 3){
    }

};

class Dog: public Animal{
    char* sound = new char[] {'B', 'a', 'r', 'k'};
public:
    Dog(): Animal(sound, 5){
    }

    Dog(int weight): Animal(sound, weight, 1.5){}

};

#endif