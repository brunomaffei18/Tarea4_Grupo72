#include "../include/ControladorUsuario.h"
#include "../include/ManejadorUsuario.h"
#include "../include/ManejadorInmueble.h"
#include "../include/Usuario.h"
#include "../include/DTInmuebleAdministrado.h"
#include "../include/ControladorFechaActual.h"
#include "../include/ControladorInmueble.h"
#include "../include/ManejadorNotificaciones.h"


ControladorUsuario* ControladorUsuario::instancia = NULL;

ControladorUsuario::ControladorUsuario() {
    manejadorusu = ManejadorUsuario::getManejadorUsuario();
    ultimaInmobiliaria = NULL;
}

ControladorUsuario* ControladorUsuario::getInstancia() {
    if (instancia == NULL)
        instancia = new ControladorUsuario();
    return instancia;
}

bool ControladorUsuario::altaCliente(std::string nickname, std::string contrasena, std::string nombre, std::string email,std::string apellido, std::string documento) {
    if (manejadorusu->existeUsuario(nickname)) {
        return false;}
    Cliente* cliente = new Cliente(nickname, contrasena, nombre, email, apellido, documento);
    manejadorusu->agregarUsuario(cliente);
    return true;
}
bool ControladorUsuario::altaInmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion,std::string url, std::string telefono) {
    if (manejadorusu->existeUsuario(nickname)) {
        return false;}
    Inmobiliaria* inmobiliaria = new Inmobiliaria(nickname, contrasena, nombre, email, direccion, url, telefono);
    manejadorusu->agregarUsuario(inmobiliaria);
   ManejadorNotificaciones::getInstance()->agregarInmobiliaria(inmobiliaria);
    return true;
}
bool ControladorUsuario::altaPropietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria,std::string telefono) {
    if (manejadorusu->existeUsuario(nickname)) {
        return false;}
    Propietario* propietario = new Propietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono);
    manejadorusu->agregarUsuario(propietario);
    ControladorInmueble::getInstancia()->setPropietarioRecordado(propietario);
    return true;
}
std::set<DTInmuebleAdministrado> ControladorUsuario::listarInmueblesAdministrados(std::string nicknameInmobiliaria) {
    Inmobiliaria* inmo = manejadorusu->getInmobiliaria(nicknameInmobiliaria);

    std::set<AdministraPropiedad*>administrados=inmo->getAdministraciones();
    std::set<DTInmuebleAdministrado> administradosDT;
    for (auto& administracion : administrados) {
        Inmueble* inmueble = administracion->getInmueble();
        DTInmuebleAdministrado dtInmueble(
            inmueble->getCodigo(),
            inmueble->getDireccion(),
            administracion->getFechaPublicacion()
        );
        administradosDT.insert(dtInmueble);
    }
    return administradosDT;
}
std::set<DTUsuario> ControladorUsuario::ListarInmobiliarias() {
    //ManejadorInmueble* manejadorInmuebles = ManejadorInmueble::getManejadorInmueble();

    std::map<std::string, Inmobiliaria*> users = manejadorusu->getInmobiliarias();
    std::set<DTUsuario> listaDT;
    for (auto& inmobiliaria : users) {
        DTUsuario dtInmobiliaria(
            inmobiliaria.second->getNickname(),
            inmobiliaria.second->getNombre()
        );
        listaDT.insert(dtInmobiliaria);
    }
    return listaDT;
}
std::set<DTUsuario> ControladorUsuario::ListarPropietarios() {
    ManejadorInmueble* manejadorinm = ManejadorInmueble::getManejadorInmueble();
    std::map<std::string, Propietario*> dueños = manejadorusu->getPropietarios();
    std::set<DTUsuario> listaDT;
    for (auto& propietario : dueños) {
        DTUsuario dtPropietario(
            propietario.second->getNickname(),
            propietario.second->getNombre()
        );
        listaDT.insert(dtPropietario);
    }
    return listaDT;
}
std::set<DTUsuario> ControladorUsuario::ListarClientes() {
    auto clientes = manejadorusu->getClientes();
    std::set<DTUsuario> listaDT;
    for (auto& cliente : clientes) {
        DTUsuario dtCliente(
            cliente.second->getNickname(),
            cliente.second->getNombre()
        );
        listaDT.insert(dtCliente);
    }
    return listaDT;
}
void ControladorUsuario::representarPropietario(std::string nicknamePropietario) {
    Propietario* propietario = manejadorusu->getPropietario(nicknamePropietario);

    if (ultimaInmobiliaria != NULL && propietario != NULL) {
        ultimaInmobiliaria->agregarRepresentado(propietario);
        propietario->agregarRepresentante(ultimaInmobiliaria);
    }
}

Inmobiliaria* ControladorUsuario::getUltimaInmobiliaria(){
    return ultimaInmobiliaria;
}

