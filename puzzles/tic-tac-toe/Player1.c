#include <stdio.h>
#include "Player1.h"

int pegaJogada1(char jogo[4][4]){

    int i,j;
    printf("===Jogador 1, insira sua jogada: [linha/coluna] ===\n");
    scanf("%d",&i);
    scanf("%d",&j);
    i--;
    j--;
    if(jogo[i][j]!='O' && jogo[i][j]!='X'){
        jogo[i][j]='X';
        return 1;
        }
    else
        return 0;
}

int verificaFim(char jogo[4][4]){
    int cont=0;
    int i;
    int j;
    int fimJogo1=0;
    int fimJogo2=0;

    for(i=0; i < 3; i++){
        for(j=0; j < 3; j++){
            if(jogo[i][j]=='X')
                fimJogo1++;
            if(jogo[i][j]=='O')
                fimJogo2++;
        }
        if(fimJogo1==3)
            return 1;
        if(fimJogo2==3)
            return 2;

        fimJogo1=0;
        fimJogo2=0;
    }
    for(j=0; j < 3; j++){
        for(i=0; i < 3; i++){
            if(jogo[i][j]=='X')
                fimJogo1++;
            if(jogo[i][j]=='O')
                fimJogo2++;
        }
        if(fimJogo1==3)
            return 1;
        if(fimJogo2==3)
            return 2;

        fimJogo1=0;
        fimJogo2=0;
    }
    if(jogo[0][0]==jogo[1][1] && jogo[1][1]==jogo[2][2]){ /// verifica diagonal primaria
        if(jogo[0][0]=='X')
            return 1;             /// verifica quem venceu
        if(jogo[0][0]=='O')
            return 2;
        }
    if(jogo[0][2]==jogo[1][1] && jogo[1][1]==jogo[2][0]){ /// verifica diagonal secundaria
        if(jogo[0][2]=='X')
            return 1;           /// verifica quem venceu
        if(jogo[0][2]=='O')
            return 2;
        }
    for(i=0; i < 3; i++)
        for(j = 0; j < 3; j++)
            if(jogo[i][j]=='X' || jogo[i][j]=='O')  /// verifica se deu velha
                cont++;
    if(cont==9)
        return 3;
    return 0;                   /// caso ninguém tenha vencido, a funçao retorna 0
}

void imprimeVencedor(char jogo[4][4]){
    system("cls");
    imprimeJogo(jogo);
    int quemVenceu = verificaFim(jogo);
    if(quemVenceu==1)
        printf("\n===***Parabens, o JOGADOR 1 foi o VENCEDOR***===");
    if(quemVenceu==2)
        printf("\n===***O computador foi o VENCEDOR, seu noob***===");
    if(quemVenceu==3)
        printf("\n===***NOOB, o jogo deu VELHA***===");
}
void imprimeJogo(char jogo[4][4]){
    int i,j;
    for (i=0; i < 3; i++){
            for(j=0; j < 3; j++){
                printf("  %c  |   ",jogo[i][j]);
            }
            printf("\n");
        }
}

