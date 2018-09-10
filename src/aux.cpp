/*
    Universidade de Brasília
    Instituto de Ciências Exatas
    Departamento de Ciência da Computação¹

    Teoria e Aplicação de Grafos 2018/2

    Gabriel Nunes Rodrigues Fonseca - 16/0006597¹
    Matheus Rodrigues Guimarães     - 15/0141661¹
*/

#ifndef AUX_H
#define AUX_H

#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int degrees(vector< vector<int> > graph) {
    ofstream fp; 
    int sum = 0;
    
    fp.open("../output/degrees.txt");
    fp << "GRAU DOS VÉRTICES:" << endl;
    for(int i = 0; i < graph.size() ; i++) {
        sum += graph[i].size();
        fp << setw(2) << setfill('0') << i+1 <<": " << setw(2) << setfill('0') << graph[i].size() << " grau(s)" << endl;
    }  
    return sum/2;
}

void imprimir(vector< vector<int> >  vet, string local, string header) {
    ofstream fp;

    fp.open(local);
    
    fp << header << endl;
    fp << "( Nº | TAMANHO | VÉRTICES )" << endl;
    for ( std::vector<std::vector<int>>::size_type i = 0; i < vet.size(); i++ ) {
        fp << setw(2) << setfill('0') << i + 1 << " (" << setw(2) << setfill('0') << vet[i].size() << ")" << " -> {";
        for ( std::vector<int>::size_type j = 0; j < vet[i].size(); j++ ) {
            fp << setw(2) << setfill('0') << vet[i][j]+1;
            if(j+1 != vet[i].size()) fp << ", ";             
        }
        fp << "}" << endl;
    }
    fp << endl;       
}

#endif