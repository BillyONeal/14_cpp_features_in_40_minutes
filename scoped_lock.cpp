#include <mutex>
#include <shared_mutex>

struct DataValue {
    mutable std::shared_mutex m;
    int theValue;
};
void modify_both(DataValue& a, DataValue& b) {
    // class template argument deduction!
    std::scoped_lock lock(a.m, b.m); // takes both mutexes without deadlock
    std::swap(a.theValue, b.theValue);
    // both mutexes are unlocked upon exiting the scope
}
