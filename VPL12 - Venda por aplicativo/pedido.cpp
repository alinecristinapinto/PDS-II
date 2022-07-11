#include "pedido.hpp"

/**
 *** Pedido::~Pedido() ***
 * Aqui voce deve deletar os ponteiros contidos na lista m_produtos
*/
Pedido::~Pedido() {
  this->m_produtos.clear();
}

void Pedido::setEndereco(const std::string& endereco) {
  this->m_endereco = endereco;
}

float Pedido::calculaTotal() const {
  float total = 0;
  
  for(const auto& produto : this->m_produtos){
    total += produto->getValor() * produto->getQtd();
  }
 
  return total;
}

void Pedido::adicionaProduto(Produto* p) {
  this->m_produtos.push_back(p);
}

/**
 *** Pedido::resumo() ***
 * Aqui voce deve percorrer a lista de produtos para criar um resumo completo
 * do pedido. A cada iteracao, utilize o metodo descricao de cada produto para
 * montar o resumo do pedido. Por fim, adicione o endereco de entrega.
 * Exemplo de saida:
 * 2X Pizza Calabresa, 4 pedacos e borda recheada.
 * Endereco: Rua Lavras 158 Sao Pedro, Belo Horizonte
 *
*/
std::string Pedido::resumo() const {
  std::string resumo = "";
  
  for(const auto& produto : this->m_produtos){
    resumo += produto->descricao() + "\n";
  }
  
  resumo += "Endereco: " + this->m_endereco;

  return resumo;
}