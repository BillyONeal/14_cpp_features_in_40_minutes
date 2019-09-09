#include <string_view>

using namespace std::string_view_literals;

constexpr auto s = "hello world"sv;
static_assert(s.starts_with("hello"sv));
static_assert(!s.ends_with("hello"sv));
static_assert(!s.starts_with(" world"sv));
static_assert(s.ends_with(" world"sv));

int main() {}
