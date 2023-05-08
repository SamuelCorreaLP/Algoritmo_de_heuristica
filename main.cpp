/*
AED2 Prof. Thiago de Souza Rodrigues
Aluno: Samuel Correa Lucas Pereira
       Tarcísio Batista Prates
Implementação da Heurística construtiva
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "grafo.h"
#include "heuristicaConstrutiva.h"

void addContents(std::ifstream& ff){
    std::string type;
    int xCurrentLine;
    int cityNumber;
    int numberCities;
    ff >> type;
    ff >> numberCities;
    XGrafo* grafo = new XGrafo(numberCities);
    if(type.compare("si") == 0){
        for(int i = 0; i < numberCities; i++){
            for(int j = i; j < numberCities; j++){
                ff >> cityNumber;
                grafo->insereAresta(i, j, cityNumber);
                grafo->insereAresta(j, i, cityNumber);
            }
        }

    } else if(type.compare("pa") == 0) {
        for(int i = 0; i < numberCities; i++){
            for(int j = 0; j <= i; j++){
                ff >> cityNumber;
                grafo->insereAresta(i, j, cityNumber);
                grafo->insereAresta(j, i, cityNumber);
            }
        }

    }
    grafo->imprime();
    HeuristicaConstrutiva heuristica(grafo, numberCities);
    heuristica.imprime();
}

int main (int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "error: Passar como argumento o caminho do arquivo a ser inserido." << std::endl;
		exit(1);
	}
    std::ifstream datafile {argv[1]};
    addContents(datafile);
    datafile.close();
    return 0;
}
