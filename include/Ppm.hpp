#ifndef PPM_H
#define PPM_H

#include <iostream>
#include "Celula.hpp"

class Ppm{
private:
     Celula ** celula;
     int altura;
     int largura; 

public:
    void ler_ppm(std::string imagem_ppm);
    Pgm * converter_ppm_para_pgm();
    ~Ppm();
};


#endif