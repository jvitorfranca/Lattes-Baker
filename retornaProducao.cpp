#include<iostream>
#include<string.h>
#include<fstream>
#include<stdlib.h>
#include "arquivos.h"

using namespace std;

//função que retornará um vetor da estrutura com todas as informações contidas no arquivo
producao *retornaProducoes(int size_producao, char arquivo[]){
  // buffer fará as operações no arquivo
  char *buffer;
  char *bufferHold;

  buffer = new char [10000];

  producao *producoes;

  producoes = new producao [size_producao];

  // bufferHold retornará o buffer para a posição inicial ao final do laço
  bufferHold = buffer;

  int i = 0;

  // abre-se o arquivo
  ifstream fin(arquivo);

  if (fin.is_open()){
    // fin.getline(buffer, 10000);
    while (!fin.eof()){
      fin.getline(buffer, 10000);

      if (i == size_producao - 1){
        continue;
      }

      char *aux;

        aux = strstr(buffer, ",");
        *aux = '\0';
        strcpy(producoes[i].id_docente, buffer);
        buffer = aux + 2;

        aux = strstr(buffer, ",\"");
        *aux = '\0';
        strcpy(producoes[i].id_producao, buffer);
        buffer = aux + 1;

        aux = strstr(buffer, "\",\"");
        aux = aux + 1;
        *aux = '\0';
        strcpy(producoes[i].tipo_producao, buffer);
        buffer = aux + 1;

        // artifício utilizado para colher os tipos de issn, pois alguns são apenas aspas
        if((aux + 3) == strstr(buffer, "\",\"")){
          strcpy(producoes[i].issn, "\"\"");
          buffer = aux + 6;
        } else {
          aux = strstr(buffer, "\",\"");
          aux = aux + 1;
          *aux = '\0';
          strcpy(producoes[i].issn, buffer);
          buffer = aux + 2;
        }

        aux = strstr(buffer, "\",\"");
        aux = aux + 1;
        *aux = '\0';
        strcpy(producoes[i].titulo, buffer);
        buffer = aux + 2;

        aux = strstr(buffer, "\",");
        // aux = aux + 1;
        *aux = '\0';
        strcpy(producoes[i].local, buffer);
        buffer = aux + 2;

        producoes[i].ano_trabalho = atoi(buffer);

      i++;

      buffer = bufferHold;
    }
  }
  fin.close();

  return producoes;
}
