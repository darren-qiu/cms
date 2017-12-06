#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	printf("this is a test.\n");
	
	int *p = new int[5];
	delete [] p;

	return 0;
}

