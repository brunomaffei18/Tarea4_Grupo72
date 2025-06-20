 #include "../include/ControladorAdministrarInmueble.h" 
  
  ControladorAdministrarInmueble* ControladorAdministrarInmueble::getInstancia(){
    if (instancia==NULL){
        instancia=new ControladorAdministrarInmueble();
    }
    return instancia;

    std::set<DTInmuebleListado> listarInmueblesNoAdministradosInmobiliaria(std::string nicknameInmobiliaria);
    void altaAdministrarPropiedad(std::string nickNameInmobiliaria,int codigoInmueble);
