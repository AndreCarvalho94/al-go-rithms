#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "jogaPC.h"
#include "Player1.h"

int main (){

    char jogo[4][4];
    int i, j;
    int jogadaValida1=1;
    int imprimeDnovo=0;

    int gameOver=0;
    srand(time(NULL));
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            jogo[i][j]=' ';
    while(1){
        system("cls");
        PCjoga(jogo);
        gameOver=verificaFim(jogo); ///verifica o fim do jogo logo dps que o pc jogar
        imprimeJogo(jogo);
        if(gameOver){
            imprimeVencedor(jogo);
            for(i=0;i<3;i++)
                for(j=0;j<3;j++)
                    jogo[i][j]=' ';
            printf("\n|||||Siga as instrucoes abaixo para reiniciar, SEU NOOB|||||\n");
            system("Pause");
            system("cls");
            imprimeDnovo=1;
            }
        if(imprimeDnovo){
            PCjoga(jogo);
            imprimeJogo(jogo);
            imprimeDnovo=0;
        }
        jogadaValida1=pegaJogada1(jogo);
        while(!jogadaValida1){          ///caso a jogada seja invalida, pega jogada até validar
            printf("       ===Jogada invalida, tente Novamente===\n");
            jogadaValida1=pegaJogada1(jogo);
            if(jogadaValida1){
                system("cls");
                imprimeJogo(jogo);
            }
        }
        gameOver=verificaFim(jogo);     ///verifica logo após o jogador 1 jogar, verifica se o jogo termina
        if(gameOver){
            imprimeVencedor(jogo);
            for(i=0;i<3;i++)
                for(j=0;j<3;j++)
                    jogo[i][j]=' ';
            printf("\n|||||Pressione qualquer tecla para recomeçar|||||\n");
            system("Pause");
            }
    }
}
