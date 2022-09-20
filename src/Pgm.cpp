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
    defineFaseMemLog(3);
    std::ofstream inFile;

    inFile.open(imagem_pgm.c_str());
    
    inFile << "P2" << "\n";
    inFile << this->largura <<" "<< this->altura<< "\n";
    inFile << "49" << "\n";

    for(int i = 0; i< this->altura; i++){
        for(int j = 0; j < this->largura; j++){
            
            if(j < this->largura - 1){
                inFile << this->celulas[i][j] << " ";
            } else{
                inFile << this->celulas[i][j];
            }
            leMemLog((int)this->celulas[i][j], sizeof(int), 3);
        }
        inFile << "\n";
    }
}
