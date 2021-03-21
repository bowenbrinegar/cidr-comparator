#include "cidr.h"

int main( int argc, char *argv[] )  {
    int match = cidrcmp(argv[1], argv[2]);
    if (match == 0) {
        printf("\nIP %s matches => %s\n", argv[1], argv[2]);
    }
    else {
        printf("\nIP %s DOES NOT MATCH => %s\n", argv[1], argv[2]);
    }
    return 0;
};