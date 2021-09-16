#ifndef _HPP_ANIMAL
#define _HPP_ANIMAL

#include <iostream>

using namespace std;

struct Animal {
    int codigo;
    int idade;
    float peso;

    Animal() { /// Construtor
        codigo = 0;
        idade = 0;
        peso = 0.0f;
    }

    Animal(int cod, int ida, float pes) { /// Construtor
        codigo = cod;
        idade = ida;
        peso = pes;
    }
};

#endif /// _HPP_ANIMAL