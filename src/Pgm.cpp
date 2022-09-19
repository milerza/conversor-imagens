#include "Pgm.hpp"

#include <fstream>

Pgm::Pgm(int largura, int altura){
    this->largura = largura;
    this->altura = altura;

    if((this->altura && this->largura) <= 0){
        throw;
    }

    this->celulas = new int*[altura];

    for(int i = 0; i< altura; ++i) 
    {
        celulas[i] = new int[largura];
    }
}

void Pgm::escrever_pgm(std::string imagem_pgm){
    std::ofstream inFile;

    inFile.open(imagem_pgm.c_str());
    
    inFile << "P2";

    inFile << this->largura << " " << this->altura << "\n";

    for(int i = 0; i< this->altura; i++){
        for(int j = 0; j < this->largura; i++){
            inFile << celulas[i][j] << " ";
        }
        inFile << "\n";
    }
}

Pgm::~Pgm(){

}