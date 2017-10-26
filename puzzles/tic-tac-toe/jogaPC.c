#include <stdlib.h>
int PCjoga(char jogo[4][4]){
    int i,j,k,n;
    int jogaLah1=0; ///status para jogar evitando vitoria do usuario
    int jogaLah2=0; ///status para jogar buscando a vitoria do pc

        for(i=0;i<3;i++){
            for(k=0;k<3;k++){                                            ///joga na coluna
                if(jogo[k][i]=='O')
                    jogaLah2++;
                if(jogaLah2==2)                 ///busca primeiro a vitoria em alguma coluna
                    for(n=0;n<3;n++)
                        if(jogo[n][i]!='X'&&jogo[n][i]!='O'){
                            jogo[n][i]='O';
                            return 0;
                        }
            }
            jogaLah2=0;
            }

        for(i=0;i<3;i++){
            for(k=0;k<3;k++){
                if(jogo[k][i]=='X')
                    jogaLah1++;
                if(jogaLah1==2)         ///se nao houver possibilidade de vitoria, busca evitar a derrota
                    for(n=0;n<3;n++)
                        if(jogo[n][i]!='X'&&jogo[n][i]!='O'){
                            jogo[n][i]='O';
                            return 0;
                        }
             }
            jogaLah1=0;
            }

        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(jogo[i][j]=='O')
                    jogaLah2++;
                if(jogaLah2==2)        ///busca primeiro a vitoria em alguma linha
                    for(n=0;n<3;n++)
                        if(jogo[i][n]!='X'&&jogo[i][n]!='O'){
                            jogo[i][n]='O';
                            return 0;
                        }
                }
            jogaLah2=0;///zera status de busca para inicia-los na diagonal
        }



        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(jogo[i][j]=='X')
                    jogaLah1++;
                if(jogaLah1==2)             ///caso nao consiga vitoria, busca evitar a derrota em alguma linha
                    for(n=0;n<3;n++)
                        if(jogo[i][n]!='X'&&jogo[i][n]!='O'){
                            jogo[i][n]='O';
                            return 0;
                        }
            }
            jogaLah1=0;
        }


        for(i=0;i<3;i++){
            if(jogo[i][i]=='X')
                jogaLah1++;
            if(jogo[i][i]=='O')
                jogaLah2++;
        if(jogaLah1==2)         ///busca vitoria na diagonal primaria
            for(j=0;j<3;j++)
                if(jogo[j][j]!='X'&&jogo[j][j]!='O'){
                    jogo[j][j]='O';
                    return 0;
                }
        if(jogaLah2==2)         ///busca evitar derrota na diagonal primaria
            for(j=0;j<3;j++)
                if(jogo[j][j]!='X'&&jogo[j][j]!='O'){
                    jogo[j][j]='O';
                    return 0;
                }
        }

        jogaLah1=0;     ///zera status de busca
        jogaLah2=0;

        for(i=0;i<3;i++){
            if(jogo[i][2-i]=='X')
                jogaLah1++;
            if(jogo[i][2-i]=='O')
                jogaLah2++;
            if(jogaLah2==2)
                 for(j=0;j<3;j++)                                       /// joga na diagonal secundaria
                    if(jogo[j][2-j]!='X'&&jogo[j][2-j]!='O'){
                        jogo[j][2-j]='O';
                        return 0;
                    }
            if(jogaLah1==2)
                for(j=0;j<3;j++)                                       /// joga na diagonal secundaria
                    if(jogo[j][2-j]!='X'&&jogo[j][2-j]!='O'){
                        jogo[j][2-j]='O';
                        return 0;
                    }
        }
    while(1){          ///jogar aleatoriamente em algum canto para buscar melhor estrategia
        i=rand()%3;
        j=rand()%3;
        if((i==0&&j==2)||(i==0&&j==0)||(i==2&&j==0)||(i==2&&j==2)||(i==1&&j==1))
            if(jogo[i][j]!='X'&&jogo[i][j]!='O'){
                jogo[i][j]='O';
                return 0;;
             }
        if((jogo[0][0]=='X'||jogo[0][0]=='O')&&(jogo[0][2]=='X'||jogo[0][2]=='O')&&(jogo[2][0]=='X'||jogo[2][0]=='O')&&(jogo[2][2]=='X'||jogo[2][2]=='O'))
            break;      ///sai do laço quando nao existem mais cantos para se jogar
    }



    while(1){          ///jogar aleatoriamente em algum canto para buscar melhor estrategia
        i=rand()%3;
        j=rand()%3;
        if(jogo[i][j]!='X'&&jogo[i][j]!='O'){
                jogo[i][j]='O';
                return 0;
             }
    }
}




