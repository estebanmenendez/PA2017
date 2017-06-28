/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Administrador.cpp
 * Author: ernesto
 * 
 * Created on 9 de junio de 2017, 06:06 PM
 */

#include "Administrador.h"

Administrador::Administrador(string usu,string pwd):Usuarios(usu,pwd){
    
}

Administrador::~Administrador(){
    
}

int Administrador::getTipo(){
  return 1;
}
string Administrador::getEmail(){
    return Usuarios::getEmail();
}
string Administrador::getPwd(){
    return Usuarios::getPwd();
}
