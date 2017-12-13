#include <iostream>
#include "index.h"

using namespace std;

int main(int argc, char* argv[]) {
	cout << "this is a test about index" << endl;

	CMS_MK mk = "k1";
	CMS_MID mid;
	
	CMS_IDX idx;
	for(unsigned int i=1; i<=3; i++) {
		cout << "i " << i << endl;
		mid.msgid = (uint64_t)i; 
		idx.set_uri(mk,mid);
	}
	cout << "k1 size " << idx.len_uri(mk) << endl;

	return 0;
}

