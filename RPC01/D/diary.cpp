#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

int main()
{
    int cases, len, max, cont, dif, aux;
    char str[1005], c, d;
    bool bien;
    char alp[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    map <char,int> mp;
    map <char,char> car;

    scanf("%d",&cases);
    getchar();

    while(cases--){

        cont = max = 0;
        bien = true;
        map <char,int>::iterator it;

        gets(str);

        len = strlen(str);
        for(int i = 0; i < len; i++){
            if(str[i] == ' ')
                continue;
            mp[str[i]]++;
            if(mp[str[i]] > max){
                max = mp[str[i]];
                c = str[i];
            }
        }

        for(it = mp.begin(); it != mp.end(); it++){
            if(it->second == max)
                cont++;
            if(cont > 1){
                bien = false;
                break;
            }
        }

        if(!bien)
            printf("NOT POSSIBLE\n");
        else{
            if(c >= 'E')//esta a la derecha de E
                dif = c - 'E';
            else//esta a la izquierda DE e
                dif = (c - 'A') + (90 - 'E') + 1;

            for(int i = 0; i < 26; i++){
                d = alp[i];
                for(int j = 0; j < dif; j++){
                    d--;
                    if(d < 65)
                        d = 90;
                }
                car[alp[i]] = d;
            }

            printf("%d ",dif);
            for(int i = 0; i < len; i++){
                if(str[i] == ' ')
                    printf(" ");
                else
                    printf("%c",car[str[i]]);
            }printf("\n");

        }

        mp.clear();
        car.clear();
    }
    return 0;
}
