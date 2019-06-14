#include <unordered_set>
#include <string>
#include <string_view>

using namespace std::string_view_literals;

void example(std::unordered_set<std::string>& s) {
    s.find("hello world"); // implicitly allocates memory :(
    s.find("hello world"sv); // doesn't compile X(
    s.find(std::string("hello world"sv)); // allocates memory :(
}

struct hasher {
    // equal_to has is_transparent
    using transparent_key_equal = std::equal_to<>;
    std::size_t operator()(std::string_view sv) {
        return std::hash<std::string_view>{}(sv);
    }
};

void example(std::unordered_set<std::string, hasher>& s) {
    s.find("hello world"); // doesn't allocate memory but strlen :/
    s.find("hello world"sv); // doesn't allocate memory :D
}
