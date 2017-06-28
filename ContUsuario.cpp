/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ContUsuario.cpp
 * Author: esteban
 * 
 * Created on 12 de junio de 2017, 07:50 PM
 */

#include "ContUsuario.h"
#include "Interesado.h"
#include "ICollection.h"
#include "Inmobiliaria.h"
#include "ContProp.h"
#include "Administrador.h"
#include <iostream>
#include <string.h>
#include <stdexcept>
using namespace std;

    ContUsuario::ContUsuario() {
    }

    ContUsuario::ContUsuario(const ContUsuario& orig) {
    }

    ContUsuario::~ContUsuario() {
    }
    void ContUsuario::altaAdministrador(){
        Administrador * i = new Administrador("admin","admin");
        StringKey * skEmail = new StringKey("admin");  //GENERO LA CLAVE 
        if(IUsuario->member(skEmail)!=true)//pregunto si ya existe
            IUsuario->add(i,skEmail);//agrego el objeto mas la clave a la coleccion dicionario
        else 
            throw new invalid_argument("Usuario Asdministrador ya existente");
    }
      void ContUsuario::altaInteresado(string nombre, string apellido, int edad, string email,string contra){
          
        Interesado * i = new Interesado(nombre, apellido, edad, email,contra);
        StringKey * skEmail = new StringKey(email);  //GENERO LA CLAVE 
        if(IUsuario->member(skEmail)!=true)//pregunto si ya existe
            IUsuario->add(i,skEmail);//agrego el objeto mas la clave a la coleccion dicionario
        else 
            throw new invalid_argument("Usuario interesado ya existente");
        
    }

void ContUsuario::altaInmobiliaria( string nombre, dtDireccion * direccion, string email,string contra){
             
      Inmobiliaria * inm = new Inmobiliaria(nombre, direccion, email,contra);
      StringKey * skEmail = new StringKey(email);  //GENERO LA CLAVE 
      if(IUsuario->member(skEmail)!=true)//pregunto si ya existe
           IUsuario->add(inm,skEmail);//agrego el objeto mas la clave a la coleccion dicionario
       else throw new invalid_argument("Usuario inmobiliaria ya existente");
            
  }
Usuarios* ContUsuario::altaSesion(string usu){
    StringKey *sk=new StringKey(usu);
    Usuarios *u=dynamic_cast<Usuarios*>(IUsuario->find(sk));
    usuLog = u;
    return u;
}
void ContUsuario::cancelarAccion(){
    
}

dtReporteInmobiliaria * ContUsuario::obtenerReporteInmobiliarias (){
    
}


Usuarios * ContUsuario::usuarioLogueado(){
    return usuLog;
}

void ContUsuario::iniciarSesion(){
//    Usuarios * usu = new Usuarios();
//    altaSesion(usu);  
}

bool ContUsuario::verificarContrasena(string pwd , string pwdConfirmacion ){
    if(pwd==pwdConfirmacion){
        return true;
    }else{
        invalid_argument("Contraseña incorrecta");
        return false;
    }
}
void ContUsuario::activarUsuario(string pwd ,string email){
    Usuarios * u = new Usuarios(email,pwd);
    StringKey *sk = new StringKey(email);
    IUsuario->add(u, sk);
    
}

bool ContUsuario::validarPwd(string email,string contrasena){ 
   
    StringKey *sk=new StringKey(email);
    Usuarios *u=dynamic_cast<Usuarios*>(IUsuario->find(sk));
    
    if(u != NULL){
         return true;
    }else{
        throw invalid_argument("No existe ese Usuario");
        return false;
    }
}

void ContUsuario::CerrarSesion(){ 
    usuLog = NULL;
}

