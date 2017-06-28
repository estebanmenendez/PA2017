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
#include "Administrador.h"

using namespace std;

//CASOS DE USO
void iniciarSesion();
void definoMenu(Usuarios*);
void cerrarSesion();
void altaInmobiliaria();
void altaInteresado();
void altaEdificio();
void altaPropiedad();
void consultarPropiedad();
void consultarPropiedadDisponible();
void modificarPropiedad();
void eliminarPropiedad(); 
void enviarMsjInteresado(); // HECHO 90%
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
                case 0 : break;
        }                
    }
    
return 0;
}

///////////////////// NUEVO /////////////////////

void opcionesGenerales(){
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<endl<<endl;
    cout << "0 - Salir" << endl; 
    cout << "1 - Iniciar Sesion" << endl;
   
}


void consultarPropiedadDisponible(){
     string letraDpto, codigoZona,codigoProp;
    //Departamento *depto;
     
    
    cout << "Caso Uso Consultar Propiedad Interesado\n";
    
    Fabrica* f = Fabrica::getInstance();
    IContProp * i = f->getContProp();
    ICollection* colDtDep= NULL;
   
    try{
    colDtDep = i->listaDepartamentos();
    
    IIterator *dt =colDtDep->iterator();
    cout<<"Departamentos Disponibles\n";
    
    while(dt->hasNext()){
        dtDepartamento *dtD=dynamic_cast<dtDepartamento*>(dt->getCurrent());
        cout<<dtD->getletraDepartamento()<<"-"<<dtD->getnombreDepartamento()<<"\n";
        dt->next();        
    }
    cout<<"Elegir Letra Departamento\n";
    cin>>letraDpto;
    i->seleccionarDepartamentos(letraDpto);
    ICollection* colDtZona= NULL;
    colDtZona= i->listaZonasDepartamentos();
    IIterator *dtZ =colDtZona->iterator();
    cout<<"Zonas Disponibles\n";
    while(dtZ->hasNext()){
        dtZonas *dtZona=dynamic_cast<dtZonas*>(dtZ->getCurrent());
        cout<<dtZona->getCodigoZona()<<"-"<<dtZona->getNombreZona()<<"\n";
        dtZ->next();        
    }
    
    cout<<"Elegir Código Zona\n";
    cin>>codigoZona;
    i->seleccionaZona(codigoZona);

    ICollection* colDtPropDispo=NULL;
    colDtPropDispo=i->listaPropiedadesDisponibles();
    IIterator *dtprop=colDtPropDispo->iterator();
    
    while (dtprop->hasNext()) {
        dtPropiedadDisponible* dtpro=dynamic_cast<dtPropiedadDisponible*>(dtprop->getCurrent());
        cout<<dtpro->getCodigoProp()<<"-"<<dtpro->getAlquilerOVenta();
        dtprop->next();
        }
    cout<<"Elegir Código Propiedad\n";
    cin>>codigoProp;
    i->seleccionaPropiedadDisponible(codigoProp);
       
    }catch(invalid_argument & e){
            cout<<e.what();
        } 
}




void administradorOpciones(){
   int opAdmin=0;
    
    system("clear");
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout << "\nMENU - USUARIO ADMINISTRADOR" << endl;
    cout << "0 - Volver" << endl; 
    cout << "1 - Alta inmobiliaria" << endl;
    cout << "2 - Alta interesado" << endl;
    cout << "3 - Obtener reporte inmobiliaria" << endl;
    cout << "4 - Cerrar sesion" << endl; 
    cin>>opAdmin;
    adminOpciones(opAdmin);
}

