#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

int numLinhas(char *arquivo){
  char buffer[1000];

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
