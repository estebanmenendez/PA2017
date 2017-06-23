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

#include"IContPorp.h"
#include"IDictionary.h"
<<<<<<< HEAD
#include "dtEdificio.h"
#include "ICollection.h"
=======
#include"Edificio.h"
#include"ICollection.h"
#include"Lista.h"
>>>>>>> 5724056674296bc40ea0fdc49297da178497408f
#include <iostream>

#ifndef CONTPROP_H
#define CONTPROP_H

using namespace std;

 class ContProp : public IContProp {
    private: 
<<<<<<< HEAD
        IDictionary * cosodiccionario;
        ICollection * cosocoleccion;
        
=======
        
//        IDictionary * Departamento;
//        IDictionary * Edificio;
//        IDictionary * PropInmo;
//        IDictionary * ContUsuario;
          
          IDictionary * Diccionario;
          IDictionary * ICollection;
    
>>>>>>> 5724056674296bc40ea0fdc49297da178497408f
     
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
        void altaEdificio();
        void altaEdi(dtEdificio);
        dtReporteInmobiliaria** iniciarReporte(Inmobiliaria);
        void altaPropiedadCasa(dtPropiedadCasa);
        void altaPropiedadApto(dtPropiedadApto);
        
    };

#endif /* CONTPROP_H */