void adminOpciones(int opAdmin){
    while (opAdmin !=  0){
        switch (opAdmin){
            case 1 : altaInmobiliaria(); break;
            case 2 : altaInteresado(); break;
            case 3 : obtenerReporteInmo(); break;
            case 4 : cerrarSesion(); break;
           }
        }
}
void inmobiliariaOpciones(){ 
    int opInmo=0;
    system ("clear");
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout << "MENU - USUARIO INMOBILIARIA" << endl;
    cout << "0 - Volver" << endl; 
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

void inmoOpciones(int opInmo){
        
    while (opInmo !=  0){
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

void interesadoOpciones(){
    int opInter=0;
    system ("clear");
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout << "MENU - USUARIO INTERESADO" << endl;
    cout << "0 - Volver" << endl; 
    cout << "1 - Consultar propiedad" << endl;
    cout << "2 - Enviar mensaje interesado" << endl; 
    cout << "3 - Cerrar sesion" << endl; 
  
    cin>>opInter;
    interOpciones(opInter);
    
}
void interOpciones(int opInter){            
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
   Fabrica* f = Fabrica::getInstance();
   IContUsuario * is = f->getContUsuario();  //EJEMPLO
   is->altaAdministrador();
     // SOLICITO DATOS - AGREGAR TRY
    cout<<"\nIngrese email: ";
    cin>>us;
    cout<<"\nIngrese contrasenia: ";
    cin>>pwd;
    try{
        if (is->validarPwd(us,pwd))
            definoMenu(is->altaSesion(us));
    }catch(invalid_argument & e){
            cout<<e.what();
        } 
    
}

void definoMenu(Usuarios*  usu){
    int opUsr=0;
    if(dynamic_cast<Administrador*>(usu)->getTipo() == "Administrador"){
        opUsr == 1;
    }
    if(dynamic_cast<Interesado*>(usu)->getTipo() == "Interesado"){
        opUsr == 2;
    }
    if(dynamic_cast<Inmobiliaria*>(usu)->getTipo() == "Inmobiliaria"){
        opUsr == 3;
    }
        
    while (opUsr !=  0){
        cin >> opUsr;
    switch (opUsr){
            case 1 : administradorOpciones(); break;
            case 2 : inmobiliariaOpciones(); break;
            case 3 : interesadoOpciones(); break;
       }
    }
    
}

void altaInmobiliaria (){
    Fabrica* f = Fabrica::getInstance();
    IContUsuario * in = f->getContUsuario();  //EJEMPLO
    string nombre, ciudad, calle, numero, email,contra;
    dtDireccion* dir;
    
    system ("clear");
    cout<<"\n1 - Alta inmobiliaria\n";
    cout<<"Ingrese Nombre: ";
    cin>>nombre;
    
    cout<<"Ingrese Email: ";
    cin>>email;
    cout<<"Ingrese Contrasena: ";
    cin>>contra;
    cout<<"Ingrese Ciudad: ";
    cin>>ciudad;
    cout<<"Ingrese Calle: ";
    cin>>calle;
    cout<<"Ingrese Número: ";
    cin>>numero;
    dir = new dtDireccion(ciudad,numero,calle);

   // in->altaInmobiliaria(nombre,dir);
    //taInmobiliaria(nombre, dir)

    in->altaInmobiliaria(nombre, dir, email,contra);
    cout<<"Inmobiliaria dada de Alta ";
}

void altaPropiedad(){
    Fabrica* f = Fabrica::getInstance();
    IContProp * i = f->getContProp();  //EJEMPLO
    Departamento* depto;
    Lista * listaDep;
    Lista* listaZona;
    
    dtEdificio edif;
    string letraDep, codigoZona,ciudad, calle, numero,nEdif, VoA;
    int cAmb,cBanios,cDorm;
    float mEdif,mVerdes,valor;
    char opt,garage;
    dtPropiedadCasa * dtPropC;
    dtPropiedadApto * dtPropA;
    dtDireccion* dir;
    bool lgarage,ventAlq;
        
//    listaDep = i->listaDepartamentos();
    cout<<"Ingrese la letra del Departamento: ";
    cin>>letraDep;
    i->seleccionarDepartamentos(letraDep);
    listaZona = i->listaZonasDepartamentos();
    cout<<"Seleccione la Zona: ";
    i->seleccionaZona(codigoZona);
    cout<<"\n Ingresa Una Casa o Un Apto? C / A \n";
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
    cout<<"Indique si  Venta o Alquiler : V/A \n";
    cin>> VoA;
    if (VoA == "A"||VoA=="a"){
    ventAlq = true;
    cout<<"Ingrese Valor del Alquiler \n";
    cin>>valor; 
    }else{
    ventAlq = false;
    cout<<"Ingrese Valor de Venta \n";
    cin>>valor;
    }
    dtPropC = new dtPropiedadCasa(cAmb,cBanios,cDorm,lgarage,dir,mEdif,mVerdes,valor,ventAlq);
    i->altaPropiedadCasa(dtPropC);
   
    }else{
    cout<<"\nDatos Apartamentos\n";
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
    dir = new dtDireccion(ciudad,calle,numero);
    cout<<"Ingrese Metros Cuadrados Edif: \n";
    cin>>mEdif;
    cout<<"Indique si  Venta o Alquiler : A/V \n";
    cin>>ventAlq; 
    cout<<"Ingrese Valor de Venta/ Alquiler \n";
    cin>>valor; 
    dtPropA = new dtPropiedadApto(cAmb,cBanios,cDorm,lgarage,dir,mEdif,nEdif,valor,ventAlq);
    i->altaPropiedadApto(dtPropA);
    }
}

void enviarMsjInmobiliaria(){}

void enviarMsjInteresado(){
    string letraDpto, codigoZona,codigoProp;
    //Departamento *depto;    
    cout << "Caso Uso Enviar Mensaje Interesado\n";
    
    Fabrica* f = Fabrica::getInstance();
    IContProp * i = f->getContProp();
    ICollection* colDtDep= NULL;
    try{
    colDtDep = i->listaDepartamentos();
    
    IIterator *dt =colDtDep->iterator();
    cout<<"Departamentos Disponibles\n";
    
    while(dt->hasNext()){
        dtDepartamento *dtD=dynamic_cast<dtDepartamento*>(dt->getCurrent());
        cout<<dtD->getletraDepartamento()<<"-"<<dtD->getnombreDepartamento()<<"\n";
        dt->next();        
    }
    
    cout<<"Elegir Letra Departamento\n";
    cin>>letraDpto;
    i->seleccionarDepartamentos(letraDpto);
    
     ICollection* colDtZona= NULL;
    colDtZona= i->listaZonasDepartamentos();
    
    
    IIterator *dtZ =colDtZona->iterator();
    cout<<"Zonas Disponibles\n";
    
    while(dtZ->hasNext()){
        dtZonas *dtZona=dynamic_cast<dtZonas*>(dtZ->getCurrent());
        cout<<dtZona->getCodigoZona()<<"-"<<dtZona->getNombreZona()<<"\n";
        dtZ->next();        
    }
    
    cout<<"Elegir Código Zona\n";
    cin>>codigoZona;
    i->seleccionaZona(codigoZona);
    
    
    ICollection* colDtPropMensaje= NULL;
    colDtPropMensaje = i->listaPropiedades();
    
    cout<<"Propiedades y Mensajes\n";
    IIterator *dtPM = colDtPropMensaje->iterator();
    while(dtPM->hasNext()){
        dtPropiedadMensaje *dtPMens=dynamic_cast<dtPropiedadMensaje*>(dtPM->getCurrent());
        cout<<dtPMens->getcodigoProp()<<"-"<<dtPMens->getdireccionProp()<<"-"<<dtPMens->getCantMensajesEnviados()<<"\n";
        dtPM->next();        
    }
    
    cout<<"Elegir Código Propiedad\n";
    cin>>codigoProp;
    
    ICollection* colDtMensajes = NULL;
    colDtMensajes = i->seleccionaPropiedad(codigoProp);
    
    
    }catch(invalid_argument & e){
	cout << e.what();
    }
}
//
void altaInteresado(){

    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout<<"\n2 - Alta interesado\n";
    Fabrica* f = Fabrica::getInstance();
    IContUsuario * i = f->getContUsuario();  //EJEMPLO
    // buscarUsr(email);
    string nombre, apellido, email,contra;
    int edad;
    string seguir="s";

    while(seguir!="s"){
        try{
            cout<<"Ingrese nombre: ";
            cin>>nombre;
            cout<<"Ingrese apellido: ";
            cin>>apellido;
            cout<<"Ingrese edad: ";
            cin>>edad;
            cout<<"Ingrese email: ";
            cin>>email;
            cout<<"Ingrese Contrasena: ";
            cin>>contra;
            i->altaInteresado(nombre, apellido, edad, email,contra);
            cout<<"Usuario inmobiliaria creado correctamente ";
        }catch(invalid_argument & e){
            cout<<e.what();
        }
    }

    cout<<"\nDesea ingresar otro? ";
    cin>>seguir;
}

 dtReporteInmobiliaria obtenerReporteInmo(){
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout<<"\n - Obtener Reporte Inmobiliaria";
    
}
//
void cerrarSesion(){
    char opCerrar='n';
    cout<<"Cerrar Sesion\n";    
    cout<<"\nDesea cerrar sesion?\n";
    cin>>opCerrar;
    if (opCerrar == 's'){
        Fabrica* f = Fabrica::getInstance();
        IContUsuario * i = f->getContUsuario();  //EJEMPLO
        i->CerrarSesion();
    }
}
void modificarPropiedad(){}
//    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
//    cout<<"\n Modificar Propiedad";
//    string codigoProp;
//    
//    cout<<"\nIngrese codigo propiedad: ";
//    cin>>codigoProp;
//    // recorrerPropiedades(codigoProp);
//    //     
//}
//
void eliminarPropiedad(){
    cout<<endl<< "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout<<"Desarrollo Eliminar Propiedad";
    string codigo;
    Fabrica* f = Fabrica::getInstance();
    IContProp * i = f->getContProp();
    
    cout<<endl<<"Ingrese el codigo de la propiedad que desee eliminar: ";
    cin>>codigo;
    //dtProp = new dtPropiedad(codigoProp);
            
    i->eliminarProp(codigo);
    
}

void consultarPropiedad(){
    Fabrica *f = Fabrica::getInstance();
    IContProp *i=f->getContProp();
    i->listaPropiedadesDisponibles();
}

void altaEdificio(){
    string nombre;
    int pisos;
    float gastosComunes;
    Fabrica* f = Fabrica::getInstance();
    IContProp *i=f->getContProp();
         cout<<"Ingrese nombre del edificio: "<<endl;
         cin>>nombre;
         cout<<"Ingrese la cantidad de pisos: "<<endl;
         cin>>pisos;
         cout<<"Ingrese el valor de los gastos comunes: "<<endl;
         cin>>gastosComunes;
      //   dtEdificio *dtedi = new dtEdificio(nombre,pisos,gastosComunes);
       i->altaEdificio(nombre,pisos,gastosComunes);
       
      cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
}

