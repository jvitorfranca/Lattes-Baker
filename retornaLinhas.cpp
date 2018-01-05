#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

//a função receberá um arquivo e retornará o numero de linhas do mesmo
int numLinhas(char *arquivo){
  char buffer[1000];

  //cont = -1 para contornar a linha a mais retornada pelo fin.getline
  int cont = -1;

  ifstream fin(arquivo);

  if (fin.is_open()){
    while (!fin.eof()){
      fin.getline(buffer, 1000);
      cont++;
    }
    fin.close();
  }
  return cont;
}
