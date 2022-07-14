#include "vetor.h"
#include <string>

using namespace std;

Vetor::Vetor(int inicio, int fim){
    int tamanho = fim - inicio + 1;
    
    this->inicio_ = inicio;
    this->elementos_ = new std::string[tamanho];
}

void Vetor::atribuir(int i, std::string valor){
    this->elementos_[(i - this->inicio_)] = valor;
}

string Vetor::valor(int i) const {
    return this->elementos_[(i - this->inicio_)];
}

Vetor::~Vetor(){
    delete[] this->elementos_;
}
