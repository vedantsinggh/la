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

// Add
V1 addV1(V1 a, V1 b) {
    return (V1){a.x + b.x};
}

V2 addV2(V2 a, V2 b) {
    return (V2){a.x + b.x, a.y + b.y};
}

V3 addV3(V3 a, V3 b) {
    return (V3){a.x + b.x, a.y + b.y, a.z + b.z};
}

// Sub
V1 subV1(V1 a, V1 b) {
    return (V1){a.x - b.x};
}

V2 subV2(V2 a, V2 b) {
    return (V2){a.x - b.x, a.y - b.y};
}

V3 subV3(V3 a, V3 b) {
    return (V3){a.x - b.x, a.y - b.y, a.z - b.z};
}

// Mod
float modV1(V1 a) {
    return fabsf(a.x);
}

float modV2(V2 a) {
    return sqrtf(a.x * a.x + a.y * a.y);
}

float modV3(V3 a) {
    return sqrtf(a.x * a.x + a.y * a.y + a.z * a.z);
}

// Dot
float dotV1(V1 a, V1 b) {
    return a.x * b.x;
}

float dotV2(V2 a, V2 b) {
    return a.x * b.x + a.y * b.y;
}

float dotV3(V3 a, V3 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

// Cross product (only for V3)
V3 crossV2(V2 a, V2 b) {
	V3 x = {a.x, a.y, 0};
	V3 y = {b.x, b.y, 0};
    return crossV3(x,y);
}

V3 crossV3(V3 a, V3 b) {
    return (V3){
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    };
}

// Scale
V1 scaleV1(V1 a, float s) {
    return (V1){a.x * s};
}

V2 scaleV2(V2 a, float s) {
    return (V2){a.x * s, a.y * s};
}

V3 scaleV3(V3 a, float s) {
    return (V3){a.x * s, a.y * s, a.z * s};
}

// Normalize
V1 normalizeV1(V1 a) {
    float len = modV1(a);
    if (len > 0) {
        return scaleV1(a, 1.0f / len);
    }
    return a; 
}

V2 normalizeV2(V2 a) {
    float len = modV2(a);
    if (len > 0) {
        return scaleV2(a, 1.0f / len);
    }
    return a;
}

V3 normalizeV3(V3 a) {
    float len = modV3(a);
    if (len > 0) {
        return scaleV3(a, 1.0f / len);
    }
    return a;
}

// Angle between
float angleBetweenV2(V2 a, V2 b) {
    float dotProd = dotV2(a, b);
    float lenA = modV2(a);
    float lenB = modV2(b);
    if (lenA > 0 && lenB > 0) {
        return acosf(dotProd / (lenA * lenB));
    }
    return 0.0f;
}

float angleBetweenV3(V3 a, V3 b) {
    float dotProd = dotV3(a, b);
    float lenA = modV3(a);
    float lenB = modV3(b);
    if (lenA > 0 && lenB > 0) {
        return acosf(dotProd / (lenA * lenB));
    }
    return 0.0f;
}

// Reflect a vector
V2 reflectV2(V2 a, V2 normal) {
    float dotProd = dotV2(a, normal);
    return subV2(a, scaleV2(normal, 2.0f * dotProd));
}

V3 reflectV3(V3 a, V3 normal) {
    float dotProd = dotV3(a, normal);
    return subV3(a, scaleV3(normal, 2.0f * dotProd));
}

// Lerp
V1 lerpV1(V1 a, V1 b, float t) {
    return (V1){a.x + t * (b.x - a.x)};
}

V2 lerpV2(V2 a, V2 b, float t) {
    return (V2){
        a.x + t * (b.x - a.x),
        a.y + t * (b.y - a.y)
    };
}

V3 lerpV3(V3 a, V3 b, float t) {
    return (V3){
        a.x + t * (b.x - a.x),
        a.y + t * (b.y - a.y),
        a.z + t * (b.z - a.z)
    };
}

#endif // VECTORS.H
