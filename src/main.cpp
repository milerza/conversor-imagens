#include "Ppm.hpp"
#include "Pgm.hpp"

#include <iostream>
#include <fstream>
#include <cstring>



int main(int argc, char ** argv){

    std::string caminho_entrada = "bolao.ppm";
    std::string caminho_saida  = "bolao.pgm";
    std::string registro = "log.out";
    bool ativar_memlog = 0;
    
    Pgm * imagem_cinza;
    Ppm * image_colorida = new Ppm();

    for (int i = 0; i < argc; i++){
        if (std::string(argv[i]) == "-i"){
            caminho_entrada = std::string(argv[i + 1]);
        } else if (std::string(argv[i]) == "-o"){
            caminho_saida = std::string(argv[i + 1]);
            std::cout<< caminho_saida;
        } else if (std::string(argv[i]) == "-l"){
            ativar_memlog = 1;
        } else if (std::string(argv[i]) == "-p"){
            registro = std::string(argv[i + 1]);
        }
    }

    // create log file
    std::ofstream arquivoRegistro(registro);
    arquivoRegistro.close();
    char * nomeRegistro = new char[registro.length() + 1];
    std::strcpy(nomeRegistro, registro.c_str());

    iniciaMemLog(nomeRegistro);

    if (ativar_memlog) {
        ativaMemLog();
    } else {
        desativaMemLog();
    }

    image_colorida->ler_ppm(caminho_entrada);
    imagem_cinza = image_colorida->converter_ppm_para_pgm();
    imagem_cinza->escrever_pgm(caminho_saida);

    finalizaMemLog();

    return 0;
}