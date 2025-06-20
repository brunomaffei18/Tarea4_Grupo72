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

<<<<<<< HEAD

Inmobiliaria* ManejadorUsuario::getInmobiliaria(std::string nickname)
{ 
    inmo=inmobiliarias.find(nickname);
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
=======
Inmobiliaria* ManejadorUsuario::getInmobiliaria(std::string nickname)
{ 
    return Inmobiliarias.at(nickname);
  
}

Usuario* ManejadorUsuario::getUsuario(std::string nickname)
{ 
    return usuarios.at(nickname);
}

Cliente* ManejadorUsuario::getCliente(std::string nickname)
{ 
    return clientes.at(nickname);
}

Propietario* ManejadorUsuario::getPropietario(std::string nickname)
{ 
   return propietarios.at(nickname);
}
>>>>>>> 8e6f5efcbac8dfa947c19ae42b0f5c8e1c7c944d

void ManejadorUsuario::liberarUsuario(Usuario* usuario)
{

};

void ManejadorUsuario::eliminarUsuario(std::string nickname)
{
    
};

ManejadorUsuario::~ManejadorUsuario(){
    delete instancia;
    instancia = nullptr;
};  