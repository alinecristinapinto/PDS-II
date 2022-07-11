#include <string>
#include <iostream>

#include "Estoque.hpp"

/**
 * \brief Adiciona uma mercadoria ao estoque.
 *
 * \details
 * Este metodo adiciona qtd novas unidades de uma certa mercadoria ao
 * estoque. Se a mercadoria jah existe, entao a quantidade existente deve
 * ser incrementada. Se a mercadoria nao existe, entao uma nova entrada
 * para aquela mercadoria deve ser criada. A quantidade de novas unidades
 * eh dada pelo parametro qtd.
 *
 * \param s O nome da mercadoria que estah sendo inserida.
 * \param qtd A quantidade de unidades da mercadoria que serah inseriada.
*/
void Estoque::add_mercadoria(const std::string& mercadoria, unsigned int qtd) {
  auto dados_mercadoria = this->mercadorias.find(mercadoria);
  
  if(dados_mercadoria == this->mercadorias.end()){
    this->mercadorias.insert(std::pair<std::string, unsigned int>(mercadoria, qtd));
  } else {
    dados_mercadoria->second += qtd;   
  }
}

/**
 * \brief Remove unidades de uma mercadoria do estoque.
 *
 * \details
 * Este metodo remove 'qtd' unidades de uma certa mercadoria do estoque.
 * Duas situacoes de erro devem ser tratadas:
 * 1. Caso a quantidade da mercadoria seja inferior a qtd, a seguinte
 *    mensagem deve ser impressa, sendo <s> o nome da mercadoria:
 *
 * <s> insuficiente
 *
 * 2. Caso a mercadoria nao exista no estoque, entao deve ser impressa a
 *    mensage abaixo, sendo <s> o nome da mercadoria:
 *
 * <s> inexistente
 *
 * \param s O nome da mercadoria que estah tendo sua quantidade reduzida.
 * \param qtd A quantidade de unidades da mercadoria que serah removida.
*/
void Estoque::sub_mercadoria(const std::string& mercadoria, unsigned int qtd) {
  auto dados_mercadoria = this->mercadorias.find(mercadoria);
  
  if(dados_mercadoria == this->mercadorias.end()){
    std::cout << mercadoria << " inexistente";
    return;
  }
  
  if(dados_mercadoria->second < qtd) {
    std::cout << mercadoria << " insuficiente";
    return;
  }
  
  dados_mercadoria->second -= qtd;
}

/**
 * \brief Informa a quantidade da mercadoria 's' no estoque.
 *
 * \param s O nome da mercadoria de interesse.
 *
 * \return Zero, se 's' nao estiver presente no estoque, ou a quantidade
 * de 's', caso contrario.
*/
unsigned int Estoque::get_qtd(const std::string& mercadoria) const {
  auto dados_mercadoria = this->mercadorias.find(mercadoria);
  
  return dados_mercadoria->second;
}

/**
 * \brief Imprime a lista das mercadorias presentes no estoque.
 *
 * \details
 * Esta funcao produz uma saida da seguinte forma:
 *
 * mercadora1, qtd1
 * mercadora2, qtd2
 * ...
 * mercadorian, qtdn
 *
 * Sendo "mercadoriax" o nome de uma mercadoria, e "qtdx" a quantidade
 * daquela mercadoria. As mercadorias devem ser impressas em ordem
 * alfabetica. O nome da mercadoria deve ser seguido por uma virgula, e
 * entao por um espaco, e entao pela quantidade da mercadoria. Note que esta
 * saida eh um arquivo CSV (comma separated values) valido.
*/
void Estoque::imprime_estoque() const {
  for(const auto& mercadoria : this->mercadorias){
      std::cout << mercadoria.first << ", " << mercadoria.second << std::endl;
  }
}

/**
 * \brief Adiciona um conjunto de mercadorias ao estoque.
 *
 * \details
 * Este metodo junta dois estoques, somando as mercadorias do segundo
 * estoque ao primeiro. Em outras palavras, o comando e0 += e1 vai inserir
 * em e0 cada uma das mercadorias presente em e1. O estoque e1 permanece
 * inalterado.
 *
 * \param rhs O estoque da direita na operacao "lhs += rhs".
*/
Estoque& Estoque::operator += (const Estoque& rhs) {
  for(const auto& mercadoria :  rhs.mercadorias){
    add_mercadoria(mercadoria.first, mercadoria.second);  
  }
  
  return *this;
}

/**
 * \brief Remove um conjunto de mercadorias ao estoque.
 *
 * \details
 * O comando lhs -= rhs subtrai de lhs cada mercadoria presente em rhs.
 * O estoque rhs permanece inalterado.
 *
 * \param rhs O estoque da direita na operacao "lhs -= rhs".
*/
Estoque& Estoque::operator -= (const Estoque& rhs) {
  for(const auto& mercadoria :  rhs.mercadorias){
    sub_mercadoria(mercadoria.first, mercadoria.second);  
  }
  
  return *this;
}

/**
 * \brief Determina se um estoque estah contido em outro.
 *
 * \details
 * A operacao "lhs < rhs" eh verdade se as condicoes abaixo sao verdade:
 *
 * Para cada mercadoria m em lhs:
 * a. Existe m em rhs;
 * b. A quantidade de m em rhs eh maior que a quantidade de m em lhs
 *
 * \param lhs O sub-estoque.
 * \param qtd O super-estoque.
*/
bool operator < (Estoque& lhs, Estoque& rhs) {
  for(const auto& mercadoria : lhs.mercadorias){
      auto rhs_aux = rhs.mercadorias.find(mercadoria.first);
      
      if(rhs_aux == rhs.mercadorias.end()) return false;
      if(mercadoria.second >= rhs_aux->second) return false;
  }
  
  return true;
}

/**
 * \brief Determina se um estoque contem outro.
 *
 * \details
 * A operacao "lhs > rhs" eh verdade se as condicoes abaixo sao verdade:
 *
 * Para cada mercadoria m em rhs:
 * a. Existe m em lhs;
 * b. A quantidade de m em lhs eh maior que a quantidade de m em rhs
 *
 * Note que se dois estoques contem mercadorias diferentes, entao nao serah
 * o caso que nem "lhs > rhs" nem "lhs < rhs".
 *
 * \param lhs O super-estoque.
 * \param qtd O sub-estoque.
*/
bool operator > (Estoque& lhs, Estoque& rhs) {
  for(const auto& mercadoria : rhs.mercadorias){
    auto lhs_aux = lhs.mercadorias.find(mercadoria.first);
    
    if(lhs_aux == lhs.mercadorias.end()) return false;
    if(mercadoria.second >= lhs_aux->second) return false;
  }
  
  return true;
}