#include <iostream>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace std;

// Ejercicio 1. Función recursiva que calcule longitud de cadena de caractéres
/*
{Pre: }
{Post: }
*/

int longitudInm(char cadena[],int cont){

    if(cadena[cont]=='\0'){

            return cont;
    }else{
         return longitudInm(cadena,cont+1);
    }


}
int longitud(char cadena[]){
    return longitudInm(cadena,0);


}


// Ejercicio 2. Función recursiva que dada una cadena de caracteres sin espacios
// en blanco, devuelve verdad si dicha cadena es un palíndromo y falso en caso contrario.
/*
{Pre: }
{Post: }
*/
bool palindromoInm(char cadena[],int cont1,int cont2,bool pal){

    if(cont1>cont2){
        return pal;
    }else{
        if(cadena[cont1]!=cadena[cont2]){
            pal=false;

        }
        return palindromoInm(cadena,cont1+1,cont2-1,pal);

    }
}



bool palindromo(char cadena[]){

    return palindromoInm(cadena,0,longitud(cadena)-1,true);


}


// Ejercicio 3. Función recursiva que dada una cadena de caracteres sin espacios en blanco,
// devuelve verdad si dicha cadena contiene la letra ‘A’ y falso en caso contrario.
/*
{Pre: }
{Post: }
*/

bool contieneLaAInm(char cadena[],int cont,bool contiene){
    if(cont==0){

        return contiene;

    }else{

        if(cadena[cont-1]=='A'){
            contiene=true;

        }
        return contieneLaAInm(cadena,cont-1,contiene);

    }

}
bool contieneLaA(char cadena[]){

    return contieneLaAInm(cadena,longitud(cadena),false);

}



// Casos de prueba
TEST_CASE( "Calculando longitudes", "[longitud]" ) {
    REQUIRE( longitud((char *)"Hola") == 4 );
    REQUIRE( longitud((char *)"Adios") == 5 );
    REQUIRE( longitud((char *)"") == 0 );
}

TEST_CASE( "Comprobando palindromos", "[palindromos]" ) {
    REQUIRE( palindromo((char *)"dabaleelabad") == true );
    REQUIRE( palindromo((char *)"abba") == true );
    REQUIRE( palindromo((char *)"abcde") == false );
    REQUIRE( palindromo((char *)"abcdecba") == false );
    REQUIRE( palindromo((char *)"") == true );
    REQUIRE( palindromo((char *)"arrozalazorra") == true );
}

TEST_CASE( "Comprobando si cadenas contienen la letra A", "[contieneLaA]" ) {
    REQUIRE( contieneLaA((char *)"Pepe") == false );
    REQUIRE( contieneLaA((char *)"Pepa") == false );
    REQUIRE( contieneLaA((char *)"PEPA") == true );
    REQUIRE( contieneLaA((char *)"") == false );
    REQUIRE( contieneLaA((char *)"ABCDE") == true );
    REQUIRE( contieneLaA((char *)"BCADC") == true );
}
