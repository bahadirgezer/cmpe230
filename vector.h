#include <stdlib.h>
#define DEFAULT_CAPACITY 10

typedef struct Vector Vector;
typedef struct VectorAttributes VectorAttributes; 

struct VectorAttributes{
    Token *array;       // an array of Tokens
    int capacity;       // the capacity of the array
    int currentSize;    //the current size of the array
    Token nullToken;
};


struct Vector{
    VectorAttributes attributes;        // the attributes of the vector
    // pointers to the functions we need
    void (*pAdd)(Vector *, Token);
    void (*pIncrementSize)(Vector *);
    int (*pIsFull)(Vector *);
    Token (*pGet)(Vector *, int index);
    int (*pSize)(Vector *);
};

/*
 * Checks if the array is full
 */
int IsFull(Vector *vector){
    if (vector->attributes.currentSize == vector->attributes.capacity){
        return 1;
    } else{
        return 0;
    }
}

/*
 * Doubles the size of the array
 * Dynamically reallocates space in the heap
 */
void IncrementSize(Vector *vector){
    Token *array = realloc(vector->attributes.array, sizeof(Token) * vector->attributes.capacity * 2);
    vector->attributes.array = array;
    vector->attributes.capacity *= 2;
}

/*
 * Adds a token to the end of the vector if the capacity permits,
 * otherwise it increments the capacity of the inner array and calls itself again
 */
void Add(Vector *vector, Token token){
    if (IsFull(vector) == 0){
        vector->attributes.array[vector->attributes.currentSize] = token;
        vector->attributes.currentSize++;
    } else{
        IncrementSize(vector);
        Add(vector, token);
    }
}

/*
 * @returns
 * the size of the vector , i.e. the part of the array that is being used.
 */
int Size(Vector *vector){
    return vector->attributes.currentSize;
}

/*
 * returns the value at the specified index
 */
Token Get(Vector *vector, int index){
    if (index < vector->attributes.currentSize){
        return vector->attributes.array[index];
    } else {
        return vector->attributes.nullToken;
    }
}

/*
 * Initializes the Vector
 */
void CreateVector(Vector *vector){
    vector->pAdd = Add;
    vector->pGet = Get;
    vector->pIncrementSize = IncrementSize;
    vector->pIsFull = IsFull;
    vector->pSize = Size;
    vector->attributes.currentSize = 0;
    vector->attributes.capacity = DEFAULT_CAPACITY;
    vector->attributes.array = malloc(sizeof(Token) * DEFAULT_CAPACITY);
    vector->attributes.nullToken.isOk = 0;
}
