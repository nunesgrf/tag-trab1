/*
    Universidade de Brasília
    Instituto de Ciências Exatas
    Departamento de Ciência da Computação¹

    Teoria e Aplicação de Grafos 2018/2

    Gabriel Nunes Rodrigues Fonseca - 16/0006597¹
    Matheus Rodrigues Guimarães     - 15/0141661¹
*/

#ifndef AGLOMERACAO_H
#define AGLOMERACAO_H

#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

double coeficienteAglomeracao(vector< vector<int> > graph) {

    ofstream fp; 
    int qtdVizinhos = 0;
    int triangulosPossiveis = 0;
    double somaCoeficientes = 0;
    double coeficiente = 0;

    fp.open("../output/coeficientes.txt");
    fp << "COEFICIENTES DE AGLOMERAÇÃO:" << endl;
    
    for(int i = 0; i < graph.size(); i++) {
        double link = 0;
        vector<int> vertice = graph[i];
        qtdVizinhos = vertice.size();
        triangulosPossiveis = (qtdVizinhos * (qtdVizinhos - 1))/2;

        for(int k = 0; k < qtdVizinhos; k++){
            int vizinho = vertice.at(k);

            for(int j = 0; j < qtdVizinhos; j++){
                int adjVizinho = vertice.at(j);
                for(int z = 0; z < graph[vizinho].size(); z++){
                    if(adjVizinho == graph[vizinho].at(z)){
                        link += 0.5;
                    }
                }
            }
        }
        if(qtdVizinhos > 1){
            coeficiente = (2*link)/(qtdVizinhos * (qtdVizinhos - 1));
        }
        else{
            coeficiente = 0;
        }
        somaCoeficientes += coeficiente;

        fp << setw(2) << setfill('0') << i+1 << ": " << coeficiente << setprecision(4) << setfill('0') << endl;
    }
    fp.close();
    return somaCoeficientes;
}


int mediaCoeficienteAglomeracao(vector< vector<int> > graph, double somaCoeficientes) {
    ofstream fp;

    fp.open("../output/coeficiente_medio.txt"); 
    fp << "COEFICIENTE MÉDIA DE AGLOMERAÇÃO DO GRAFO: " << 1/(graph.size()*somaCoeficientes) << endl;   
    fp.close();
    return 1/(graph.size()*somaCoeficientes);
}

#endif