#include "../include/ManejadorUsuario.h"
#include "../include/ManejadorInmueble.h"

ManejadorUsuario* ManejadorUsuario::instancia =NULL;

ManejadorUsuario* ManejadorUsuario::getManejadorUsuario(){
    if(instancia==nullptr)
        instancia= new ManejadorUsuario();
    return instancia;
}

ManejadorUsuario::ManejadorUsuario(){};

void ManejadorUsuario:: agregarUsuario(Usuario* usuario)
{
    usuarios.insert(std::pair<std::string, Usuario*>(usuario->getNickname(),usuario));
}


bool ManejadorUsuario::existeUsuario(std::string nickname)
{ 
    return (usuarios.find(nickname) != usuarios.end());
}

Inmobiliaria* ManejadorUsuario::getInmobiliaria(std::string nickname) {
    auto it = Inmobiliarias.find(nickname);
    if (it != Inmobiliarias.end())
        return it->second;

    return NULL;
}

Usuario* ManejadorUsuario::getUsuario(std::string nickname) {
    auto it = usuarios.find(nickname);
    if (it != usuarios.end())
        return it->second;

    return NULL;
}

Cliente* ManejadorUsuario::getCliente(std::string nickname) {
    auto it = clientes.find(nickname);
    if (it != clientes.end())
        return it->second;

    return NULL;
}

Propietario* ManejadorUsuario::getPropietario(std::string nickname) {
    auto it = propietarios.find(nickname);
    if (it != propietarios.end())
        return it->second;

    return NULL;
}

std::map<std::string,Propietario*>& ManejadorUsuario::getPropietarios()
{
    return propietarios;
}
std::map<std::string,Inmobiliaria*>&  ManejadorUsuario::getInmobiliarias()
{
    return Inmobiliarias;
}
std::map<std::string,Cliente*>&  ManejadorUsuario::getClientes()
{
    return clientes;
}


ManejadorUsuario::~ManejadorUsuario(){
    
}



void ManejadorUsuario::eliminarUsuario(std::string nickname)
{
    
}