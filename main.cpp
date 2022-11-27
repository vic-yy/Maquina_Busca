#include "Busca.h"

int main() {
    vector <string> filename;
    DIR *folder;
    struct dirent *entry;
    int files = 0;
    
    vector<string> palavras_temp;
    int tam;
    string termos;
    map <string, string> palavras;

    Busca b;

    //A partir daqui receberemos a consulta do usuário
    vector<string> consulta;
    while (cin>>termos && termos != "q" ) {
        consulta.push_back(termos);
    }
    //Normalizando a stirng de consulta
    consulta = b.normalizador(consulta);


    //Adicionando as palavras a serem consultadas como index de IndexInvertido;
    for (int j = 0; j <consulta.size();++j){
        b.adicionar(consulta[j]);
    }

    folder = opendir("./documentos/");  //Aqui eu abro o diretório com os documentos txt
    if(folder == NULL) {
        perror("Unable to read directory");
        return 1;
    }

    while(entry=readdir(folder))    //Aqui eu leio o nome de todos os documentos no diretório
    {
        files++;
        filename.push_back(entry->d_name);  //Inserindo o nome dos documentos no vetor "filename"
    }
    
    closedir(folder);

    //Iterando com os nomes dos documentos
    for (auto it = filename.begin(); it!= filename.end(); it++) {

        ifstream inFile;
        //Escolhendo o caminho de todos documentos que serão abertos
        inFile.open("./documentos/"+*it, ios::in);


        if(!inFile){
            cout << "arquivo nao pode ser aberto";
            abort();
        }
    
        //Passando todas as palavras por documento para o vetor palavras_temp
        while (inFile >> termos) {
            palavras_temp.push_back(termos + ' ');
        }


        //Normalizando o vetor palavras_temp
        palavras_temp = b.normalizador(palavras_temp);

        sort(palavras_temp.begin(), palavras_temp.end());
        unique(palavras_temp.begin(), palavras_temp.end());

    
        //Pegando o tamanho do vetor palavra_temp para usar na função "comparador"
        tam = palavras_temp.size();

        //Inserindo as palavras em palavras_temp como string do map palavras, que tem como index o nome de cada documento
        for (int i = 0; i < tam; ++ i){
            palavras[*it] += palavras_temp[i];
        }

        //limpando palavras_temp para podermos usar no próximo arquivo
        palavras_temp.clear();
    
        //Iterando sobre o vetor palavras, para armazenar em second de IndexInvertido os nomes dos arquivos que contém as palavras consultadas
        b.comparador(*it, palavras[*it],consulta);
        tam = 0;
    }
    
    b.impressao();
    return 0;
}