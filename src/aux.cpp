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
    for(int i = 0; i < graph.size() ; i++) {
        sum += graph[i].size();
        fp << "Vértice " << i+1 <<": " << graph[i].size() << " grau(s)" << endl;
    }  
    return sum/2;
}

void imprimir(vector< vector<int> >  vet, string word) {
    ofstream fp;

    fp.open("../output/" + word + ".txt");

    for ( std::vector<std::vector<int>>::size_type i = 0; i < vet.size(); i++ ) {
        fp << endl << word << " " << i + 1 << ": " << endl;
        for ( std::vector<int>::size_type j = 0; j < vet[i].size(); j++ ) {
            fp << vet[i][j]+1 << ' ';             
        }
        fp << endl;
    }
    fp << endl;       
}

#endif