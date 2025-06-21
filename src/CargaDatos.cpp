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

    
// 1. Alta de Clientes
    cu->altaCliente("luisito23", "qweasd12", "Luis", "luisito23@gmail.com", "Perez", "46859342");
    cu->altaCliente("anarojo88", "claveAna1", "Ana", "anarojo88@hotmail.com", "Rojo", "31287465");
    
    
//2. Alta de Propietarios y sus Inmuebles
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
        
//3. Alta de Inmobiliarias y la relacion de a quien administra
    cu->altaInmobiliaria("casasur123","casasur99","Casa Sur","contacto@casasur.com","Canelones 2345","https://casasur.com.uy","24012345");
    cu->representarPropietario("marcelom");
    cu->representarPropietario("jorge88");
    cu->altaInmobiliaria("idealhome","home2025","IHome","info@idealhome.uy","Av. Italia 4567","https://idealhome.uy","099123456");
    cu->representarPropietario("marcelom");
    cu->representarPropietario("martagal");
    cu->representarPropietario("jorge88");
    cu->altaInmobiliaria("vivaurbana","viva4567","Viva Urbana","contacto@vivaurbana.com","18 de Julio 7890","https://vivaurbana.com","29109876");
    cu->representarPropietario("robertarce");
    cu->representarPropietario("soledadf");
    cu->representarPropietario("jorge88");

//4. Alta de AdministraPropiedad
    cf->setNewFechaActual(12,12,2015);
        cu->altaAdministrarPropiedad("casasur123",2);
    cf->setNewFechaActual(25,9,2023);
        cu->altaAdministrarPropiedad("idealhome",1);
    cf->setNewFechaActual(20,07,2022);
        cu->altaAdministrarPropiedad("vivaurbana",3);
    cf->setNewFechaActual(01,01,2022);
        cu->altaAdministrarPropiedad("vivaurbana",4);
    cf->setNewFechaActual(03,07,2010);
        cu->altaAdministrarPropiedad("idealhome",5);
    cf->setNewFechaActual(04,11,2019);
        cu->altaAdministrarPropiedad("casasur123",6);
    cf->setNewFechaActual(19,05,2020);
        cu->altaAdministrarPropiedad("vivaurbana",6);
    cf->setNewFechaActual(19,07,2024);
        cu->altaAdministrarPropiedad("idealhome",6);
    cf->setNewFechaActual(18,9,2023);
        cu->altaAdministrarPropiedad("idealhome",7);
    cf->setNewFechaActual(19,05,2022);
        cu->altaAdministrarPropiedad("vivaurbana",8);

//5. Alta de Publicaciones
    cf->setNewFechaActual(9,10,2011);
        cp->altaPublicacion("idealhome",5,Venta,"Casa al fondo Juan Paullier con 110 m fondo y techo liviano.",47000);

    cf->setNewFechaActual(15,01,2016);
        cp->altaPublicacion("casasur123",2,Alquiler,"Oportunidad en Av. Brasil: apartamento de 75 m piso 5 con ascensor.",28000);

    cf->setNewFechaActual(05,03,2019);
        cp->altaPublicacion("casasur123",2,Alquiler,"Apartamento luminoso en Av. Brasil piso alto con excelentes servicios.",29500);

    cf->setNewFechaActual(03,04,2019);
        cp->altaPublicacion("idealhome",5,Alquiler,"Casa ideal para familia en Juan Paullier barrio tranquilo.",38500);

    cf->setNewFechaActual(12,12,2019);
        cp->altaPublicacion("casasur123",6,Venta,"Apartamento en Bulevar Artigas piso 3 muy luminoso y moderno.",375000);

    cf->setNewFechaActual(12,06,2020);
        cp->altaPublicacion("casasur123",2,Venta,"Excelente apartamento en Av. Brasil con 75 m ideal para reforma.",390000);

    cf->setNewFechaActual(20,07,2020);
        cp->altaPublicacion("vivaurbana",6,Alquiler,"Apartamento 68 m en Bulevar Artigas tercer piso sin ascensor.",23000);

    cf->setNewFechaActual(04,03,2022);
        cp->altaPublicacion("vivaurbana",4,Alquiler,"Apartamento con ascensor en Colonia 1542 piso 12 excelente conectividad.",26000);

    cf->setNewFechaActual(12,9,2022);
        cp->altaPublicacion("vivaurbana",3,Alquiler,"Casa excelente en Camino Maldonado de 95 m con patio al fondo.",27000);

    cf->setNewFechaActual(01,10,2023);
        cp->altaPublicacion("idealhome",1,Venta,"Casa en Av. Rivera de 120 m con techo plano ideal para familia.",520000);

    cf->setNewFechaActual(18,10,2023);
        cp->altaPublicacion("idealhome",7,Alquiler,"Apartamento amplio en Sarmiento 1476 piso 6 con ascensor.",32000);

    cf->setNewFechaActual(19,10,2023);
        cp->altaPublicacion("idealhome",7,Venta,"Apartamento de 80 m en Sarmiento excelente estado y vista.",455000);

    cf->setNewFechaActual(20,11,2023);
        cp->altaPublicacion("idealhome",7,Alquiler,"Apartamento con gran vista a la rambla",31000);

    cf->setNewFechaActual(20,11,2023);
        cp->altaPublicacion("idealhome",7,Venta,"Aprtamente en excelentes condiciones de 80 m",450000);

    cf->setNewFechaActual(8,03,2024);
        cp->altaPublicacion("vivaurbana",3,Venta,"Venta de casa en Camino Maldonado 95 m bien distribuidos.",430000);

    cf->setNewFechaActual(05,05,2024);
        cp->altaPublicacion("idealhome",7,Alquiler,"Alquiler en Sarmiento 80 m piso alto con excelentes terminaciones.",33000);

    cf->setNewFechaActual(01,8,2024);
        cp->altaPublicacion("idealhome",6,Venta,"A estrenar en Bulevar Artigas 871 apartamento moderno.",400000);

//6. Registro de subscripciones
    cn->seSuscribe("casasur123","luisito23");
    cn->seSuscribe("idealhome","luisito23");
    cn->seSuscribe("casasur123","anarojo88");
    cn->seSuscribe("idealhome","anarojo88");
    cn->seSuscribe("vivaurbana","anarojo88");
    cn->seSuscribe("idealhome","marcelom");
    cn->seSuscribe("idealhome","robertarce");
    cn->seSuscribe("vivaurbana","soledadf");
    cn->seSuscribe("vivaurbana","martagal");
    cn->seSuscribe("casasur123","jorge88");
    cn->seSuscribe("idealhome","jorge88");
    cn->seSuscribe("vivaurbana","jorge88");
}

CargaDatos* CargaDatos::getInstance() {
    if (instance == 0) {
        instance = new CargaDatos();
    }
    return instance;
}