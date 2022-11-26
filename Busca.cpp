#include "Busca.h"

Busca::Busca() {}

string Busca::RemoveCaractereEspecial(string s) {
    
}

vector<string> Busca::normalizador(vector<string> x) {

}


void Busca::adicionar(string s) {
   
}

void Busca::comparador (string nome, string texto, vector<string> termo_buscado) {
    vector <string> achados;
    int count = 0, num = 0;
 
    sort(termo_buscado.begin(), termo_buscado.end());
    unique(termo_buscado.begin(), termo_buscado.end());

    int tam = termo_buscado.size();
    int search = -1;

    for (int i = 0; i < tam; i++) {
        search = texto.find(termo_buscado[i], search + 1);
        if (search != -1) {
            achados.push_back(termo_buscado[i]);
            count++;
            search = -1;
        }
    
}

void Busca::impressao () {
    auto it = IndexInvertido.begin();
    for (auto it1 = (it->second).begin(); it1 != (it->second).end(); it1++++){
        cout << *it1 << endl;
}
