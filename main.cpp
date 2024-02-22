#include <iostream>

#include "cypher.hpp"

#define SIZE 32

using namespace std;

int main(){

	unsigned int m[SIZE/16] = {0xb0c152f9, 0xebf2831f};
	unsigned int *r[SIZE/16];
	unsigned int cyphered[] = {0x46508fb7, 0x6677e201};
	decypher (SIZE, 0,cyphered, r);

	

	return 0;
}


