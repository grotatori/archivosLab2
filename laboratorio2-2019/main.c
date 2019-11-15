#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define COMESTIBLE "Comestible"
#define MADERA "Madera"
#define METAL "Metal"
#define PLASTICO "Plastico"
#define VIDRIO "Vidrio"

#define ARCHIVOCAJON "cajones.bin"
#define ARCHIVOPEDIDO "pedidos.bin"

#define BALCARCE "Balcarce"
#define TANDIL "Tandil"
#define MIRAMAR "Miramar"
#define PINAMAR "Pinamar"
#define NECOCHEA "Necochea"

typedef struct{
    char categoria[20];
    float peso;
}Cajon;

typedef struct{
    char ciudad[20];
    char categoria[20];
    float cantidad; //kilos
}Pedido;

void cargarArchivoCajon(){
    FILE * archi = fopen(ARCHIVOCAJON, "ab");
    char control = 's';
    printf("CAJONES:\n\n");
    while(control == 's'){
        Cajon aux;
        int cat;
        printf("Cate: ");
        fflush(stdin);
        scanf("%d", &cat);
        switch(cat){
            case 1:
                strcpy(aux.categoria, COMESTIBLE);
                break;
            case 2:
                strcpy(aux.categoria, MADERA);
                break;
            case 3:
                strcpy(aux.categoria, METAL);
                break;
            case 4:
                strcpy(aux.categoria, PLASTICO);
                break;
            case 5:
                strcpy(aux.categoria, VIDRIO);
                break;
        }

        printf("Peso: ");
        fflush(stdin);
        scanf("%f", &aux.peso);

        fwrite(&aux, sizeof(Cajon), 1, archi);

        printf("Otro? "); fflush(stdin); control = getch(); printf("\n");
    }
    fclose(archi);
}

void cargarArchivoPedido(){
    FILE * archi = fopen(ARCHIVOPEDIDO, "ab");
    char control = 's';
    printf("PEDIDOS:\n\n");
    while(control == 's'){
        Pedido aux;
        int cat, ciud;

        printf("Cate:");
        fflush(stdin);
        scanf("%d", &cat);
        switch(cat){
            case 1:
                strcpy(aux.categoria, COMESTIBLE);
                break;
            case 2:
                strcpy(aux.categoria, MADERA);
                break;
            case 3:
                strcpy(aux.categoria, METAL);
                break;
            case 4:
                strcpy(aux.categoria, PLASTICO);
                break;
            case 5:
                strcpy(aux.categoria, VIDRIO);
                break;
        }

        printf("Ciudad: "); fflush(stdin); scanf("%d", &ciud);
        switch(cat){
            case 1:
                strcpy(aux.ciudad, BALCARCE);
                break;
            case 2:
                strcpy(aux.ciudad, TANDIL);
                break;
            case 3:
                strcpy(aux.ciudad, MIRAMAR);
                break;
            case 4:
                strcpy(aux.ciudad, PINAMAR);
                break;
            case 5:
                strcpy(aux.ciudad, NECOCHEA);
                break;
        }
        printf("Cantidad: "); fflush(stdin); scanf("%f", &aux.cantidad);

        fwrite(&aux, sizeof(Pedido), 1, archi);

        printf("Otro? "); fflush(stdin); control = getch(); printf("\n");
    }
    fclose(archi);
}

void mostrarArchivoCajon(){
    FILE * archi = fopen(ARCHIVOCAJON, "rb");
    Cajon aux;
    printf("CAJONES:\n\n");
    while(fread(&aux, sizeof(Cajon), 1, archi) > 0){
        printf("Categoria: %s\n", aux.categoria);
        printf("Peso: %.2f\n\n", aux.peso);
    }
    fclose(archi);
}

void mostrarArchivoPedido(){
    FILE * archi = fopen(ARCHIVOPEDIDO, "rb");
    Pedido aux;
    printf("PEDIDOS:\n\n");
    while(fread(&aux, sizeof(Pedido), 1, archi)>0){
        printf("Categoria: %s\n", aux.categoria);
        printf("Ciudad: %s\n", aux.ciudad);
        printf("Cantidad (kg): %.2f\n\n", aux.cantidad);
    }
    fclose(archi);
}
int main()
{
    cargarArchivoCajon();
    cargarArchivoPedido();
    system("cls");
    mostrarArchivoCajon();
    mostrarArchivoPedido();
    return 0;
}
