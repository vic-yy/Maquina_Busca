#include <iostream>
#include <dirent.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>
#include <set>
#include <list>

using namespace std;

map<string, set<string>> IndexInvertido;
map<string, set<string> >::iterator iter_;
set<string>::iterator iterator_;
set<string>arq_nome;
vector<string>words;

string removeSpecialCharacter(string s)
{
    
    for (int i = 0; i < s.size(); i++) {
         
        
        if (s[i] < 'A' || s[i] > 'Z' &&
            s[i] < 'a' || s[i] > 'z' )
        {  
            // erase function to erase
            // the character
            s.erase(i, 1);
            i--;
        }
    }
    return s;
}


vector<string> normalizador(vector<string> x){
    string termos;
 
    vector <string> formatado;



for (int i = 0 ; i < x.size(); i++){
    termos = x[i];
        termos = removeSpecialCharacter(termos);
        termos += ' ';
        formatado.push_back(termos);
    }


   
    
    for (int j = 0; j <formatado.size(); j++){
        for_each(formatado[j].begin(), formatado[j].end(), [](char & c){
         c = ::tolower(c);
         });
         
        
    }
    
    return formatado;

}




void comparador (string nome, string texto, vector<string> termo_buscado){

    
  vector <string> achados;
 
  int count = 0, num = 0;
  string consulta;
  list<string> numero;

    sort(termo_buscado.begin(), termo_buscado.end());
    unique(termo_buscado.begin(), termo_buscado.end());


  int tam = termo_buscado.size();
  int i = 0;
  int search = -1;
  for (i = 0; i < tam; i++)
  {
    search = texto.find(termo_buscado[i], search + 1);
    if (search != -1)
    {
      achados.push_back(termo_buscado[i]);
      count++;
      search = -1;

    }
  }

  if (count == tam && tam != 0)
  {
    arq_nome.insert(nome); 
  }


}
  



using namespace std;
int main()
{
  

    

    vector <string> filename;
    DIR *folder;
    struct dirent *entry;
    int files = 0;
    // auto iterator_ = iter_->second.begin();
    vector<string>palavras_temp;
    int tam;


    string termos;
    map <string, string> palavras;
    vector <string> formatado;




    
    //A partir daqui receberemos a consulta do usuário
    vector<string> consulta;
    while (cin>>termos && termos != "fim" ){
        consulta.push_back(termos);
    }
    //Normalizando a stirng de consulta
    consulta = normalizador(consulta);


    //Adicionando as palavras a serem consultadas como index de IndexInvertido;
    for (int j = 0; j <consulta.size();++j){
        IndexInvertido[consulta[j]];
    }


    // for (auto it_teste = IndexInvertido.begin(); it_teste!= IndexInvertido.end(); it_teste++)
    // for (auto it_teste2 = it_teste->first.begin(); it_teste2 != it_teste->first.end(); it_teste2++)
    // cout << *it_teste2;


    folder = opendir("./documentos/");  //Aqui eu abro o diretório com os documentos txt
    if(folder == NULL)
    {
        perror("Unable to read directory");
        return(1);
    }

    while( (entry=readdir(folder)) )    //Aqui eu leio o nome de todos os documentos no diretório
    {
        files++;
        filename.push_back(entry->d_name);  //Inserindo o nome dos documentos no vetor "filename"
    }
    

    closedir(folder);


    

    //Iterando com os nomes dos documentos
    for (auto it = filename.begin(); it!= filename.end(); it++){

    ifstream inFile;
    //Escolhendo o caminho de todos documentos que serão abertos
    inFile.open("./documentos/"+*it, ios::in);


    if(!inFile){
        cout << "arquivo nao pode ser aberto";
        abort();
   }
    
    
    list<string> palavras_2;
    //Passando todas as palavras por documento para o vetor palavras_temp
   while (inFile >> termos){
    palavras_temp.push_back(termos + ' ');
    }


    //Normalizando o vetor palavras_temp
    palavras_temp = normalizador(palavras_temp);

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
    comparador(*it, palavras[*it],consulta);

    tam = 0;


    }


    for (auto it = arq_nome.begin(); it!= arq_nome.end(); it++){
    cout << *it << endl;
    }

    


    return(0);
}
