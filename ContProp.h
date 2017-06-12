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
#include"dtPropiedadMensaje.h"
#include"dtPropiedadDisponible.h"
#include"dtPropiedadCasa.h"
#include"dtPropiedadApto.h"
#include"dtDepartamento.h"
#include"dtConversaInmobiliaria.h"
#include"dtReporteInmobiliaria.h"
#include"dtMensajes.h"
#include"dtPropiedadInmobiliaria.h"
#include"dtZonas.h"
#include"Inmobiliaria.h"
#include <iostream>

#ifndef CONTPROP_H
#define CONTPROP_H


 class ContProp {
    private: 
    
     
    public:
        ContProp();
        ContProp(const ContProp& orig);
        virtual ~ContProp();
        dtDepartamento ** listaDepartamentos();
        void seleccionarDepartamentos(string);
        dtZonas ** listaZonasDepartamentos(string);
        void seleccionaZona(string);
        dtPropiedadMensaje ** listaPropiedades(string);
        dtPropiedadMensaje ** seleccionaPropiedad(string,int);
        void enviarMensaje(string);
        string ingesrarCodProp(string);
        void modifPropCasa(dtPropiedadCasa);
        void modifPropApto(dtPropiedadApto);
        dtConversaInmobiliaria ** listaConversacionesInmobiliarias();
        void seleccionaConversacion(string);
        dtMensajes ** listaUltimosCincoMensajes();
        void seleccionaMensaje(string);
        void agregaMensaje(string,string);
        dtPropiedadDisponible ** listaPropiedadesDisponibles();
        dtPropiedadInmobiliaria ** seleccionaPropiedadDisponible(string);
        void altaInteresado (string,string,int,string);
        void altaEdificio(string,int,int);
        dtReporteInmobiliaria** iniciarReporte(Inmobiliaria);
        void altaPropiedadCasa (dtPropiedadCasa);
        void altaPropiedadApto(dtPropiedadApto);
    };

#endif /* CONTPROP_H */

