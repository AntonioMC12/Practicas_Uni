//guess.cc
//A program that generate a random number and the user introduce can predict the number generated


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){

//A simple resume of the program for the user
cout<<"El programa genera un numero aleatorio y tu puedes adivinarlo introduciendo un numero"<<endl;

//we generate a random number
srand(time(NULL));
int randNUM = (rand()%11);

//we create a number that the user introduce

int userNUM;
cout<<"introduce un numero"<<endl;
cin>>userNUM;

//we use a loop to know if the number is bigger or not than the rand number
  while (userNUM != randNUM) {
      if (userNUM < randNUM) {
        cout<<"El numero introducido es menor"<<endl;
        cout<<"introduce un nuevo numero"<<endl;
        cin>>userNUM;
      }
      if (userNUM > randNUM) {
        cout<<"El numero introducido es mayor"<<endl;
        cout<<"introduce un nuevo numero"<<endl;
        cin>>userNUM;
      }
  }
  //cuando sale del while, ya es el numero correcto
    cout<<"El numero introducido es el correcto"<<endl;

}
