#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

typedef struct _docentes_{
  char id_docente[100];
  char nome_completo[100];
}docente;

docente *retornaDocente(int size_docente){
  char *buffer;
  char *bufferHold;
  char arquivo[] = "arquivosTrabalho/docentes.csv";

  buffer = new char [1000];

  docente *docentes;

  docentes = new docente [size_docente];

  bufferHold = buffer;

  int i = 0;

  ifstream fin(arquivo);

  if (fin.is_open()){
    while (!fin.eof()){
      fin.getline(buffer, 1000);

      if (i == size_docente){
        continue;
      }

      char *aux;

      aux = strstr(buffer, ",");
      *aux = '\0';
      strcpy(docentes[i].id_docente, buffer);
      buffer = aux + 1;

      strcpy(docentes[i].nome_completo, buffer);

      i++;

      buffer = bufferHold;
    }
  }
  fin.close();

  return docentes;
}
