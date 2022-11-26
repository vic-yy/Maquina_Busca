#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Busca.cpp"


TEST_CASE("Busca::Busca()") {
    Busca b;
    std::map<string, set<string>> i;
    CHECK(i.size() == 0);
}

TEST_CASE("string Busca::RemoveCaractereEspecial(string s)") {
    // Testa se a função retorna a palavra sem caracteres especiais
    Busca b;
    string s;

    //CASO 1: Palavra sem nenhum caractere especial
    s = "string";
    s = b.RemoveCaractereEspecial(s);
    CHECK(s == "string");
    s.clear();
    //CASO 2: Palavra com um caractere especial
    s = "str-ing";
    s = b.RemoveCaractereEspecial(s);
    CHECK(s == "string");
    s.clear();
    //CASO 3: Palavra com vários caracteres especiais
    s = "st-riín-g";
    s = b.RemoveCaractereEspecial(s);
    CHECK(s == "string");
}

TEST_CASE("vector<string> Busca::normalizador(vector<string> x)") {
    // Testa se a função normaliza um vector de strings
    Busca b;
    vector<string> v = {"string", "STRING", "STR-ING", "STRIÍn-g"};

    v = b.normalizador(v);

    for(int i=0; i<4; i++) {
        CHECK(v[i] == "string "); // O normalizador coloca um espaço depois da palavra
    }
}

TEST_CASE("void Busca::comparador (string nome, string texto, vector<string> termo_buscado)") {
    // Testa se a função está comparando adequadamente as palavras de um arquivo com uma busca
    // e então adicionando no IndexInvertido.
    vector<string> v = {"string ", "teste "};
    string t; // que irá receber uma simulação de consulta
    string s = "arquivo.txt";
    string comparadora = "";
    set<string> c;
    
    //CASO 1: O arquivo tem ambas as palavras presentes
    Busca b1;
    b1.adicionar("caso1");
    t = "Estamos em um teste de string ";
    b1.comparador(s, t, v);
    c = b1.Valor();
    auto it1 = c.begin();
    comparadora = *it1;
    CHECK(comparadora == "arquivo.txt");
    t.clear(); comparadora.clear(); c.clear();
    
    //CASO 2: A consulta tem uma palavra presente, mas a outra não
    Busca b2;
    b2.adicionar("caso2");
    t = "Temos apenas o teste ";
    b2.comparador(s, t, v);
    c = b2.Valor();
    CHECK(c.size() == 0);
    t.clear(); c.clear();

    //CASO 3: A consulta não tem nenhuma palavra presente
    Busca b3;
    b3.adicionar("caso3");
    t = "Não temos nenhum ";
    b3.comparador(s, t, v);
    c = b3.Valor();
    CHECK(c.size() == 0);
}