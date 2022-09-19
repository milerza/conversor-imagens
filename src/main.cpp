#include "Ppm.hpp"
#include "Pgm.hpp"
#include <iostream>

int main(int argc, char ** argv){
    char command;
    char opcao;

    std::string caminho_imagem_ppm;
    std::string caminho_imagem_pgm;

    Pgm * imagem_cinza;
    Ppm * image_colorida = new Ppm();
    

    image_colorida->ler_ppm(caminho_imagem_ppm);
    imagem_cinza = image_colorida->converter_ppm_para_pgm();
    imagem_cinza->escrever_pgm(caminho_imagem_pgm);

    /*while (std::cin >> command) {
        switch (command){
            case '-i':{
                std::cin >> caminho_imagem_ppm;
                break;
            }
            case '-o':{           
                break;
                std::cout << caminho_imagem_ppm << std::endl;
                break;
            }
            case '-p':{
                std::cout << "imprimir desempenho" << std::endl;
                break;

            }
            case '-l':{ 
                std::cout << "deseja registrar o acesso a memória?(s/n):" << std::endl;
                std::cin >> opcao;
                if(opcao =='s'){
                    //registrar acesso;
                }  
                else if (opcao =='n'){

                }
                break;
            }     
        } 

    }*/
    
    return 0;
}