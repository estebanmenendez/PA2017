
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
//#include"Fabrica.h"
#include"sistema.h"
#include"PropInmo.h"
#include "dtPropiedadApto.h"
#include "dtPropiedadCasa.h"
#include"Usuarios.h"



using namespace std;
//void menu();
void opcionesGenerales(); // MENU GENERAL DE OPCIONES ADMIN/INTER/INMO/CARGAR PRUEBA
void cargaDatosPrueba();
void administradorOpciones();
void inmobiliariaOpciones();
void interesadoOpciones();
void iniciarSesion();

void adminOpciones(int opAdmin);
void inmoOpciones(int opInmo);
void interOpciones(int opInter);

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




int idSesion=0;
string us, pwd; // LOS DEFINO COMO VARIABLES GLOBALES PARA MOSTRAR EL USUARIO EN CADA CU

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
    
   // cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<endl<<endl;
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

void administradorOpciones(){
    int opAdmin=0;
    system ("clear");
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout << "\nMENU - USUARIO ADMINISTRADOR" << endl;
    cout << "1 - Alta inmobiliaria" << endl;
    cout << "2 - Alta interesado" << endl;
    cout << "3 - Obtener reporte inmobiliaria" << endl;
    cout << "4 - Cerrar sesion" << endl; 
    cin>>opAdmin;
    adminOpciones(opAdmin);
}

void inmobiliariaOpciones(){
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

void interesadoOpciones(){
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

void iniciarSesion(){
    Usuarios * usu;
    
    string datos = "n";
    cout<<"Desea precargar datos? ";
    cin>>datos;
       
    if (datos=="s"){
        cout<<"precargarDatos();";
    }
    
    cout<<"\nIngrese email: ";
    cin>>us;
    
    cout<<"\nIngrese contrasenia: ";
    cin>>pwd;
    
    // usu = recorrerUsuarios(us, pwd); Recorrer colección de usuarios
    // ESTO ES SOLO PARA PROBAR EL MENU
    system ("clear");
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout<<"\nSeleccione tipo de usuario: ";
    cout<<"\n1 - Administrador"<<endl;
    cout<<"2 - Inmobiliaria"<<endl;
    cout<<"3 - Interesado"<<endl;
        
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

void adminOpciones(int opAdmin){
     //int opAdmin=1;    
    while (opAdmin !=  0){
                //cin >> opAdmin;
        switch (opAdmin){
                case 1 : altaInmobiliaria(); break;
                case 2 : altaInteresado(); break;
                case 3 : obtenerReporteInmo(); break;
                case 4 : cerrarSesion(idSesion); break;
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
                case 2 : modificarPropiedad(propiedad); break;
                case 3 : eliminarPropiedad(propiedad); break;
                case 4 : consultarPropiedad(prop); break;
                case 5 : altaEdificio(nombre, pisos, gastosComunes); break;
                case 6 : enviarMsjInmobiliaria(msjInmo); break;
                case 7 : cerrarSesion(idSesion); break;
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
                case 1 : consultarPropiedad(propiedad); break;
                case 2 : enviarMsjInteresado(msjInter); break;
                case 3 : cerrarSesion(idSesion); break;
           }
        }
}

void cargaDatosPrueba(){
    
}
Usuarios buscarUsr(string email){
    
}

void altaInteresado(){
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout<<"\n2 - Alta interesado\n";
    //Fabrica* f = Fabrica::getInstance();
   // IC_CliIt * iC = f->getC_CliIt();  EJEMPLO
    // buscarUsr(email);
    string nombre, apellido, email;
    int edad;
    string seguir="s";
    
    //if(buscarUsr(email)!= NULL){
    while(!seguir){
        try{
            cout<<"Ingrese nombre: ";
            cin>>nombre;
            cout<<"Ingrese apellido: ";
            cin>>apellido;
            cout<<"Ingrese edad: ";
            cin>>edad;
            cout<<"Ingrese email: ";
            cin>>email;            
            
            // i->ingresarDatosInter(nombre, apellido, edad, email);
            //cout<<"Usuario inmobiliaria creado correctamente ";
        }catch(invalid_argument & e){
            cout<<e.what();
        }
        }
    //}
    cout<<"\nDesea ingresar otro? ";
    cin>>seguir;
        
    
}

dtReporteInmobiliaria obtenerReporteInmo(){
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout<<"Desarrollo Obtener Reporte Inmo";
    
}

void cerrarSesion(int idSesion){
    cout<<"Desarrollo Cerrar Sesion";
}

void modificarPropiedad(dtPropiedad propiedad){
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout<<"Desarrollo Modificar Propiedad";
    
}

void eliminarPropiedad(dtPropiedad prop){
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout<<"Desarrollo Eliminar Propiedad";
}

dtPropiedad consultarPropiedad(string propiedad){
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout<<"Desarrollo Consultar Propiedad";
    
}

void altaEdificio(string nombre, int pisos, int gastosComunes){
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout<<"Desarrollo Alta Edificio";
}

void enviarMsjInmobiliaria(string msjInmo){
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout<<"Desarrollo Enviar Msj Inmobiliaria";
}

void enviarMsjInteresado(string msjInter){
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout<<"Desarrollo Enviar Msj Interesado";
}
//////////////////////////////////////////



void altaPropiedad(){
    sistema* s= new sistema();
    dtDepartamento** listaDep;
    
    dtZonas** listaZona;
    dtEdificio edif;
    string letraDep, codigoZona,ciudad, calle, numero,nEdif;
    int cAmb,cBanios,cDorm;
    float mEdif,mVerdes,valor;
    char opt,garage;
    dtPropiedadCasa * dtPropC;
    dtPropiedadApto * dtPropA;
    dtDireccion* dir;
    bool lgarage,ventAlq;
    
    
    listaDep = s->listaDepartamentos();
    s->seleccionaDepartamento(letraDep);
    listaZona = s->listaZonaDepartamento(letraDep);
    s->seleccionaZona(codigoZona);
    system ("clear");
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout<<"\n1 - Alta propiedad\n";
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
    cin>>ventAlq; 
    cout<<"Ingrese Valor de Venta/ Alquiler \n";
    cin>>valor; 
    dtPropC = new dtPropiedadCasa(cAmb,cBanios,cDorm,lgarage,dir,mEdif,mVerdes,valor,ventAlq);
    s->altaPropiedadCasa(*dtPropC);
   
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
    cout<<"Indique si  Venta o Alquiler : A/V \n";
    cin>>ventAlq; 
    cout<<"Ingrese Valor de Venta/ Alquiler \n";
    cin>>valor; 
    dtPropA = new dtPropiedadApto(cAmb,cBanios,cDorm,lgarage,dir,mEdif,nEdif,valor,ventAlq);
    s->altaPropiedadApto(*dtPropA);
    }
}

void altaInmobiliaria(){
    string nombre, ciudad, calle, numero;
    sistema* s= new sistema();
    //Fabrica* f = Fabrica::getInstance();
   // IC_CliIt * iC = f->getC_CliIt();  EJEMPLO
    dtDireccion* dir;
    
    system ("clear");
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
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

	
