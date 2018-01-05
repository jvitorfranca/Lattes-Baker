#include<iostream>
#include<string.h>
#include<fstream>
#include "arquivos.h"

using namespace std;

int main(int argc, char const *argv[]) {
  docente *docente_arq;
  docente *docente_cpy;
  orientacao *orientacao_arq;
  producao *producao_arq;
  periodico *periodico_arq;
  congresso *congresso_arq;
  avaliacao *regra;

  int i, j, k, l;
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
  char arquivo_regra[50];
  char *saida;
  char *nome_saida;
  int ano_maximo;
  int ano_minimo;
  int num_regras;

  /*cout << "informe o arquivo de docentes: " << endl;
  cin >> arquivo_docente;
  cout << "informe o arquivo de orientacoes: " << endl;
  cin >> arquivo_orientacao;
  cout << "informe o arquivo de producoes: " << endl;
  cin >> arquivo_producao;
  cout << "informe o arquivo de congresos: " << endl;
  cin >> arquivo_congresso;
  cout << "informe o arquivo de periodicos: " << endl;
  cin >> arquivo_periodico;*/

  size_docente = numLinhas(arquivo_docente);
  size_orientacao = numLinhas(arquivo_orientacao);
  size_producao = numLinhas(arquivo_producao);
  size_periodico = numLinhas(arquivo_periodico);
  size_congresso = numLinhas(arquivo_congresso);

  docente_arq = retornaDocente(size_docente, arquivo_docente);
  docente_cpy = retornaDocente(size_docente, arquivo_docente);
  orientacao_arq = retornaOrientacao(size_orientacao, arquivo_orientacao);
  producao_arq = retornaProducoes(size_producao, arquivo_producao);
  periodico_arq = retornaPeriodico(size_periodico, arquivo_periodico);
  congresso_arq = retornaCongresso(size_congresso, arquivo_congresso);

  conta_orientacao *qntd_orientacao;
  conta_producao *qntd_producao;
  conta_periodico *qntd_periodico;
  conta_congresso *qntd_congresso;
  conta_pontuacao *pontuacao_final;

  qntd_orientacao = qntdOrientacao(size_docente, size_orientacao, docente_arq, orientacao_arq);
  qntd_producao = qntdProducao(size_docente, size_producao, docente_arq, producao_arq);

  saida = new char [20];
  nome_saida = new char [20];

  cout << "informe o numero de regras que serão submetidas: " << endl;
  cin >> num_regras;

  regra = new avaliacao [num_regras];

for (l = 0;l < num_regras;l++){
  cout << "informe o arquivo de avaliação: " << endl;
  cin >> arquivo_regra;

  cout << "informe o ano minimo: " << endl;
  cin >> ano_minimo;

  cout << "informe o ano maximo: " << endl;
  cin >> ano_maximo;

  regra[l] = retornaPontuacoes(arquivo_regra);

  for (i = 0;i < size_docente;i++){
    strcpy(docente_cpy[i].id_docente, docente_arq[i].id_docente);
    strcpy(docente_cpy[i].nome_completo, docente_arq[i].nome_completo);
  }

  qntd_congresso = qntdCongresso(size_docente, size_producao, size_congresso, ano_minimo, ano_maximo, docente_cpy, producao_arq, congresso_arq, qntd_producao);

  qntd_periodico = qntdPeriodico(size_docente, size_producao, size_periodico, ano_minimo, ano_maximo, l, docente_cpy, producao_arq, periodico_arq, regra);

  pontuacao_final = pontuacaoFinal(size_docente, l, qntd_congresso, qntd_periodico, qntd_orientacao, regra);

  saida = retornaNome(arquivo_regra);

  ordenaPontuacao(size_docente, pontuacao_final, docente_cpy);

  nome_saida = strcat(saida, ".csv");

  ofstream output;
  output.open(nome_saida);
  for (i = 1;i < size_docente;i++){
    output << docente_cpy[i].nome_completo << endl;
    output << pontuacao_final[i].pont_con_A1 << "," << pontuacao_final[i].pont_con_A2 << "," << pontuacao_final[i].pont_con_B1 << "," << pontuacao_final[i].pont_con_B2 << "," << pontuacao_final[i].pont_con_B3 << "," << pontuacao_final[i].pont_con_B4 << "," << pontuacao_final[i].pont_con_B5 << "," <<
    pontuacao_final[i].pont_con_C << "," << pontuacao_final[i].pont_con_SE << "," << pontuacao_final[i].pont_per_A1 << "," << pontuacao_final[i].pont_per_A2 << "," << pontuacao_final[i].pont_per_B1 << "," << pontuacao_final[i].pont_per_B2 << "," << pontuacao_final[i].pont_per_B3 << "," <<
    pontuacao_final[i].pont_per_B4 << "," << pontuacao_final[i].pont_per_B5 << "," << pontuacao_final[i].pont_per_C << "," << pontuacao_final[i].pont_per_SE << "," << pontuacao_final[i].pont_IC << "," << pontuacao_final[i].pont_TC << "," << pontuacao_final[i].pont_DM << "," <<
    pontuacao_final[i].pont_TD << "," << pontuacao_final[i].somatorio << endl;
  }
  output.close();
}

  delete [] docente_arq;
  delete [] docente_cpy;
  delete [] orientacao_arq;
  delete [] producao_arq;
  delete [] periodico_arq;
  delete [] congresso_arq;
  delete [] qntd_orientacao;
  delete [] qntd_producao;
  delete [] qntd_periodico;
  delete [] qntd_congresso;
  delete [] pontuacao_final;
  delete [] regra;
  delete [] saida;

  return 0;
}
