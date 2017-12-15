#include<iostream>
#include<string.h>
#include<fstream>

using namespace std;

typedef struct _periodicos_{
  char issn[50];
  char nome_periodico[200];
  char area_de_avaliacao[100];
  char estrato_qualis[10];
}periodico;

periodico *retornaPeriodico(int size_periodico){
  char *buffer;
  char *bufferHold;

  char arquivo[] = "arquivosTrabalho/qualis_capes_periodicos.csv";

  buffer = new char [10000];

  periodico *periodicos;

  periodicos = new periodico [size_periodico];

  bufferHold = buffer;

  int i = 0;

  ifstream fin(arquivo);

  if (fin.is_open()){
    fin.getline(buffer, 10000);
    while (!fin.eof()){
      fin.getline(buffer, 10000);

      if (i == size_periodico - 1){
        continue;
      }

      char *aux;

      aux = strstr(buffer, "\",\"");
      aux = aux + 1;
      *aux = '\0';
      strcpy(periodicos[i].issn, buffer);
      buffer = aux + 1;

      aux = strstr(buffer, "\",\"");
      aux = aux + 1;
      *aux = '\0';
      strcpy(periodicos[i].nome_periodico, buffer);
      buffer = aux + 1;

      aux = strstr(buffer, "\",\"");
      aux = aux + 1;
      *aux = '\0';
      strcpy(periodicos[i].area_de_avaliacao, buffer);
      buffer = aux + 1;

      strcpy(periodicos[i].estrato_qualis, buffer);


      i++;

      buffer = bufferHold;

    }
  }
  fin.close();

  return periodicos;
}
