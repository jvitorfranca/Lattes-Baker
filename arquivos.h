// biblioteca que conterá os as estruturas principais

#ifndef _ARQUIVOS_H
#define _ARQUIVOS_H

#include<iostream>
#include<string.h>
#include<fstream>

//estrutura que receberá as informações do docente
typedef struct _docentes_{
  char id_docente[100];
  char nome_completo[100];
}docente;

// estrutura que conterá as informações do arquivo de avaliação
typedef struct _avaliacao_{
    char area_de_avaliacao[50];
    int pontuacao[22];
}avaliacao;

//estrutura que receberá as informações do arquivo de orientacao
typedef struct _orientacao_{
  char id_docente[100];
  char id_orientacao[100];
  char tipo_orientacao[100];
  char titulo[500];
  char nome_orientando[100];
  char ano[20];
}orientacao;

//estrutura do arquivo de produção
typedef struct _producao_{
  char id_docente[100];
  char id_producao[300];
  char tipo_producao[300];
  char issn[50];
  char titulo[300];
  char local[300];
  int ano_trabalho;
}producao;

// estrutura que receberá as informações do arquivo qualis_capes_congressos
typedef struct _congressos_{
  char nome_congresso[100];
  char sigla_congresso[20];
  char estrato_qualis[10];
}congresso;

// estrutura que receberá as informações do arquivo periodico
typedef struct _periodicos_{
  char issn[50];
  char nome_periodico[200];
  char area_de_avaliacao[100];
  char estrato_qualis[10];
}periodico;

// estrutura que armazena o numero de artigos e trabalho em evento de cada docente
typedef struct _producao_por_docente_{
  int artigo_publicado;
  int trabalho_evento;
}conta_producao;

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

// estrutura que armazena a quantidade de orientacoes de cada docente
typedef struct _orientacao_por_docente_{
  int iniciacao_cientifica;
  int trabalho_conclusao;
  int dissertacao_mestrado;
  int tese_doutorado;
}conta_orientacao;

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

// estrutura que calcula a quantidade final de cada pontuação
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

//função que recebe o arquivo e retorna seu número de linhas
int numLinhas(char *arquivo);

//função que recebe o tamanho do arquivo docente e retora um vetor com as informações contidas no aquivo
docente *retornaDocente(int size_docente, char arquivo[]);

//função que recebe o tamanho do arquivo orientacao e retorna um vetor com as informações contidas no aquivo
orientacao *retornaOrientacao(int size_orientacao, char arquivo[]);

//função que recebe o tamanho do arquivo producao e retorna um vetor com as informações contidas no aquivo
producao *retornaProducoes(int size_producao, char arquivo[]);

//função que recebe o tamanho do arquivo periodico e retorna um vetor com as informações contidas no aquivo
periodico *retornaPeriodico(int size_periodico, char arquivo[]);

//função que recebe o tamanho do arquivo congresso e retorna um vetor com as informações contidas no aquivo
congresso *retornaCongresso(int size_congresso, char arquivo[]);

//função que recebe o tamanho do arquivo de avaliação e retorna um vetor com as informações contidas no aquivo
avaliacao retornaPontuacoes(char regra_avaliacao[]);

//função que conta a quantidade de orientacoes de cada docente
conta_orientacao *qntdOrientacao(int size_docente, int size_orientacao, docente *docente_arq, orientacao *orientacao_arq);

//função que conta a quantidade de produções de cada docentes
conta_producao *qntdProducao(int size_docente, int size_producao, docente *docente_arq, producao *producao_arq);

//função que conta a quantidade de congressos dos docentes
conta_congresso *qntdCongresso(int size_docente, int size_producao, int size_congresso, int ano_minimo, int ano_maximo, docente *docente_cpy, producao *producao_arq, congresso *congresso_arq, conta_producao *qntd_producao);

//função que conta a quantidade de periódicos de cada docente
conta_periodico *qntdPeriodico(int size_docente, int size_producao, int size_periodico, int ano_minimo, int ano_maximo, int l, docente *docente_arq, producao *producao_arq, periodico *periodico_arq, avaliacao *regra);

//função que calcula a pontuação final dos docentes
conta_pontuacao *pontuacaoFinal(int size_docente, int l, conta_congresso *qntd_congresso, conta_periodico *qntd_periodico, conta_orientacao *qntd_orientacao, avaliacao *regra);

//função que ordena as pontuações dos docentes
void ordenaPontuacao(int size_docente, conta_pontuacao *pontuacao_final, docente *docente_cpy);

//função que recebe o nome do arquivo da regra e retorna seu nome sem a extensão
char *retornaNome(char arquivo_regra[]);

#endif
