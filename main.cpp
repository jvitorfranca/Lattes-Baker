#include<iostream>
#include<string.h>
#include<fstream>
#include "arquivos.h"

using namespace std;

typedef struct _orientacao_por_docente_{
  int iniciacao_cientifica;
  int trabalho_conclusao;
  int dissertacao_mestrado;
  int tese_doutorado;
  int monografia_aperfeicoamento;
}conta_orientacao;

typedef struct _producao_por_docente_{
  int artigo_publicado;
  int trabalho_evento;
}conta_producao;

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

int main(int argc, char const *argv[]) {
  docente *docente_arq;
  orientacao *orientacao_arq;
  producao *producao_arq;
  periodico *periodico_arq;
  congresso *congresso_arq;

  int i, j;
  int size_docente;
  int size_orientacao;
  int size_producao;
  int size_periodico;
  int size_congresso;

  char arquivo_docente[] = "arquivosTrabalho/docentes.csv";
  char arquivo_orientacao[] = "arquivosTrabalho/orientacao.csv";
  char arquivo_producao[] = "arquivosTrabalho/producao_V2.csv";
  char arquivo_periodico[] = "arquivosTrabalho/qualis_capes_periodicos.csv";
  char arquivo_congresso[] = "arquivosTrabalho/qualis_capes_congressos.csv";

  size_docente = numLinhas(arquivo_docente);
  size_orientacao = numLinhas(arquivo_orientacao);
  size_producao = numLinhas(arquivo_producao);
  size_periodico = numLinhas(arquivo_periodico);
  size_congresso = numLinhas(arquivo_congresso);

  docente_arq = retornaDocente(size_docente);
  orientacao_arq = retornaOrientacao(size_orientacao);
  producao_arq = retornaProducoes(size_producao);
  periodico_arq = retornaPeriodico(size_periodico);
  congresso_arq = retornaCongresso(size_congresso);

  conta_orientacao *qntd_orientacao;

  qntd_orientacao = new conta_orientacao [size_docente];

  conta_producao *qntd_producao;

  qntd_producao = new conta_producao [size_docente];

  conta_periodico *qntd_periodico;

  qntd_periodico = new conta_periodico [size_docente];

  for (i = 1;i < size_docente;i++){
    qntd_orientacao[i].iniciacao_cientifica = 0;
    qntd_orientacao[i].trabalho_conclusao = 0;
    qntd_orientacao[i].dissertacao_mestrado = 0;
    qntd_orientacao[i].tese_doutorado = 0;
    qntd_orientacao[i].monografia_aperfeicoamento = 0;
    for (j = 1;j < size_orientacao;j++){
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
        if (strcmp(orientacao_arq[j].tipo_orientacao,"\"MONOGRAFIA_DE_CONCLUSAO_DE_CURSO_APERFEICOAMENTO_E_ESPECIALIZACAO\"") == 0){
          qntd_orientacao[i].monografia_aperfeicoamento += 1;
        }
      }
    }
  }

  for (i = 0;i < size_docente;i++){
    qntd_producao[i].artigo_publicado = 0;
    qntd_producao[i].trabalho_evento = 0;
    for (j = 0;j < size_producao;j++){
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
/*
  for (i = 0;i < size_docente;i++){
    qntd_periodico[i].estrato_A1 = 0;
    qntd_periodico[i].estrato_A2 = 0;
    qntd_periodico[i].estrato_B1 = 0;
    qntd_periodico[i].estrato_B2 = 0;
    qntd_periodico[i].estrato_B3 = 0;
    qntd_periodico[i].estrato_B4 = 0;
    qntd_periodico[i].estrato_B5 = 0;
    qntd_periodico[i].estrato_C = 0;
    qntd_periodico[i].sem_estrato = 0;
    for (j = 0;j < size_periodico;j++){
      if (strcmp(producao_arq[i].issn, periodico_arq[j].issn) == 0){
        if (strcmp(periodico_arq[j].estrato_qualis, "\"A1\"") == 0){
          qntd_periodico[i].estrato_A1 += 1;
        }
        if (strcmp(periodico_arq[j].estrato_qualis, "\"A2\"") == 0){
          qntd_periodico[i].estrato_A2 += 1;
        }
        if (strcmp(periodico_arq[j].estrato_qualis, "\"B1\"") == 0){
          qntd_periodico[i].estrato_B1 += 1;
        }
        if (strcmp(periodico_arq[j].estrato_qualis, "\"B2\"") == 0){
          qntd_periodico[i].estrato_B2 += 1;
        }
        if (strcmp(periodico_arq[j].estrato_qualis, "\"B3\"") == 0){
          qntd_periodico[i].estrato_B3 += 1;
        }
        if (strcmp(periodico_arq[j].estrato_qualis, "\"B4\"") == 0){
          qntd_periodico[i].estrato_B4 += 1;
        }
        if (strcmp(periodico_arq[j].estrato_qualis, "\"B5\"") == 0){
          qntd_periodico[i].estrato_B5 += 1;
        }
        if (strcmp(periodico_arq[j].estrato_qualis, "\"C\"") == 0){
          qntd_periodico[i].estrato_C += 1;
        }
      }
    }
  }
*/

for (i = 1;i < size_docente;i++){
  cout << "Docente: " << docente_arq[i].nome_completo << endl;
  cout << "Dissertações de mestrado: " << qntd_orientacao[i].dissertacao_mestrado << endl;
  cout << "Trabalho de conclusao de curso: " << qntd_orientacao[i].trabalho_conclusao << endl;
  cout << "Iniciações científicas: " << qntd_orientacao[i].iniciacao_cientifica << endl;
  cout << "Teses de doutorado: " << qntd_orientacao[i].tese_doutorado << endl;
  // cout << "Monografia: " << qntd_orientacao[i].monografia_aperfeicoamento << endl;
  cout << endl;
  cout << "Artigos publicados: " << qntd_producao[i].artigo_publicado << endl;
  cout << "Trabalhos em eventos: " << qntd_producao[i].trabalho_evento << endl;
  cout << endl;
}
/*
for (i = 1;i < size_docente;i++){
    cout << "Docente: " << docente_arq[i].nome_completo << endl;
    cout << "Estrato A1: " << qntd_periodico[i].estrato_A1 << endl;
    cout << "Estrato A2: " << qntd_periodico[i].estrato_A2 << endl;
    cout << "Estrato B1: " << qntd_periodico[i].estrato_B1 << endl;
    cout << "Estrato B2: " << qntd_periodico[i].estrato_B2 << endl;
    cout << "Estrato B3: " << qntd_periodico[i].estrato_B3 << endl;
    cout << "Estrato B4: " << qntd_periodico[i].estrato_B4 << endl;
    cout << "Estrato B5: " << qntd_periodico[i].estrato_B5 << endl;
    cout << "Estrato C: " << qntd_periodico[i].estrato_C << endl;
    cout << "Sem Estrato: " << qntd_periodico[i].sem_estrato << endl;
}
*/
  delete [] docente_arq;
  delete [] orientacao_arq;
  delete [] producao_arq;
  delete [] periodico_arq;
  delete [] congresso_arq;
  delete [] qntd_orientacao;
  delete [] qntd_producao;

  return 0;
}
