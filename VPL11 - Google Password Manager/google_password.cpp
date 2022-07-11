#include "google_password.hpp"

#include <iostream>

void GooglePassword::insert(const std::string& url,
                            const std::string& login,
                            const std::string& password) {
    if (this->m_passwords.find(url) != this->m_passwords.end()) return;
    if (!checkPassword(password)) return;
    
    Usuario usuario(login, password);
    this->m_passwords.insert(std::pair<std::string, Usuario>(url, usuario));
}

void GooglePassword::remove(const std::string& url) {
  this->m_passwords.erase(url);
}

/**
 *** GooglePassword::update(...) ***
 * Este metodo nao pode inserir novas credenciais, apenas atualizar as
 * ja existentes. Alem disso, o login e/ou senha do usuario so podem ser
 * atualizados se a senha armazenada no sistema for igual a old_password.
 * Nao esqueca de verificar se o novo password tambem e valido.
*/
void GooglePassword::update(const std::string& url,
                            const std::string& login,
                            const std::string& old_password,
                            const std::string& new_password) {
  
  auto data = this->m_passwords.find(url);
  
  if (data == this->m_passwords.end()) return;
  if (old_password != data->second.getPassword()) return;
  if (!checkPassword(new_password)) return;
  
  data->second.setLogin(login);
  data->second.setPassword(new_password);
}

/**
 *** GooglePassword::printPasswords() ***
 * Exemplo de saida:
 * 3
 * aaa.site.com: login and password
 * www.site.com: login and password
 * zzz.site.com: login and password
 *
*/
void GooglePassword::printPasswords() {
    std::cout << this->m_passwords.size() << std::endl;
    
    for (const auto& data : this->m_passwords) {
       std::cout << data.first << ": " << data.second.getLogin() << " and " << data.second.getPassword() << std::endl;
    }
}

/**
 *** GooglePassword::checkPassword(...) ***
 * Condicao 1: A senha nao pode ter a seguencia '123456'.
 * Condicao 2: A senha nao pode ter mais do que 50 caracteres (no maximo 50).
 * Condicao 3: A senha nao pode ter menos do que 6 caracteres (no minimo 6).
 * Condicao 4: A senha nao pode ter caracteres em branco ' '.
*/
bool GooglePassword::checkPassword(const std::string& password) const {
    bool contains_invalid_sequence = password.find("123456") != std::string::npos;
    bool more_than_50_characters = password.length() > 50;
    bool less_than_6_characters = password.length() < 6;
    bool contains_blank_character = password.find(" ") != std::string::npos;
    
    return !contains_invalid_sequence 
            && !more_than_50_characters 
            && !less_than_6_characters 
            && !contains_blank_character;
}

