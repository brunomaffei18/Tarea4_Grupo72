#include "../include/ManejadorUsuario.h"

ManejadorUsuario* ManejadorUsuario::instancia = nullptr;

ManejadorUsuario* ManejadorUsuario::getManejadorUsuario(){
    if(instancia==nullptr)
        instancia= new ManejadorUsuario();
    return instancia;
}

ManejadorUsuario::ManejadorUsuario(){};

bool ManejadorUsuario::existeUsuario(std::string nickname)
{ 
    return (usuarios.find(nickname) != usuarios.end());
}

Inmobiliaria* getInmobiliaria(std::string nickname);
{ 
    inmo=inmobiliarias.find(nickname);
    if(inmo!=inmobiliarias.end()){
        return inmo->second;
    }
    else
        return inmo ;
}