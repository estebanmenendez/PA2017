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

Administrador::Administrador(){
    
}

Administrador::~Administrador(){
    
}
Administrador::Administrador(string pwd, string email){
    this->getEmail() = "adminsis";
    this->getPwd() = "pass1";
}
string Administrador::getTipo(){
  return "Administrador";
}
string Administrador::getEmail(){
    return this->getEmail();
}
string Administrador::getPwd(){
   return this->getPwd();
}
