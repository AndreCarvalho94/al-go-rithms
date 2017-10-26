#include "funçoes.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>



          /// /// /// /// /// /// /// /// * Testa a Condição de Delaunay * /// /// /// /// /// /// /// /// /// ///

int delaunay(triangulo t1,ponto nuvem[],int tamanho){

    circunferencia c1;
    int valido=1;
    int i;
    float distanciaCentro;


    c1=calculaCirc(t1.v1,t1.v2,t1.v3);  ///Calcula a circunferencia a qual o triangulo é inscrito

        for(i=0;i<tamanho;i++){
            distanciaCentro=calcDist(nuvem[i],c1.centro);
            if(distanciaCentro<c1.raio)
                valido=0;
        }

    return valido;

}





            ///  ///  /// /// ///*  Calcula area de um triangulo usando determinante * /// /// /// /// ///

triangulo calculaArea(triangulo t1){

    float mat[3][5];
    float det;
    float area;
    ponto p1,p2,p3;
    triangulo aux;
    aux.v1=p1=t1.v1;
    aux.v2=p2=t1.v2;
    aux.v3=p3=t1.v3;

    mat[0][3]=mat[0][0]=p1.x;
    mat[1][3]=mat[1][0]=p2.x;
    mat[2][3]=mat[2][0]=p3.x;

    mat[0][4]=mat[0][1]=p1.y;
    mat[1][4]=mat[1][1]=p2.y;
    mat[2][4]=mat[2][1]=p3.y;

    mat[0][2]=1;
    mat[1][2]=1;
    mat[2][2]=1;

    det=(mat[0][0]*mat[1][1]*mat[2][2])
        +(mat[0][1]*mat[1][2]*mat[2][3])
        +(mat[0][2]*mat[1][3]*mat[2][4])
        -(mat[0][2]*mat[1][1]*mat[2][0])
        -(mat[0][3]*mat[1][2]*mat[2][1])
        -(mat[0][4]*mat[1][3]*mat[2][2]);




    if(det!=0){
        if(det<0)
            det=det*(-1);
        area=det/2;
        aux.area=area;
        aux.triValido=1;
    }
    else
        aux.triValido=0;

    return aux;

}


float calcDist (ponto p1, ponto p2){
    float distancia;
    distancia = sqrt((float)pow(p2.x-p1.x,2)+(float)pow(p2.y-p1.y,2));
    return distancia;
    }


            /// /// ///* Função que calcula a reta perpendicular a reta formada por 2 pontos dados * /// /// ///

eq_Reta retaPerpend(ponto p1, ponto p2){

    eq_Reta reta;  /// equaçao da reta perpendicular a reta dada
    ponto pmedio;  /// ponto medio da reta formada pelos 2 pontos dados
    float m;   /// coeficiente angular da reta formada pelos 2 pontos


        pmedio.x=(p1.x+p2.x)/2;
        pmedio.y=(p1.y+p2.y)/2;

    reta.valida=1;

    if(p2.x==p1.x){
        reta.m=0;
        reta.c=pmedio.y;
        reta.valida=1;
        return reta;
    }

    if(p2.y==p1.y){
        reta.valida=0;
        return reta;
    }


    if(reta.valida){

        m=(p2.y-p1.y)/(p2.x-p1.x);
        reta.m=-(1/m);                       ///coeficiente angular da reta perpendicular
        reta.c=pmedio.y-(reta.m*pmedio.x);  /// termo independente da equaçao da reta perpendicular
        return reta;

    }
    return reta;
}

            /// /// ///* Função que calcula o ponto e o raio da circunferencia de 3 pontos dados * /// /// ///
circunferencia calculaCirc(ponto p1, ponto p2, ponto p3){

    eq_Reta reta1;
    eq_Reta reta2;
    circunferencia bola;

    float det;
    float det1;
    float det2;


        reta1=retaPerpend(p1,p2);               ///calcula a primeira equaçao do sistema
        if(reta1.valida==0)
            reta1=retaPerpend(p1,p3);

        reta2=retaPerpend(p2,p3);               ///calcula a segunda equaçao do sistema
        if(reta2.valida==0)
            reta2=retaPerpend(p1,p3);


    det=(reta1.m*-1)-(reta2.m*-1);              ///resoluçao do sistema pelo metodo de cramer para obter coordenadas do centro
    det1=(reta1.c*-1)-(reta2.c*-1);
    det2=(reta1.m*reta2.c)-(reta1.c*reta2.m);


    bola.centro.x=(det1/det)*(-1);
    bola.centro.y=(det2/det)*(-1);
    bola.raio=calcDist(bola.centro,p1);         ///calcula o raio da circunferencia


    return bola;

}






/// /// /// /// /// /// /// /// * Função que Insere Triangulo na Lista * /// /// /// /// /// /// /// ///

void insereTri(triangulo novo, triangulo *cab){
   triangulo *Tnovo;
   Tnovo = (triangulo *)malloc( sizeof (triangulo));
   *Tnovo=novo;
   Tnovo->next = cab->next;
   cab->next = Tnovo;
}


/// /// /// /// /// /// /// * Imprime Todos os Triangulos * /// /// /// /// /// /// /// ///

void imprimeTri(triangulo *cab){
    triangulo *aux;
    int i = 1;
    for(aux=cab->next; aux!=NULL; aux = aux->next){
        printf("\n%d   º %0.2f , %0.2fº%0.2f , %0.2fº%0.2f , %0.2fº area :%0.2f",i,
        aux->v1.x,aux->v1.y,aux->v2.x,aux->v2.y,aux->v3.x,aux->v3.y,aux->area);
        i++;
        }
}

/// /// /// /// /// /// /// * Imprime Todos os Triangulos Com Area >= N * /// /// /// /// /// ///
void imprimeTri2(triangulo *cab, float N){
    triangulo *aux;
    int i=1;
    aux=cab->next;

     for(aux=aux->next; aux!=NULL; aux = aux->next){
        if(aux->area>=N){
            printf("\n%d   º %0.2f , %0.2fº%0.2f , %0.2fº%0.2f , %0.2fº area :%0.2f",i,
            aux->v1.x,aux->v1.y,aux->v2.x,aux->v2.y,aux->v3.x,aux->v3.y,aux->area);
            i++;
        }
    }
}


/// /// /// /// /// ///  * Invalida Triangulo Caso Haja mais de 4 Pontos na Circunferencia * /// /// /// /// /// ///
int invalidaInterno(triangulo t1, ponto nuvem[],int tamanho){


    int i;
    circunferencia c1;
    int cont=0;
    float distanciaCentro;


     c1=calculaCirc(t1.v1,t1.v2,t1.v3);  ///Calcula a circunferencia a qual o triangulo é inscrito

        for(i=0;i<tamanho;i++){
            distanciaCentro=calcDist(nuvem[i],c1.centro);
            if(distanciaCentro==c1.raio){ ///Verifica se algum ponto da nuvem está dentro da circunferencia formada
                cont++;
                if(cont>=4)
                    return 0;
            }
        }
    return 1;
}


