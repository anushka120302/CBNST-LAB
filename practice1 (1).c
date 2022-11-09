#include <stdio.h>
#include <math.h>

int main(){
    int n;
    scanf("%d", &n);

    double adj[n][n + 1];

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= n; j++){
            scanf("%lf", &adj[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j != i){
                double t = adj[j][i]/adj[i][i];

                for(int k = 0; k <= n; k++){
                    adj[j][k] = adj[j][k] - (adj[i][k] * t);
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        adj[i][n] /= adj[i][i];
        adj[i][i] = 1.0;
    }

    printf("\n");
    
    for(int i = 0; i < n; i++){
        printf("%0.5lf\t", adj[i][n]);
    }

    return 0;
}