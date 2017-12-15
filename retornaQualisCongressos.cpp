#include<iostream>
#include<string.h>
#include<fstream>

using namespace std;

typedef struct _congressos_{
  char nome_congresso[100];
  char sigla_congresso[20];
  char estrato_qualis[10];
}congresso;

congresso *retornaCongresso(int size_congresso){
  char *buffer;
  char *bufferHold;

  char arquivo[] = "arquivosTrabalho/qualis_capes_congressos.csv";

  buffer = new char [10000];

  congresso *congressos;

  congressos = new congresso [size_congresso];

  bufferHold = buffer;

  int i = 0;

  ifstream fin(arquivo);

  if (fin.is_open()){
    fin.getline(buffer, 10000);
    while (!fin.eof()){
      fin.getline(buffer, 10000);

      if (i == size_congresso - 1){
        continue;
      }

      char *aux;

      aux = strstr(buffer, "\",\"");
      aux = aux + 1;
      *aux = '\0';
      strcpy(congressos[i].nome_congresso, buffer);
      buffer = aux + 1;

      aux = strstr(buffer, "\",\"");
      aux = aux + 1;
      *aux = '\0';
      strcpy(congressos[i].sigla_congresso, buffer);
      buffer = aux + 1;

      strcpy(congressos[i].estrato_qualis, buffer);

      i++;

      buffer = bufferHold;
    }
  }
  fin.close();

  return congressos;
}
