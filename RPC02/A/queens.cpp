#include <cstdio>

using namespace std;

int main()
{
    char board[8][8], str[8];
    int lad, sup, queens;
    bool bien;
    while(scanf("%s",str) != EOF){
        bien = true;
        queens = 0;
        for(int i = 0; i < 8; i++)
            board[0][i] = str[i];
        for(int i = 1; i < 8; i++){
            scanf("%s",str);
            for(int j = 0; j < 8; j++){
                board[i][j] = str[j];
            }
        }

        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(board[i][j] == '*'){
                    lad = j;
                    sup = i;
                    //superior izquierda
                    lad--;
                    sup--;
                    while(lad >= 0 && sup >= 0){
                        if(board[sup][lad] == '*')
                            bien = false;
                        sup--;
                        lad--;
                    }
                    lad = j;
                    sup = i;
                    //superior centro
                    sup--;
                    while(sup >= 0){
                        if(board[sup][lad] == '*')
                            bien = false;
                        sup--;
                    }
                    lad = j;
                    sup = i;
                    //superior derecha
                    sup--;
                    lad++;
                    while(sup >= 0 && lad < 8){
                        if(board[sup][lad] == '*')
                            bien = false;
                        sup--;
                        lad++;
                    }
                    lad = j;
                    sup = i;
                    //centro izquierda
                    lad--;
                    while(lad >= 0){
                        if(board[sup][lad] == '*')
                            bien = false;
                        lad--;
                    }
                    lad = j;
                    sup = i;
                    //centro derecha
                    lad++;
                    while(lad < 8){
                        if(board[sup][lad] == '*')
                            bien = false;
                        lad++;
                    }
                    lad = j;
                    sup = i;
                    //inferior izquierda
                    lad--;
                    sup++;
                    while(lad >= 0 && sup < 8){
                        if(board[sup][lad] == '*')
                            bien = false;
                        lad--;
                        sup++;
                    }
                    lad = j;
                    sup = i;
                    //inferior centro
                    sup++;
                    while(sup < 8){
                        if(board[sup][lad] == '*')
                            bien = false;
                        sup++;
                    }
                    lad = j;
                    sup = i;
                    //inferior derecha
                    sup++;
                    lad++;
                    while(sup < 8 && lad < 8){
                        if(board[sup][lad] == '*')
                            bien = false;
                        sup++;
                        lad++;
                    }

                    if(bien)
                        queens++;
                }
            }
        }
        if(queens == 8)
            printf("valid\n");
        else
            printf("invalid\n");

    }
    return 0;
}
