#include <iostream>
#include <string>
#include <dirent.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>
#include <set>
#include <list>

using namespace std;

class Busca {

public:

    Busca();

    // Acessa o set de IndexInvertido
    set<string> Valor();

    // Recebe uma cópia de IndexInvertido
    map<string, set<string>> Index();

    string RemoveCaractereEspecial(string s);

    vector<string> normalizador(vector<string> x);

    void adicionar(string s); // adiciona itens ao indice de IndexInvertido

    void comparador (string nome, string texto, vector<string> termo_buscado);

    void impressao (); 

private:

    map<string, set<string>> IndexInvertido;

};