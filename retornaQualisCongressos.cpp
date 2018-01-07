#include<iostream>
#include<string.h>
#include<fstream>
#include "arquivos.h"

using namespace std;

// função retornará um vetor da struct com as informações contidas no arquivo
congresso *retornaCongresso(int size_congresso, char arquivo[]){
  // buffer fará as operações no arquivo
  char *buffer;
  char *bufferHold;

  //char arquivo[] = "qualis_capes_congressos.csv";

  buffer = new char [10000];

  congresso *congressos;

  congressos = new congresso [size_congresso];

  //bufferHold retornará o buffer para a posição inicial
  bufferHold = buffer;

  int i = 0;

  int size_sigla;

  ifstream fin(arquivo);

  // verifica-se se o arquivo foi aberto
  if (fin.is_open()){
    fin.getline(buffer, 10000);
    while (!fin.eof()){
      fin.getline(buffer, 10000);

      buffer += 1;

      // artificio que ignora a linha a mais criada pelo getline
      if (i == size_congresso - 1){
        continue;
      }

      char *aux;

      //aqui são feitas as operações para passar as informações para o vetor da struct
      aux = strstr(buffer,"\",\"");
      *aux = '\0';
      strcpy(congressos[i].nome_congresso,buffer);
      buffer = aux + 3;

      aux = strstr(buffer,"\",\"");
      *aux = '\0';
      strcpy(congressos[i].sigla_congresso,buffer);
      buffer = aux + 3;

      aux = strstr(buffer,"\"");
      *aux = '\0';
      strcpy(congressos[i].estrato_qualis, buffer);

      //retirando a sigla do nome do congresso

      size_sigla = strlen(congressos[i].sigla_congresso) + 3;
      strcpy(buffer,congressos[i].nome_congresso);
      buffer += size_sigla;
      strcpy(congressos[i].nome_congresso,buffer);

      i++;

      buffer = bufferHold;
    }
  }
  fin.close();

  return congressos;
}
