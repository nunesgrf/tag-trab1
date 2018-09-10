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
#include "aglomeracao.cpp"

using namespace std;

void cabecalho() {
    cout << endl;
    cout << "Gabriel Nunes Rodrigues Fonseca - 16/0006597" << endl;
    cout << "Matheus Rodrigues Guimarães     - 15/0141661" << endl;
    cout << endl;
    cout << "VERIFIQUE A PASTA OUTPUT PARA VISUALIZAR OS RESULTADOS" << endl;
    cout << endl;

}
int main() {

    string arquivo = "../gml/karate.gml";         // Arquivo sobre o qual o algoritmo irá trabalhar. 
    vector< vector<int> > graph = parse(arquivo); 
    vector< vector<int> > max;                    // Vetor de cliques maximais.
    vector<int> r,p,x;                            // Vetores auxiliares para Bron-Kerbosch 

    for (int i = 0; i < graph.size(); i++) p.push_back(i); // Carregamento do vetor auxiliar p.
    bronkerboschAlgorithm(&max,graph,r,p,x);               // O resultado obtido está armazenado em @param max.

    degrees(graph); // Cria o arquivo degrees.txt com o grau de cada vértice. Retorna o número de vértices do grafo.
    imprimir(graph,"../output/lista_adjacencia.txt","LISTA DE ADJACENCIA:"); // Imprime um .txt com a lista de adjacência do grafo.
    imprimir(max,"../output/cliques_maximais.txt","CLIQUES_MAXIMAIS:"); // Imprime um .txt com os cliques maximais do grafo.
    mediaCoeficienteAglomeracao(graph,coeficienteAglomeracao(graph)); // Imprime 2 .txt -- 1 com o coeficiente de aglomeração de cada nó e o outro com o coeficiente médio do grafo.

    cabecalho();
}