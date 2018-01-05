#include<iostream>
#include<string.h>
#include<fstream>

using namespace std;

typedef struct _producao_por_docente_{
  int artigo_publicado;
  int trabalho_evento;
}conta_producao;

conta_producao *qntdProducao(int size_docente, int size_producao, docente *docente_arq, producao *producao_arq){
  conta_producao *qntd_producao;

  qntd_producao = new conta_producao [size_docente];

  for (int i = 0;i < size_docente;i++){
    qntd_producao[i].artigo_publicado = 0;
    qntd_producao[i].trabalho_evento = 0;
    for (int j = 0;j < size_producao;j++){
      if (strcmp(docente_arq[i].id_docente, producao_arq[j].id_docente) == 0){
        if (strcmp(producao_arq[j].tipo_producao,"\"ARTIGO-PUBLICADO\"") == 0){
          qntd_producao[i].artigo_publicado += 1;
        }
        if (strcmp(producao_arq[j].tipo_producao,"\"ARTIGO-ACEITO-PARA-PUBLICACAO\"") == 0){
          qntd_producao[i].artigo_publicado += 1;
        }
        if (strcmp(producao_arq[j].tipo_producao,"\"TRABALHO_EM_EVENTO\"") == 0){
          qntd_producao[i].trabalho_evento += 1;
        }
      }
    }
  }

  return qntd_producao;

}
