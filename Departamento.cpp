/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Departamento.cpp
 * Author: lucia
 * 
 * Created on 9 de junio de 2017, 06:33 PM
 */

#include "Departamento.h"

Departamento::Departamento() {
}

Departamento::Departamento(const Departamento& orig) {
}

Departamento::~Departamento() {    
}


Lista* Departamento::getZonas(){
IIterator *it=IZona->getIteratorObj();
   
    Lista *resul=new Lista();
    while (it->hasNext()) {
        Zona* z= dynamic_cast <Zona*> (it->getCurrent());
        resul->add(z->getZonas());
        it->next();
    }
    delete it;
    return resul;
}
    Zona* Departamento::getZona(string letraZona){
        
    IIterator * it=IZona->getIteratorObj();
    StringKey *sk= new StringKey(letraZona);
    Zona *z=dynamic_cast<Zona*>(IZona->find(sk));
    if(z!=NULL)
        return z;   
    else 
        throw invalid_argument("No existe esa Zona");
    }
    
    
    dtDepartamento* Departamento::getDatos(){}
    dtPropEnDpto* Departamento::getpropEnDepto(Usuarios inmobiliaria){}
    Zona* getZona(){}

string Departamento::getLetraDpto(){
    return this->letraDpto;
}
