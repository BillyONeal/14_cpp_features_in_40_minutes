#include <stdio.h>
#include <random>
#include <algorithm>
#include <vector>
#include <iterator>

int main() {
    // make a vector of 1000 random unsigned integers:
    std::random_device rd;
    std::vector<unsigned> examples(1000);
    std::generate(examples.begin(), examples.end(), std::ref(rd));

    // print the lowest and highest values:
    auto [lowest, highest] =
        std::minmax_element(examples.begin(), examples.end());
    printf("Low: %u High: %u\n", *lowest, *highest);
}
