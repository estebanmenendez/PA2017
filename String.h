/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   String.h
 * Author: esteban
 *
 * Created on 19 de junio de 2017, 05:40 PM
 */
#ifndef _STRING_HH
#define _STRING_HH

#include <stdio.h>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class String{
      // Datos de la cadena
      private: 
                char * arreglo;
                int largo;
		
	  	int largoCadena(const char*) const;
            
      
      public:
// PARTE 1
						
// Constructores:
                 
      // Constructor por defecto. Construye la cadena vacía.
      String();
      
      // Constructor por copia.
      // String(s) construye una cadena copia de s.
      String(const String&);
      
      // Constructor común.
      // String(cc) construye un String a partir la cadena de
      // caracteres indicada en cc.
      String (const char*);


// Destructor:
              
      // Libera la memoria utilizada por la instancia.
      virtual ~String();


// Operadores:
              
      // operator=(s) Asigna al objeto implícito la cadena s.
      String &operator=(const String&);
      String &operator=(const char*);
      
      // operator+(s) Retorna el resultado de la concatenación
      // del objeto implícito y s.
      String operator+(const String&) const;
      String operator+(const char*) const;
      
      
      // operator+=(s) Asigna el resultado de la concatenación
      // del objeto implícito y s sobre el objeto implícito.
      String& operator+=(const String &);
      String& operator+=(const char*);
      
      // operator!() Retorna true sii la cadena es vacía.
      bool operator!()const;
      
      // operator==(s) Retorna true sii la cadena del objeto
      // implícito es igual a s.
      bool operator==(const String &) const;
      bool operator==(const char*) const;
      // operator!=(s) Retorna true sii la cadena del objeto
      // implícito es distinta de s.
      bool operator!=(const String&) const;
      bool operator!=(const char*) const;
      
      // operator<(s) Retorna true sii la cadena del
      // objeto implícito es menor que la cadena s.
      bool operator<(const String&) const;
      bool operator<(const char*) const;
      
      // operator>(s) Retorna true sii la cadena del
      // objeto implícito es mayor que la cadena s.
      bool operator>(const String&) const;
      bool operator>(const char*) const;
      
      // operator<=(s) Retorna true sii la cadena del
      // objeto implícito es menor o igual que la cadena s.
      bool operator<=(const String&) const;
      bool operator<=(const char*) const;
      
      // operator>=(s) Retorna true sii la cadena del
      // objeto implícito es mayor o igual que la cadena s.
      bool operator>=(const String&) const;
      bool operator>=(const char*) const;
      
      // operator[i] Retorna el carácter de la cadena del
      // objeto implícito en la posición i.
      // Si i esta fuera de rango lanzar std::out_of_range.
      char operator[](unsigned int) const;

// Operaciones:
               
      // length() devuelve la cantidad de caracteres
      // de la cadena.
      unsigned int length() const;
      
      // isSubString(s1) devuelve true sii s1 es subcadena
      // del objeto implícito.
      // Dadas las cadenas s y s1, s1 es subcadena de s sii
      // existen cadenas x e y tales que s = x + s1 + y.
      bool isSubString(const String&) const;
      bool isSubString(const char*) const;
      
      // subString(inf, sup) devuelve la subcadena del objeto
      // implícito que se encuentra entre las posiciones dadas
      // por inf y sup (inf y sup inclusive).
      // Si inf y/o sup se van de rango lanzar std::out_of_range.
      // Si inf > sup lanzar la excepción std::invalid_argument.
      String subString(unsigned int, unsigned int) const;
      
      // replace(c1, c2) Devuelve la cadena resultado de sustituir
      // todas las ocurrencias de c1 por c2.
      String replace(char, char) const;
      
      // toUpperCase() Devuelve la cadena resultado de sustituir
      // todas las ocurrencias de caracteres en mayúscula
      // por su equivalente en minúscula.
      String toUpperCase() const;
      
      // toLowerCase() Devuelve la cadena resultado de sustituir
      // todas las ocurrencias de caracteres en mayúscula
      // por su equivalente en minúscula.
      String toLowerCase() const;

	// La Operacion getCadena la definimos nosotros
	// Devuelve la cadena del String
	char* getCadena() const;
};

// PARTE 2
			// Escribe una cadena de caracteres en un flujo cualquiera.
         ostream& operator<<(ostream&, const String&);

         // Escribe una cadena de caracteres en un flujo cualquiera.         
         // Lee una cadena de caracteres de un flujo cualquiera.
         istream& operator>>(istream&, String&);
		

// PARTE 3

         // Operadores de comparación entre char* e instancias de String.
         bool operator==(const char*, const String&);
         bool operator!=(const char*, const String&);
         bool operator<(const char*, const String&);
         bool operator>(const char*, const String&);
         bool operator<=(const char*, const String&);
         bool operator>=(const char*, const String&);

#endif