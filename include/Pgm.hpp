#ifndef PGM_H
#define PGM_H

#include <iostream>
#include "Celula.hpp"

class Pgm{
private:
     int ** celula;
     int altura;
     int largura; 

public:
    void escrever_pgm(std::string imagem_pgm);
    
    ~Pgm();
};


#endif