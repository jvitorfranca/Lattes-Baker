#include<iostream>
#include<string.h>
#include<fstream>

using namespace std;

typedef struct _pontuacao_final_{
  int pont_con_A1;
  int pont_con_A2;
  int pont_con_B1;
  int pont_con_B2;
  int pont_con_B3;
  int pont_con_B4;
  int pont_con_B5;
  int pont_con_C;
  int pont_con_SE;
  int pont_per_A1;
  int pont_per_A2;
  int pont_per_B1;
  int pont_per_B2;
  int pont_per_B3;
  int pont_per_B4;
  int pont_per_B5;
  int pont_per_C;
  int pont_per_SE;
  int pont_IC;
  int pont_TC;
  int pont_DM;
  int pont_TD;
  int somatorio;
}conta_pontuacao;

conta_pontuacao *pontuacaoFinal(int size_docente, int l, conta_congresso *qntd_congresso, conta_periodico *qntd_periodico, conta_orientacao *qntd_orientacao, avaliacao *regra){
  conta_pontuacao *pontuacao_final;

  pontuacao_final = new conta_pontuacao [size_docente];

  int contador = 0;
  int soma = 0;

  for (int i = 1;i < size_docente;i++){
    pontuacao_final[i].pont_con_A1 = 0;
    pontuacao_final[i].pont_con_A1 = qntd_congresso[i].estrato_A1 * regra[l].pontuacao[contador];
    soma += pontuacao_final[i].pont_con_A1;
    contador += 1;
    pontuacao_final[i].pont_con_A2 = 0;
    pontuacao_final[i].pont_con_A2 = qntd_congresso[i].estrato_A2 * regra[l].pontuacao[contador];
    soma += pontuacao_final[i].pont_con_A2;
    contador += 1;
    pontuacao_final[i].pont_con_B1 = 0;
    pontuacao_final[i].pont_con_B1 = qntd_congresso[i].estrato_B1 * regra[l].pontuacao[contador];
    soma += pontuacao_final[i].pont_con_B1;
    contador += 1;
    pontuacao_final[i].pont_con_B2 = 0;
    pontuacao_final[i].pont_con_B2 = qntd_congresso[i].estrato_B2 * regra[l].pontuacao[contador];
    soma += pontuacao_final[i].pont_con_B2;
    contador += 1;
    pontuacao_final[i].pont_con_B3 = 0;
    pontuacao_final[i].pont_con_B3 = qntd_congresso[i].estrato_B3 * regra[l].pontuacao[contador];
    soma += pontuacao_final[i].pont_con_B3;
    contador += 1;
    pontuacao_final[i].pont_con_B4 = 0;
    pontuacao_final[i].pont_con_B4 = qntd_congresso[i].estrato_B4 * regra[l].pontuacao[contador];
    soma += pontuacao_final[i].pont_con_B4;
    contador += 1;
    pontuacao_final[i].pont_con_B5 = 0;
    pontuacao_final[i].pont_con_B5 = qntd_congresso[i].estrato_B5 * regra[l].pontuacao[contador];
    soma += pontuacao_final[i].pont_con_B5;
    contador += 1;
    pontuacao_final[i].pont_con_C = 0;
    pontuacao_final[i].pont_con_C = qntd_congresso[i].estrato_C * regra[l].pontuacao[contador];
    soma += pontuacao_final[i].pont_con_C;
    contador += 1;
    pontuacao_final[i].pont_con_SE = 0;
    pontuacao_final[i].pont_con_SE = qntd_congresso[i].sem_estrato * regra[l].pontuacao[contador];
    soma += pontuacao_final[i].pont_con_SE;
    contador += 1;
    pontuacao_final[i].pont_per_A1 = 0;
    pontuacao_final[i].pont_per_A1 = qntd_periodico[i].estrato_A1 * regra[l].pontuacao[contador];
    soma += pontuacao_final[i].pont_per_A1;
    contador += 1;
    pontuacao_final[i].pont_per_A2 = 0;
    pontuacao_final[i].pont_per_A2 = qntd_periodico[i].estrato_A2 * regra[l].pontuacao[contador];
    soma += pontuacao_final[i].pont_per_A2;
    contador += 1;
    pontuacao_final[i].pont_per_B1 = 0;
    pontuacao_final[i].pont_per_B1 = qntd_periodico[i].estrato_B1 * regra[l].pontuacao[contador];
    soma += pontuacao_final[i].pont_per_B1;
    contador += 1;
    pontuacao_final[i].pont_per_B2 = 0;
    pontuacao_final[i].pont_per_B2 = qntd_periodico[i].estrato_B2 * regra[l].pontuacao[contador];
    soma += pontuacao_final[i].pont_per_B2;
    contador += 1;
    pontuacao_final[i].pont_per_B3 = 0;
    pontuacao_final[i].pont_per_B3 = qntd_periodico[i].estrato_B3 * regra[l].pontuacao[contador];
    soma += pontuacao_final[i].pont_per_B3;
    contador += 1;
    pontuacao_final[i].pont_per_B4 = 0;
    pontuacao_final[i].pont_per_B4 = qntd_periodico[i].estrato_B4 * regra[l].pontuacao[contador];
    soma += pontuacao_final[i].pont_per_B4;
    contador += 1;
    pontuacao_final[i].pont_per_B5 = 0;
    pontuacao_final[i].pont_per_B5 = qntd_periodico[i].estrato_B5 * regra[l].pontuacao[contador];
    soma += pontuacao_final[i].pont_per_B5;
    contador += 1;
    pontuacao_final[i].pont_per_C = 0;
    pontuacao_final[i].pont_per_C = qntd_periodico[i].estrato_C * regra[l].pontuacao[contador];
    soma += pontuacao_final[i].pont_per_C;
    contador += 1;
    pontuacao_final[i].pont_per_SE = 0;
    pontuacao_final[i].pont_per_SE = qntd_periodico[i].sem_estrato * regra[l].pontuacao[contador];
    soma += pontuacao_final[i].pont_per_SE;
    contador += 1;
    pontuacao_final[i].pont_IC = 0;
    pontuacao_final[i].pont_IC = qntd_orientacao[i].iniciacao_cientifica * regra[l].pontuacao[contador];
    soma += pontuacao_final[i].pont_IC;
    contador += 1;
    pontuacao_final[i].pont_TC = 0;
    pontuacao_final[i].pont_TC = qntd_orientacao[i].trabalho_conclusao * regra[l].pontuacao[contador];
    soma += pontuacao_final[i].pont_TC;
    contador += 1;
    pontuacao_final[i].pont_DM = 0;
    pontuacao_final[i].pont_DM = qntd_orientacao[i].dissertacao_mestrado * regra[l].pontuacao[contador];
    soma += pontuacao_final[i].pont_DM;
    contador += 1;
    pontuacao_final[i].pont_TD = 0;
    pontuacao_final[i].pont_TD = qntd_orientacao[i].tese_doutorado * regra[l].pontuacao[contador];
    soma += pontuacao_final[i].pont_TD;
    contador = 0;
    pontuacao_final[i].somatorio = soma;
    soma = 0;
  }

  return pontuacao_final;
}
