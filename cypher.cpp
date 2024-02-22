#include "cypher.hpp"
#include "stdio.h"
#include <malloc.h>


void cypher(int size, unsigned int message[], unsigned int r[]){
    for (int i=0; i<size/16; i++){
        r[i]=0;
    }
    int r0=0;
    int r1=0;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++) {
            r[(i + j) / 32] ^= ( (message[i / 32] >> (i % 32)) &
                (message[j / 32 + size / 32] >> (j % 32)) & 1 ) << ((i + j) % 32);   // Magic centaurian operation
            printf("i=%d j=%d; affected in r : %d by message in %d and %d\n",i,j,(i+j)/32,i/32,j/32+size/32);
            if ((i+j)/32==0){
                r0++;
            } else {
                r1++;
            }
        }
    }
    printf("r0=%d r1=%d\n", r0,r1);
}

int decypher (int size, int maxr,unsigned int cyphered[], unsigned int* r[]){
    
    int nr = 1; // the number of solutions
    int ***chains;
    int chain_sizes[size*2];
    createChain(size,chains,chain_sizes);

    for (int i=0;i<size;i++){
        int chain_size = chain_sizes[i];
        printf("chain n°%d in bit %d: \n",i/16,i%16);
        for (int j=0;j<chain_size;j++){
            int *datas = chains[i][j];
            int bit0 = datas[0];
            int bit1 = datas[1];
            
            printf("\taffected by 0 in bit %d and 1 in bit %d\n",bit0,bit1);
            free(chains[i][j]);

        }
        free(chains[i]);
    }
    free(chains);

    return nr;
}

void createChain(int size, int*** &chain, int chain_sizes[]){
    chain = (int***)malloc(sizeof(int**)*size*2);
    
    for (int i = 0; i<size*2;i++){
        chain[i] = (int**)malloc(sizeof(int*)*size*size);
        for (int j = 0; j<size*size; j++){
            chain[i][j] = (int*)malloc(sizeof(int)*2);
            for(int k=0;k<2;k++){
                chain[i][j][k] = -1;
            }
        }
        chain_sizes[i] = -1;
    }

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++) {
            int r = ((i+j)/32)*32+((i+j)%32);
            printf("r=%d\n",r);
            chain_sizes[r]++;
            int *datas = chain[r][chain_sizes[r]];
            datas[0] = i%32;
            datas[1] = j%32;
            
        }
    }
    for (int i=0;i<size;i++){
        chain_sizes[i]++;
    }

}