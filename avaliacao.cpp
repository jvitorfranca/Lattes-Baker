#include<iostream>
#include<string.h>
#include<fstream>

using namespace std;

typedef struct _avaliacao_{
    char area_de_avaliacao[50];
    int pontuacao[22];
}avaliacao;

avaliacao retornaPontuacoes(char regra_avaliacao[]){
  char *buffer;
  avaliacao regra;

  buffer = new char [100];

  ifstream fin(regra_avaliacao);

  int i = 0;

  if (fin.is_open()){
    fin.getline(buffer, 100);
    while (!fin.eof()){
      fin.getline(buffer, 100);

      char *aux;

      if (i == 22){
        continue;
      }

      aux = strstr(buffer, ":");
      if (aux == NULL){
        strcpy(regra.area_de_avaliacao, buffer);
      } else {
        buffer = aux + 1;
        regra.pontuacao[i] = atoi(buffer);
        i++;
      }
    }
  }

  fin.close();

  return regra;
}
