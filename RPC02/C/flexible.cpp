#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 102

using namespace std;

int main()
{
    int w, p, part;
    bool ans[MAX];
    vector <int> vec;
    while(scanf("%d %d",&w,&p) != EOF){

        fill(ans,ans+w+1,false);
        vec.push_back(0);

        for(int i = 0; i < p; i++){
            scanf("%d",&part);
            vec.push_back(part);
        }

        vec.push_back(w);
        for(int i = 0; i < vec.size() - 1; i++){
            for(int j = i + 1; j < vec.size(); j++){
                ans[vec.at(j) - vec.at(i)] = true;
            }
        }

        for(int i = 1; i <= w; i++){
            if(ans[i]){
                if(i != w)
                    printf("%d ",i);
                else
                    printf("%d",i);
            }
        }printf("\n");

        vec.clear();
    }
    return 0;
}
