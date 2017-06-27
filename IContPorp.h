/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IContPorp.h
 * Author: ernesto
 *
 * Created on 13 de junio de 2017, 08:03 AM
 */

#ifndef ICONTPORP_H
#define ICONTPORP_H
#include"dtPropiedadMensaje.h"
#include"dtPropiedadDisponible.h"
#include"dtDepartamento.h"
#include"dtConversaInmobiliaria.h"
#include"dtReporteInmobiliaria.h"
#include"dtMensajes.h"
#include"dtPropiedadInmobiliaria.h"
#include"dtZonas.h"
#include"Inmobiliaria.h"
#include"dtPropiedadCasa.h"
#include"dtPropiedadApto.h"
#include "dtEdificio.h"
#include "IKey.h"
#include "Lista.h"
#include "Departamento.h"

using namespace std;

 class IContProp {
    private: 
 
     
    public:
       
        virtual ~IContProp();
       virtual void seleccionarDepartamentos(string) = 0;
       virtual Lista * listaDepartamentos() = 0;
       virtual Lista * listaZonasDepartamentos() = 0;
        virtual void seleccionaZona(string) = 0;
        virtual Lista * listaPropiedades() = 0;
        virtual Lista * seleccionaPropiedad(string) = 0;
        virtual void enviarMensaje(string) = 0;
        virtual string ingesrarCodProp(string) = 0;
        virtual void modifPropCasa(dtPropiedadCasa) = 0;
        virtual void modifPropApto(dtPropiedadApto) = 0;
        virtual dtConversaInmobiliaria * listaConversacionesInmobiliarias() = 0;
        virtual void seleccionaConversacion(string) = 0;
        virtual dtMensajes * listaUltimosCincoMensajes() = 0;
        virtual void seleccionaMensaje(string) = 0;
        virtual void agregaMensaje(string,string) = 0;
        virtual dtPropiedadDisponible * listaPropiedadesDisponibles() = 0;
        virtual dtPropiedadInmobiliaria * seleccionaPropiedadDisponible(string) = 0;
        virtual void altaInteresado (string,string,int,string) = 0;
        virtual void altaEdificio(string,int,float) = 0;
        virtual dtReporteInmobiliaria* iniciarReporte(Inmobiliaria) = 0;
        virtual void altaPropiedadCasa(dtPropiedadCasa*) = 0;
        virtual void altaPropiedadApto(dtPropiedadApto*) = 0;
        virtual void eliminarProp(string) = 0;
        
    };


#endif /* ICONTPORP_H */

