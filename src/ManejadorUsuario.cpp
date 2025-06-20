#include "../include/ManejadorUsuario.h"

ManejadorUsuario* ManejadorUsuario::instancia = NULL;

ManejadorUsuario* ManejadorUsuario::getManejadorUsuario(){
    if(instancia==NULL)
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


/*void ManejadorUsuario::eliminarUsuario(std::string nickname)
{
    
}*/

ManejadorUsuario::~ManejadorUsuario(){
    delete instancia;
    instancia = NULL;
}  