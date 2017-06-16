/* 
 * File:   main.cpp
 * Author: lucia
 *
 * Created on 6 de mayo de 2017, 04:34 PM
 */

#include<cstdlib>
#include<cstdlib>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<typeinfo>
#include<iostream>
#include<fstream>
#include"dtEdificio.h"
#include"dtDepartamento.h"
#include"dtDireccion.h"
#include"dtReporteInmobiliaria.h"
#include"Propiedad.h"
#include"dtPropiedad.h"
#include"sistema.h"




//void menu();
void opcionesGenerales(); // MENU GENERAL DE OPCIONES ADMIN/INTER/INMO/CARGAR PRUEBA
void cargaDatosPrueba();
void administradorOpciones();
void inmobiliariaOpciones();
void interesadoOpciones();
void iniciarSesion();

void adminOpciones();
void inmoOpciones();
void interOpciones();

void altaInteresado();
dtReporteInmobiliaria obtenerReporteInmo();
void cerrarSesion(int idSesion);
void modificarPropiedad(dtPropiedad propiedad);
void eliminarPropiedad(dtPropiedad prop);

dtPropiedad consultarPropiedad(string propiedad);
void altaEdificio(string nombre, int pisos, int gastosComunes);
void enviarMsjInmobiliaria(string msjInmo);
void enviarMsjInteresado(string msjInter);


//usuarios
Usuarios * recorrerUsuarios(string, string);

/////////////////////////////////////////
void altaInmobiliaria();
void altaPropiedad();


using namespace std;

int idSesion=0;


int main(int argc, char** argv) {

   /* int option = -1;
    
    while(option != 0){
        menu();
        cin>>option;
        switch(option){
            case 1:
                altaInmobiliaria();
                break;
            case 2:
                altaPropiedad();
                
                break;
        }
    }*/
    
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<endl<<endl;
	int opcion=1;

	while (opcion !=  0){
		opcionesGenerales();
		cin >> opcion;
		switch (opcion){
			case 1 : iniciarSesion();break;
                }

	}
	
    return 0;
}

///////////////////// NUEVO /////////////////////

void opcionesGenerales(){
	cout << "1 - Iniciar Sesion" << endl;
        cout << "2 - Iniciar Sesion - con datos precargados" << endl;
	cout << "0 - Salir" << endl; 
}

void administradorOpciones(){
    cout << "1 - Alta inmobiliaria" << endl;
    cout << "2 - Alta interesado" << endl;
    cout << "3 - Obtener reporte inmobiliaria" << endl;
    cout << "4 - Cerrar sesion" << endl; 
}

void inmobiliariaOpciones(){
    cout << "1 - Alta propiedad" << endl;
    cout << "2 - Modificar propiedad" << endl; 
    cout << "3 - Eliminar propiedad" << endl;
    cout << "4 - Consultar propiedad" << endl; 
    cout << "5 - Alta edificio" << endl;
    cout << "6 - Enviar mensaje inmobiliaria" << endl;
    cout << "7 - Cerrar sesion" << endl; 
}

void interesadoOpciones(){
    cout << "1 - Consultar propiedad" << endl;
    cout << "2 - Enviar mensaje interesado" << endl; 
    cout << "3 - Cerrar sesion" << endl; 
    
}

void iniciarSesion(){
    string us, pwd;
    Usuarios * usu;
    
    cout<<"Ingrese email: ";
    cin>>us;
    
    cout<<"\nIngrese contrasenia: ";
    cin>>pwd;
    
    // usu = recorrerUsuarios(us, pwd); Recorrer colección de usuarios
    
        
    int opUsr=1;
        
    while (opUsr !=  0){
                cin >> opUsr;
        switch (opUsr){
                case 1 : administradorOpciones(); break;
                case 2 : inmobiliariaOpciones(); break;
                case 3 : interesadoOpciones(); break;
           }
        }
    
}

void adminOpciones(){
    
     int opAdmin=1;
     //int idSesion;
        
    while (opAdmin !=  0){
                cin >> opAdmin;
        switch (opAdmin){
                case 1 : altaInmobiliaria(); break;
                case 2 : altaInteresado(); break;
                case 3 : obtenerReporteInmo(); break;
                case 4 : cerrarSesion(idSesion); break;
           }
        }
}

void inmoOpciones(){
    
     int opInmo=1;
     dtPropiedad propiedad;
     string prop;
     string nombre;
     int pisos;
     int gastosComunes;
     string msjInmo;
        
    while (opInmo !=  0){
                cin >> opInmo;
        switch (opInmo){
                case 1 : altaPropiedad(); break;
                case 2 : modificarPropiedad(propiedad); break;
                case 3 : eliminarPropiedad(propiedad); break;
                case 4 : consultarPropiedad(prop); break;
                case 5 : altaEdificio(nombre, pisos, gastosComunes); break;
                case 6 : enviarMsjInmobiliaria(msjInmo); break;
                case 7 : cerrarSesion(idSesion); break;
           }
        }
}

void interOpciones(){
    
     int opAdmin=1;
     string propiedad;
     string msjInter;
        
    while (opAdmin !=  0){
                cin >> opAdmin;
        switch (opAdmin){
                case 1 : consultarPropiedad(propiedad); break;
                case 2 : enviarMsjInteresado(msjInter); break;
                case 3 : cerrarSesion(idSesion); break;
           }
        }
}



