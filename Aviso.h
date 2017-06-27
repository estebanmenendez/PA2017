/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Aviso.h
 * Author: esteban
 *
 * Created on 11 de junio de 2017, 06:42 PM
 */

//#include"Propiedad.h"
#include"dtPropiedad.h"


#ifndef AVISO_H
#define AVISO_H


using namespace std;

class Aviso {
       
public:
    Aviso();
    Aviso(const Aviso& orig);
    virtual ~Aviso();
    
    virtual bool esVenta();
    virtual bool esAlquiler();
        
    virtual Aviso getAviso();
    
    virtual void altaAlquiler(float);
    virtual void altaVenta(float);

private:    
    

};

#endif /* AVISO_H */