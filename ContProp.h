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

#include"IContPorp.h"
#include"IDictionary.h"
#include"dtEdificio.h"
#include"ICollection.h"
#include"Edificio.h"
#include"Lista.h"
#include"ICollection.h"
#include"ListDicc.h"
#include"ContUsuario.h"
#include<iostream>



using namespace std;

 class ContProp : public IContProp {
    private: 
        
        IDictionary * IDepartamento;
        IDictionary * IEdificio;
        IDictionary * IPropiedad;
        ICollection * PropInmo;
        ContUsuario * ControladorUsuario;

    public:
        ContProp();
        ContProp(const ContProp& orig);
        virtual ~ContProp();
        ListDicc * listaDepartamentos();
        void seleccionarDepartamentos(string);
        ListDicc * listaZonasDepartamentos(string);
        void seleccionaZona(string);
        dtPropiedadMensaje * listaPropiedades(string);
        dtPropiedadMensaje * seleccionaPropiedad(string,int);
        void enviarMensaje(string);
        string ingesrarCodProp(string);
        void modifPropCasa(dtPropiedadCasa);
        void modifPropApto(dtPropiedadApto);
        dtConversaInmobiliaria * listaConversacionesInmobiliarias();
        void seleccionaConversacion(string);
        dtMensajes * listaUltimosCincoMensajes();
        void seleccionaMensaje(string);
        void agregaMensaje(string,string);
        dtPropiedadDisponible * listaPropiedadesDisponibles();
        dtPropiedadInmobiliaria * seleccionaPropiedadDisponible(string);
        void altaInteresado (string,string,int,string);
        void altaEdificio(string,int,float);
        dtReporteInmobiliaria * iniciarReporte(Inmobiliaria);
        void altaPropiedadCasa(dtPropiedadCasa*);
        void altaPropiedadApto(dtPropiedadApto*);
        void eliminarProp(string);
        
    };

#endif /* CONTPROP_H */




