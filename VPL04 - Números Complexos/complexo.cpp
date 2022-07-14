// Copyright 2022 Universidade Federal de Minas Gerais (UFMG)

#include "complexo.h"

#include <cmath>

Complexo::Complexo() {
  this->real_ = 0;
  this->imag_ = 0;
}

Complexo::Complexo(double a, double b) {
  this->real_ = sqrt(a*a + b*b);
  this->imag_ = atan2(b, a); 
}

double Complexo::real() {
  return this->real_ * cos(this->imag_);
}

double Complexo::imag() {
  return this->real_ * sin(this->imag_);
}

// TODO
bool Complexo::igual(Complexo x) {
  return this->real() == x.real() && this->imag() == x.imag();
}

void Complexo::Atribuir(Complexo x) {
  this->real_ = x.real_;
  this->imag_ = x.imag_;
}

double Complexo::modulo() {
  return this->imag_;
}

Complexo Complexo::conjugado() {
  Complexo c; 
  c.real_ = this->real_;
  c.imag_ = -this->imag_;
  return c;
}

Complexo Complexo::simetrico() {
  Complexo c;
  c.real_ = this->real_;
  c.imag_ = this->imag_ + M_PI;
  return c;
}

Complexo Complexo::inverso() {
  Complexo i;
  i.real_ = 1.0 / this->real_;
  i.imag_ = -this->imag_;
  return i;
}

Complexo Complexo::somar(Complexo y) {
  Complexo s((this->real() + y.real()), (this->imag() + y.imag()));
  return s;
}

Complexo Complexo::subtrair(Complexo y) {
  Complexo s(-y.real(), -y.imag());
  return this->somar(s);
}

Complexo Complexo::multiplicar(Complexo y) {
  Complexo p;
  p.real_ = this->real_ * y.real_;
  p.imag_ = this->imag_ + y.imag_;
  return p;
}

Complexo Complexo::dividir(Complexo y) {
  return this->multiplicar(y.inverso());
}
