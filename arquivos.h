// biblioteca que conterá os as estruturas principais

#ifndef _ARQUIVOS_H
#define _ARQUIVOS_H

#include<iostream>
#include<string.h>
#include<fstream>
#include "retornaDocentes.cpp"
#include "retornaLinhas.cpp"
#include "retornaOrientacao.cpp"
#include "retornaProducao.cpp"
#include "retornaQualisPeriodicos.cpp"
#include "retornaQualisCongressos.cpp"
#include "retornaNome.cpp"
#include "avaliacao.cpp"

int numLinhas(char *arquivo);

docente *retornaDocente(int size_docente);

orientacao *retornaOrientacao(int size_orientacao);

producao *retornaProducoes(int size_producao);

periodico *retornaPeriodico(int size_periodico);

congresso *retornaCongresso(int size_congresso);

avaliacao retornaPontuacoes(char regra_avaliacao[]);

char *retornaNome(char arquivo_regra[]);

#endif
