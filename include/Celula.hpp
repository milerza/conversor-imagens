#ifndef CELULA_H
#define CELULA_H

class Celula{
private:
     int vermelho;
     int verde;
     int azul; 

public:
    Celula();
    Celula(int vermelho, int verde, int azul);
    int rgb_para_cinza();
};


#endif