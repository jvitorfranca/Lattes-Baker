#include<iostream>
#include<string.h>
#include<fstream>
#include "arquivos.h"

using namespace std;

// função que retorna um vetor da estrutura, com o número total de orientações de cada docente
conta_orientacao *qntdOrientacao(int size_docente, int size_orientacao, docente *docente_arq, orientacao *orientacao_arq){
  conta_orientacao *qntd_orientacao;

  qntd_orientacao = new conta_orientacao [size_docente];

  // primeiro for roda os docentes e zera as quantidades iniciais
  for (int i = 1;i < size_docente;i++){
    qntd_orientacao[i].iniciacao_cientifica = 0;
    qntd_orientacao[i].trabalho_conclusao = 0;
    qntd_orientacao[i].dissertacao_mestrado = 0;
    qntd_orientacao[i].tese_doutorado = 0;
    // segundo for roda as orientações, compara o id e o tipo de produção
    for (int j = 1;j < size_orientacao;j++){
      if (strcmp(docente_arq[i].id_docente, orientacao_arq[j].id_docente) == 0){
        if (strcmp(orientacao_arq[j].tipo_orientacao,"\"Dissertação de mestrado\"") == 0){
          qntd_orientacao[i].dissertacao_mestrado += 1;
        }
        if (strcmp(orientacao_arq[j].tipo_orientacao,"\"TRABALHO_DE_CONCLUSAO_DE_CURSO_GRADUACAO\"") == 0){
          qntd_orientacao[i].trabalho_conclusao += 1;
        }
        if (strcmp(orientacao_arq[j].tipo_orientacao,"\"INICIACAO_CIENTIFICA\"") == 0){
          qntd_orientacao[i].iniciacao_cientifica += 1;
        }
        if (strcmp(orientacao_arq[j].tipo_orientacao,"\"Tese de doutorado\"") == 0){
          qntd_orientacao[i].tese_doutorado += 1;
        }
      }
    }
  }

  return qntd_orientacao;
}
