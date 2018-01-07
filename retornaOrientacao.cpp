#include<iostream>
#include<string.h>
#include<fstream>
#include "arquivos.h"

using namespace std;

/*
  função recebe o tamanho do arquivo, o nome do mesmo
  e retorna um vetor da estrutura com as informações
*/
orientacao *retornaOrientacao(int size_orientacao, char arquivo[]){
  //buffer que fará as operações no arquivo
  char *buffer;
  char *bufferHold;
  //char arquivo[] = "orientacao.csv";

  buffer = new char [1000];

  orientacao *orientacoes;

  orientacoes = new orientacao [size_orientacao];

  //bufferHold recebe buffer para no final do laço retorná-lo a posição original
  bufferHold = buffer;

  int i = 0;

  //abre-se o arquivo e verifica-se se o mesmo está aberto
  ifstream fin(arquivo);

  if (fin.is_open()){
    fin.getline(buffer, 1000);
    while (!fin.eof()){
      fin.getline(buffer, 1000);

      //artificio contorna a linha a mais retornada pela função getline
      if (i == size_orientacao - 1){
        continue;
      }

      // aqui as informações são repassadas para o vetor da estrutura
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
