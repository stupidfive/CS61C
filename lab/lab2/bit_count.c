#include <stdio.h>
#include <stdlib.h>

// YOUR CODE HERE
// Define a function to count the bits in a
// number, and find the hightest and lowest
// 1 bit positions. Valid positions are 0
// for the lowest position, through 31 for
// the highest position. If the number has
// no 1 bits, the positions are both -1.
// ... you will need to change this function
// definition entirely
int * analyze(const unsigned x) {
    int* output = (int *) malloc (3 * sizeof(int));
    output [0] = 0;      // # of 1s
    output [1] = -1;     // highest
    output [2] = -1;     // lowest
    int i;
    for (i = 0; i < 32; i++) {
        if ((x >> i) & 1) {
            if (!output[0]) {
                output[2] = i;
            }
            output[0]++;
            output[1] = i;
        }
    }
    return output;
}


void bit_analyze(const int x) {
    int * output = analyze(x);
    unsigned bit_count = output[0];
    int high_1, low_1;

    // YOUR CODE HERE
    // Call the function you defined, and update
    // the 3 values: bit_count, high_1, low_1.
    // ... you will need to change this function
    // call to match your function definition
    high_1 = output[1];
    low_1 = output[2];
    

    
    printf("   NUMBER: %u\n",x);
    printf("     BITS: %u\n",bit_count);
    printf("HIGHEST 1: %d\n",high_1);
    printf(" LOWEST 1: %d\n",low_1);
    printf("\n");
}
int stoi(const char * str) {
    char * x = NULL;
    const long parsed = strtol(str, &x, 0);
    return x==str ? 0 : (int)parsed;
}
int main(int argc,
         const char * argv[]) {
    bit_analyze(argc>1 ? stoi(argv[1]) : 0);    
    return 0;
}