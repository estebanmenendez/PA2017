/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Chat.cpp
 * Author: esteban
 * 
 * Created on 11 de junio de 2017, 06:45 PM
 */

#include<string.h>
#include <stdio.h>
#include <iostream>
#include "Chat.h"
#include "Mensaje.h"
#include "Lista.h"

int Chat::getChat(){
	return Chat::getChat();
	
}

void Chat::setChat(int){
	
}

Chat::Chat() {
    this->IMensajes= new Lista();	
}

Chat::~Chat() {
	
}

void Chat::eliminarLinksMensajes(){
	
}

bool Chat::esDelUsuario(){
	
}

int Chat::getCantidadMensaje(){
    int cantMensajes = 0;
    IIterator * it=IMensajes->iterator();
    while (it->hasNext()) {
        Mensaje *m=dynamic_cast<Mensaje*>(it->getCurrent());
        cantMensajes ++;
        it->next();
    }
    delete it;
    return cantMensajes;
}

bool Chat::pertPropUsuario(){
	
}

dtMensajes** Chat::getUltimosCinco(){
	
}

void Chat::enviaMensaje(string mensaje ){
	
}
void Chat::setInteresado(Interesado *usu){
    this->Inter=usu;
}
void Chat::altaMensaje(string mensa,dtFecha* fecha,dtHora* hora, Interesado * usuario) {
    setInteresado(usuario);
    Mensaje *m=new Mensaje(mensa,fecha,hora);
    IMensajes->add(m);
   
}
