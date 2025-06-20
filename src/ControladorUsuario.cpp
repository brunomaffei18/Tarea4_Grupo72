#include "../include/ControladorUsuario.h"
#include "../include/ManejadorUsuario.h"
#include "../include/ManejadorInmueble.h"
#include "../include/Usuario.h"
#include "../include/DTInmuebleAdministrado.h"
#include "../include/ControladorFechaActual.h"

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
    std::set<AdministraPropiedad*>administrados=inmo->getAdministraciones();
    std::set<DTInmuebleAdministrado*> administradosDT;
    for (auto& administracion : administrados) {
        Inmueble* inmueble = administracion->getInmueble();
        DTInmuebleAdministrado* dtInmueble = new DTInmuebleAdministrado(
            inmueble->getCodigo(),
            inmueble->getDireccion(),
            administracion->getFechaPublicacion()
        );
        administradosDT.insert(dtInmueble);
    }
    return administradosDT;
}
std::set<DTUsuario*> ControladorUsuario::ListarInmobiliarias() {
    ManejadorUsuario* manejadorusu = ManejadorUsuario::getManejadorUsuario();
    ManejadorInmueble* manejadorinm = ManejadorInmueble::getManejadorInmueble();
    std::map<std::string, Inmobiliaria*> users = manejadorusu->getInmobiliarias();
    std::set<DTUsuario*> listaDT;
    for (auto& inmobiliaria : users) {
        DTUsuario* dtInmobiliaria = new DTUsuario(
            inmobiliaria.second->getNickname(),
            inmobiliaria.second->getNombre(),
        );
        listaDT.insert(dtInmobiliaria);
    }
    return listaDT;
}
std::set<DTUsuario*> ControladorUsuario::ListarPropietarios() {
    ManejadorUsuario* manejadorusu = ManejadorUsuario::getManejadorUsuario();
    ManejadorInmueble* manejadorinm = ManejadorInmueble::getManejadorInmueble();
    std::map<std::string, Propietario*> dueños = manejadorusu->getPropietarios();
    std::set<DTUsuario*> listaDT;
    for (auto& propietario : dueños) {
        DTUsuario* dtPropietario = new DTUsuario(
            propietario.second->getNickname(),
            propietario.second->getNombre()
        );
        listaDT.insert(dtPropietario);
    }
    return listaDT;
}
std::set<DTUsuario*> ControladorUsuario::ListarClientes() {
    ManejadorUsuario* manejadorusu = ManejadorUsuario::getManejadorUsuario();
    auto clientes = manejadorusu->getClientes();
    std::set<DTUsuario*> listaDT;
    for (auto& cliente : clientes) {
        DTUsuario* dtCliente = new DTUsuario(
            cliente.second->getNickname(),
            cliente.second->getNombre()
        );
        listaDT.insert(dtCliente);
    }
    return listaDT;
}
void ControladorUsuario::representarPropietario(std::string nicknamePropietario) {
ManejadorUsuario* manejadorusu = ManejadorUsuario::getManejadorUsuario();
    manejadorusu->representarPropietario(nicknamePropietario);
}
void ControladorUsuario::finalizarAltaUsuario() {
    manejadorusu->finalizarAltaUsuario();
}
DTUsuario ControladorUsuario::getUsuario(std::string nickname) {
    return manejadorusu->getUsuario(nickname);
}


    std::set<DTInmuebleListado> listarInmueblesNoAdministradosInmobiliaria(std::string nicknameInmobiliaria);{}
    void altaAdministrarPropiedad(std::string nickNameInmobiliaria,int codigoInmueble){}