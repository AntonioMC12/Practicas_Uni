/*

Creamos un fichero para repasar la creacion de clases
Dicho esto vamos a volver a crear la clase dados

------------------------------------------------------

                REPASO EXAMEN POO

------------------------------------------------------

En el fichero .h se guarda la declaracion de la clase

*/

//dados.h
//representa el lanzamiento de dos dados

#ifndef DADOS_H
#define DADOS_H

class Dados{

    private:        //en la part privada declaramos las variables que vayamos a usar por la misma clase
        int d1_;    //cuando declaramos un elemento que queremos que sea privado se le añade _ en el ultimo caracter
        int d2_;

    public:         //en la parte publica declaramos las funciones que permite usar dicha clase

        Dados();    //El constructor de la clase en este caso no devolvería nada.
                    //En caso de que heredara alguna clase, si habría que inicializarlo

        int getDado1();              //retorna el valor del dado1 
        int getDado2();              //retorna el valor del dado2
        void lanzamiento();          //asigna valores a los dados
        bool setDado1(int numero);   //asigna valor al dado1
        bool setDado2(int numero);   //asigna valor al dado2
        int getSuma();               //retorna la suma de los dados
};

#endif