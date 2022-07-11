#include "venda.hpp"

#include <iomanip>

/**
 *** Venda::~Venda() *** 
 * Aqui voce deve deletar os ponteiros contidos na lista m_pedidos
*/
Venda::~Venda() {
   this->m_pedidos.clear();
}

void Venda::adicionaPedido(Pedido* p) {
  this->m_pedidos.push_back(p);
}

/**
 *** Venda::imprimeRelatorio() ***
 * Aqui voce tem que percorrer a lista de todos os pedidos e imprimir o resumo
 * de cada um. Por ultimo, devera ser exibido o total de venda e a quantidade
 * de pedidos processados.
 * Exemplo de saida:
 * Pedido 1
 * 2X Pizza Calabresa, 4 pedacos e borda recheada.
 * 1X Pizza Frango com catupity, 6 pedacos e sem borda recheada.
 * Endereco: Rua Lavras 158 Sao Pedro, Belo Horizonte
 * Relatorio de Vendas
 * Total de vendas: R$ 249.70
 * Total de pedidos: 1
*/
void Venda::imprimeRelatorio() const {
  float total_vendas = 0;
  int qtd_pedidos = 0;
  
  for(const auto& pedido : this->m_pedidos){
    total_vendas += pedido->calculaTotal();
    qtd_pedidos ++;
    
    std::cout << "Pedido " << qtd_pedidos << std::endl;
    std::cout << pedido->resumo() << std::endl;
  }
  
  std::cout << "Relatorio de Vendas" << std::endl;
  std::cout << std::fixed << std::setprecision(2) << "Total de vendas: R$ " << total_vendas << std::endl;
  std::cout << "Total de pedidos: " << qtd_pedidos << std::endl;
}