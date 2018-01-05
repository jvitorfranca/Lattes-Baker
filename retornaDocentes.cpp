#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

//estrutura que receberá as informações do docente
typedef struct _docentes_{
  char id_docente[100];
  char nome_completo[100];
}docente;

docente *retornaDocente(int size_docente, char arquivo[]){
  //buffer que receberá as informações do arquivo
  char *buffer;
  char *bufferHold;

  buffer = new char [1000];

  docente *docentes;

  docentes = new docente [size_docente];

  //bufferHold retornará o buffer para a posição original após rodar o laço
  bufferHold = buffer;

  int i = 0;

  //abre-se o arquivo e verifica-se se o mesmo foi aberto de fato
  ifstream fin(arquivo);

  if (fin.is_open()){
    while (!fin.eof()){
      fin.getline(buffer, 1000);

      //a função fin.getline retorna uma linha a mais, logo esse artifício faz com que isso não aconteça
      if (i == size_docente){
        continue;
      }

      char *aux;

      //aqui as informações são repassadas para a estrutura
      aux = strstr(buffer, ",");
      *aux = '\0';
      strcpy(docentes[i].id_docente, buffer);
      buffer = aux + 1;

      strcpy(docentes[i].nome_completo, buffer);

      i++;

      //buffer retorna a sua posição original
      buffer = bufferHold;
    }
  }
  fin.close();

  return docentes;
}
