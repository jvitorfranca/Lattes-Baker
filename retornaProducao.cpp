#include<iostream>
#include<string.h>
#include<fstream>

using namespace std;

typedef struct _producao_{
  char id_docente[100];
  char id_producao[300];
  char tipo_producao[300];
  char issn[50];
  char titulo[300];
  char local[300];
  int ano_trabalho;
}producao;

producao *retornaProducoes(int size_producao, char arquivo[]){
  char *buffer;
  char *bufferHold;

  //char arquivo[] = "producao_V2.csv";

  buffer = new char [10000];

  producao *producoes;

  producoes = new producao [size_producao];

  bufferHold = buffer;

  int i = 0;

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
/*
        aux=strstr(buffer,",");
            *aux='\0';
            strcpy(producoes[i].id_docente,buffer);
            buffer= aux + 1;

            aux=strstr(buffer,",");
            *aux='\0';
            strcpy(producoes[i].id_producao,buffer);
            buffer= aux+2;

            aux=strstr(buffer,"\",\"");
            *aux='\0';
            strcpy(producoes[i].tipo_producao,buffer);
            buffer= aux+3;

            aux=strstr(buffer,"\",\"");
            *aux='\0';
            if(buffer!=NULL){
              strcpy(producoes[i].issn,buffer);
            }
            buffer= aux + 3;

            aux=strstr(buffer,"\",\"");
            *aux='\0';
            strcpy(producoes[i].titulo,buffer);
            buffer= aux+3;


            aux=strstr(buffer,"\",");
            *aux='\0';
            strcpy(producoes[i].local,buffer);
            buffer= aux+2;

            strcpy(producoes[i].ano_trabalho,buffer);

            // cout << producoes[i].local << endl;
*/
      i++;

      buffer = bufferHold;
    }
  }
  fin.close();

  return producoes;
}
