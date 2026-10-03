/* This Hello, World! program only compiles on GCC 4.9 if the standard is set to C++14. */
#include <iostream>

int main() {
    auto lambda = [](auto x) {
        int shadow_var = 10;
        int shadow_var = 20;
        std::cout << "Hello, World!\n";
    };

    lambda(0);
    return 0;
}
