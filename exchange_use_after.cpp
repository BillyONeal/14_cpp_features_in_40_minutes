#include <utility>
#include <string>

struct MySmartThing {
    std::string member;

    std::string Detach() {
        return std::exchange(member, {});
    }
};
