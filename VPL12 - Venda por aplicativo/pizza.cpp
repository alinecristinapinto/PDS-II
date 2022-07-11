#include "pizza.hpp"

/*
 * Note que aqui voce deve retornar uma descricao detalhada da pizza.
 *
 * Exemplos:
 * 2X Pizza Calabresa, 4 pedacos e borda recheada.
 * 2X Pizza Calabresa, 4 pedacos sem borda recheada.
*/
std::string Pizza::descricao() const {
  std::string descricao = std::to_string(this->m_qtd) + "X Pizza "
                        + this->sabor + ", " 
                        + std::to_string(this->pedacos) + " pedacos e " 
                        + std::string(this->borda_recheada ? "borda recheada." : "sem borda recheada.");
   
  return descricao;
}

Pizza::Pizza(const std::string& sabor,
             int pedacos,
             bool borda_recheada,
             int qtd,
             float valor_unitario) {
  this->sabor = sabor;
  this->pedacos = pedacos;
  this->borda_recheada = borda_recheada;
  this->m_qtd = qtd;
  this->m_valor_unitario = valor_unitario;
}