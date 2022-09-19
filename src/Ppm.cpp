#include "Ppm.hpp"

#include <fstream>

void Ppm::inicializar_matriz_ppm(){
    /* if((this->altura && this->largura) <= 0){
        throw;
    }
    */
    this->celulas = new Celula*[altura];

    for(int i = 0; i< altura; ++i) 
    {
        this->celulas[i] = new Celula[largura];
    }
}

void Ppm::ler_ppm(std::string imagem_ppm){
    std::ifstream inFile;
    std::string verificador;
    int vermelho, verde, azul;

    inFile.open(imagem_ppm.c_str());
    
    inFile >> verificador;
    if(verificador != "P3"){
        return;
    }

    inFile >> verificador;
    if(verificador != "255"){
        return;
    }

    inFile >> this->largura >> this->altura;

    for(int i = 0; i< this->altura; i++){
        for(int j = 0; j < this->largura; i++){
            inFile >> vermelho >> verde >> azul;
            celulas[i][j] = Celula(vermelho, verde,azul);
        }
    }

}

Pgm * Ppm::converter_ppm_para_pgm(){
    Pgm * imagem_cinza = new Pgm(this->largura, this->altura);
    for(int i = 0; i< this->altura; i++){
        for(int j = 0; j < this->largura; i++){
            imagem_cinza->celulas[i][j] = this->celulas[i][j].rgb_para_cinza();
        }
    }
    return imagem_cinza;
}

Ppm::~Ppm(){}

