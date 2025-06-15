#include"../include/Usuario.h"
#include "../include/DTUsuario.h"

Usuario::Usuario(std::string nickname, std::string contrasena, std::string nombre, std::string email){
    this->nickname = nickname;
    this->contrasena = contrasena;
    this->nombre = nombre;
    this->email = email;
}

std::string Usuario::getNickname() {
    return nickname;
}

std::string Usuario::getContrasena() {
    return contrasena;
}

std::string Usuario::getNombre() {
    return nombre;
}

std::string Usuario::getEmail() {
    return email;
}

DTUsuario Usuario::getDatos() {
    return DTUsuario(nombre, email);
}