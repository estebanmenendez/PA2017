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
#include"PropInmo.h"
#include"Edificio.h"
#include"Lista.h"
#include"ListDicc.h"
#include"ContUsuario.h"
#include"Usuarios.h"
#include"Inmobiliaria.h"
#include "Departamento.h"
#include<iostream>



using namespace std;

 class ContProp : public IContProp {
     
    private: 
        Zona * zona;
        Departamento* dep;
        Usuarios* usuario;

        IDictionary * IDepartamento;
        IDictionary * IEdificio;
        ContUsuario * ControladorUsuario;
                
 public:
        
ContProp();

ContProp(const ContProp& orig);

~ContProp();
        Lista * listaDepartamentos(); 
        void seleccionarDepartamentos(string); 
        Lista * listaZonasDepartamentos();
        void seleccionaZona(string);
        Lista * listaPropiedades();
//        void seleccionaZona(string letrazona);
        Lista * seleccionaPropiedad(string);
        string ingesrarCodProp(string);
        void modifPropCasa(dtPropiedadCasa);
        void modifPropApto(dtPropiedadApto);
        Lista * listaConversacionesInmobiliarias();
        void seleccionaConversacion(string);
        Lista * listaUltimosCincoMensajes();
        void seleccionaMensaje(string);
        void agregaMensaje(string,string);
        Lista * listaPropiedadesDisponibles();
        dtPropiedadInmobiliaria * seleccionaPropiedadDisponible(string);
        void altaInteresado (string,string,int,string);
        void altaEdificio(string,int,float);
        Lista * iniciarReporte(Inmobiliaria);
        void altaPropiedadCasa(dtPropiedadCasa*);
        void altaPropiedadApto(dtPropiedadApto*);
        void eliminarProp(string);
        void altaZona(string,string,string);
        void altaDepto(dtDepartamento*);
    };

#endif /* CONTPROP_H */



