#ifndef PGM_H
#define PGM_H

#include <iostream>
#include "Celula.hpp"

class Pgm{
private:
     int altura;
     int largura; 
     
public:
    int ** celulas;

public:
    Pgm(int largura, int altura);
    void escrever_pgm(std::string imagem_pgm);
};


#endif