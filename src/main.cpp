#include "Ppm.hpp"
#include "Pgm.hpp"
#include <iostream>

int main(int argc, char ** argv){
    std::string caminho_imagem_ppm;
    std::string caminho_imagem_pgm;
    
    Ppm * image_colorida = new(Ppm);
    Pgm * imagem_cinza = new(Pgm);

    image_colorida->ler_ppm(caminho_imagem_ppm);
    imagem_cinza = image_colorida->converter_ppm_para_pgm();
    imagem_cinza->escrever_pgm(caminho_imagem_pgm);
}