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

    // Construtor, que cria um IndexInvertido vazio
    Busca();

    // Acessa o set de IndexInvertido
    set<string> Valor();

    // Recebe uma cópia de IndexInvertido
    map<string, set<string>> Index();

    // Apaga os caracteres especiais (acentos, hífens, etc)
    string RemoveCaractereEspecial(string s);

    // Formata todas as palavras de um vector<string>
    vector<string> normalizador(vector<string> x);

    // Adiciona itens ao indice de IndexInvertido
    void adicionar(string s);

    // Compara um "texto" advindo do arquivo com a consulta do usuário em "termo_buscado".
    // Caso todas as palavras da consulta estejam presentes no texto, fazemos a indexação, 
    // colocando o "nome" no set<string> de IndexInvertido.
    void comparador (string nome, string texto, vector<string> termo_buscado);

    // Imprimimos os elementos do set<string> de IndexInvertido.
    void impressao (); 

private:

    map<string, set<string>> IndexInvertido;

};