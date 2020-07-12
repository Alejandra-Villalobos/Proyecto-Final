#include "iostream"
using namespace std;

const int longCad = 20;

struct costoPorArticulo
{
char nombreArticul[longCad + 1];
int cantidad;
float precio;
float costoPorArticulo;
};

void Leer (costoPorArticulo *, int);
void Calcular (costoPorArticulo *, int);
void Mostrar (costoPorArticulo *, int);
void TotalCompra (costoPorArticulo *, int, float *);

int main()
{
    int n;
    float Total;
    cout << "Ingrese la cantidad de articulos a incluir: "; 
    cin >> n;   
    costoPorArticulo * articulos = new costoPorArticulo[n]; //Se declara el arreglo 
    Leer (articulos, n);
    Calcular (articulos, n);
    Mostrar (articulos, n);
    TotalCompra (articulos, n, &Total);
    cout << "\t" << "Total de la compra: $" << Total << endl; //Despliega el total de la compra
}   

void Leer (costoPorArticulo * datos , int n) //Sirve para introducir los datos de cada artículo
{
    for (int i=0; i<n; i++)
    {
        cout << "Nombre del articulo " << i+1 << " (que no exceda de 6 letras): "; //Si el nombre del artículo es muy grande, el formato de la factura se desconfigura
        cin >> (datos+i)->nombreArticul; //Guarda el nombre del artículo "i" en el campo "nombreArticul"
        cout << "Cantidad: "; 
        cin >> (datos+i)->cantidad; //Guarda la cantidad del artículos "i" en el campo "cantidad"
        cout << "Precio unitario: $";
        cin >> (datos+i)->precio; //Guarda el precio del artículo "i" en el campo "precio"
    }
}

void Calcular (costoPorArticulo * datos , int n) //Calcula el costo total de cada artículo
{
    for (int i=0; i<n; i++)
        (datos+i)->costoPorArticulo=((datos+i)->cantidad*(datos+i)->precio); //Multiplica el precio por la cantidad y lo guarda en el campo "costoPorArticulo"
}

void Mostrar (costoPorArticulo * datos , int n) //Muestra cada producto con su respectiva cantidad, precio unitario y total en formato de factura 
{

    cout << endl << "\t" << "\t" << "\t" << "\t" <<  "\t" <<  "FACTURA" << endl << endl;
    cout << "\t" << "Cant." << "\t" << "Producto" << "\t" << "Precio unitario" << "\t" << "\t" << "Total por producto" << endl;
    for (int i=0; i<n; i++)
    {
        cout << "\t" << (datos+i)->cantidad << "\t" << " " << (datos+i)->nombreArticul;
        cout << "\t" << "\t" << "\t" << "$" << (datos+i)->precio;
        cout << "\t" << "\t" << "\t" << "$" << (datos+i)->costoPorArticulo << endl;
    }
    cout << "\t" << "__________________________________________________________________" << endl; //Linea divisora
}

void TotalCompra (costoPorArticulo * datos , int n, float * Total) //Realiza la suma de los precios totales para calcular el total de toda la compra 
{
    for (int i=0; i<n; i++)
        *Total+=(datos+i)->costoPorArticulo; //Almacena la suma en la variable "Total"
}