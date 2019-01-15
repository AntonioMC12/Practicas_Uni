#include <iostream>
#include <array>
#include <string>

using namespace std;

const int MAX_INGREDIENTES_PIZZA = 10;
const int MAX_PEDIDOS = 20;

typedef array <int, MAX_INGREDIENTES_PIZZA> Ingredientes_solicitados;
typedef array <string, MAX_INGREDIENTES_PIZZA> ING;
const ING INGREDIENTES = {{"tomate", "queso", "nata", "cebolla", "pollo", "huevo", "salami", "anchoa", "bacon", "gamba"}};


struct Pedido {

    string nombre;
    string telefono;
    int codigo_pedido/*numero de cada pedido*/;
    int numero_ingredientes/*numero total de ingredientes que solicitan*/;
    Ingredientes_solicitados ingredientes;

};

typedef array <Pedido, MAX_PEDIDOS> Lista;


struct Pizzeria {

    int codigo_pedidos  /*aumenta con pedido insertado*/;
    int numero_pedidos  /*numero de pedidios almacenado en lista_pedidos*/;
    Lista lista_pedidos;

};

void inicializar_datos (Pizzeria& p)
{
    p.numero_pedidos = 0;
    p.codigo_pedidos = 1;
}

void leer_ingrediente (int& ing)
{
    string ingrediente;
    cout <<"\nIntroduce el ingrediente que quieres agregar a la pizza: ";
    cin >> ingrediente;
    ing = 0;

    while (ingrediente != INGREDIENTES [ing])
        {ing++;
        if(ing > int (INGREDIENTES.size()))
            {cout << "Introduce un ingrediente valido por favor: ";
            cin >> ingrediente;
            ing=0;}
        }
}

void escribir_ingrediente (int ing)
{
    cout << INGREDIENTES[ing] << ' ';
}

void leer_pedido (Pedido& ped, bool& ok)
{
    cout << "Su numero de pedido es: "<< ped.codigo_pedido<< endl;
    ped.codigo_pedido++;

    cout << "Introduce su nombre: ";
    getline(cin, ped.nombre);

    cout << "Introduce su numero de telefono: ";
    cin >> ped.telefono;
    while (ped.telefono.size()!=9)
    {
        cout << "El numero de telefono no es correcto, introduce un numero adecuado: ";
        cin >> ped.telefono;
    }

    cout << "Introduce el numero de ingredientes: ";
    cin >> ped.numero_ingredientes;
    while(ped.numero_ingredientes >MAX_INGREDIENTES_PIZZA)
        {
            ok = false;
            cout << "Introduce el numero de ingredientes valido: ";
            cin >> ped.numero_ingredientes;
        }
        if (ped.numero_ingredientes <= MAX_INGREDIENTES_PIZZA)
            {
            ok = true;
            for(int i=0; i<ped.numero_ingredientes;i++)
            leer_ingrediente(ped.ingredientes[i]);
            }

}

void insertar_pedido (Pizzeria& p, const Pedido& ped, bool& ok)
{
    if (p.numero_pedidos < MAX_PEDIDOS)
    {
        p.lista_pedidos[p.numero_pedidos] = ped;
        p.numero_pedidos++;
        p.lista_pedidos[p.numero_pedidos].codigo_pedido = p.codigo_pedidos;
        p.codigo_pedidos++;
        ok = true;
    } else
        ok=false;
}

void escribir_pedido(const Pedido& ped)
{
    cout << ped.nombre << ' ' << ped.telefono << ' ' << ped.codigo_pedido << ' ' << ped.numero_ingredientes << ' ';
    escribir_ingrediente(ped.numero_ingredientes);
}

void escribir_pedidos(const Pizzeria& p)
{
    cout << p.codigo_pedidos << endl;
    cout << p.numero_pedidos << endl;
    for (int i = 0; i < p.numero_pedidos; i++)
        escribir_pedido(p.lista_pedidos[i]);

    for (int j= 0; j <= (INGREDIENTES.size()-1); j++)
        escribir_ingrediente(j);
}

void eliminar_pedido(Pizzeria& p, int cod_pedido, bool& ok)
{
    int i = 0;
    while ((i<p.numero_pedidos) && (cod_pedido!=p.lista_pedidos[i].codigo_pedido)){
        i++;
    }
    if(i >= p.numero_pedidos)
    {
        ok = false;
    } else{
        for (int j = i; j < p.lista_pedidos.size()-1; j++)
        {
            p.lista_pedidos[j] = p.lista_pedidos[j+1];
        }
        ok = true;
        p.numero_pedidos--;
    }
}

int buscar_pedido (const Pizzeria& p, const string& nombre)
{
    int i = -1;
    int j = 0;
    while ((j<p.numero_pedidos) && (nombre!=p.lista_pedidos[j].nombre)){
        j++;
        }
    if (j>=p.numero_pedidos)
    {
        return i;
    }else {
        i = j;
        return i;
    }
}




int main ()
{
    Pedido p;
    bool ok;
    leer_pedido(p, ok);
    cout << p.nombre << ' ' << ok;
}










