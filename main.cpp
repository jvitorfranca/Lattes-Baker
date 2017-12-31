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
}conta_orientacao;

typedef struct _producao_por_docente_{
  int artigo_publicado;
  int trabalho_evento;
}conta_producao;

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

int main(int argc, char const *argv[]) {
  docente *docente_arq;
  orientacao *orientacao_arq;
  producao *producao_arq;
  periodico *periodico_arq;
  congresso *congresso_arq;
  avaliacao regra;

  int i, j, k;
  int size_docente;
  int size_orientacao;
  int size_producao;
  int size_periodico;
  int size_congresso;

  char arquivo_docente[50];// = "docentes.csv";
  char arquivo_orientacao[50];// = "orientacao.csv";
  char arquivo_producao[50];// = "producao_V2.csv";
  char arquivo_periodico[50];// = "qualis_capes_periodicos.csv";
  char arquivo_congresso[50];// = "qualis_capes_congressos.csv";
  char arquivo_regra[50];
  int ano_maximo;
  int ano_minimo;

  cout << "informe o arquivo de docentes: " << endl;
  cin >> arquivo_docente;
  cout << "informe o arquivo de orientacoes: " << endl;
  cin >> arquivo_orientacao;
  cout << "informe o arquivo de producoes: " << endl;
  cin >> arquivo_producao;
  cout << "informe o arquivo de congresos: " << endl;
  cin >> arquivo_congresso;
  cout << "informe o arquivo de periodicos: " << endl;
  cin >> arquivo_periodico;

  size_docente = numLinhas(arquivo_docente);
  size_orientacao = numLinhas(arquivo_orientacao);
  size_producao = numLinhas(arquivo_producao);
  size_periodico = numLinhas(arquivo_periodico);
  size_congresso = numLinhas(arquivo_congresso);

  docente_arq = retornaDocente(size_docente, arquivo_docente);
  orientacao_arq = retornaOrientacao(size_orientacao, arquivo_orientacao);
  producao_arq = retornaProducoes(size_producao, arquivo_producao);
  periodico_arq = retornaPeriodico(size_periodico, arquivo_periodico);
  congresso_arq = retornaCongresso(size_congresso, arquivo_congresso);

  cout << "informe o arquivo de avaliação: " << endl;
  cin >> arquivo_regra;

  cout << "informe o ano minimo: " << endl;
  cin >> ano_minimo;

  cout << "informe o ano maximo: " << endl;
  cin >> ano_maximo;

  regra = retornaPontuacoes(arquivo_regra);

  conta_orientacao *qntd_orientacao;

  qntd_orientacao = new conta_orientacao [size_docente];

  conta_producao *qntd_producao;

  qntd_producao = new conta_producao [size_docente];

  conta_periodico *qntd_periodico;

  qntd_periodico = new conta_periodico [size_docente];

  conta_congresso *qntd_congresso;

  qntd_congresso = new conta_congresso [size_docente];

  conta_pontuacao *pontuacao_final;

  pontuacao_final = new conta_pontuacao [size_docente];

  for (i = 1;i < size_docente;i++){
    qntd_orientacao[i].iniciacao_cientifica = 0;
    qntd_orientacao[i].trabalho_conclusao = 0;
    qntd_orientacao[i].dissertacao_mestrado = 0;
    qntd_orientacao[i].tese_doutorado = 0;
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

  for (i = 0;i < size_docente;i++){
    qntd_congresso[i].estrato_A1 = 0;
    qntd_congresso[i].estrato_A2 = 0;
    qntd_congresso[i].estrato_B1 = 0;
    qntd_congresso[i].estrato_B2 = 0;
    qntd_congresso[i].estrato_B3 = 0;
    qntd_congresso[i].estrato_B4 = 0;
    qntd_congresso[i].estrato_B5 = 0;
    qntd_congresso[i].estrato_C = 0;
    qntd_congresso[i].sem_estrato = 0;
    for (j = 0;j < size_producao;j++){
      if (strcmp(docente_arq[i].id_docente,producao_arq[j].id_docente) == 0 && strcmp(producao_arq[j].tipo_producao,"\"TRABALHO_EM_EVENTO\"")==0 && (producao_arq[j].ano_trabalho >= ano_minimo && producao_arq[j].ano_trabalho <= ano_maximo)){
        for (k = 0;k < size_congresso;k++){
          if (strstr(producao_arq[j].local,congresso_arq[k].nome_congresso) != NULL){
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
    qntd_congresso[i].sem_estrato = qntd_producao[i].trabalho_evento - (qntd_congresso[i].estrato_A1 + qntd_congresso[i].estrato_A2 + qntd_congresso[i].estrato_B1 + qntd_congresso[i].estrato_B2 + qntd_congresso[i].estrato_B3 + qntd_congresso[i].estrato_B4 + qntd_congresso[i].estrato_B5 + qntd_congresso[i].estrato_C);
    if (qntd_congresso[i].sem_estrato < 0){
      qntd_congresso[i].sem_estrato = 0;
    }
  }

  int flag_periodico = 0;

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
    for (j = 0;j < size_producao;j++){
      if ((strcmp(docente_arq[i].id_docente, producao_arq[j].id_docente) == 0) && (strcmp(producao_arq[j].tipo_producao,"\"ARTIGO-PUBLICADO\"") == 0 || strcmp(producao_arq[j].tipo_producao,"\"ARTIGO-ACEITO-PARA-PUBLICACAO\"") == 0) && (producao_arq[j].ano_trabalho >= ano_minimo && producao_arq[j].ano_trabalho <= ano_maximo)){
        for (k = 0;k < size_periodico;k++){
          if ((strcmp(producao_arq[j].issn, periodico_arq[k].issn) == 0) && (strcmp(periodico_arq[k].area_de_avaliacao, regra.area_de_avaliacao) == 0)){
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

int contador = 0;
int soma = 0;

for (i = 1;i < size_docente;i++){
  pontuacao_final[i].pont_con_A1 = 0;
  pontuacao_final[i].pont_con_A1 = qntd_congresso[i].estrato_A1 * regra.pontuacao[contador];
  soma += pontuacao_final[i].pont_con_A1;
  contador += 1;
  pontuacao_final[i].pont_con_A2 = 0;
  pontuacao_final[i].pont_con_A2 = qntd_congresso[i].estrato_A2 * regra.pontuacao[contador];
  soma += pontuacao_final[i].pont_con_A2;
  contador += 1;
  pontuacao_final[i].pont_con_B1 = 0;
  pontuacao_final[i].pont_con_B1 = qntd_congresso[i].estrato_B1 * regra.pontuacao[contador];
  soma += pontuacao_final[i].pont_con_B1;
  contador += 1;
  pontuacao_final[i].pont_con_B2 = 0;
  pontuacao_final[i].pont_con_B2 = qntd_congresso[i].estrato_B2 * regra.pontuacao[contador];
  soma += pontuacao_final[i].pont_con_B2;
  contador += 1;
  pontuacao_final[i].pont_con_B3 = 0;
  pontuacao_final[i].pont_con_B3 = qntd_congresso[i].estrato_B3 * regra.pontuacao[contador];
  soma += pontuacao_final[i].pont_con_B3;
  contador += 1;
  pontuacao_final[i].pont_con_B4 = 0;
  pontuacao_final[i].pont_con_B4 = qntd_congresso[i].estrato_B4 * regra.pontuacao[contador];
  soma += pontuacao_final[i].pont_con_B4;
  contador += 1;
  pontuacao_final[i].pont_con_B5 = 0;
  pontuacao_final[i].pont_con_B5 = qntd_congresso[i].estrato_B5 * regra.pontuacao[contador];
  soma += pontuacao_final[i].pont_con_B5;
  contador += 1;
  pontuacao_final[i].pont_con_C = 0;
  pontuacao_final[i].pont_con_C = qntd_congresso[i].estrato_C * regra.pontuacao[contador];
  soma += pontuacao_final[i].pont_con_C;
  contador += 1;
  pontuacao_final[i].pont_con_SE = 0;
  pontuacao_final[i].pont_con_SE = qntd_congresso[i].sem_estrato * regra.pontuacao[contador];
  soma += pontuacao_final[i].pont_con_SE;
  contador += 1;
  pontuacao_final[i].pont_per_A1 = 0;
  pontuacao_final[i].pont_per_A1 = qntd_periodico[i].estrato_A1 * regra.pontuacao[contador];
  soma += pontuacao_final[i].pont_per_A1;
  contador += 1;
  pontuacao_final[i].pont_per_A2 = 0;
  pontuacao_final[i].pont_per_A2 = qntd_periodico[i].estrato_A2 * regra.pontuacao[contador];
  soma += pontuacao_final[i].pont_per_A2;
  contador += 1;
  pontuacao_final[i].pont_per_B1 = 0;
  pontuacao_final[i].pont_per_B1 = qntd_periodico[i].estrato_B1 * regra.pontuacao[contador];
  soma += pontuacao_final[i].pont_per_B1;
  contador += 1;
  pontuacao_final[i].pont_per_B2 = 0;
  pontuacao_final[i].pont_per_B2 = qntd_periodico[i].estrato_B2 * regra.pontuacao[contador];
  soma += pontuacao_final[i].pont_per_B2;
  contador += 1;
  pontuacao_final[i].pont_per_B3 = 0;
  pontuacao_final[i].pont_per_B3 = qntd_periodico[i].estrato_B3 * regra.pontuacao[contador];
  soma += pontuacao_final[i].pont_per_B3;
  contador += 1;
  pontuacao_final[i].pont_per_B4 = 0;
  pontuacao_final[i].pont_per_B4 = qntd_periodico[i].estrato_B4 * regra.pontuacao[contador];
  soma += pontuacao_final[i].pont_per_B4;
  contador += 1;
  pontuacao_final[i].pont_per_B5 = 0;
  pontuacao_final[i].pont_per_B5 = qntd_periodico[i].estrato_B5 * regra.pontuacao[contador];
  soma += pontuacao_final[i].pont_per_B5;
  contador += 1;
  pontuacao_final[i].pont_per_C = 0;
  pontuacao_final[i].pont_per_C = qntd_periodico[i].estrato_C * regra.pontuacao[contador];
  soma += pontuacao_final[i].pont_per_C;
  contador += 1;
  pontuacao_final[i].pont_per_SE = 0;
  pontuacao_final[i].pont_per_SE = qntd_periodico[i].sem_estrato * regra.pontuacao[contador];
  soma += pontuacao_final[i].pont_per_SE;
  contador += 1;
  pontuacao_final[i].pont_IC = 0;
  pontuacao_final[i].pont_IC = qntd_orientacao[i].iniciacao_cientifica * regra.pontuacao[contador];
  soma += pontuacao_final[i].pont_IC;
  contador += 1;
  pontuacao_final[i].pont_TC = 0;
  pontuacao_final[i].pont_TC = qntd_orientacao[i].trabalho_conclusao * regra.pontuacao[contador];
  soma += pontuacao_final[i].pont_TC;
  contador += 1;
  pontuacao_final[i].pont_DM = 0;
  pontuacao_final[i].pont_DM = qntd_orientacao[i].dissertacao_mestrado * regra.pontuacao[contador];
  soma += pontuacao_final[i].pont_DM;
  contador += 1;
  pontuacao_final[i].pont_TD = 0;
  pontuacao_final[i].pont_TD = qntd_orientacao[i].tese_doutorado * regra.pontuacao[contador];
  soma += pontuacao_final[i].pont_TD;
  contador = 0;
  pontuacao_final[i].somatorio = soma;
  soma = 0;
}

/*for (i = 1;i < size_docente;i++){
  cout << "Docente: " << docente_arq[i].nome_completo << endl;
    cout << "Estrato A1: " << qntd_congresso[i].estrato_A1 << endl;
    cout << "Estrato A2: " << qntd_congresso[i].estrato_A2 << endl;
    cout << "Estrato B1: " << qntd_congresso[i].estrato_B1 << endl;
    cout << "Estrato B2: " << qntd_congresso[i].estrato_B2 << endl;
    cout << "Estrato B3: " << qntd_congresso[i].estrato_B3 << endl;
    cout << "Estrato B4: " << qntd_congresso[i].estrato_B4 << endl;
    cout << "Estrato B5: " << qntd_congresso[i].estrato_B5 << endl;
    cout << "Estrato C: " << qntd_congresso[i].estrato_C << endl;
    cout << "Sem Estrato: " << qntd_congresso[i].sem_estrato << endl;
    cout << endl;
    cout << "Docente: " << docente_arq[i].nome_completo << endl;
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
    cout << endl;
    cout << "Dissertações de mestrado: " << qntd_orientacao[i].dissertacao_mestrado << endl;
    cout << "Trabalho de conclusao de curso: " << qntd_orientacao[i].trabalho_conclusao << endl;
    cout << "Iniciações científicas: " << qntd_orientacao[i].iniciacao_cientifica << endl;
    cout << "Teses de doutorado: " << qntd_orientacao[i].tese_doutorado << endl;
    cout << endl;
}*/

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

  ofstream output;
  output.open("arquivo.csv");
  for (i = 1;i < size_docente;i++){
    for (j = i + 1;j < size_docente;j++){
      if (pontuacao_final[i].somatorio < pontuacao_final[j].somatorio){
        strcpy(aux_docente, docente_arq[i].nome_completo);
        strcpy(docente_arq[i].nome_completo,docente_arq[j].nome_completo);
        strcpy(docente_arq[j].nome_completo,aux_docente);

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
    output << docente_arq[i].nome_completo << endl;
    output << pontuacao_final[i].pont_con_A1 << "," << pontuacao_final[i].pont_con_A2 << "," << pontuacao_final[i].pont_con_B1 << "," << pontuacao_final[i].pont_con_B2 << "," << pontuacao_final[i].pont_con_B3 << "," << pontuacao_final[i].pont_con_B4 << "," << pontuacao_final[i].pont_con_B5 << "," <<
    pontuacao_final[i].pont_con_C << "," << pontuacao_final[i].pont_con_SE << "," << pontuacao_final[i].pont_per_A1 << "," << pontuacao_final[i].pont_per_A2 << "," << pontuacao_final[i].pont_per_B1 << "," << pontuacao_final[i].pont_per_B2 << "," << pontuacao_final[i].pont_per_B3 << "," <<
    pontuacao_final[i].pont_per_B4 << "," << pontuacao_final[i].pont_per_B5 << "," << pontuacao_final[i].pont_per_C << "," << pontuacao_final[i].pont_per_SE << "," << pontuacao_final[i].pont_IC << "," << pontuacao_final[i].pont_TC << "," << pontuacao_final[i].pont_DM << "," <<
    pontuacao_final[i].pont_TD << "," << pontuacao_final[i].somatorio << endl;
  }
  output.close();

  delete [] docente_arq;
  delete [] orientacao_arq;
  delete [] producao_arq;
  delete [] periodico_arq;
  delete [] congresso_arq;
  delete [] qntd_orientacao;
  delete [] qntd_producao;
  delete [] qntd_periodico;
  delete [] qntd_congresso;
  delete [] pontuacao_final;

  return 0;
}
