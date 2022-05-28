#include <stdio.h>
#include <stdlib.h>

// archivos a llamar
#include "registro.h"

void MostrarListado();
int menu();
void registrarProducto();
void verProducto();
void registrarEntrada();
float sumarEntrada(float existActual, float entrada);

int menu()
{
    int op;
    system("cls");
    printf("\t---------- M E N U ---------- \n");
    printf(" 1. Registrar Producto \n ");
    printf("2. Ver Producto \n ");
    printf("3. Registrar Entradas \n ");
    printf("4. Registrar Salidas \n ");
    printf("5. Salir \n");
    printf("Opcion: ");
    scanf("%i", &op);
    switch (op)
    {
    case 1:
        printf("Bienvenido al Registro de productos\n");
        registrarProducto();
        system("pause");
        break;

    case 2:
        printf("Ver productos\n");
        MostrarListado();
        system("pause");
        break;

    case 3:
        printf("Registrar entrada\n");
        registrarEntrada();
        break;
    default:
        break;
    }
    return op;
}

void registrarProducto()
{
    registro reg;
    system("cls");
    printf("Digite los datos de su Producto \n");

    printf("id: ");
    scanf("%i", &reg.id);

    printf("NombreProducto: ");
    scanf(" %[^\n]", reg.nombreProd);

    printf("Descripcion: ");
    scanf(" %[^\n]", reg.descripcion);

    printf("Precio: C$");
    scanf("%f", &reg.precio);

    printf("Existencia: ");
    scanf("%f", &reg.existencia);

    FILE *datos;
    datos = fopen("datos.bin", "a");
    fwrite(&reg, sizeof(registro), 1, datos);
    fclose(datos);
}

void verProducto()
{

    FILE *datos;
    registro reg;
    datos = fopen("datos.bin", "r");
    if (datos == NULL)
    {
        printf("Archivo vacío...\n");
        return 0;
    }
    while (feof(datos) == 0)
    {
        fread(&reg, sizeof(registro), 1, datos);
        printf("id: %i\n", reg.id);
        printf("nombre Producto: %s. \n ", reg.nombreProd);
        printf("Descripcion: %s. \n ", reg.descripcion);
        printf("Precio: C$: %.2f \n", reg.precio);
        printf("Existencia: %.2f \n", reg.existencia);
    }
    fclose(datos);
}

void registrarEntrada()
{
    registro productos[100];
    int id;
    float cant;
    printf("Digita el Codigo del producto: ");
    scanf("%i", &id);

    FILE *file = fopen("datos.bin", "r");

    int i = 0;
    while (feof(file) == 0)
    {
        fread(&productos[i], sizeof(registro), 1, file);
        i++;
    }
    fclose(file);

    for (int cont = 0; cont < i; cont++)
    {
        if (id == productos[cont].id)
        {
            printf("Dime la cantidad de entrada: ");
            scanf("%f", &cant);
            productos[cont].existencia = sumarEntrada(productos[cont].existencia, cant);
            break;
        }
    }

    file = fopen("datos.bin", "w");
    for (int cont = 0; cont < i; cont++)
    {
        fwrite(&productos[cont], sizeof(registro), 1, file);
    }
    fclose(file);
}

float sumarEntrada(float existActual, float entrada)
{
    // esto se trata de que se llama la id y se retira cierta cantidad del producto por su precio
    return existActual + entrada;
}

void registrarSalida()
{
    // esto se trata que cuando retiras un producto con la id de registroEntrada, se ven los cambios reflejados.
}

void MostrarListado()
{
    registro productos[100];
    FILE *file = fopen("datos.bin", "r");

    int i = 0;
    while (feof(file) == 0)
    {
        fread(&productos[i], sizeof(registro), 1, file);
        i++;
    }
    fclose(file);

    for (int cont = 0; cont < i; cont++)
    {
        printf("Codigo: %i\n", productos[cont].id);
        printf("Titulo: %s \n", productos[cont].nombreProd);
        printf("Existencia: %.2f\n", productos[cont].existencia);
    }
}