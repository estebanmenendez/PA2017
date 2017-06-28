/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Interesado.cpp
 * Author: ernesto
 * 
 * Created on 9 de junio de 2017, 06:07 PM
 */

#include "Interesado.h"
#include "ListDicc.h"

  int Interesado::getEdad(){
      
  }
  void Interesado::setEdad(){
      
  }
  Interesado::Interesado(){
  }
Interesado::Interesado(string nombre, string apellido,int edad, string email,string contra):Usuarios(email,contra ){
    this->nombreInt = nombre;
    this->apellidoInt = apellido;
    this->edad = edad;
}   
  Interesado::~Interesado(){
      
  }
int Interesado::getTipo(){
  return 3;
}
string Interesado::getPwd(){
    return Usuarios::getPwd();
}
string Interesado::getEmail(){
    return Usuarios::getEmail();
}

    
