#include "japonesa.hpp"

/*
 *** Japonesa::descricao() *** 
 * Note que aqui voce deve retornar uma descricao detalhada da comida
 * japonesa.
 *
 * Exemplos:
 * 1X Comida japonesa - Combo 1, 4 sushis, 5 temakis e 6 hots.
 * 1X Comida japonesa - Combo 2, 5 sushis, 6 temakis e 8 hots.
*/
std::string Japonesa::descricao() const {
  std::string descricao = std::to_string(this->m_qtd) + "X Comida japonesa - " 
                        + this->combinado + ", "
                        + std::to_string(this->sushis) + " sushis, "
                        + std::to_string(this->temakis) + " temakis e "
                        + std::to_string(this->hots) + " hots.";
  
  return descricao;
}

Japonesa::Japonesa(const std::string& combinado,
                   int sushis,
                   int temakis,
                   int hots,
                   int qtd,
                   float valor_unitario) {
  this->combinado = combinado;
  this->sushis = sushis;
  this->temakis = temakis;
  this->hots = hots;
  this->m_qtd = qtd;
  this->m_valor_unitario = valor_unitario;
}