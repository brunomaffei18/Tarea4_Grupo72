#include "../include/CargaDatos.h"
#include <cstddef>

CargaDatos* CargaDatos::instance = NULL;

CargaDatos::CargaDatos() {
    Factory* factory = Factory::getInstance();
    cu = factory->getControladorUsuario();
    cp = factory->getControladorPublicacion();
    cf = factory->getControladorFechaActual();
    cn = factory->getControladorNotificaciones();
    ci = factory->getControladorInmueble();
    ca = factory->getControladorAdministrarInmueble();

    // 1. Establecer fecha actual
    cf->setNewFechaActual(15, 3, 2025);

    // 2. Alta de usuarios (clientes, propietarios, inmobiliarias)
    cu->altaCliente("luisito", "clave123", "Luis", "luis@mail.com", "Perez", "41234567");
    cu->altaCliente("maria", "clave456", "Maria", "maria@mail.com", "Rodriguez", "41234888");

    cu->altaPropietario("propjuan", "clave789", "Juan", "juan@mail.com", "cuenta123", "099000111");
    cu->altaPropietario("propluz", "clave999", "Luz", "luz@mail.com", "cuenta456", "099888777");

    cu->altaInmobiliaria("urbana", "passurb", "Urbana Real Estate", "urbana@mail.com", "Av. Rivera 1234", "www.urbana.com", "27000001");
    cu->altaInmobiliaria("puntacasa", "puntapass", "Punta Casa", "punta@mail.com", "Gorlero 456", "www.puntacasa.com", "26223344");

    // 3. Alta de inmuebles (propietario los registra)
    
    ci->altaCasa(datos de la casa)

    // 4. Representación (inmobiliaria representa a propietario)
    cu->representarPropietario("urbana", "propjuan");
    cu->representarPropietario("puntacasa", "propluz");

    // 5. Alta de administraciones
    ca->altaAdministrarInmueble("urbana", 1);      // ID inmueble 1 → casa de Juan
    ca->altaAdministrarInmueble("puntacasa", 2);   // ID inmueble 2 → apto de Luz

    // 6. Publicaciones
    cp->altaPublicacion("urbana", 1, Venta, "Casa ideal en el centro", 120000);
    cp->altaPublicacion("puntacasa", 2, Alquiler, "Apartamento luminoso", 18000);

    // 7. Suscripciones
    std::list<std::string> inmoSus;
    inmoSus.push_back("urbana");
    inmoSus.push_back("puntacasa");
    cn->subscribirse("luisito", inmoSus);
    cn->subscribirse("maria", inmoSus);
}

CargaDatos* CargaDatos::getInstance() {
    if (instance == 0) {
        instance = new CargaDatos();
    }
    return instance;
}