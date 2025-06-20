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

    // 1. Establecer fecha actual
    cf->setNewFechaActual(15, 3, 2025);

    // 2. Alta de Clientes
    cu->altaCliente("luisito23", "qweasd12", "Luis", "luisito23@gmail.com", "Perez", "46859342");
    cu->altaCliente("anarojo88", "claveAna1", "Ana", "anarojo88@hotmail.com", "Rojo", "31287465");

    //3. Alta de Inmobiliarias
    cu->altaInmobiliaria("casasur123","casasur99","Casa Sur","contacto@casasur.com","Canelones 2345","https://casasur.com.uy","24012345");
    cu->altaInmobiliaria("idealhome","home2025","IHome","info@idealhome.uy","Av. Italia 4567","https://idealhome.uy","099123456");
    cu->altaInmobiliaria("vivaurbana","viva4567","Viva Urbana","contacto@vivaurbana.com","18 de Julio 7890","https://vivaurbana.com","29109876");

    //4. Alta de Propietarios y sus Inmuebles
    cu->altaPropietario("marcelom",	"banco123",	"Marcelo","marcelo.m@gmail.com","099876543","123456789012");
        ci->altaCasa("Av. Rivera", 1011 ,120,1995,true,Plano);
        ci->altaApartamento("Av. Brasil",2031,75,1980,5,true,3500);
    cu->altaPropietario("robertarce","pass456","Roberto","roberto.a@yahoo.com","091234567","987654321001");
        ci->altaCasa("Camino Maldonado",1540,95,1988,false,	Plano);
    cu->altaPropietario("soledadf","sole789","Soledad","soledad.f@gmail.com","092345678","654321987654");
        ci->altaApartamento("Colonia",1542,60,1978,12,true,2800);
    cu->altaPropietario("martagal","martA01","Marta","marta.galvez@outlook.com","098765432","321098765432");
        ci->altaCasa("Juan Paullier",801,110,2000,true,Liviano);
    cu->altaPropietario("jorge88","jorgepass88","Jorge","jorge.rivera@uy.com","097654321","890123456789");
        ci->altaApartamento("Bulevar Artigas",871,68,2002,3,false,2200);
        ci->altaApartamento("Sarmiento",1476,80,2008,6,true,3100);
        ci->altaCasa("Cno. Carrasco",1576,140,2007,true,Plano);

/*
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
*/

}

CargaDatos* CargaDatos::getInstance() {
    if (instance == 0) {
        instance = new CargaDatos();
    }
    return instance;
}