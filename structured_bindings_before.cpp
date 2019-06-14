#include <stdio.h>

struct example {
    int a;
    int b;
    int c;
};

void print_example(const example& ex) {
    printf("a: %d b: %d c: %d",
        ex.a, ex.b, ex.c);
}

int main() {
    example ex;
    ex.a = 42;
    ex.b = 1234;
    ex.c = 1729;

    print_example(ex);
}
