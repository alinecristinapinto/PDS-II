#include "fila.h"

Fila::Fila(){
    this->primeiro_ = nullptr;
    this->ultimo_ = nullptr;
}

string Fila::primeiro(){
    return this->primeiro_->chave;
}

string Fila::ultimo(){
    return this->ultimo_->chave;
}

bool Fila::vazia(){
    return this->primeiro_ == nullptr;
}

void Fila::Inserir(string k){
    No* novoElemento = new No{k, nullptr};
    
    if(this->vazia()){
        this->primeiro_ = novoElemento;
        this->ultimo_ = novoElemento;
    } else {
        this->ultimo_->proximo = novoElemento;
        this->ultimo_ = novoElemento;
    }
}

void Fila::Remover(){
    No* primeiro = this->primeiro_;
    
    this->primeiro_ = this->primeiro_->proximo;
    
    delete primeiro;
}

int Fila::tamanho(){
    if(this->vazia()) return 0;
    
    int tamanho = 1;
    No* atual = this->primeiro_;
    
    while(atual->proximo != nullptr){
        atual = atual->proximo;
        tamanho ++;
    }
    
    return tamanho;
}

Fila::~Fila() {
    while(!this->vazia()){
        this->Remover();
    }
}
