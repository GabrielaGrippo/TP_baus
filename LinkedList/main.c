#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"LinkedList.h"
/*typedef struct{
int id;
char nombre[20];
char sexo;
int edad;
}eMascota;
void mostrarMascota(eMascota* m);
void mostrarMascotas(LinkedList* list);
int filterHembras(void* pElement);
int filterCachorros(void*pElement);
int filterBunny(void* pElement);*/

typedef struct{
int id;
char nombre[20];
char sexo;
int edad;
}eCliente;

void mostrarCliente(eCliente* c);
void mostrarClientes(LinkedList* list);
int ordenarClientes(void* cliente1, void* cliente2);
int main()
{
    //ll_newLinkedList
   LinkedList* Lista = ll_newLinkedList();

   /*eMascota m1 ={1234,"Bobby",'m',2};
   eMascota m2 ={3322,"Pepe",'m',5};
   eMascota m3 ={6543,"Lola",'h',1};
   eMascota m4 ={1111,"Bunny",'h',7};
   eMascota m5 ={9891,"Susy",'h',2};
   eMascota m6 ={2310,"Lolo",'m',1};*/

        eCliente cliente1= {1, "Gabriela", 'f',27};
        eCliente cliente2= {2, "Nahuel", 'm',30};
        eCliente cliente3= {3, "Sebastian", 'm',19};
        eCliente cliente4= {4, "Lautaro", 'm',16};
	    eCliente cliente5= {5, "Carolina", 'f',45};
	    eCliente cliente6= {6, "Fabian", 'm',47};

        eCliente* clienteEliminado;
        eCliente* auxCliente;
/*
   ll_add(Lista,&m1);
   ll_add(Lista,&m2);
   ll_add(Lista,&m3);
   ll_add(Lista,&m4);
   ll_add(Lista,&m5);
   ll_add(Lista,&m6);*/

   //ll_add
    ll_add(Lista,&cliente1);
   ll_add(Lista,&cliente2);
   ll_add(Lista,&cliente3);
   ll_add(Lista,&cliente4);
   ll_add(Lista,&cliente5);
   int tam=ll_len(Lista);
   int indice;
  /* mostrarMascotas(Lista);
   LinkedList* hembras=ll_filter(Lista,filterHembras);
     mostrarMascotas(hembras);
      LinkedList* cachorros=ll_filter(Lista,filterCachorros);
      mostrarMascotas(cachorros);
       LinkedList* bunnies=ll_filter(Lista,filterBunny);
    mostrarMascotas(bunnies);*/

    //ll_isEmpty
    if(ll_isEmpty(Lista))
	    {
	        printf("La lista esta vacia");
	    }
	    else
	    {
        printf("*.Muestro el listado de clientes:\n\n");
        mostrarClientes(Lista);
	    }
	    printf("*.Muestro el tamano de la lista : %d\n\n",tam);

	     printf("*.Ordeno los clientes alfabeticamente de forma ascendente:\n\n");
	       //ll_sort
	        ll_sort(Lista, ordenarClientes,1);
	        mostrarClientes(Lista);

	  printf("*.Copio la lista de clientes en una lista nueva:\n\n");
	       //ll_clone
	        LinkedList* nuevaLista = ll_clone(Lista);
	        //ll_containsAll
	        if(ll_containsAll(nuevaLista,Lista))
	        {
	          printf("La lista se copio correctamente. Nueva lista:\n");
	          mostrarClientes(nuevaLista);
	          printf("\n\n");
	        }
	        else
	        {
	            printf("La lista no se copio correctamente\n");
	            printf("\n");
	        }

            printf("*.Elimino un cliente de la lista: \n\n");
	      //ll_remove
	        ll_remove(Lista,1);
	         printf("Lista sin el cliente eliminado:\n\n");
	        mostrarClientes(Lista);

	          printf("*.Elimino a otro cliente y muestro a quien elimine:\n");
	       //ll_pop
	        clienteEliminado=ll_pop(Lista, 2);
	        mostrarCliente(clienteEliminado);
	        printf("\n");




	         printf("*.Piso los datos de un cliente con los datos de otro cliente : \n\n");
	        //ll_set
	        ll_set(Lista,2, &cliente3);
	        mostrarClientes(Lista);

	        //ll_get
        printf("*.ll_get se usa dentro de la funcion mostrarClientes para tomar cada elemento\n\n");


	         printf("*.Agrego un Cliente entre los indices 2 y 3 en la primera lista:\n\n");
	        //ll_push
	        ll_push(Lista,2,&cliente6);
	        mostrarClientes(Lista);

            printf("*.Busco un cliente en la lista,ejemplo cliente numero 6 \n\n");
	        //ll_contains
	        if(ll_contains(Lista, &cliente6)){
                printf("Si Esta.\n");
                mostrarCliente(&cliente6);
	        }
	        else{
                printf("Este cliente no esta");
	        }
     //ll_sublist
    LinkedList* sublista = ll_subList(Lista,2,4);

    printf("*.Creo una sublista solo con los elementos entre los indices 2 y 4\n");

    mostrarClientes(sublista);

    printf("*.Elimino a todos los clientes de la lista clonada:\n");
	      //ll_clear
	        ll_clear(nuevaLista);
	         printf("Muestro la lista clonada vacia:\n\n");
	        mostrarClientes(nuevaLista);

	        printf("Elimino la lista clonada\n");
	        //ll_DeleteLinkedList
	        if(ll_deleteLinkedList(nuevaLista))
	       {
	            printf("Lista eliminada correctamente\n\n");
	        }
        else{
            printf("No se pudo eliminar\n");
        }



    auxCliente = &cliente4;
    //ll_indexOf
    indice =  ll_indexOf(Lista,auxCliente);

     printf("*.Indice donde esta ubicado un elemento en la lista\n\n");
    printf("El indice donde esta Lautaro es el indice: %d \n \n", indice);

    mostrarClientes(Lista);



    return 0;
}

