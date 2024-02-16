#include "cypher.hpp"
#include "stdio.h"
#include <malloc.h>


void cypher(int size, unsigned int message[], unsigned int r[]){
    for (int i=0; i<size/16; i++){
        r[i]=0;
    }
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++) {
            r[(i + j) / 32] ^= ( (message[i / 32] >> (i % 32)) &
                (message[j / 32 + size / 32] >> (j % 32)) & 1 ) << ((i + j) % 32);   // Magic centaurian operation
        
  }
}

int decypher (int size, int maxr,unsigned int cyphered[], unsigned int* r[]){
    for (int i=0; i<size/16; i++){
        r[0][i]=0;
    }
    int nr = 1; // the number of solutions
    for (int i = size-1; i>=0; i--){
        for (int j = size-1; j>=0; j--){
            
        }
    }

    return nr;
}

