/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sistema.h
 * Author: lucia
 *
 * Created on 6 de mayo de 2017, 05:32 PM
 */
#include <string.h>
#include <stdio.h>
#include <iostream>
#include"dtDireccion.h"
#include"dtDepartamento.h"
#include"dtZonas.h"
#include"dtEdificio.h"
#include"dtPropiedadCasa.h"
#include"dtPropiedadApto.h"




#ifndef SISTEMA_H
#define SISTEMA_H

using namespace std;

class sistema {
public:
    sistema();
    sistema(const sistema& orig);
    virtual ~sistema();
    
    void altaInmobiliaria(string nombreInm, dtDireccion* ubicacionInm);
    
    dtDepartamento** listaDepartamentos();
    void seleccionaDepartamento(string letraDepartamento);
    
    dtZonas** listaZonaDepartamento(string letraDepartamento);
    void seleccionaZona(string codigoZona);
    void altaPropiedadCasa(dtPropiedadCasa);
    dtEdificio** listarEdificioZona(string codigoZona);
    void altaEdificio(dtEdificio edificio);
    string seleccionarEdificio();    
    void altaPropiedadApto(dtPropiedadApto);
    void eliminarProp(dtPropiedad);
       
    
private:

};

#endif /* SISTEMA_H */