/*void mostrarMascota(eMascota* m)
{
    if(m != NULL){
    printf("%d %s %c %d \n",m->id
           ,m ->nombre
           ,m ->sexo
          , m ->edad);
    }

}*/
void mostrarCliente(eCliente* c){
if(c!=NULL){
    printf("%d  %s  %c %d \n"
           ,c->id
           ,c->nombre
           ,c->sexo
           ,c->edad);
}

}


/*void mostrarMascotas(LinkedList* list){
int tam;
if(list !=NULL){
        tam=ll_len(list);
printf("Id Nombre Sexo Edad");
for(int i=0;i <tam;i++){
    mostrarMascota((eMascota*) ll_get(list,i));

}
printf("\n\n");
}

}*/

void mostrarClientes(LinkedList* list){
int tam;
if(list !=NULL){
    tam=ll_len(list);
    printf("Id Nombre Sexo Edad\n");
    for(int i =0;i<tam;i++){
        mostrarCliente((eCliente*)ll_get(list,i));
    }
}
printf("\n\n");
}
/*int filterHembras(void* pElement){

return((eMascota*)pElement)->sexo=='h';

}
int filterCachorros(void*pElement){
return((eMascota*)pElement)->edad< 2;
}
int filterBunny(void* pElement){
    int retorno=0;
   if( strcmp(((eMascota*)pElement)->nombre,"Bunny")){
    retorno=1;
   }

}*/
int ordenarClientes(void* cliente1, void* cliente2)
{
    eCliente* cli1;
    eCliente* cli2;
    int retorno=-2;


    cli1 = (eCliente*)cliente1;
    cli2 = (eCliente*)cliente2;


    if(cli1 != NULL && cli2 != NULL)
    {

        retorno = strcmp(cli1->nombre, cli2->nombre);

    }

    return retorno;
}
