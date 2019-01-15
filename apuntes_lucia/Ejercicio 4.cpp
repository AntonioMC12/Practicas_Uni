#include <iostream>
#include <string>
using namespace std;

void leer_string (string& cadena)
{
    cout << "Introduce una cadena de caracteres: " << endl;
    cin >> cadena;
}

string extraer_consonantes(const string& cadena, string& nueva){

  int i, j = 0;

  for (i = 0 ; i <= cadena.size() ; i++){

    if( cadena[i] != 'a' && cadena[i] != 'e' && cadena[i] != 'i' && cadena[i] != 'o' && cadena[i] != 'u'){

      nueva[j] = cadena[i];
      j++;

    }
  }
  return nueva;
}


int main ()
{
    string cadena, nueva;

    leer_string(cadena);

    std::cout << "La nueva cadena es: " << extraer_consonantes(cadena, nueva) <<'\n';

    return 0;
}
