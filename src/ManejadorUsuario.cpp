#include "../include/ManejadorUsuario.h"
#include "../include/ManejadorInmueble.h"

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

Inmobiliaria* ManejadorUsuario::getInmobiliaria(std::string nickname)
{ 
    auto inmo=Inmobiliarias.find(nickname);
    if(inmo!=inmobiliarias.end()){
        return inmo->second;
    }
    else
        return inmo ;
};

Usuario* ManejadorUsuario::getUsuario(std::string nickname)
{ 
    usu=usuarios.find(nickname);
    if(usu!=usuarios.end()){
        return usu->second;
    }
    else
        return usu ;
};

Cliente* ManejadorUsuario::getCliente(std::string nickname)
{ 
    cli=clientes.find(nickname);
    if(cli!=clientes.end()){
        return cli->second;
    }
    else
        return cli ;
};

Propietario* ManejadorUsuario::getPropietario(std::string nickname)
{ 
    prop=propietarios.find(nickname);
    if(cli!=propietarios.end()){
        return prop->second;
    }
    else
        return prop ;
};

void ManejadorUsuario::liberarUsuario(Usuario* usuario)
{

};

void ManejadorUsuario::eliminarUsuario(std::string nickname)
{
    
};