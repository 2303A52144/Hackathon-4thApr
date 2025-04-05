#include <stdio.h>
#include <stdlib.h>

#define MAX_N 10
#define MAX_M 10

typedef struct {
    int temp;
    int humidity;
    int id;
} Biome;

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        
        Biome biomes[MAX_N * MAX_M];
        int biome_count = 0;
        int available_biomes[MAX_N][MAX_M] = {0};
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int id;
                scanf("%d", &id);
                if (id != 0) {
                    biomes[biome_count++] = (Biome){i + 1, j + 1, id};
                    available_biomes[i][j] = id; 
                }
            }
        }
        
        if (biome_count < 2) {
            printf("-1\n");
            continue;
        }
        int h = 1; 
        int w = biome_count; 
        
        printf("%d %d\n", h, w);
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                printf("%d ", biomes[j].id);
            }
            printf("\n");
        }
    }
    
    return 0;
}
