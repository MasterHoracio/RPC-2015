#include <cstdio>
#include <cmath>

using namespace std;

typedef long long ll;

int main()
{
    ll a, b, c;
    while(scanf("%lld %lld",&a,&b)){
            if(a == 0 && b == 0)
                break;
        if(a >= b){
            c = a / b;
            a -= b * c;
        }else{
            c = 0;
        }
        printf("%lld %lld / %lld\n",c,a,b);

    }
    return 0;
}
