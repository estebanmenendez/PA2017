/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StringKey.h
 * Author: esteban
 *
 * Created on 19 de junio de 2017, 05:38 PM
 */

#ifndef STRINGKEY_H
#define STRINGKEY_H

#include "String.h"
#include "IKey.h"

class StringKey: public IKey{
	private:
		String value;
	public:
		StringKey();
		StringKey(String value);
		String getString();
		bool equals(IKey* key);		
		virtual ~StringKey();

};
#endif