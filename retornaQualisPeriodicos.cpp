#include<iostream>
#include<string.h>
#include<fstream>
#include "arquivos.h"

using namespace std;

// função retornará um vetor da estrutura
periodico *retornaPeriodico(int size_periodico, char arquivo[]){
  // buffer fará as operações no arquivo
  char *buffer;
  char *bufferHold;

  buffer = new char [10000];

  periodico *periodicos;

  periodicos = new periodico [size_periodico];

  //bufferHold retornará o buffer para a posição original
  bufferHold = buffer;

  int i = 0;

  ifstream fin(arquivo);

  // verifica-se se o arquivo foi aberto
  if (fin.is_open()){
    fin.getline(buffer, 10000);
    while (!fin.eof()){
      fin.getline(buffer, 10000);

      // ignorando a linha a mais retornada pela função getline
      if (i == size_periodico - 1){
        continue;
      }

      char *aux;

      // aqui as informações são passadas para a struct
      aux = strstr(buffer, "\",\"");
      aux = aux + 1;
      *aux = '\0';
      strcpy(periodicos[i].issn, buffer);
      buffer = aux + 1;

      aux = strstr(buffer, "\",\"");
      aux = aux + 1;
      *aux = '\0';
      strcpy(periodicos[i].nome_periodico, buffer);
      buffer = aux + 2;

      aux = strstr(buffer, "\",\"");
      // aux = aux + 1;
      *aux = '\0';
      strcpy(periodicos[i].area_de_avaliacao, buffer);
      buffer = aux + 3;

      aux=strstr(buffer,"\"");
      *aux= '\0';
      strcpy(periodicos[i].estrato_qualis, buffer);

      // cout << periodicos[i].estrato_qualis << endl;

      i++;

      buffer = bufferHold;

    }
  }
  fin.close();

  return periodicos;
}