void ControladorUsuario::finalizarAltaUsuario() {
    ultimaInmobiliaria = NULL;
}

DTUsuario ControladorUsuario::getUsuario(std::string nickname) {
    Usuario* usuario = manejadorusu->getUsuario(nickname);
    return DTUsuario(usuario->getNickname(), usuario->getNombre());
}

std::set<DTInmuebleListado> ControladorUsuario:: listarInmueblesNoAdministradosInmobiliaria(std::string nicknameInmobiliaria)
{
    Inmobiliaria* inm= manejadorusu->getInmobiliaria(nicknameInmobiliaria);
     std::set<DTInmuebleListado> listado;
     
    std::map<std::string, Propietario*> mapa=  inm->getRepresentados();
    for(std::map<std::string,Propietario*>::iterator iter = mapa.begin(); iter != mapa.end(); ++iter)
    {
        Propietario* prop=iter->second;
        std::map<int,Inmueble*> inmueble=prop->getPropiedades();
        for(std::map<int,Inmueble*>::iterator itera = inmueble.begin(); itera != inmueble.end(); ++itera)
        {
            Inmueble* adm=itera->second;
            std::set<AdministraPropiedad*>admi=adm->getInmueblesAdministrados();
                for(std::set<AdministraPropiedad*>::iterator iti = admi.begin(); iti != admi.end(); ++iti)
                {
                    AdministraPropiedad* johan=*iti;
                    if(johan->getInmobiliaria()==inm)
                        {
                            DTInmuebleListado dtlistado(
                                adm->getCodigo(),
                                adm->getDireccion(),
                                iter->second->getNickname()
                            );
                            listado.insert(dtlistado);
                        }
                }
        }
    }
return listado;
}        
// void ControladorUsuario::altaAdministrarPropiedad(std::string nickNameInmobiliaria,int codigoInmueble){
//     Inmobiliaria* inmobiliaria = manejadorusu->getInmobiliaria(nickNameInmobiliaria);
//     std::map<std::string, Propietario*> mapa= manejadorusu->getPropietarios();
//     std::map<std::string,Propietario*>::iterator iterador = mapa.begin();
//     bool flag=false;
//     while(iterador != mapa.end() && flag==false )
//     {
//         Propietario* inmue=iterador->second;
//         std::map<int, Inmueble*> pichu=inmue->getPropiedades();
//         std::map<int, Inmueble*>::iterator itera=pichu.begin();
//         while(itera != pichu.end() || itera->second->getCodigo()!=codigoInmueble) {
//             ++itera;
//         }
//         if(itera!=pichu.end()){
//             Inmueble * inmueble=itera->second;
//             DTFecha* fecha=ControladorFechaActual ::getInstance()->getFechaActual();
//             AdministraPropiedad admi( fecha, inmueble, inmobiliaria);
//             AdministraPropiedad * admin=&admi;
//             inmueble->AgregarAdministrados(admin);
//             inmobiliaria->agregarAdministracion(admin);
//             flag==true;
//         }
//         else{
//             ++iterador;
//         }
//     }



// }
void ControladorUsuario::altaAdministrarPropiedad(std::string nickNameInmobiliaria, int codigoInmueble) {
    
    ManejadorUsuario* mu = ManejadorUsuario::getManejadorUsuario();
    if (mu == NULL)        
        return;

    std::map<std::string, Inmobiliaria*> mapaInmobiliarias = manejadorusu->getInmobiliarias();

    auto itInmo = mapaInmobiliarias.find(nickNameInmobiliaria);
    if (itInmo == mapaInmobiliarias.end()) {
        return;
    }
    Inmobiliaria* inmobiliaria = itInmo->second;
    std::map<std::string, Propietario*> mapaPropietarios = manejadorusu->getPropietarios();

    for (auto& [nick, propietario] : mapaPropietarios) {
        std::map<int, Inmueble*> propiedades = propietario->getPropiedades();
        auto itInmueble = propiedades.find(codigoInmueble);

        if (itInmueble != propiedades.end()) {
            Inmueble* inmueble = itInmueble->second;

            std::set<AdministraPropiedad*> administraciones = inmueble->getInmueblesAdministrados();
            for (AdministraPropiedad* admin : administraciones) {
                if (admin->getInmobiliaria() == inmobiliaria) {
                    return;  // ya esta administrado
                }
            }
            DTFecha* fecha = ControladorFechaActual::getInstance()->getFechaActual();
            AdministraPropiedad admin =  AdministraPropiedad(fecha, inmueble, inmobiliaria);
            AdministraPropiedad * administra=&admin;

            inmueble->AgregarAdministrados(administra);
            inmobiliaria->agregarAdministracion(administra);
            return;  // Administración creada, se termina
        }
    }

}


ControladorUsuario::~ControladorUsuario() {
   
}