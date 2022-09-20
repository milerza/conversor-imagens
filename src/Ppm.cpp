#include "Ppm.hpp"

#include <fstream>

int rgb_para_cinza(int vermelho, int verde, int azul){
    double cinza = 49.0/255.0 * (0.30 * vermelho + 0.59 * verde + 0.11 * azul);
    return (int)cinza;
}

void Ppm::inicializar_matriz_ppm(){
    /* if((this->altura && this->largura) <= 0){
        throw;
    }
    */
    this->celulas = new Celula*[altura];

    for(int i = 0; i< altura; i++) 
    {
        this->celulas[i] = new Celula[largura];
        
    }
}

void Ppm::ler_ppm(std::string imagem_ppm){
    std::ifstream inFile;
    std::string verificador, verificador2;

    inFile.open(imagem_ppm.c_str());
    
    inFile >> verificador;

    inFile >> this->largura >> this->altura;

    inFile >> verificador2;

    /*if(verificador != "255"){
        return;
    }*/

    this->inicializar_matriz_ppm();
    
    for(int i = 0; i< this->altura; i++){
        for(int j = 0; j < this->largura; j++){
            inFile >> celulas[i][j].vermelho >> celulas[i][j].verde >> celulas[i][j].azul;
        }
    }
    

    inFile.close();

}

Pgm * Ppm::converter_ppm_para_pgm(){
    Pgm * imagem_cinza = new Pgm(this->largura, this->altura);
    for(int i = 0; i< this->altura; i++){
        for(int j = 0; j < this->largura; j++){
            imagem_cinza->celulas[i][j] = rgb_para_cinza(celulas[i][j].vermelho, celulas[i][j].verde, celulas[i][j].azul);
        }
    }
    std::cout << "aloca" << std::endl;
    return imagem_cinza;
}


