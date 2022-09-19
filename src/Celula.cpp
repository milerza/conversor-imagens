#include "Celula.hpp"

Celula::Celula(int vermelho, int verde, int azul){
    this->vermelho = vermelho;
    this->verde = vermelho;
    this->azul = vermelho;
}

int Celula::rgb_para_cinza(){
    double cinza = 49/255 * 
                   (0.30 * this->vermelho + 
                   0.59 * this->vermelho + 
                   0.11 * this->vermelho);
    return (int)cinza;
}