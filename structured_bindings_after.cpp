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
    auto& [d, e, f] = ex;
    d = 42;
    e = 1234;
    f = 1729;

    print_example(ex);
}
