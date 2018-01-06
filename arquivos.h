// biblioteca que conterá os as estruturas principais

#ifndef _ARQUIVOS_H
#define _ARQUIVOS_H

//aqui são recebidos todos os arquivos cpp
#include<iostream>
#include<string.h>
#include<fstream>
#include "retornaAvaliacao.cpp"
#include "retornaDocentes.cpp"
#include "retornaLinhas.cpp"
#include "retornaOrientacao.cpp"
#include "retornaProducao.cpp"
#include "retornaQualisPeriodicos.cpp"
#include "retornaQualisCongressos.cpp"
#include "retornaNome.cpp"
#include "qntdOrientacao.cpp"
#include "qntdProducao.cpp"
#include "qntdCongresso.cpp"
#include "qntdPeriodico.cpp"
#include "pontuacaoFinal.cpp"
#include "ordenaPontuacao.cpp"

//função que recebe o arquivo e retorna seu número de linhas
int numLinhas(char *arquivo);

//função que recebe o tamanho do arquivo docente e retora um vetor com as informações contidas no aquivo
docente *retornaDocente(int size_docente);

//função que recebe o tamanho do arquivo orientacao e retorna um vetor com as informações contidas no aquivo
orientacao *retornaOrientacao(int size_orientacao);

//função que recebe o tamanho do arquivo producao e retorna um vetor com as informações contidas no aquivo
producao *retornaProducoes(int size_producao);

//função que recebe o tamanho do arquivo periodico e retorna um vetor com as informações contidas no aquivo
periodico *retornaPeriodico(int size_periodico);

//função que recebe o tamanho do arquivo congresso e retorna um vetor com as informações contidas no aquivo
congresso *retornaCongresso(int size_congresso);

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
