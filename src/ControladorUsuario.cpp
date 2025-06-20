#include "../include/ControladorUsuario.h"
#include "../include/ManejadorUsuario.h"
#include "../include/ManejadorInmueble.h"
#include "../include/ControladorAdministrarInmueble.h"
#include "../include/Usuario.h"

ControladorUsuario* ControladorUsuario::Intancia = nullptr;

bool ControladorUsuario::altaCliente(std::string nickname, std::string contrasena, std::string nombre, std::string email,std::string apellido, std::string documento) {
    ManejadorUsuario* manejadorusu = ManejadorUsuario::getManejadorUsuario();
    if (manejadorusu->existeUsuario(nickname)) {
        return false;}
    Cliente* cliente = new Cliente(nickname, contrasena, nombre, email, apellido, documento);
    manejadorusu->agregarUsuario(cliente);
    //elimino manejador?
    return true;
}
bool ControladorUsuario::altaInmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion,std::string url, std::string telefono) {
    ManejadorUsuario* manejadorusu = ManejadorUsuario::getManejadorUsuario();
    if (manejadorusu->existeUsuario(nickname)) {
        return false;}
    Inmobiliaria* inmobiliaria = new Inmobiliaria(nickname, contrasena, nombre, email, direccion, url, telefono);
    manejadorusu->agregarUsuario(inmobiliaria);
    return true;
}
bool ControladorUsuario::altaPropietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria,std::string telefono) {
    ManejadorUsuario* manejadorusu = ManejadorUsuario::getManejadorUsuario();
    if (manejadorusu->existeUsuario(nickname)) {
        return false;}
    Propietario* propietario = new Propietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono);
    manejadorusu->agregarUsuario(propietario);
    return true;
}
std::set<DTInmuebleAdministrado*> ControladorUsuario::listarInmueblesAdministrados(std::string nicknameInmobiliaria) {
    ManejadorUsuario* manejadorusu = ManejadorUsuario::getManejadorUsuario();
    Inmobiliaria* inmo = manejadorusu->getInmobiliaria(nicknameInmobiliaria);
    std::set<AdministraPropiedad*>administrados=inmo->getInmueblesAdministrados();
    return administrados;
}
std::set<DTUsuario*> ControladorUsuario::ListarInmobiliarias() {
    ManejadorUsuario* manejadorusu = ManejadorUsuario::getManejadorUsuario();
    ManejadorInmueble* manejadorinm = ManejadorInmueble::getManejadorInmueble();
    users = manejadorusu->getInmobiliarias();
    std::set<DTUsuario*> listaDT;
    for (auto& inmobiliaria : users) {
        DTUsuario* dtInmobiliaria = new DTUsuario(
            inmobiliaria.second->getNickname(),
            inmobiliaria.second->getNombre(),
            inmobiliaria.second->getEmail(),
            inmobiliaria.second->getTipo()
        );
        listaDT.insert(dtInmobiliaria);
    }
    return listaDT;
}
std::set<DTUsuario*> ControladorUsuario::ListarPropietarios() {
    ManejadorUsuario* manejadorusu = ManejadorUsuario::getInstancia();
    ManejadorUsuario* manejadorinm = ManejadorInmueble::getManejadorInmueble();
    return manejadorusu->ListarPropietarios();
}
std::set<DTUsuario*> ControladorUsuario::ListarClientes() {
    return manejadorusu->ListarClientes();
}
void ControladorUsuario::representarPropietario(std::string nicknamePropietario) {
    manejadorusu->representarPropietario(nicknamePropietario);
}
void ControladorUsuario::finalizarAltaUsuario() {
    manejadorusu->finalizarAltaUsuario();
}
DTUsuario ControladorUsuario::getUsuario(std::string nickname) {
    return manejadorusu->getUsuario(nickname);
}