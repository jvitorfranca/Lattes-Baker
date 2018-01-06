#include<iostream>
#include<string.h>
#include<fstream>
#include "arquivos.h"

using namespace std;

int main(int argc, char const *argv[]) {
  // criado vetores das estruturas criadas
  docente *docente_arq;
  docente *docente_cpy;
  orientacao *orientacao_arq;
  producao *producao_arq;
  periodico *periodico_arq;
  congresso *congresso_arq;
  avaliacao *regra;

  // variaveis que conterão os tamanhos dos arquivos
  int i, j, k, l;
  int size_docente;
  int size_orientacao;
  int size_producao;
  int size_periodico;
  int size_congresso;

  // strings que conterão o nome dos arquivos
  char arquivo_docente[50];// = "arquivosTrabalho/docentes.csv";
  char arquivo_orientacao[50];// = "arquivosTrabalho/orientacao.csv";
  char arquivo_producao[50];// = "arquivosTrabalho/producao_V2.csv";
  char arquivo_periodico[50];// = "arquivosTrabalho/qualis_capes_periodicos.csv";
  char arquivo_congresso[50];// = "arquivosTrabalho/qualis_capes_congressos.csv";
  char arquivo_regra[50];
  char *saida;
  char *nome_saida;
  int ano_maximo;
  int ano_minimo;
  int num_regras;

  cout << "informe o arquivo de docentes(ex: docentes.csv) " << endl;
  cin >> arquivo_docente;
  cout << "informe o arquivo de orientacoes(ex: orientacao.csv) " << endl;
  cin >> arquivo_orientacao;
  cout << "informe o arquivo de producoes(ex: producao_V2.csv) " << endl;
  cin >> arquivo_producao;
  cout << "informe o arquivo de congressos(ex: qualis_capes_congressos.csv) " << endl;
  cin >> arquivo_congresso;
  cout << "informe o arquivo de periodicos(ex: qualis_capes_periodicos.csv) " << endl;
  cin >> arquivo_periodico;

  // variaveis recebem o numero de linhas de cada arquivo
  size_docente = numLinhas(arquivo_docente);
  size_orientacao = numLinhas(arquivo_orientacao);
  size_producao = numLinhas(arquivo_producao);
  size_periodico = numLinhas(arquivo_periodico);
  size_congresso = numLinhas(arquivo_congresso);

  // os vetores recebem os dados das structs
  docente_arq = retornaDocente(size_docente, arquivo_docente);
  docente_cpy = retornaDocente(size_docente, arquivo_docente);
  orientacao_arq = retornaOrientacao(size_orientacao, arquivo_orientacao);
  producao_arq = retornaProducoes(size_producao, arquivo_producao);
  periodico_arq = retornaPeriodico(size_periodico, arquivo_periodico);
  congresso_arq = retornaCongresso(size_congresso, arquivo_congresso);

  // vetores que conterão a quantidade de cada arquivos
  conta_orientacao *qntd_orientacao;
  conta_producao *qntd_producao;
  conta_periodico *qntd_periodico;
  conta_congresso *qntd_congresso;
  conta_pontuacao *pontuacao_final;

  // quantidade de orientacoes e produções
  qntd_orientacao = qntdOrientacao(size_docente, size_orientacao, docente_arq, orientacao_arq);
  qntd_producao = qntdProducao(size_docente, size_producao, docente_arq, producao_arq);

  // nome que serao do arquivo de saida
  saida = new char [20];
  nome_saida = new char [20];

  cout << "informe o numero de regras que serão submetidas: " << endl;
  cin >> num_regras;

if (num_regras >= 0){
  regra = new avaliacao [num_regras];
  // laço que criará o número de arquivo de acordo com as regras submetidas
  for (l = 0;l < num_regras;l++){
    cout << "informe o arquivo de avaliação(ex: regra_de_aval.txt) " << endl;
    cin >> arquivo_regra;

    cout << "informe o ano minimo: " << endl;
    cin >> ano_minimo;

    cout << "informe o ano maximo: " << endl;
    cin >> ano_maximo;

    if (ano_minimo > ano_maximo){
      cout << "o ano mínimo é maior que o ano máximo!" << endl;
      break;
    }

    regra[l] = retornaPontuacoes(arquivo_regra);

    // usa-se a cópia pois o arquivo é alterado durante a ordenação
    for (i = 0;i < size_docente;i++){
      strcpy(docente_cpy[i].id_docente, docente_arq[i].id_docente);
      strcpy(docente_cpy[i].nome_completo, docente_arq[i].nome_completo);
    }

    // quantidade de estratos dos congressos
    qntd_congresso = qntdCongresso(size_docente, size_producao, size_congresso, ano_minimo, ano_maximo, docente_cpy, producao_arq, congresso_arq, qntd_producao);

    // quantidade de estratos dos periodicos
    qntd_periodico = qntdPeriodico(size_docente, size_producao, size_periodico, ano_minimo, ano_maximo, l, docente_cpy, producao_arq, periodico_arq, regra);

    // calculo das pontuações finais
    pontuacao_final = pontuacaoFinal(size_docente, l, qntd_congresso, qntd_periodico, qntd_orientacao, regra);

    saida = retornaNome(arquivo_regra);

    // ordenação das pontuações
    ordenaPontuacao(size_docente, pontuacao_final, docente_cpy);

    nome_saida = strcat(saida, ".csv");

    // criação dos arquivos relativos a cada regra
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
    cout << "arquivo criado com sucesso!" << endl;
  }
} else {
  cout << "número de regras inválido" << endl;
  return 0;
}
  // todas os vetores alocados são deletados
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
