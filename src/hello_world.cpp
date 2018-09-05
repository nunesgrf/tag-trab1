#include <vector>
#include <iostream>
#include "parser.cpp"
#include "aux.cpp"

using namespace std;

int main() {

    string arquivo = "../gml/karate.gml";
    vector< vector<int> > graph = parse(arquivo);

    imprimirgrafo(graph);
    cout << "SOMA: " << RelSum(graph) << endl;
}