#include "Ppm.hpp"

#include <fstream>

int rgb_para_cinza(int vermelho, int verde, int azul){
    double cinza = 49.0/255.0 * (0.30 * vermelho + 0.59 * verde + 0.11 * azul);
    return (int)cinza;
}

void Ppm::inicializar_matriz_ppm(){
    defineFaseMemLog(0);
    this->celulas = new Celula*[altura];

    for(int i = 0; i< altura; i++) {
        this->celulas[i] = new Celula[largura];
        escreveMemLog((long int)this->celulas[i], sizeof(long int), 0);
    }
}

void Ppm::ler_ppm(std::string imagem_ppm){
    defineFaseMemLog(1);
    std::ifstream inFile;
    std::string verificador, verificador2;

    inFile.open(imagem_ppm.c_str());
    erroAssert(inFile, "Arquivo de entrada inválido!");
    
    inFile >> verificador;
    erroAssert(verificador == "P3", "Formato arquivo inválido!");

    inFile >> this->largura >> this->altura;
    
    inFile >> verificador2;
    erroAssert(verificador2 == "255", "Canal incorreto!");

    this->inicializar_matriz_ppm();
    
    for(int i = 0; i< this->altura; i++){
        for(int j = 0; j < this->largura; j++){
            inFile >> celulas[i][j].vermelho >> celulas[i][j].verde >> celulas[i][j].azul;
            escreveMemLog((int)this->celulas[i][j].vermelho, sizeof(int), 1);
            escreveMemLog((int)this->celulas[i][j].verde, sizeof(int), 1);
            escreveMemLog((int)this->celulas[i][j].azul, sizeof(int), 1);
        }
    }
    

    inFile.close();

}

Pgm * Ppm::converter_ppm_para_pgm(){
    defineFaseMemLog(2);
    Pgm * imagem_cinza = new Pgm(this->largura, this->altura);
    for(int i = 0; i< this->altura; i++){
        for(int j = 0; j < this->largura; j++){
            imagem_cinza->celulas[i][j] = rgb_para_cinza(celulas[i][j].vermelho, celulas[i][j].verde, celulas[i][j].azul);
            escreveMemLog((int)imagem_cinza->celulas[i][j], sizeof(int), 2);
        }
    }
    std::cout << "aloca" << std::endl;
    return imagem_cinza;
}


