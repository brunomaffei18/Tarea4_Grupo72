OBJETOS = AdministraPropiedad.o Apartamento.o CargaDatos.o Casa.o \
		  Cliente.o ControladorFechaActual.o DTApartamento.o DTCasa.o DTFecha.o DTInmueble.o \
		  DTInmuebleAdministrado.o DTInmuebleListado.o DTPublicacion.o DTUsuario.o Factory.o \
		  IControladorFechaActual.o Inmobiliaria.o Inmueble.o Menu.o Propietario.o Publicacion.o \
		  TipoInmueble.o TipoPublicacion.o TipoTecho.o Usuario.o ManejadorInmueble.o ManejadorPublicaciones.o \
		  ManejadorUsuario.o ControladorUsuario.o ControladorInmueble.o ControladorPublicacion.o \
		  ControladorNotificaciones.o DTNotificacion.o Subscriptor.o main.o ManejadorNotificaciones.o TipoEnumToString.o


FUENTES = ./include/AdminsitraPropiedad.h ./src/AdminsitraPropiedad.cpp \
		  ./include/Apartamento.h ./src/Apartamento.cpp \
		  ./include/CargaDatos.h ./src/CargaDatos.cpp \
		  ./include/Casa.h ./src/Casa.cpp \
		  ./include/Cliente.h ./src/Cliente.cpp \
		  ./include/ControladorFechaActual.h ./src/ControladorFechaActual.cpp \
		  ./include/DTApartamento.h ./src/DTApartamento.cpp \
		  ./include/DTCasa.h ./src/DTCasa.cpp \
		  ./include/DTFecha.h ./src/DTFecha.cpp \
		  ./include/DTInmueble.h ./src/DTInmueble.cpp \
		  ./include/DTInmuebleAdministrado.h ./src/DTInmuebleAdministrado.cpp \
		  ./include/DTInmuebleListado.h ./src/DTInmuebleListado.cpp \
		  ./include/DTPublicacion.h ./src/DTPublicacion.cpp \
		  ./include/DTUsuario.h ./src/DTUsuario.cpp \
		  ./include/Factory.h ./src/Factory.cpp \
		  ./include/IControladorFechaActual.h ./src/IControladorFechaActual.cpp \
		  ./include/Inmueble.h ./src/Inmueble.cpp \
		  ./include/Menu.h ./src/Menu.cpp \
		  ./include/Propietario.h ./src/Propietario.cpp \
		  ./include/Publicacion.h ./src/Publicacion.cpp \
		  ./include/TipoInmueble.h ./src/TipoInmueble.cpp \
		  ./include/TipoPublicacion.h ./src/TipoPublicacion.cpp \
		  ./include/TipoTecho.h ./src/TipoTecho.cpp \
		  ./include/Usuario.h ./src/Usuario.cpp \
		  ./include/ManejadorInmueble.h ./src/ManejadorInmueble.cpp \
		  ./include/ManejadorPublicaciones.h ./src/ManejadorPublicaciones.cpp \
		  ./include/ManejadorUsuario.h ./src/ManejadorUsuario.cpp \
		  ./include/ControladorInmueble.h ./src/ControladorInmueble.cpp \
		  ./include/ControladorPublicacion.h ./src/ControladorPublicacion.cpp \
		  ./include/DTNotificacion.h ./src/DTNotificacion.cpp \
		  ./include/Subscriptor.h ./src/Subscriptor.cpp \
		  ./include/ControladorNotificaciones.h ./src/ControladorNotificaciones.cpp \
		  ./include/ControladorUsuario.h ./src/ControladorUsuario.cpp \
		  ./include/AdministraPropiedad.h ./src/AdministraPropiedad.cpp \
		  ./include/Factory.h ./src/Factory.cpp \
		  ./include/ControladorPublicacion.h ./src/ControladorPublicacion.cpp \
		  ./include/main.h ./src/main.cpp \
		  ./include/Inmobiliaria.h ./src/Inmobiliaria.cpp \
		  ./include/ManejadorNotificaciones.h ./src/ManejadorNotificaciones.cpp \
		  ./include/TipoEnumToString.h ./src/TipoEnumToString.cpp




CC = g++
ENTREGA = 72_lab4.zip

OPCIONES =  -g -c

ejec: $(OBJETOS) ./src/main.cpp Makefile
	g++ -o principal $(OBJETOS) 

main.o: ./src/main.cpp
	$(CC) -c ./src/main.cpp -o main.o

