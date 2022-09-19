#ifndef CELULA_H
#define CELULA_H

class Celula{
private:
     int vermelho;
     int verde;
     int azul; 

public:
    //Celula();
    Celula(int vermelho=0, int verde=0, int azul=0);
    int rgb_para_cinza();
};


#endif