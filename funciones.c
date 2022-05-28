#include <stdio.h>
#include <stdlib.h>

//archivos a llamar
#include "registro.h"

int menu(){
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
        system ("pause");
        break;

    case 2:
        printf("Ver productos\n");
        verProducto();
        system ("pause");
        break;
    
    default:
        break;
    }
    return op;
}

void registrarProducto(){
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

void verProducto(){
    
    FILE *datos;
    registro reg;
    datos = fopen("datos.bin", "r");
    if(datos == NULL) {
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
   
void registrarEntrada(){
    //esto se trata de que se llama la id y se retira cierta cantidad del producto por su precio
}

void registrarSalida(){
    //esto se trata que cuando retiras un producto con la id de registroEntrada, se ven los cambios reflejados.
}