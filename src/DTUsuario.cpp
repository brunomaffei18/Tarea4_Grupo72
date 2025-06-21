#include "../include/DTUsuario.h"
#include <iostream>
#include <string>

DTUsuario::DTUsuario(std::string nickname, std::string nombre) {
    this->nickname = nickname;
    this->nombre = nombre;
}

std::string DTUsuario::getNickname() {
    return nickname;
}

std::string DTUsuario::getNombre() {
    return nombre;
}

bool DTUsuario::operator<(const DTUsuario& other) const {
    return nickname < other.nickname;
}

 
std::ostream& operator<<(std::ostream& os,  DTUsuario& dt){
  os<< "- Nickname: " << dt.getNickname()<< ", Nombre: " << dt.getNombre() << std::endl;
  return os;
}