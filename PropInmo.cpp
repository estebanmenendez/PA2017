/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PropInmo.cpp
 * Author: esteban
 * 
 * Created on 11 de junio de 2017, 06:48 PM
 */

#include "PropInmo.h"


using namespace std;

PropInmo::PropInmo() {
        
}

PropInmo::PropInmo(const PropInmo& orig) {
}

PropInmo::~PropInmo() {
}

int PropInmo::getCantidadMensajes(){
    int cantMensajes= 0;
    IIterator * it=IChatPropInmo->iterator();
    while (it->hasNext()) {
        Chat *ch=dynamic_cast<Chat*>(it->getCurrent());
        cantMensajes += ch->getCantidadMensaje();
        it->next();
    }
    delete it;
    return cantMensajes;
    
}
string PropInmo ::esAlquileroVenta(){
if(this->aviPropInmo[0]->esVenta())
    return "V";
if(this->aviPropInmo[1]->esVenta())
    return "V";
if(this->aviPropInmo[0]->esAlquiler())
    return "A";
if(this->aviPropInmo[1]->esAlquiler())
    return "A";
}
void PropInmo::enviarMensaje(Propiedad * propiedad, string mensaje){
    
}
void PropInmo::altaMensaje(string mensaje,dtFecha *fecha, dtHora* hora, Interesado * usu){
    Chat *chatAlta;
    chatAlta->altaMensaje(mensaje,fecha,hora,usu);
}

void PropInmo::eliminarLinks(){
	
}


dtAvisoPropiedad* PropInmo::getAvisos(){
	
}

void PropInmo::crearAvisoProp(bool ventAlq,float valor){
     Aviso* pi= new Aviso();
     if (ventAlq=true){
     
     pi = aviPropInmo [1] = new Alquiler();
     dynamic_cast<Alquiler*>(prop)->altaAlquiler(valor);
     }else{
      
     pi = aviPropInmo [2] = new Venta();
     dynamic_cast<Venta*>(prop)->altaVenta(valor);
     }
}
   
