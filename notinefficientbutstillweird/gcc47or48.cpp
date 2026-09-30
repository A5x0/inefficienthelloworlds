/* This Hello, World! program only compiles on GCC 4.7 and 4.8 when the C++11 standard is selected. */
#include <iostream>

struct ConstexprWithTry {
    constexpr ConstexprWithTry() {
        try {
        } catch(...) {
        }
    }
};

int main() {
    ConstexprWithTry test;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
