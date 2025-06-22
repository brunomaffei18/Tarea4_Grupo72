#include"../include/Usuario.h"
#include "../include/DTUsuario.h"

Usuario::Usuario(std::string nickname, std::string contrasena, std::string nombre, std::string email){
    this->nickname = nickname;
    this->contrasena = contrasena;
    this->nombre = nombre;
    this->email = email;
}

std::string Usuario::getNickname() const{
    return nickname;
}

std::string Usuario::getContrasena() const{
    return contrasena;
}

std::string Usuario::getNombre() const{
    return nombre;
}

std::string Usuario::getEmail() const{
    return email;
}

DTUsuario Usuario::getDatos() const{
    return DTUsuario(nombre, email);
}

Usuario::~Usuario() {}