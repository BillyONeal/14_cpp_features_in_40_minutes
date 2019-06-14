#include <stdio.h>
#include <limits.h>
#include <random>
#include <memory>

std::unique_ptr<int> get_value() {
    constexpr auto maxInt = static_cast<unsigned>(INT_MAX);
    const unsigned val = std::random_device{}();
    if (val > maxInt) { return {}; }
    return std::make_unique<int>(static_cast<int>(val));
}

int main() {
    for (int i = 0; i < 10; ++i) {
        if (std::unique_ptr<int> p = get_value(); p.get()) {
            printf("The value was %i\n", *p);
        } else {
            puts("The value was null");
        }
    }
}
