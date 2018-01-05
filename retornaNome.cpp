#include<iostream>
#include<string.h>
#include<fstream>

using namespace std;

char *retornaNome(char arquivo_regra[]) {
  char *nome_saida;

  nome_saida = new char [20];

  char *aux;

  aux = strstr(arquivo_regra, ".");
  *aux = '\0';
  strcpy(nome_saida, arquivo_regra);

  return nome_saida;
}
