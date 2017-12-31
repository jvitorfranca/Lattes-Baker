#include<iostream>
#include<string.h>
#include<fstream>

using namespace std;

typedef struct _orientacao_{
  char id_docente[100];
  char id_orientacao[100];
  char tipo_orientacao[100];
  char titulo[500];
  char nome_orientando[100];
  char ano[20];
}orientacao;

orientacao *retornaOrientacao(int size_orientacao, char arquivo[]){
  char *buffer;
  char *bufferHold;
  //char arquivo[] = "orientacao.csv";

  buffer = new char [1000];

  orientacao *orientacoes;

  orientacoes = new orientacao [size_orientacao];

  bufferHold = buffer;

  int i = 0;

  ifstream fin(arquivo);

  if (fin.is_open()){
    fin.getline(buffer, 1000);
    while (!fin.eof()){
      fin.getline(buffer, 1000);

      if (i == size_orientacao - 1){
        continue;
      }

      char *aux;

      aux = strstr(buffer, ",");
      *aux = '\0';
      strcpy(orientacoes[i].id_docente, buffer);
      buffer = aux + 1;

      aux = strstr(buffer, ",\"");
      *aux = '\0';
      strcpy(orientacoes[i].id_orientacao,buffer);
      buffer = aux + 1;

      aux = strstr(buffer, "\",\"");
      aux = aux + 1;
      *aux = '\0';
      strcpy(orientacoes[i].tipo_orientacao, buffer);
      buffer = aux + 1;

      aux = strstr(buffer, "\",\"");
      aux = aux + 1;
      *aux = '\0';
      strcpy(orientacoes[i].titulo, buffer);
      buffer = aux + 1;

      aux = strstr(buffer, "\",");
      aux = aux + 1;
      *aux = '\0';
      strcpy(orientacoes[i].nome_orientando, buffer);
      buffer = aux + 1;

      strcpy(orientacoes[i].ano,buffer);

      i++;

      buffer = bufferHold;
    }
  }
  fin.close();

  return orientacoes;
}
