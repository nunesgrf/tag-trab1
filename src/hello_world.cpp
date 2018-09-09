/*
    Universidade de Brasília
    Instituto de Ciências Exatas
    Departamento de Ciência da Computação¹

    Teoria e Aplicação de Grafos 2018/2

    Gabriel Nunes Rodrigues Fonseca - 16/0006597¹
    Matheus Rodrigues Guimarães     - 15/0141661¹
*/

#include <bits/stdc++.h>
#include "parser.cpp"
#include "aux.cpp"
#include "BronKerbosch.cpp"

using namespace std;

int main() {

    string arquivo = "../gml/karate.gml";         // Arquivo sobre o qual o algoritmo irá trabalhar. 
    vector< vector<int> > graph = parse(arquivo); 
    vector< vector<int> > max;                    // Vetor de cliques maximais.
    vector<int> r,p,x;                            // Vetores auxiliares para Bron-Kerbosch 

    for (int i = 0; i < graph.size(); i++) p.push_back(i); // Carregamento do vetor auxiliar p.
    bronkerboschAlgorithm(&max,graph,r,p,x);               // O resultado obtido está armazenado em @param max.

    degrees(graph); // Cria o arquivo degrees.txt com o grau de cada vértice. Retorna o número de vértices do grafo.
    imprimir(max,"cliques"); // Cria um .txt com o nome do segundo parâmetro com os valores da tabela passada no primeiro parâmetro.
}