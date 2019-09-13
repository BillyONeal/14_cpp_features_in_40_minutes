#include <utility>
#include <string>

struct MySmartThing {
    std::string member;

    std::string Detach() {
        std::string old = std::move(member);
        member = {};
        return old;
    }
};
