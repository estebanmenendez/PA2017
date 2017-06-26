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
#include <stdexcept>
#include"dtEdificio.h"
#include"dtDepartamento.h"
#include"dtDireccion.h"
#include"dtReporteInmobiliaria.h"
#include"dtPropiedadApto.h"
#include"dtPropiedadCasa.h"
#include"dtPropiedad.h"
#include"Fabrica.h"
#include"PropInmo.h"
#include"Propiedad.h"
#include"ICollection.h"
#include"Inmobiliaria.h"
#include"Interesado.h"
#include"ListDicc.h"
#include"Usuarios.h"
#include"ListaIterator.h"
#include"ContProp.h"

using namespace std;

//CASOS DE USO
void iniciarSesion();
void cerrarSesion();
void altaInmobiliaria();
void altaInteresado();
void altaEdificio();
void altaPropiedad();
dtPropiedad consultarPropiedad();
void modificarPropiedad();
void eliminarPropiedad();
void enviarMsjInteresado();
void enviarMsjInmobiliaria();
dtReporteInmobiliaria obtenerReporteInmo();


// MENU GENERAL DE OPCIONES ADMIN/INTER/INMO/CARGAR PRUEBA
void opcionesGenerales(); 
void cargaDatosPrueba();
void administradorOpciones(string, string);
void inmobiliariaOpciones(string, string);
void interesadoOpciones(string, string);
void adminOpciones(int opAdmin);
void inmoOpciones(int opInmo);
void interOpciones(int opInter);
//Usuarios
Usuarios * recorrerUsuarios(string, string);

/////////////////////////////////////////

int idSesion=0;
string us, pwd; // LOS DEFINO COMO VARIABLES GLOBALES PARA MOSTRAR EL USUARIO EN CADA CU

int main(int argc, char** argv) {
    
	int opcion=1;

	while (opcion !=  0){
		opcionesGenerales();
		cin >> opcion;
		switch (opcion){
			case 1 : iniciarSesion();break;
                        case 2 : iniciarSesion();break;
                        case 0 : break;
                }
                
	}
	
    return 0;
}

///////////////////// NUEVO /////////////////////

void opcionesGenerales(){
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<endl<<endl;
    cout << "1 - Iniciar Sesion" << endl;
    cout << "0 - Salir" << endl; 
}

void administradorOpciones(string us, string pwd){
    Usuarios *usu;
    Fabrica* f = Fabrica::getInstance();
    IContUsuario * isAdmin = f->getContUsuario();  //EJEMPLO
    //isAdmin->validarPwd(pwd);
    
    try{
        if(isAdmin->validarPwd(pwd)==true){
            isAdmin->iniciarSesion(us, pwd);
            cout<<"Sesion iniciada correctamente ";
            invalid_argument("Contrasena incorrecta");
        }
    }catch(invalid_argument & e){
        cout<<e.what();
        } 
    
    
    
    int opAdmin=0;
    system("clear");
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout << "\nMENU - USUARIO ADMINISTRADOR" << endl;
    cout << "1 - Alta inmobiliaria" << endl;
    cout << "2 - Alta interesado" << endl;
    cout << "3 - Obtener reporte inmobiliaria" << endl;
    cout << "4 - Cerrar sesion" << endl; 
    cin>>opAdmin;
    adminOpciones(opAdmin);
    
}

void inmobiliariaOpciones(string us, string pwd){
    string op="s";
    string confPwd;
    Fabrica* f = Fabrica::getInstance();
    IContUsuario * isInmo = f->getContUsuario();  //EJEMPLO
    
    cout<<"\n Inicia sesion por primera vez?";
    while(op=="s"){ 
        try{
            cin>>op;
            cout<<"Ingrese contraseña";
            cin>>pwd;
            cout<<"Confirmar contraseña";
            cin>>confPwd;
            if(isInmo->verificarContrasena(pwd, confPwd)==true){
                isInmo->iniciarSesion(us, pwd);
                cout<<"Sesion iniciada correctamente ";
                invalid_argument("COSO");
        }
        }catch(invalid_argument & e){
            cout<<e.what();
        } 
    }
    
    isInmo->iniciarSesion(us, pwd);
    cout<<"Sesion iniciada correctamente ";
    
    int opInmo=0;
    system ("clear");
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout << "MENU - USUARIO INMOBILIARIA" << endl;
    cout << "1 - Alta propiedad" << endl;
    cout << "2 - Modificar propiedad" << endl; 
    cout << "3 - Eliminar propiedad" << endl;
    cout << "4 - Consultar propiedad" << endl; 
    cout << "5 - Alta edificio" << endl;
    cout << "6 - Enviar mensaje inmobiliaria" << endl;
    cout << "7 - Cerrar sesion" << endl;
    cin>>opInmo;
    inmoOpciones(opInmo); 
}

