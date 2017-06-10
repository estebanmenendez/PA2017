/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dtDireccion.h
 * Author: lucia
 *
 * Created on 6 de mayo de 2017, 05:11 PM
 */

#ifndef DTDIRECCION_H
#define DTDIRECCION_H
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class dtDireccion {
public:
    dtDireccion();
    dtDireccion(string ciudad, string calle, string numero);
    dtDireccion(const dtDireccion& orig);
    virtual ~dtDireccion();
    
    string getCalle() const;
    string getNumero() const;    
    string getCiudad() const; 
    
    
private:
    string ciudad;
    string calle;
    string numero;

};

#endif /* DTDIRECCION_H */

