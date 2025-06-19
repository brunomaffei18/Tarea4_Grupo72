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

Usuario* getUsuario(std::string nickname);
{ 
    usu=usuarios.find(nickname);
    if(usu!=usuarios.end()){
        return usu->second;
    }
    else
        return usu ;
}

Cliente* getCliente(std::string nickname);
{ 
    cli=clientes.find(nickname);
    if(cli!=clientes.end()){
        return cli->second;
    }
    else
        return cli ;
}

Propietario* getPropietario(std::string nickname);
{ 
    prop=propietarios.find(nickname);
    if(cli!=propietarios.end()){
        return prop->second;
    }
    else
        return prop ;
}