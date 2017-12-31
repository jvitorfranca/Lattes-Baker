#include<iostream>
#include<string.h>
#include<fstream>

using namespace std;

typedef struct _congressos_{
  char nome_congresso[100];
  char sigla_congresso[20];
  char estrato_qualis[10];
}congresso;

congresso *retornaCongresso(int size_congresso, char arquivo[]){
  char *buffer;
  char *bufferHold;

  //char arquivo[] = "qualis_capes_congressos.csv";

  buffer = new char [10000];

  congresso *congressos;

  congressos = new congresso [size_congresso];

  bufferHold = buffer;

  int i = 0;

  int size_sigla;

  ifstream fin(arquivo);

  if (fin.is_open()){
    fin.getline(buffer, 10000);
    while (!fin.eof()){
      fin.getline(buffer, 10000);

      buffer += 1;

      if (i == size_congresso - 1){
        continue;
      }

      char *aux;

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

      // cout << congressos[i].estrato_qualis << endl;

      i++;

      buffer = bufferHold;
    }
  }
  fin.close();

  return congressos;
}
