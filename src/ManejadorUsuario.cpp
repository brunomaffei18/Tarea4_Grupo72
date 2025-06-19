#include "../include/ManejadorUsuario.h"

ManejadorUsuario* ManejadorUsuario::instancia = nullptr;

ManejadorUsuario* ManejadorUsuario::getManejadorUsuario(){
    if(instancia==nullptr)
        instancia= new ManejadorUsuario();
    return instancia;
}

ManejadorUsuario::ManejadorUsuario(){};

void ManejadorUsuario::altaCliente(std::string nickname, std::string contrasena, std::string nombre, std::string email,std::string apellido, std::string documento){
    //Asumo que esta funcion solo se convoca si se verifica si el  Cliente no esta ingresado actualmente
    
}