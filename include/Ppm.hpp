#ifndef PPM_H
#define PPM_H

#include <iostream>
#include <istream>
#include "Pgm.hpp"
#include "Celula.hpp"

class Ppm{
private:
    Celula ** celulas;
    int altura;
    int largura; 

private:
    void inicializar_matriz_ppm();
    
public:
    void ler_ppm(std::string imagem_ppm);
    Pgm * converter_ppm_para_pgm();
    ~Ppm();

};

#endif