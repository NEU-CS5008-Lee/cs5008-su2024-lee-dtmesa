// name: Dylan Mesa
// email: mesa.d@northeastern.edu

#include <stdio.h>

int d[20];

long long int dp(int n) {
    if(n == 0){
        return 1;
    }
    
    d[0] = 1;
    d[1] = 0;
    d[2] = 3;
    
    for(int i = 3; i <= n; i++){
        d[i] = 3 * d[i - 2];

        for(int j = 4; j <= i; j += 2){
            d[n] += 2 * d[i - j];
        }
    }
    
    return d[n];
}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%lld\n", dp(n));
}
