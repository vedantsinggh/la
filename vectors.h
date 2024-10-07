#include <math.h>

#ifndef VEC
#define VEC

typedef struct V1 {
	float x;
} V1;

typedef struct V2 {
	float x;
	float y;
} V2;

typedef struct V3 {
	float x;
	float y;
	float z;
} V3;

V1 addV1(V1 a, V1 b){
	return (V1){a.x + b.x};
}

V2 addV2(V2 a, V2 b){
	return (V2){a.x + b.x, a.y + b.y};
}

V3 addV3(V3 a, V3 b){
	return (V3){a.x + b.x, a.y + b.y, a.y + b.z};
}

V1 subV1(V1 a, V1 b){
	return (V1){a.x - b.x};
}

V2 subV2(V2 a, V2 b){
	return (V2){a.x - b.x, a.y - b.y};
}

V3 subV3(V3 a, V3 b){
	return (V3){a.x - b.x, a.y - b.y, a.y - b.z};
}

int modV1(V1 a){
	return a.x>0 ? a.x : -1*a.x;
}

int modV2(V2 a){
	return sqrt(a.x*a.x + a.y*a.y);
}

int modV3(V3 a){
	return sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
}

int dotV1(V1 a, V1 b){
	return (int)(a.x*b.x);
}

int dotV2(V2 a, V2 b){
	return (int)(a.x*b.x + a.y*b.y);
}

int dotV3(V3 a, V3 b){
	return (int)(a.x*b.x + a.y*b.y + a.z*b.z);
}

#endif // VECTORS.H 
