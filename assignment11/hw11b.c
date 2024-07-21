// name: <your name here>
// email: <your email here>

#include <stdio.h>

int d[20];

long long int dp(int n) {
    for(int i = 0; i <= n; i++){
        d[i] = -1;
    }
    
    if(n == 0 || n == 1){
        return 1;
    }
    else if(d[n] == -1){
        d[n] = dp(n - 1) + 2 * dp(n - 2);
    }
    return d[n];
}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%lld\n", dp(n));
}