void interesadoOpciones(string us, string pwd){
    string op="s";
    string confPwd;
    Fabrica* f = Fabrica::getInstance();
    IContUsuario * isInter = f->getContUsuario();  //EJEMPLO
    
    cout<<"\n Inicia sesion por primera vez?";
    while(op=="s"){ 
        try{
            cin>>op;
            cout<<"Ingrese contraseña";
            cin>>pwd;
            cout<<"Confirmar contraseña";
            cin>>confPwd;
            if(isInter->verificarContrasena(pwd, confPwd)==true){
                isInter->iniciarSesion(us, pwd);
                cout<<"Sesion iniciada correctamente ";
                invalid_argument("COSO");
        }
        }catch(invalid_argument & e){
            cout<<e.what();
        } 
    }
    isInter->iniciarSesion(us, pwd);
    cout<<"Sesion iniciada correctamente ";
    
    int opInter=0;
    system ("clear");
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout << "MENU - USUARIO INTERESADO" << endl;
    cout << "1 - Consultar propiedad" << endl;
    cout << "2 - Enviar mensaje interesado" << endl; 
    cout << "3 - Cerrar sesion" << endl; 
    cin>>opInter;
    interOpciones(opInter);
    
}

void adminOpciones(int opAdmin){
     //int opAdmin=1;    
    while (opAdmin !=  0){
                //cin >> opAdmin;
        switch (opAdmin){
                case 1 : altaInmobiliaria(); break;
                case 2 : altaInteresado(); break;
                case 3 : obtenerReporteInmo(); break;
                case 4 : cerrarSesion(); break;
           }
        }
}

void inmoOpciones(int opInmo){
    
     //int opInmo=1;
     dtPropiedad propiedad;
     string prop;
     string nombre;
     int pisos;
     int gastosComunes;
     string msjInmo;
        
    while (opInmo !=  0){
                //cin >> opInmo;
        switch (opInmo){
                case 1 : altaPropiedad(); break;
                case 2 : modificarPropiedad(); break;
                case 3 : eliminarPropiedad(); break;
                case 4 : consultarPropiedad(); break;
                case 5 : altaEdificio(); break;
                case 6 : enviarMsjInmobiliaria(); break;
                case 7 : cerrarSesion(); break;
           }
        }
}

void interOpciones(int opInter){
    
    // int opInter=1;
     string propiedad;
     string msjInter;
        
    while (opInter !=  0){
                //cin >> opAdmin;
        switch (opInter){
                case 1 : consultarPropiedad(); break;
                case 2 : enviarMsjInteresado(); break;
                case 3 : cerrarSesion(); break;
           }
        }
}

void cargaDatosPrueba(){}

void iniciarSesion(){
//    Fabrica* f = Fabrica::getInstance();
//    IContUsuario * is = f->getContUsuario();  //EJEMPLO
    Usuarios * usuTipo;
    string usuario;
    int opUsr=1;
    string datos = "n";
    // PRECARGA DE DATOS
    
    cout<<"Desea precargar datos? ";
    cin>>datos;
       
    if (datos=="s"){
        cout<<"precargarDatos();";
    }
    
    // SOLICITO DATOS
    cout<<"\nIngrese email: ";
    cin>>us;
    cout<<"\nIngrese contrasenia: ";
    cin>>pwd;
    
    usuario = usuTipo->getTipo();
    
    if( usuario== "Administrador"){
        opUsr == 1;
    }
    if(usuario == "Interesado"){
        opUsr == 2;
    }
    if(usuario == "Administrador"){
        opUsr == 3;
    }
    
    system ("clear");
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout<<"\nSeleccione tipo de usuario: ";
    cout<<"\n1 - Administrador"<<endl;
    cout<<"2 - Inmobiliaria"<<endl;
    cout<<"3 - Interesado"<<endl;
        
    while (opUsr !=  0){
                cin >> opUsr;
        switch (opUsr){
                case 1 : administradorOpciones(us,pwd); break;
                case 2 : inmobiliariaOpciones(us,pwd); break;
                case 3 : interesadoOpciones(us,pwd); break;
           }
        }
    
}
void altaInmobiliaria (){
    Fabrica* f = Fabrica::getInstance();
    IContUsuario * in = f->getContUsuario();  //EJEMPLO
    string nombre, ciudad, calle, numero, email;
   // sistema* s= new sistema();
    dtDireccion* dir;
    
    system ("clear");
    cout<<"\n1 - Alta inmobiliaria\n";
    cout<<"Ingrese Nombre: ";
    cin>>nombre;
    cout<<"Ingrese Email: ";
    cin>>email;
    cout<<"Ingrese Ciudad: ";
    cin>>ciudad;
    cout<<"Ingrese Calle: ";
    cin>>calle;
    cout<<"Ingrese Número: ";
    cin>>numero;
    dir = new dtDireccion(ciudad,numero,calle);

    in->altaInmobiliaria(nombre, dir, email);
