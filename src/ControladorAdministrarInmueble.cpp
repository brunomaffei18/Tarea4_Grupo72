 #include "../include/ControladorAdministrarInmueble.h" 
  
  ControladorAdministrarInmueble* ControladorAdministrarInmueble::getInstancia(){
    if (Instancia==NULL){
        Instancia=new ControladorAdministrarInmueble();
    }
    return Instancia;

    std::set<DTInmuebleListado> listarInmueblesNoAdministradosInmobiliaria(std::string nicknameInmobiliaria);
    void altaAdministrarPropiedad(std::string nickNameInmobiliaria,int codigoInmueble);
