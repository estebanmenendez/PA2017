/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dtFecha.h
 * Author: Boris
 *
 * Created on 10 de junio de 2017, 12:22 AM
 */

#include <string.h>
#include <stdio.h>
#include <iostream>

#ifndef DTFECHA_H
#define DTFECHA_H

using namespace std;

class dtFecha {
public:
    dtFecha();
    dtFecha(const dtFecha& orig);
    virtual ~dtFecha();
    dtFecha(string dd, string mm, string aa);
    
    string getDias() const;
    string getMeses() const;
    string getAños() const;
    
private:
    string dd;
    string mm;
    string aa;

};

#endif /* DTFECHA_H */

