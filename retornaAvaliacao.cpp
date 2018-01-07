#include<iostream>
#include<string.h>
#include<fstream>
#include<stdlib.h>
#include "arquivos.h"

using namespace std;

// função retornará as informações contidas no arquivo
avaliacao retornaPontuacoes(char regra_avaliacao[]){
  // buffer fará as operações no arquivo
  char *buffer;

  avaliacao regra;

  buffer = new char [100];

  ifstream fin(regra_avaliacao);

  int i = 0;

  // verifica-se se o arquivo foi aberto
  if (fin.is_open()){
    fin.getline(buffer, 100);
    while (!fin.eof()){
      fin.getline(buffer, 100);

      char *aux;

      // contorna a linha a mais retornada pelo getline
      if (i == 22){
        continue;
      }

      // aqui as informações são repassadas para a variavel
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
