#include <stdio.h>
#include <set>

template<class Container>
void print_ints(const char* const tag, const Container& c) {
    printf("%s: {", tag);
    auto i = c.begin();
    const auto e = c.end();
    if (i != e) {
        printf("%d", *i);
        while (++i != e) {
            printf(", %d", *i);
        }
    }

    puts("}");
}

int main() {
    std::set set1 = {1, 2, 4, 1000, 1234, -67, 1729};
    std::set set2 = {-1, 2, 4, -1000, 1234, 7, -1729};
    print_ints("set1", set1);
    print_ints("set2", set2);
    set1.merge(set2);
    print_ints("set1, after merge", set1);
    print_ints("set2, after merge", set2);
}
