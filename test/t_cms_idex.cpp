#include <iostream>
#include "index.h"

using namespace std;

int main(int argc, char* argv[]) {
	cout << "this is a test about index" << endl;

	CMS_MK mk = "k1";
	CMS_MID mid;
	
	CMS_IDX idx;
	unsigned int i,j;
	
	for(i=1; i<=3; i++) {
		cout << "i " << i << endl;
		mid.msgid = (uint64_t)i; 
		idx.set_uri(mk,mid);
	}
	cout << "k1 size " << idx.len_uri(mk) << endl;
	
	for(j=1; j<=3; j++) {
		cout << "j " << j << endl;
		mid.msgid = j;
		idx.del_uri(mk,mid);
	}
	cout << "k1 size " << idx.len_uri(mk) << endl;

	for(i=0; i<=3; i++) {
		cout << "i " << i << endl;
		mid.msgid = i;
		idx.set_rsi(mk,mid);
	}
	cout << "K1 rsi size " << idx.len_rsi(mk) << endl;

	for(i=0; i<=3; i++) {
		cout << "i " << i << endl;
		mid.msgid = i;
		idx.set_rsi(mk,mid);
	}
	cout << "k1 rsi size " << idx.len_rsi(mk) << endl;

	vector<CMS_MID> res;
	idx.get_rsi(mk,res);
	for(i=0; i<res.size(); i++) {
		cout << "i " << i;
		cout << " mid " << res[i].msgid << endl;
	}
	return 0;
}

