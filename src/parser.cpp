#ifndef PARSER_H
#define PARSER_H
#endif

#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void push_vet(vector< vector<int> > * vet) {
    vector<int> aux;
    vet->push_back(aux);
}

int catchInt(string &words) {
    int a;
    std::string s;

    std::istringstream iss(words);
    iss >> s >> a;

    return a;
}

vector< vector<int> > parse(string arquivo) {

    vector< vector<int> > adjacencyList;  // lista de adjascência
    ifstream fp;                          // file pointer
    string line;
    int source;

    fp.open(arquivo);

    if(fp.is_open()) {

        while (getline(fp,line)) {
		    if(line.find("id") != string::npos) push_vet(&adjacencyList);
            else if(line.find("source") != string::npos) source = catchInt(line) - 1;
            else if(line.find("target") != string::npos) adjacencyList[source].push_back(catchInt(line)-1);         
        }
        fp.close();
    }

    return adjacencyList;
}