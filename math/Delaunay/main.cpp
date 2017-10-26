#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include <stdio.h>
#include <stdbool.h>
#include "grafico.h"
#include "funçoes.h"


int main()
{



        if (!inicializar())
    {
        return -1;
    }


srand(time(NULL));


ponto nuvem[maxPoints];
    int Tamanho=maxPoints;
    int i,j,k;

    float area;

    int op;

        triangulo atual;
        triangulo *cab =(triangulo *)malloc(sizeof(triangulo));
        triangulo *aux;
        aux=cab->next;


    printf("\nOBS: PARA GERCAO GRAFICA DA MALHA OS VALORES DE X VARIAM ENTRE 0 - 640\n E OS DE Y VARIAM 0 - 480 \n\nNAO ENTRE COM PONTOS REPETIDOS E TENHA PREFERENCIA POR NUMEROS ALTOS\n\n");





    printf("Para inserir os pontos digite 1, para gerar 100 numeros aleatorios digite 2: ");
    scanf("%d", &op);

    if(op==1){
        printf("\nDigite a quantidade de pontos a serem inseridos: ");
        scanf("%d", &Tamanho);
        printf("\nDigite os pontos (x,y) e press enter:\n ");
        for(i=0;i<Tamanho;i++){
            scanf("%f %f",&nuvem[i].x,&nuvem[i].y);
        }
    }

    if(op==2){
        for(i=0;i<maxPoints;i++){
            nuvem[i].x=rand()%640;
            nuvem[i].y=rand()%480;
        }
    }


    for(i=0;i<Tamanho-2;i++)
        for(j=i+1;j<Tamanho-1;j++)
            for (k=j+1;k<Tamanho;k++){
                atual.v1=nuvem[i];
                atual.v2=nuvem[j];
                atual.v3=nuvem[k];

                atual=calculaArea(atual);
                if(atual.triValido){
                    atual.triValido=delaunay(atual,nuvem,Tamanho);
                   /// if(atual.triValido)
                      ///  atual.triValido=invalidaInterno(atual,nuvem,Tamanho);
                }
            if(atual.triValido)
                insereTri(atual,cab);
            }

    printf("\nDigite a area minima dos triangulos a serem listados: ");
    scanf("%f",&area);
    imprimeTri2(cab,area);

    printf("\n\nSe desejar listar todos os triangulos digite 1: ");
    scanf("%d",&op);
    if(op==1)
            imprimeTri(cab);



    printf("\n\n\n\n**********Aguarde Enquanto os Triangulos sao Gerados**************");

    for(aux=cab->next; aux!=NULL; aux = aux->next){

        al_draw_triangle(aux->v1.x,aux->v1.y,
                         aux->v2.x,aux->v2.y,
                         aux->v3.x,aux->v3.y,
                          al_map_rgb(255, 255, 255), 1.0);

                          al_flip_display();
                          al_rest(0.3);
    }
    al_rest(15);



    return 0;
}

