/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ContProp.cpp
 * Author: juan
 * 
 * Created on 9 de junio de 2017, 08:17 PM
 */

#include "ContProp.h"
#include "ICollection.h"
#include "Edificio.h"
#include "Lista.h"
#include "Propiedad.h"

ContProp::ContProp() {
}

ContProp::ContProp(const ContProp& orig) {
}

ContProp::~ContProp() {
}
 dtDepartamento** ContProp::listaDepartamentos(){}
void ContProp::seleccionarDepartamentos(string){}
dtZonas ** ContProp::listaZonasDepartamentos(string){}
void ContProp::seleccionaZona(string){}
dtPropiedadMensaje ** ContProp::listaPropiedades(string){}
dtPropiedadMensaje ** ContProp::seleccionaPropiedad(string,int){}
void ContProp::enviarMensaje(string){}
string ContProp::ingesrarCodProp(string){}
void ContProp::modifPropCasa(dtPropiedadCasa){}
void ContProp::modifPropApto(dtPropiedadApto){}
dtConversaInmobiliaria ** ContProp::listaConversacionesInmobiliarias(){}
void ContProp::seleccionaConversacion(string){}
dtMensajes ** ContProp::listaUltimosCincoMensajes(){}
void ContProp::seleccionaMensaje(string){}
void ContProp::agregaMensaje(string,string){}
dtPropiedadDisponible ** ContProp::listaPropiedadesDisponibles(){}
dtPropiedadInmobiliaria ** ContProp::seleccionaPropiedadDisponible(string){}
void ContProp::altaInteresado (string,string,int,string){}
void ContProp::altaEdificio(){}
void ContProp::altaEdi(dtEdificio){
 cout<<"co";}


dtReporteInmobiliaria** ContProp::iniciarReporte(Inmobiliaria){}
void ContProp::altaPropiedadCasa(dtPropiedadCasa){
   
//    Lista* l = new Lista();
//    Propiedad* p = new Propiedad(dtPropiedadCasa);
//    if (dtPropiedadCasa* empr = dynamic_cast <Casa *>(emp[i]))
//    cout<<empr;
//
//    else
//    break;
//
//    Propiedad* p = new Propiedad(dtPropiedadCasa);
}

void ContProp::altaPropiedadApto(dtPropiedadApto){
    
 // if (dtPropiedadApto* empr = dynamic_cast <Apartamento *>(emp[i]))
                
}
