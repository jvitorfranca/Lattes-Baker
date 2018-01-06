#include<iostream>
#include<string.h>
#include<fstream>

using namespace std;

// estrutura que receberá a quantidade de estratos de congresso para cada docente
typedef struct _qualis_congressos_{
  int estrato_A1;
  int estrato_A2;
  int estrato_B1;
  int estrato_B2;
  int estrato_B3;
  int estrato_B4;
  int estrato_B5;
  int estrato_C;
  int sem_estrato;
}conta_congresso;

// função que retorna um vetor da estrutura que contêm a quantidade dos congressos
conta_congresso *qntdCongresso(int size_docente, int size_producao, int size_congresso, int ano_minimo, int ano_maximo, docente *docente_cpy, producao *producao_arq, congresso *congresso_arq, conta_producao *qntd_producao){
  conta_congresso *qntd_congresso;

  qntd_congresso = new conta_congresso [size_docente];

  // primeiro laço roda os docentes e zera o numero de estratos
  for (int i = 0;i < size_docente;i++){
    qntd_congresso[i].estrato_A1 = 0;
    qntd_congresso[i].estrato_A2 = 0;
    qntd_congresso[i].estrato_B1 = 0;
    qntd_congresso[i].estrato_B2 = 0;
    qntd_congresso[i].estrato_B3 = 0;
    qntd_congresso[i].estrato_B4 = 0;
    qntd_congresso[i].estrato_B5 = 0;
    qntd_congresso[i].estrato_C = 0;
    qntd_congresso[i].sem_estrato = 0;
    // segundo laço roda a produção e verifica o id e o tipo de producao
    for (int j = 0;j < size_producao;j++){
      if (strcmp(docente_cpy[i].id_docente,producao_arq[j].id_docente) == 0 && strcmp(producao_arq[j].tipo_producao,"\"TRABALHO_EM_EVENTO\"")==0 && (producao_arq[j].ano_trabalho >= ano_minimo && producao_arq[j].ano_trabalho <= ano_maximo)){
        // terceiro laço roda o congresso e verifica se o local da produção é igual ao nome do congresso
        for (int k = 0;k < size_congresso;k++){
          if (strstr(producao_arq[j].local,congresso_arq[k].nome_congresso) != NULL){
            // compara os estratos
            if (strcmp(congresso_arq[k].estrato_qualis, "A1") == 0){
              qntd_congresso[i].estrato_A1 += 1;
            } else if (strcmp(congresso_arq[k].estrato_qualis, "A2") == 0){
              qntd_congresso[i].estrato_A2 += 1;
            } else if (strcmp(congresso_arq[k].estrato_qualis, "B1") == 0){
              qntd_congresso[i].estrato_B1 += 1;
            } else if (strcmp(congresso_arq[k].estrato_qualis, "B2") == 0){
              qntd_congresso[i].estrato_B2 += 1;
            } else if (strcmp(congresso_arq[k].estrato_qualis, "B3") == 0){
              qntd_congresso[i].estrato_B3 += 1;
            } else if (strcmp(congresso_arq[k].estrato_qualis, "B4") == 0){
              qntd_congresso[i].estrato_B4 += 1;
            } else if (strcmp(congresso_arq[k].estrato_qualis, "B5") == 0){
              qntd_congresso[i].estrato_B5 += 1;
            }  else if (strcmp(congresso_arq[k].estrato_qualis, "C") == 0){
              qntd_congresso[i].estrato_C += 1;
            }
          }
        }
      }
    }
    // quantidade de congresso é igual a quantidade total menos aqueles que tem estrato
    qntd_congresso[i].sem_estrato = qntd_producao[i].trabalho_evento - (qntd_congresso[i].estrato_A1 + qntd_congresso[i].estrato_A2 + qntd_congresso[i].estrato_B1 + qntd_congresso[i].estrato_B2 + qntd_congresso[i].estrato_B3 + qntd_congresso[i].estrato_B4 + qntd_congresso[i].estrato_B5 + qntd_congresso[i].estrato_C);
    if (qntd_congresso[i].sem_estrato < 0){
      qntd_congresso[i].sem_estrato = 0;
    }
  }

  return qntd_congresso;
}
