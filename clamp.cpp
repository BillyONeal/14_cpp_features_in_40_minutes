#include <algorithm>

constexpr int a = std::clamp(1234, 10, 20);
constexpr int b = std::clamp(11, 10, 20);
constexpr int c = std::clamp(0, 10, 20);
static_assert(a == 20);
static_assert(b == 11);
static_assert(c == 10);
