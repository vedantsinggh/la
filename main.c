#include <stdio.h>
#include "vectors.h"

int main(void){
	V2 a = {5,8};
	V2 b = {3,1};

	V2 v = addV2(a,b);
	v = subV2(a,b);
	int r = dotV2(a,b);
	r = modV2(a);
	return 0;
}
