#include<iostream>
#include<string.h>
#include<fstream>

using namespace std;

void ordenaPontuacao(int size_docente, conta_pontuacao *pontuacao_final, docente *docente_cpy){
  char aux_docente[100];
  int aux_con_A1 = 0;
  int aux_con_A2 = 0;
  int aux_con_B1 = 0;
  int aux_con_B2 = 0;
  int aux_con_B3 = 0;
  int aux_con_B4 = 0;
  int aux_con_B5 = 0;
  int aux_con_C = 0;
  int aux_con_SE = 0;
  int aux_per_A1 = 0;
  int aux_per_A2 = 0;
  int aux_per_B1 = 0;
  int aux_per_B2 = 0;
  int aux_per_B3 = 0;
  int aux_per_B4 = 0;
  int aux_per_B5 = 0;
  int aux_per_C = 0;
  int aux_per_SE = 0;
  int aux_IC = 0;
  int aux_TC = 0;
  int aux_DM = 0;
  int aux_TD = 0;
  int aux_final = 0;

  for (int i = 1;i < size_docente;i++){
    for (int j = i + 1;j < size_docente;j++){
      if (pontuacao_final[i].somatorio < pontuacao_final[j].somatorio){
        strcpy(aux_docente, docente_cpy[i].nome_completo);
        strcpy(docente_cpy[i].nome_completo,docente_cpy[j].nome_completo);
        strcpy(docente_cpy[j].nome_completo,aux_docente);

        aux_con_A1 = pontuacao_final[i].pont_con_A1;
        pontuacao_final[i].pont_con_A1 = pontuacao_final[j].pont_con_A1;
        pontuacao_final[j].pont_con_A1 = aux_con_A1;

        aux_con_A2 = pontuacao_final[i].pont_con_A2;
        pontuacao_final[i].pont_con_A2 = pontuacao_final[j].pont_con_A2;
        pontuacao_final[j].pont_con_A2 = aux_con_A2;

        aux_con_B1 = pontuacao_final[i].pont_con_B1;
        pontuacao_final[i].pont_con_B1 = pontuacao_final[j].pont_con_B1;
        pontuacao_final[j].pont_con_B1 = aux_con_B1;

        aux_con_B2 = pontuacao_final[i].pont_con_B2;
        pontuacao_final[i].pont_con_B2 = pontuacao_final[j].pont_con_B2;
        pontuacao_final[j].pont_con_B2 = aux_con_B2;

        aux_con_B3 = pontuacao_final[i].pont_con_B3;
        pontuacao_final[i].pont_con_B3 = pontuacao_final[j].pont_con_B3;
        pontuacao_final[j].pont_con_B3 = aux_con_B3;

        aux_con_B4 = pontuacao_final[i].pont_con_B4;
        pontuacao_final[i].pont_con_B4 = pontuacao_final[j].pont_con_B4;
        pontuacao_final[j].pont_con_B4 = aux_con_B4;

        aux_con_B5 = pontuacao_final[i].pont_con_B5;
        pontuacao_final[i].pont_con_B5 = pontuacao_final[j].pont_con_B5;
        pontuacao_final[j].pont_con_B5 = aux_con_B5;

        aux_con_C = pontuacao_final[i].pont_con_C;
        pontuacao_final[i].pont_con_C = pontuacao_final[j].pont_con_C;
        pontuacao_final[j].pont_con_C = aux_con_C;

        aux_con_SE = pontuacao_final[i].pont_con_SE;
        pontuacao_final[i].pont_con_SE = pontuacao_final[j].pont_con_SE;
        pontuacao_final[j].pont_con_SE = aux_con_SE;

        aux_per_A1 = pontuacao_final[i].pont_per_A1;
        pontuacao_final[i].pont_per_A1 = pontuacao_final[j].pont_per_A1;
        pontuacao_final[j].pont_per_A1 = aux_per_A1;

        aux_per_A2 = pontuacao_final[i].pont_per_A2;
        pontuacao_final[i].pont_per_A2 = pontuacao_final[j].pont_per_A2;
        pontuacao_final[j].pont_per_A2 = aux_per_A2;

        aux_per_B1 = pontuacao_final[i].pont_per_B1;
        pontuacao_final[i].pont_per_B1 = pontuacao_final[j].pont_per_B1;
        pontuacao_final[j].pont_per_B1 = aux_per_B1;

        aux_per_B2 = pontuacao_final[i].pont_per_B2;
        pontuacao_final[i].pont_per_B2 = pontuacao_final[j].pont_per_B2;
        pontuacao_final[j].pont_per_B2 = aux_per_B2;

        aux_per_B3 = pontuacao_final[i].pont_per_B3;
        pontuacao_final[i].pont_per_B3 = pontuacao_final[j].pont_per_B3;
        pontuacao_final[j].pont_per_B3 = aux_per_B3;

        aux_per_B4 = pontuacao_final[i].pont_per_B4;
        pontuacao_final[i].pont_per_B4 = pontuacao_final[j].pont_per_B4;
        pontuacao_final[j].pont_per_B4 = aux_per_B4;

        aux_per_B5 = pontuacao_final[i].pont_per_B5;
        pontuacao_final[i].pont_per_B5 = pontuacao_final[j].pont_per_B5;
        pontuacao_final[j].pont_per_B5 = aux_per_B5;

        aux_per_C = pontuacao_final[i].pont_per_C;
        pontuacao_final[i].pont_per_C = pontuacao_final[j].pont_per_C;
        pontuacao_final[j].pont_per_C = aux_per_C;

        aux_per_SE = pontuacao_final[i].pont_per_SE;
        pontuacao_final[i].pont_per_SE = pontuacao_final[j].pont_per_SE;
        pontuacao_final[j].pont_per_SE = aux_per_SE;

        aux_IC = pontuacao_final[i].pont_IC;
        pontuacao_final[i].pont_IC = pontuacao_final[j].pont_IC;
        pontuacao_final[j].pont_IC = aux_IC;

        aux_TC = pontuacao_final[i].pont_TC;
        pontuacao_final[i].pont_TC = pontuacao_final[j].pont_TC;
        pontuacao_final[j].pont_TC = aux_TC;

        aux_DM = pontuacao_final[i].pont_DM;
        pontuacao_final[i].pont_DM = pontuacao_final[j].pont_DM;
        pontuacao_final[j].pont_DM = aux_DM;

        aux_TD = pontuacao_final[i].pont_TD;
        pontuacao_final[i].pont_TD = pontuacao_final[j].pont_TD;
        pontuacao_final[j].pont_TD = aux_TD;

        aux_final = pontuacao_final[i].somatorio;
        pontuacao_final[i].somatorio = pontuacao_final[j].somatorio;
        pontuacao_final[j].somatorio = aux_final;
      }
    }
  }
}
