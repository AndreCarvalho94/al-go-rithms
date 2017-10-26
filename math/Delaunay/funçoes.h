
#define maxPoints 100
#define FLT_MAX   3.402823466E+38F
#define maxT 30




typedef struct _ponto_{

    float x;
    float y;
    int posicao;

}ponto;



typedef struct _triangulo_{
    ponto v1;
    ponto v2;
    ponto v3;
    float area;
    int triValido;
    struct _triangulo_ *next;
}triangulo;



typedef struct _circunferencia_{
    ponto centro;
    float raio;
    }circunferencia;


typedef struct _eqReta_{
    float m;
    float c;
    int valida;
}eq_Reta;



void insereTri(triangulo novo, triangulo *cab);

void imprimeTri(triangulo *cab);

void imprimeTri2(triangulo *cab, float N);

triangulo calculaArea(triangulo t1);

int delaunay(triangulo t1,ponto nuvem[], int tamanho);

float calcDist (ponto p1, ponto p2);

eq_Reta retaPerpend(ponto p1, ponto p2);    ///dados 2 pontos, calcula a reta perpendicular a reta formada por eles

circunferencia calculaCirc(ponto p1, ponto p2, ponto p3); ///   retorna a circunferencia formada pelos 3 pontos dados

int invalidaInterno(triangulo t1, ponto nuvem[],int tamanho);



bool inicializar();

