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

      void ContUsuario::altaInteresado(string nombre, string apellido, int edad, string email){
          
        Interesado * i = new Interesado(nombre, apellido, edad, email);
        StringKey * skEmail = new StringKey(email);  //GENERO LA CLAVE 


       /* if(IInteresados->member(skEmail)!=true)//pregunto si ya existe
            IInteresados->add(i,skEmail);//agrego el objeto mas la clave a la coleccion dicionario
        */
        if(IUsuario->member(skEmail)!=true)//pregunto si ya existe
            IUsuario->add(i,skEmail);//agrego el objeto mas la clave a la coleccion dicionario


        else throw new invalid_argument("Usuario interesado ya existente");
        
    }
      void ContUsuario::altaInmobiliaria( string nombre, dtDireccion * direccion, string email){
             
      Inmobiliaria * coso = new Inmobiliaria(nombre, direccion, email);
      StringKey * skEmail = new StringKey(email);  //GENERO LA CLAVE 
      //StringKey * skEmail = new StringKey(nombre);


       /* if(IInmobiliaria->member(skEmail)!=true)//pregunto si ya existe
            IInmobiliaria->add(coso,skEmail);//agrego el objeto mas la clave a la coleccion dicionario
        */
        if(IUsuario->member(skEmail)!=true)//pregunto si ya existe
           IUsuario->add(coso,skEmail);//agrego el objeto mas la clave a la coleccion dicionario
        else throw new invalid_argument("Usuario inmobiliaria ya existente");
            
  }
void ContUsuario::altaSesion(Usuarios * usu){
    usuLog = usu;
}
void ContUsuario::cancelarAccion(){
    
}

dtReporteInmobiliaria * ContUsuario::obtenerReporteInmobiliarias (){
    
}


Usuarios * ContUsuario::usuarioLogueado(){
    return usuLog;
}

void ContUsuario::iniciarSesion(string email , string pwd){
    Usuarios * usu = new Usuarios();
    altaSesion(usu);  
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
    Usuarios * u = new Usuarios();
    StringKey *sk = new StringKey(email);
    IUsuario->add(u, sk);
    
}

bool ContUsuario::validarPwd(string contrasena){ 
    string ok="s";
    StringKey * skPwd = new StringKey(contrasena);
    
    if(IUsuario->find(skPwd)!= NULL){
        return true;
    }else{
        return false;
    }
}

void ContUsuario::CerrarSesion(){ 
usuLog = NULL;
}

