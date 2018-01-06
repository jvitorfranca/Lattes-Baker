#include<iostream>
#include<string.h>
#include<fstream>

using namespace std;

// estrutura que armazena a quantidade de cada estrato de cada docente
typedef struct _qualis_periodicos_{
  int estrato_A1;
  int estrato_A2;
  int estrato_B1;
  int estrato_B2;
  int estrato_B3;
  int estrato_B4;
  int estrato_B5;
  int estrato_C;
  int sem_estrato;
}conta_periodico;

// função que retorna um vetor com a quantidade dos estratos dos periódicos
conta_periodico *qntdPeriodico(int size_docente, int size_producao, int size_periodico, int ano_minimo, int ano_maximo, int l, docente *docente_cpy, producao *producao_arq, periodico *periodico_arq, avaliacao *regra){
  conta_periodico *qntd_periodico;

  qntd_periodico = new conta_periodico [size_docente];

  // flag que ira contar o numero de sem estrato
  int flag_periodico = 0;

  // primeiro for roda os docentes e zera a quantidade de cada estrato
  for (int i = 0;i < size_docente;i++){
    qntd_periodico[i].estrato_A1 = 0;
    qntd_periodico[i].estrato_A2 = 0;
    qntd_periodico[i].estrato_B1 = 0;
    qntd_periodico[i].estrato_B2 = 0;
    qntd_periodico[i].estrato_B3 = 0;
    qntd_periodico[i].estrato_B4 = 0;
    qntd_periodico[i].estrato_B5 = 0;
    qntd_periodico[i].estrato_C = 0;
    qntd_periodico[i].sem_estrato = 0;
    // segundo for roda a producao e compara o id e o tipo de producao
    for (int j = 0;j < size_producao;j++){
      if ((strcmp(docente_cpy[i].id_docente, producao_arq[j].id_docente) == 0) && (strcmp(producao_arq[j].tipo_producao,"\"ARTIGO-PUBLICADO\"") == 0 || strcmp(producao_arq[j].tipo_producao,"\"ARTIGO-ACEITO-PARA-PUBLICACAO\"") == 0) && (producao_arq[j].ano_trabalho >= ano_minimo && producao_arq[j].ano_trabalho <= ano_maximo)){
        // terceiro for roda os periodicos
        for (int k = 0;k < size_periodico;k++){
          // if compara o issn da producao e do periodico e compara a area de avaliacao
          if ((strcmp(producao_arq[j].issn, periodico_arq[k].issn) == 0) && (strcmp(periodico_arq[k].area_de_avaliacao, regra[l].area_de_avaliacao) == 0)){
            flag_periodico = 1;
            if (strcmp(periodico_arq[k].estrato_qualis, "A1") == 0){
              qntd_periodico[i].estrato_A1 += 1;
            } else if (strcmp(periodico_arq[k].estrato_qualis, "A2") == 0){
              qntd_periodico[i].estrato_A2 += 1;
            } else if (strcmp(periodico_arq[k].estrato_qualis, "B1") == 0){
              qntd_periodico[i].estrato_B1 += 1;
            } else if (strcmp(periodico_arq[k].estrato_qualis, "B2") == 0){
              qntd_periodico[i].estrato_B2 += 1;
            } else if (strcmp(periodico_arq[k].estrato_qualis, "B3") == 0){
              qntd_periodico[i].estrato_B3 += 1;
            } else if (strcmp(periodico_arq[k].estrato_qualis, "B4") == 0){
              qntd_periodico[i].estrato_B4 += 1;
            } else if (strcmp(periodico_arq[k].estrato_qualis, "B5") == 0){
              qntd_periodico[i].estrato_B5 += 1;
            } else if (strcmp(periodico_arq[k].estrato_qualis, "C") == 0){
              qntd_periodico[i].estrato_C += 1;
            }
          }
        }
        //issn bate mas não tem estrato no qualis
        if(flag_periodico==0){
          qntd_periodico[i].sem_estrato +=1;
        }else{
          flag_periodico = 0;
        }
      }
    }
  }

  return qntd_periodico;
}
