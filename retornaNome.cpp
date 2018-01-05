#include<iostream>
#include<string.h>
#include<fstream>

using namespace std;

/*
  função recebe o nome do arquivo e retorna o mesmo sem extensão,
  para que possa ser usado na criação do arquivo final
*/
char *retornaNome(char arquivo_regra[]) {
  char *nome_saida;

  nome_saida = new char [20];

  char *aux;

  aux = strstr(arquivo_regra, ".");
  *aux = '\0';
  strcpy(nome_saida, arquivo_regra);

  return nome_saida;
}
