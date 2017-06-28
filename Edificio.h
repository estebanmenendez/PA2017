/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Edificio.h
 * Author: ernesto
 *
 * Created on 9 de junio de 2017, 07:14 PM
 */

#include"ICollectible.h"
#include "dtEdificio.h"
#include<string.h>
#include<stdio.h>
#include<iostream>

#ifndef EDIFICIO_H
#define EDIFICIO_H

using namespace std;

class Edificio :public ICollectible {

    private:
        string nombreEdificio;
        int cantpisosEdificio;
        float gastosComunes;
        
public: 
    dtEdificio* getEdificio();
    dtEdificio* getEdificio(string);
    void SetGastosComunes(float gastosComunes);
    float GetGastosComunes() const;
    void SetCantpisosEdificio(int cantpisosEdificio);
    int GetCantpisosEdificio() const;
    void SetNombreEdificio(string nombreEdificio);
    string GetNombreEdificio() const;
    
    
    Edificio ();
    Edificio(const Edificio& orig);
    Edificio (string,int,float);
    virtual ~Edificio();
        
};
#endif /* EDIFICIO_H */