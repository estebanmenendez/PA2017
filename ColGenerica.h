/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ColGenerica.h
 * Author: esteban
 *
 * Created on 19 de junio de 2017, 06:32 PM
 */

#ifndef COLGENERICA_H
#define COLGENERICA_H

#include "IDictionary.h"
#include "ListDiccIteratorObj.h"
#include "ListDiccIteratorKey.h"
#include "StringKey.h"
#include "Propiedad.h"
#include "Zona.h"
#include "ListaDicc.h"



class ColGenerica {
public:
    ColGenerica();
    virtual ~ColGenerica();
        ColGenerica(IDictionary* dicc);
        void addP(Propiedad* po, StringKey* key);
        void addZ(Zona* zo, StringKey* key);
        bool member(StringKey* key);
        Propiedad* removeKey(StringKey* key);
        Propiedad* removeObj(StringKey* obj);
        Propiedad* find(StringKey* key);
        ListDiccIteratorObj* getIteratorObj();
        ListDiccIteratorKey* getIteratorKey();
        unsigned int size();
   

private:
 IDictionary * dicc;   

};

#endif /* COLGENERICA_H */

