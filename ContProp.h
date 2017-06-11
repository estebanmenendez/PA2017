/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ContProp.h
 * Author: juan
 *
 * Created on 9 de junio de 2017, 08:17 PM
 */

#ifndef CONTPROP_H
#define CONTPROP_H


 class ContProp: public I_ContProp{
    private: 
    
     
    public:
        ContProp();
        ContProp(const ContProp& orig);
        virtual ~ContProp();
        dtDepartamentos ** listaDepartamentos();
        void seleccionarDepartamentos(string);
        dtZonas ** listaZonasDepartamentos(string);
        void seleccionaZona(string);
        dtPropiedadMensaje ** listaPropiedades(string);
        dtPropiedadMensaje ** seleccionaPropiedad(string,int);
        void enviarMensaje(string);
        string ingesrarCodProp(string);
        void modifPropCasa(DtPropCasa);
        void modifPropApto(DtPropApto);
        dtConversaInmobiliarias ** listaConversacionesInmobiliarias();
        void seleccionaConversacion(string);
        dtMensajes ** listaUltimosCincoMensajes();
        void seleccionaMensaje(string);
        void agregaMensaje(string,string);
        dtPropiedadDisponibles ** listaPropiedadesDisponibles();
        dtPropiedadInmobiliaria ** seleccionaPropiedadDisponible(string);
        void altaInteresado (string,string,int,string);
        void altaEdificio(string,int,int);
        dtReporte ** iniciarReporte(inmobiliaria);
        void altaPropiedadCasa (dtPropiedadCasa);
        void altaPropiedadApto(dtPropiedadApto);
    };

};

#endif /* CONTPROP_H */