##Muy importente volver a chequear las dependencias y herencias para estas reglas
DTInmueble.o: ./include/DTInmueble.h ./src/DTInmueble.cpp
	$(CC) $(OPCIONES) ./src/DTInmueble.cpp -o DTInmueble.o 
 
DTApartamento.o: DTInmueble.o ./include/DTApartamento.h ./src/DTApartamento.cpp 
	$(CC) $(OPCIONES) ./src/DTApartamento.cpp -o DTApartamento.o

DTCasa.o: ./include/TipoTecho.h ./include/DTCasa.h ./src/DTCasa.cpp
	$(CC) $(OPCIONES) ./src/DTCasa.cpp -o DTCasa.o


DTFecha.o: ./include/DTFecha.h ./src/DTFecha.cpp
	$(CC) $(OPCIONES) ./src/DTFecha.cpp -o DTFecha.o

DTInmuebleAdministrado.o: DTFecha.o ./include/DTInmuebleAdministrado.h ./src/DTInmuebleAdministrado.cpp 
	$(CC) $(OPCIONES) ./src/DTInmuebleAdministrado.cpp -o DTInmuebleAdministrado.o

DTInmuebleListado.o: ./include/DTInmuebleListado.h ./src/DTInmuebleListado.cpp
	$(CC) $(OPCIONES) ./src/DTInmuebleListado.cpp -o DTInmuebleListado.o


DTPublicacion.o: DTFecha.o ./include/DTPublicacion.h ./src/DTPublicacion.cpp
	$(CC) $(OPCIONES) ./src/DTPublicacion.cpp -o DTPublicacion.o

DTUsuario.o: ./include/DTPublicacion.h ./src/DTPublicacion.cpp
	$(CC) $(OPCIONES) ./src/DTUsuario.cpp -o DTUsuario.o

IControladorFechaActual.o: DTFecha.o ./include/IControladorFechaActual.h ./src/IControladorFechaActual.cpp
	$(CC) $(OPCIONES) ./src/IControladorFechaActual.cpp -o IControladorFechaActual.o

ControladorFechaActual.o: DTFecha.o IControladorFechaActual.o ./include/ControladorFechaActual.h ./src/ControladorFechaActual.cpp
	$(CC) $(OPCIONES) ./src/ControladorFechaActual.cpp -o ControladorFechaActual.o

Usuario.o: DTUsuario.o ./include/Usuario.h ./src/Usuario.cpp
	$(CC) $(OPCIONES) ./src/Usuario.cpp -o Usuario.o
	
Cliente.o: Usuario.o ./include/Cliente.h ./src/Cliente.cpp
	$(CC) $(OPCIONES) ./src/Cliente.cpp -o Cliente.o

Inmueble.o: ./include/Inmueble.h ./src/Inmueble.cpp
	$(CC) $(OPCIONES) ./src/Inmueble.cpp -o Inmueble.o

TipoTecho.o: ./include/TipoTecho.h ./src/TipoTecho.cpp
	$(CC) $(OPCIONES) ./src/TipoTecho.cpp -o TipoTecho.o

Casa.o: Inmueble.o TipoTecho.o ./include/Casa.h ./src/Casa.cpp
	$(CC) $(OPCIONES) ./src/Casa.cpp -o Casa.o

CargaDatos.o: ./include/CargaDatos.h ./src/CargaDatos.cpp
	$(CC) $(OPCIONES) ./src/CargaDatos.cpp -o CargaDatos.o

Apartamento.o: Inmueble.o ./include/Apartamento.h ./src/Apartamento.cpp
	$(CC) $(OPCIONES) ./src/Apartamento.cpp -o Apartamento.o

Inmobiliaria.o: Usuario.o ./include/Inmobiliaria.h ./src/Inmobiliaria.cpp
	$(CC) $(OPCIONES) ./src/Inmobiliaria.cpp -o Inmobiliaria.o

TipoPublicacion.o: ./include/TipoPublicacion.h ./src/TipoPublicacion.cpp
	$(CC) $(OPCIONES) ./src/TipoPublicacion.cpp -o TipoPublicacion.o

##Los siguientes dos hay que tener ojo porque pueden tener delcaraciones circulares, pareciera que en adminsitrapropiedad hay qe poner un puntero a 
##publicacion y no una isntancia de publicacion
Publicacion.o: TipoPublicacion.o DTFecha.o ./include/Publicacion.h ./src/Publicacion.cpp
	$(CC) $(OPCIONES) ./src/Publicacion.cpp -o Publicacion.o

