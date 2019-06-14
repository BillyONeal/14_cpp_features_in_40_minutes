#include <set>

int main() {
    std::set s = {1, 2, 4, 1000, 1234, 67, 1729};

    printf("find != end 24: %s\n", s.find(24) != s.end() ? "true" : "false");
    printf("find != end 67: %s\n", s.find(67) != s.end() ? "true" : "false");

    printf("count 24: %s\n", s.count(24) != 0 ? "true" : "false");
    printf("count 67: %s\n", s.count(67) != 0 ? "true" : "false");

    printf("contains 24: %s\n", s.contains(24) ? "true" : "false");
    printf("contains 67: %s\n", s.contains(67) ? "true" : "false");
}
