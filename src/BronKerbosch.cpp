/*
    Universidade de Brasília
    Instituto de Ciências Exatas
    Departamento de Ciência da Computação¹

    Teoria e Aplicação de Grafos 2018/2

    Gabriel Nunes Rodrigues Fonseca - 16/0006597¹
    Matheus Rodrigues Guimarães     - 15/0141661¹
*/

#ifndef BRONKERBOSCH_H
#define BRONKERBOSCH_H
#endif

#include <vector>
#include <bits/stdc++.h>

using namespace std; 

void bronkerboschAlgorithm(vector< vector<int> > * max, vector<vector< int> > graph, vector<int> r, vector<int> p, vector<int> x) {

    vector<int> p_aux = p;

    if(p.empty() && x.empty()) (*max).push_back(r);

    for(int i : p_aux) {

        vector<int> r_aux = r;
        vector<int> intersec_p = {}, intersec_x = {};

        for(int j: graph[i]) {

            for(int k : p) {
                if(k == j) intersec_p.push_back(j);
            }

            for(int l : x) {
                if(l == j) intersec_x.push_back(j);
            }

        }
        
        r_aux.push_back(i);
        bronkerboschAlgorithm(max,graph,r_aux,intersec_p,intersec_x);
        p.erase(remove(p.begin(),p.end(),i),p.end());
        x.push_back(i);
    }

}