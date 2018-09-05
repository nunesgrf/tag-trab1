#ifndef AUX_H
#define AUX_H
#endif

#include <vector>
#include <iostream>

using namespace std;

int RelSum(vector< vector<int> > vet) {
    int sum = 0;
    for(int i = 0; i <= 33; i++) sum += vet[i].size();
    
    return sum;
}

void imprimirgrafo(vector< vector<int> >  vet) {
    for ( std::vector<std::vector<int>>::size_type i = 0; i < vet.size(); i++ ) {
        cout << "\nNó " << i + 1 << ": " << endl;
        for ( std::vector<int>::size_type j = 0; j < vet[i].size(); j++ ) {
            std::cout << vet[i][j]+1 << ' ';             
        }
        cout << endl;
    }
    cout << endl;       
}