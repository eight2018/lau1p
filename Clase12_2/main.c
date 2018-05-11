#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "pantalla.h"
#include "utn.h"
#include "Contratacion.h"
#include "informar.h"

#define QTY 10
#define LEN_CONT    1000
int menuDeOpciones(void);
int main()
{
    Pantalla array[QTY];
    Contratacion contrataciones[LEN_CONT];
    int menu;
    int auxiliarId;
    int auxiliarIdbaja;
    pantalla_init(array,QTY);
    cont_init(contrataciones,LEN_CONT);

    /*pantalla_altaForzada(array,QTY,"Martin","Las Flores 50",50,0);
    pantalla_altaForzada(array,QTY,"Juan","Belgrano 250",2000,0);
    pantalla_altaForzada(array,QTY,"Miguel","Cerrito 300",3000,0);
    pantalla_altaForzada(array,QTY,"Lorena","Lavalle 450",1000,1);
    pantalla_altaForzada(array,QTY,"Zaira","Mitre 150",5000,1);

    cont_altaForzada(contrataciones,LEN_CONT,array,QTY,0,"video.avi","10911911915",100);
    cont_altaForzada(contrataciones,LEN_CONT,array,QTY,0,"video1.avi","20911911915",400);
    cont_altaForzada(contrataciones,LEN_CONT,array,QTY,0,"video2.avi","30911911915",300);
    cont_altaForzada(contrataciones,LEN_CONT,array,QTY,2,"video3.avi","50911911915",400);
    cont_altaForzada(contrataciones,LEN_CONT,array,QTY,2,"video4.avi","60911911915",500);
    cont_altaForzada(contrataciones,LEN_CONT,array,QTY,2,"video5.avi","40911911915",600);
*/
    informar_ListarCantidadContratacionesImporte(contrataciones,LEN_CONT,array,QTY);
    do
    {
       menu=menuDeOpciones();
        switch(menu)
        {
            case 1://Alta de pantalla
                pantalla_alta(array,QTY);
                break;
            case 2://Modificar datos de pantalla
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                pantalla_modificacion(array,QTY,auxiliarId);
                break;
            case 3://Baja de pantalla
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                pantalla_baja(array,QTY,auxiliarId);
                break;
            case 4://Contratar una publicidad
                cont_alta(contrataciones,LEN_CONT,array,QTY);
                break;
            case 5://Modificar condiciones de publicación
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                cont_modificacion(contrataciones,LEN_CONT,&auxiliarId);
                break;
            case 6://Cancelar contratación
                getValidInt("ID?","\nNumero valida\n",&auxiliarIdbaja,0,200,2);
                    cont_baja(contrataciones,LEN_CONT,&auxiliarIdbaja);
                break;
            case 7://Consulta facturación
                informar_ConsultaFacturacion(contrataciones,LEN_CONT,array,QTY,"20911911915");

                break;
            case 8://Listar contrataciones
                cont_mostrar(contrataciones,LEN_CONT);
                //pantalla_ordenar(array,QTY, 1);
                //informar_ListarContrataciones(contrataciones,LEN_CONT,array,QTY);
                break;
            case 9://Listar​ ​pantallas
                pantalla_mostrar(array,QTY);
                break;
            case 10://Informar
                break;
            case 11://Salir
                break;
        }

    }while(menu != 11);

    return 0;
}
int menuDeOpciones(void)
{
    int menu;
   printf("\n1-Alta de cliente.\n");
   printf("2-Modificar datos de cliente.\n");
   printf("3-Baja de cliente.\n");
   printf("4-Contratar una publicidad.\n");
   printf("5-Modificar condiciones de publicacion.\n");
   //printf("6-Cancelar contratacion.\n");
   //printf("7-Consulta facturacion.\n");
   printf("8-Listar contrataciones.\n");
   printf("9-Listar pantallas.\n");
  // printf("10-Informar.\n");
   getValidInt("11-salir.","la opcion no exite",&menu,1,11,2);
   return menu;

}
