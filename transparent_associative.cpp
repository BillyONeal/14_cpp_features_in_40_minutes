#include <set>
#include <string>
#include <string_view>

using namespace std::string_view_literals;

void example(std::set<std::string>& s) {
    s.find("hello world"); // implicitly allocates memory :(
    s.find("hello world"sv); // doesn't compile X(
    s.find(std::string("hello world"sv)); // allocates memory :(
}

void example(std::set<std::string, std::less<>>& s) {
    s.find("hello world"); // doesn't allocate memory but strlen :/
    s.find("hello world"sv); // doesn't allocate memory :D
}
