#include <iostream>

#include "cypher.hpp"

#define SIZE 32

using namespace std;

int main(){

	unsigned int m[SIZE/16] = {0xb0c152f9, 0xebf2831f};
	unsigned int r[SIZE/16];
	cypher(SIZE, m, r);

	cout << hex << r[0] << " " << hex << r[1] << endl;

	return 0;
}


