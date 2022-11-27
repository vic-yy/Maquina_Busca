#include "Busca.h"

Busca::Busca() {}

set<string> Busca::Valor() {
    auto it = IndexInvertido.begin();
    return it->second;
}

map<string, set<string>> Busca::Index() {
    return IndexInvertido;
}

string Busca::RemoveCaractereEspecial(string s) {
    for (int i = 0; i < s.size(); i++) {
        // Encontrando o caractere cujo valor na tabela ASCII foge do intervalo
        
        if (s[i] < 'A' || s[i] > 'Z' && s[i] < 'a' || s[i] > 'z' ) {  
          if(s[i]!='0' && s[i]!='1' && s[i]!='2'&& s[i]!='3'&& s[i]!='4'&& s[i]!='5'&& s[i]!='6'&& s[i]!='7'&& s[i]!='8'&& s[i]!='9') {
            // Apaga o caractere
            s.erase(i, 1);
            i--;
          }
        }
    }
    return s;    
}

vector<string> Busca::normalizador(vector<string> x) {
    string termos;
    vector<string> formatado;

    for (int i = 0 ; i < x.size(); i++){
        termos = x[i];
        termos = RemoveCaractereEspecial(termos);
        termos += ' ';
        formatado.push_back(termos);
    }

    for (int j = 0; j <formatado.size(); j++) {
        for_each(formatado[j].begin(), formatado[j].end(), [](char & c) 
        {c = ::tolower(c);} );
    }
    
    return formatado;
}


void Busca::adicionar(string s) {
   IndexInvertido[s];
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

    auto ite = IndexInvertido.begin(); 
    if (count == tam && tam != 0) {
        (ite->second).insert(nome); //Indexação
    }
}

void Busca::impressao () {
    auto it = IndexInvertido.begin();
    for (auto it1 = (it->second).begin(); it1 != (it->second).end(); it1++++){
        cout << *it1 << endl;
    }
}
