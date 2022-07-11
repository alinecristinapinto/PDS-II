#include <regex>
#include <math.h>
#include <string>
#include <vector>
#include <sstream>

#include "LineProcessor.hpp"

void LinePrinter::processaLinha(const std::string &str) {
  std::cout << str << std::endl;
}

bool ContadorPopRural::linhaValida(const std::string &str) const {
  // Neste exemplo usaremos expressoes regulares para verificar se uma linha
  // eh valida ou nao.
  //
  // Esta expressao regular eh formada por cinco partes. Cada uma dessas
  // partes eh um dos tres tipos de padrao regular abaixo:
  //
  // \\w+ eh qualquer palavra com um ou mais digitos, letras e sublinhas (_)
  // \\s* eh qualquer sequencia de zero ou mais espacos (inclui tab)
  // \\d+ eh qualquer sequencia de um ou mais digitos
  std::regex regularExpr("\\w+\\s*\\d+\\s*\\d+");

  // A funcao regex_match vai retornar verdadeiro se a string str casa-se com
  // a expressao regular que acabamos de criar:
  return std::regex_match(str, regularExpr);
}

void ContadorPopRural::processaLinha(const std::string &str) {
  //
  // Em geral eh mais facil ler dados de uma string se a string eh transformada
  // em um objeto do tipo stringstream:
  std::stringstream ss(str);
  //
  // Iremos ler os dados da string nestas tres variaveis abaixo:
  std::string nomePais;
  unsigned populacao, percUrbana;
  //
  // Como sabemos que a linha contem string int int, podemos fazer a leitura
  // facilmente usando o operador de streaming:
  ss >> nomePais >> populacao >> percUrbana;
  //
  // Note que precisamos arredondar o valor que serah impresso. O arredondamento
  // serah feito via a funcao floor. Ou seja, decimais serao sempre
  // arredondados para baixo:
  unsigned popRural = floor(populacao - (populacao * (percUrbana/100.0)));
  //
  // Uma vez encontrados os valores que precisam ser impressos, seguimos o
  // modelo do enunciado do exercicio:
  std::cout << popRural << " pessoas vivem no campo no " << nomePais <<
    std::endl;
}

/**
 * \brief invalido: tudo que nao eh numero ([^0-9]) e nao eh espaco ([^\\s])
 */
bool ContadorNumNaturais::linhaValida(const std::string &str) const {
  return !std::regex_search(str, std::regex("[^0-9\\s]"));
}

void ContadorNumNaturais::processaLinha(const std::string &str) {
  if(linhaValida(str)){
    int inicio = 0, fim = 0, soma=0;
    auto numeros_por_espaco = std::regex_replace(str, std::regex("\\s{2,}"), " "); 
 
    while (fim != -1) {
        fim = numeros_por_espaco.find(" ", inicio);
        soma += std::stoi(numeros_por_espaco.substr(inicio, fim - inicio));
        inicio = fim + 1;
    }
    
    std::cout << soma << std::endl;
  }
}

bool LeitorDeFutebol::linhaValida(const std::string &str) const {
  return std::regex_match(str, std::regex("\\s*[A-Za-z]+\\s*\\d+\\s*[A-Za-z]+\\s*\\d+"));
}

void LeitorDeFutebol::processaLinha(const std::string &str) {
  if(linhaValida(str)){
    int inicio = 0, fim = 0;
    std::vector<std::string> jogo;
    auto dados = std::regex_replace(str, std::regex("\\s{2,}"), " ");
    dados = std::regex_replace(dados, std::regex("^\\s+"), ""); 
    dados = std::regex_replace(dados, std::regex("\\s+$"), "");

    while (fim != -1) {
      fim = dados.find(" ", inicio);
      jogo.push_back(dados.substr(inicio, fim - inicio));
      inicio = fim + 1;
    }
    
    if(jogo[1] > jogo[3]) std::cout << "Vencedor: " << jogo[0] << std::endl;
    else if(jogo[1] < jogo[3]) std::cout << "Vencedor: " << jogo[2] << std::endl;
    else std::cout << "Empate" << std::endl;
  }
}

void ContadorDePalavras::processaLinha(const std::string &str) {
  int palavras = 0;
  auto aux = std::regex_replace(str, std::regex("^\\s+"), ""); // remove espaco no inicio
  aux = std::regex_replace(aux, std::regex("\\s+$"), ""); // remove espaco no fim
  
  for (int i = 0; i < aux.length(); i++) {
    int c = aux[i];
    if (isspace(c)) palavras++;
  } 
  
  std::cout << palavras + 1 << std::endl;
}

/**
 * \brief invalido: tudo que nao eh letra e espaco
 */
bool InversorDeFrases::linhaValida(const std::string &str) const {
  return !regex_search(str, std::regex("[^A-Za-z\\s]"));
}

void InversorDeFrases::processaLinha(const std::string &str) {
  if(linhaValida(str)){
    std::vector<std::string> frase;
    int inicio = 0, fim = 0;
    
    while(fim != -1){
      fim = str.find(" ", inicio);
      frase.push_back(str.substr(inicio, fim - inicio));
      inicio = fim + 1;
    }
    
    for (auto i = frase.crbegin(); i != frase.crend(); ++i){
      std::cout << *i << " ";
    }
    std::cout << std::endl;
  }
}

bool EscritorDeDatas::linhaValida(const std::string &str) const {
  std::string dateFormat = "\\s*\\d\\d?/\\d\\d?/\\d{4}";

  return std::regex_match(str, std::regex(dateFormat));
}

void EscritorDeDatas::processaLinha(const std::string &str) {
  std::map<int, std::string> meses;
  
  meses.insert(std::pair<int, std::string>(1, "Jan"));
  meses.insert(std::pair<int, std::string>(3, "Mar"));
  meses.insert(std::pair<int, std::string>(2, "Fev"));
  meses.insert(std::pair<int, std::string>(4, "Abr"));
  meses.insert(std::pair<int, std::string>(5, "Mai"));
  meses.insert(std::pair<int, std::string>(6, "Jun"));
  meses.insert(std::pair<int, std::string>(7, "Jul"));
  meses.insert(std::pair<int, std::string>(8, "Ago"));
  meses.insert(std::pair<int, std::string>(9, "Set"));
  meses.insert(std::pair<int, std::string>(10, "Out"));
  meses.insert(std::pair<int, std::string>(11, "Nov"));
  meses.insert(std::pair<int, std::string>(12, "Dez"));
  
  int delimiter = str.find("/");
  std::string num_mes = "";
 
  while (true) {
    delimiter++;
    int caracter = str[delimiter];
    if(caracter == '/') break;
    num_mes += str.substr(delimiter, 1);
  }
  
  auto mes = meses.find(std::stoi(num_mes));
  std::cout << mes->second << std::endl;
}