void cargaDatosPrueba(){
    
}

void altaInteresado(){
    
}

dtReporteInmobiliaria obtenerReporteInmo(){
    
}

void cerrarSesion(int idSesion){
    
}

void modificarPropiedad(dtPropiedad propiedad){
    
}

void eliminarPropiedad(dtPropiedad prop){
    
}

dtPropiedad consultarPropiedad(string propiedad){
    
}

void altaEdificio(string nombre, int pisos, int gastosComunes){
    
}

void enviarMsjInmobiliaria(string msjInmo){
    
}

void enviarMsjInteresado(string msjInter){
    
}
//////////////////////////////////////////



void altaPropiedad(){
    sistema* s= new sistema();
    dtDepartamento** listaDep;
    
    dtZonas** listaZona;
    dtEdificio edif;
    string letraDep, codigoZona,ciudad, calle, numero,nEdif,ventaAlq;
    int cAmb,cBanios,cDorm;
    float mEdif,mVerdes,valor;
    char opt,garage;
    dtDireccion* dir;
    bool lgarage;
    
    
    listaDep = s->listaDepartamentos();
    s->seleccionaDepartamento(letraDep);
    listaZona = s->listaZonaDepartamento(letraDep);
    s->seleccionaZona(codigoZona);
    cout<<"Ingresa Una Casa o Un Apto? C / A \n";
    cin>>opt;
    if (opt == 'C'){
    cout<<"\nDatos Casa\n";
    cout<<"Ingrese Cantidad Ambientes: \n";
    cin>>cAmb;
    cout<<"Ingrese Cantidad Baños: \n";
    cin>>cBanios;
    cout<<"Ingrese Cantidad Dormitorios: \n";
    cin>>cDorm;
    cout<<"Tiene Garage : S/N \n";
    cin>>garage; 
    if(garage =='S')
        lgarage = true;
    else
        lgarage = false;
    
    cout<<"Ingrese Ciudad: ";
    cin>>ciudad;
    cout<<"Ingrese Calle: ";
    cin>>calle;
    cout<<"Ingrese Número: ";
    cin>>numero;
    dir = new dtDireccion(ciudad,numero,calle);
    cout<<"Ingrese Metros Cuadrados Edif: \n";
    cin>>mEdif;
    cout<<"Ingrese Metros Verdes: \n";
    cin>>mVerdes;
    cout<<"Indique si  Venta o Alquiler : A/V \n";
    cin>>ventaAlq; 
    cout<<"Ingrese Valor de Venta/ Alquiler \n";
    cin>>valor; 
    s->altaPropiedadCasa(cAmb,cBanios,cDorm,lgarage,dir,mEdif,mVerdes,valor,ventaAlq);
    
    }else{
        s->listarEdificioZona(codigoZona);
        cout<<"Ingrese Un Edificio: S/N \n";
        cin>>opt;
        if (opt =='S'){
            s->altaEdificio(edif);
            s->listarEdificioZona(codigoZona);
        }
        nEdif = s->seleccionarEdificio();
     
    cout<<"\nDatos Apartamentos\n";
    cout<<"Ingrese Cantidad Ambientes: \n";
    cin>>cAmb;
    cout<<"Ingrese Cantidad Baños: \n";
    cin>>cBanios;
    cout<<"Ingrese Cantidad Dormitorios: \n";
    cin>>cDorm;
    cout<<"Ingrese Garage : S/N \n";
    cin>>garage; 
    cout<<"Ingrese Ciudad: ";
    cin>>ciudad;
    cout<<"Ingrese Calle: ";
    cin>>calle;
    cout<<"Ingrese Número: ";
    cin>>numero;
    dir = new dtDireccion(ciudad,numero,calle);
    cout<<"Ingrese Metros Cuadrados Edif: \n";
    cin>>mEdif;
    cout<<"Indique si  Venta o Alquiler : A/V \n";
    cin>>ventaAlq; 
    cout<<"Ingrese Valor de Venta/ Alquiler \n";
    cin>>valor; 
     s->altaPropiedadApto(cAmb,cBanios,cDorm,lgarage,dir,mEdif,nEdif,valor,ventaAlq);
    }
}

void altaInmobiliaria(){
    string nombre, ciudad, calle, numero;
    sistema* s= new sistema();
    dtDireccion* dir;
    
    system ("clear");
    cout<<"\n1 - Alta inmobiliaria\n";
    cout<<"Ingrese Nombre: ";
    cin>>nombre;
    cout<<"Ingrese Ciudad: ";
    cin>>ciudad;
    cout<<"Ingrese Calle: ";
    cin>>calle;
    cout<<"Ingrese Número: ";
    cin>>numero;
    dir = new dtDireccion(ciudad,numero,calle);
    s->altaInmobiliaria(nombre,dir);
    cout<<"Inmobiliaria dada de Alta ";
    
    
    
}
   
/*void menu(){
    system ("clear");
    cout<<"\n1 - Alta inmobiliaria"<<endl;
    cout<<"2 - Alta propiedad"<<endl; 
    cout<<"0 - Salir"<<endl;
}
*/

	
