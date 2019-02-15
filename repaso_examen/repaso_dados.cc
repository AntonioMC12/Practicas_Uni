/*

Creamos un fichero para repasar la creacion de clases
Dicho esto vamos a volver a crear la clase dados

------------------------------------------------------

                REPASO EXAMEN POO

------------------------------------------------------

En el fichero .cc se guarda el cuerpo de la clase

*/


#include <ctime>
#include <cstdlib>
#include <repaso_dados.h>

int main(){

    Dados::Dados(){

        //inicializamos el constructor 

        srand(time(NULL));
        d1_ = 1;
        d2_ = 1;
    }

    int Dados::getDado1(){

        return d1_;
    }

    int Dados::getDado2(){

        return d2_;
    }

    void Dados::lanzamiento(){

        d1_ = (rand()6+1);
        d2_ = (rand()6+1);
    }

    bool setDado1(int numero){

        if (0 > numero && numero < 7) {
            d1_ = numero;
            return true;
        }
        else{
            return false;
        }
    }

    bool setDado2(int numero){

        if (0 > numero && numero < 7) {
            d2_ = numero;
            return true;
        }
        else{
            return false;
        }
    }

    int getSuma(){

        return (d1_+d2_);
    }
}
