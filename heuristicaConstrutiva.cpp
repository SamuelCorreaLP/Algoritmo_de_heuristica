#include <iostream>
#include <fstream>
#include <iomanip>
#include "heuristicaConstrutiva.h"
#include "aresta.h"

HeuristicaConstrutiva::HeuristicaConstrutiva (XGrafo* grafo, int tamanho) : m_grafo(grafo), m_tamanho(tamanho) {
    for (int i = 0; i <= m_tamanho; i++) {
        m_verificado.push_back(false);
        m_chave.push_back(-1);
        m_predecessor.push_back(-1);
    }
    this->geraHeuristica();
}

void HeuristicaConstrutiva::geraHeuristica() {
    m_chave[0] = 0; //inicia o ponto zero como a origem
    m_predecessor[0] = 0;
    Aresta* aux = m_grafo->primeiroListaAdj(0); //pega o primeiro vertice
    int chaveMenor = aux->getPeso(); 
    int sucessorMenor = aux->getV2();
    while (aux != NULL) {
        if ((!m_verificado[aux->getV2()]) && ( ( aux->getPeso() < m_chave[aux->getV2()]) || (m_chave[aux->getV2()] < 0) ) ) { //atualiza no vetor de chave e antecessores as arestas com peso menor
            if (aux->getPeso() < chaveMenor) {
                chaveMenor = aux->getPeso();
                sucessorMenor = aux->getV2();
            }
        }
        aux = m_grafo->proxAdj(0); // passa para o proximo adjacente
    }
    std::cout << "Avança 0 para " << sucessorMenor << " com chave " << chaveMenor << std::endl;
    m_chave[sucessorMenor] = chaveMenor;
    m_predecessor[sucessorMenor] = 0;
    m_verificado[0] = true;
    this->geraHeuristicaInterno(sucessorMenor);
}

void HeuristicaConstrutiva::geraHeuristicaInterno(int raiz) {
    Aresta* aux;

    aux = m_grafo->primeiroListaAdj(raiz); //pega o primeiro vertice
    int chaveMenor = 0;
    int sucessorMenor = 0;
    while (aux != NULL) { //permanece no loop ate terminar a lista de adjacencia
        if ((!m_verificado[aux->getV2()]) && ( (aux->getPeso() < m_chave[aux->getV2()]) || (m_chave[aux->getV2()] < 0) ) ) { //atualiza no vetor de chave e antecessores as arestas com peso menor
            if ( (!m_verificado[aux->getV2()]) &&  ( (aux->getPeso() < chaveMenor) || (chaveMenor == 0) ) ) { //dentre os vertices do ponto, procura-se o menor de todos
                chaveMenor = aux->getPeso();
                sucessorMenor = aux->getV2();
            }
        }
        aux = m_grafo->proxAdj(raiz); // passa para o proximo adjacente
    } //depois de atualizar os vetores, avança recursivamente para o ponto com vetor de menor peso
    m_chave[sucessorMenor] = chaveMenor;
    m_predecessor[sucessorMenor] = raiz;
    m_verificado[raiz] = true;
    if (!m_verificado[sucessorMenor] && sucessorMenor >= 0) { //avança apenas para o galho com menor valor, ate que encontre um galho já verificado, que então para a recursividade
        std::cout << "avança de " << raiz << " para " << sucessorMenor << " valor " << chaveMenor << std::endl;
        this->geraHeuristicaInterno(sucessorMenor);
    } else { //atualiza a raiz para o antecessor ser o ultimo elemnto analizado para terminar
        std::cout << "atualiza " << raiz << " para 0 com chave " << m_grafo->peso(0,raiz) << std::endl;
        m_predecessor[0] = raiz;
        m_chave[0] = m_grafo->peso(0,raiz);
    }
}

void HeuristicaConstrutiva::imprime() {
    std::ofstream saida;
    saida.open("saida.txt");
    saida << "           ";
    for (int i = 0; i <= m_tamanho; i++) {
        saida << " " << std::setw(2) << i;
    }
    saida << std::endl;
    saida << "chave:     ";
    for (int i = 0; i <= m_tamanho; i++) {
        saida <<  " " << std::setw(2) << m_chave[i];
    }
    saida << std::endl;
    saida << "Antecessor:";
    for (int i = 0; i <= m_tamanho; i++) {
        saida <<  " " << std::setw(2) << m_predecessor[i];
    }
    saida << std::endl;
    int somaPesos = 0;
    for (int i = 0; i <= m_tamanho; i++) {
        somaPesos = somaPesos + m_chave[i];
    }
    saida <<  "Peso total: "  << somaPesos << std::endl;

    saida.close();
}