AdministraPropiedad.o: DTFecha.o Inmueble.o Inmobiliaria.o Publicacion.o ./src/AdministraPropiedad.cpp ./include/AdministraPropiedad.h
	$(CC) $(OPCIONES) ./src/AdministraPropiedad.cpp -o AdministraPropiedad.o

Factory.o: IControladorFechaActual.o ./include/Factory.h ./src/Factory.cpp	
	$(CC) $(OPCIONES) ./src/Factory.cpp -o Factory.o

ManejadorInmueble.o: DTInmueble.o Inmueble.o ./include/ManejadorInmueble.h ./src/ManejadorInmueble.cpp	
	$(CC) $(OPCIONES) ./src/ManejadorInmueble.cpp -o ManejadorInmueble.o

ManejadorPublicaciones.o: Publicacion.o DTPublicacion.o ./include/ManejadorPublicaciones.h ./src/ManejadorPublicaciones.cpp	
	$(CC) $(OPCIONES) ./src/ManejadorPublicaciones.cpp -o ManejadorPublicaciones.o

ManejadorUsuario.o: Inmobiliaria.o Propietario.o Cliente.o Usuario.o ./include/ManejadorUsuario.h ./src/ManejadorUsuario.cpp	
	$(CC) $(OPCIONES) ./src/ManejadorUsuario.cpp -o ManejadorUsuario.o

Menu.o: ./include/Menu.h ./src/Menu.cpp	
	$(CC) $(OPCIONES) ./src/Menu.cpp -o Menu.o

##Falta herecia de IControladorUsuario
ControladorUsuario.o: DTUsuario.o Propietario.o Cliente.o Inmobiliaria.o ./include/ControladorUsuario.h ./src/ControladorUsuario.cpp	
	$(CC) $(OPCIONES) ./src/ControladorUsuario.cpp -o ControladorUsuario.o

##Falta herecia de IControladorInmueble
ControladorInmueble.o: Inmobiliaria.o ManejadorInmueble.o ManejadorPublicaciones.o ManejadorUsuario.o ControladorUsuario.o ./include/ControladorInmueble.h ./src/ControladorInmueble.cpp
	$(CC) $(OPCIONES) ./src/ControladorInmueble.cpp -o ControladorInmueble.o

ControladorPublicacion.o: Inmobiliaria.o ManejadorInmueble.o ManejadorPublicaciones.o ManejadorUsuario.o ControladorUsuario.o ./include/ControladorPublicacion.h ./src/ControladorPublicacion.cpp
	$(CC) $(OPCIONES) ./src/ControladorPublicacion.cpp -o ControladorPublicacion.o

ControladorNotificaciones.o: Inmobiliaria.o ManejadorInmueble.o ManejadorPublicaciones.o ManejadorUsuario.o ControladorUsuario.o ./include/ControladorNotificaciones.h ./src/ControladorNotificaciones.cpp
	$(CC) $(OPCIONES) ./src/ControladorNotificaciones.cpp -o ControladorNotificaciones.o

##Notificacion.o: DTFecha.o Subscriptor.o ./include/Notificacion.h ./src/Notificacion.cpp
##	$(CC) $(OPCIONES) ./src/Notificacion.cpp -o Notificacion.o

Subscriptor.o: DTFecha.o DTNotificacion.o ./include/Subscriptor.h ./src/Subscriptor.cpp
	$(CC) $(OPCIONES) ./src/Subscriptor.cpp -o Subscriptor.o

Propietario.o: Usuario.o DTUsuario.o ./include/Propietario.h ./src/Propietario.cpp
	$(CC) $(OPCIONES) ./src/Propietario.cpp -o Propietario.o

TipoInmueble.o: ./include/TipoInmueble.h ./src/TipoInmueble.cpp
	$(CC) $(OPCIONES) ./src/TipoInmueble.cpp -o TipoInmueble.o

TipoEnumToString.o: ./src/TipoEnumToString.cpp
	$(CC) $(OPCIONES) ./src/TipoEnumToString.cpp -o TipoEnumToString.o

DTNotificacion.o: DTFecha.o ./include/DTNotificacion.h ./src/DTNotificacion.cpp
	$(CC) $(OPCIONES) ./src/DTNotificacion.cpp -o DTNotificacion.o

ManejadorNotificaciones.o: DTNotificacion.o Subscriptor.o ./include/ManejadorNotificaciones.h ./src/ManejadorNotificaciones.cpp
	$(CC) $(OPCIONES) ./src/ManejadorNotificaciones.cpp -o ManejadorNotificaciones.o




clean:
	rm -f $(OBJETOS) ejec

rebase:
	make clean && make