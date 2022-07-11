#include "hamburguer.hpp"

/*
 *** Hamburguer::descricao() ***
 * Note que aqui voce deve retornar uma descricao detalhada do Hamburguer.
 *
 * Exemplos:
 * 1X Hamburguer X-tudo artesanal.
 * 1X Hamburguer X-tudo simples.
*/
std::string Hamburguer::descricao() const {
  std::string descricao = std::to_string(this->m_qtd) + "X "
                        + "Hamburguer " + this->tipo + " " 
                        + std::string(this->artesanal ? "artesanal." : "simples.");

  return descricao;
}

Hamburguer::Hamburguer(const std::string& tipo,
                       bool artesanal,
                       int qtd,
                       float valor_unitario) {
  this->tipo = tipo;
  this->artesanal = artesanal;
  this->m_qtd = qtd;
  this->m_valor_unitario = valor_unitario;
}