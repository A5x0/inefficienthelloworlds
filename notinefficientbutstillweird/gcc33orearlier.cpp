/* This Hello, World! program only compiles on GCC 3.3 or earlier. */
#include <iostream>

template <typename T>
struct Outer {
    struct Inner {
        void hello() {
            std::cout << "Hello, World!" << std::endl;
        }
    };
};

void Outer<int>::Inner::hello() {
    std::cout << "Hello, World!" << std::endl;
}

int main() {
    Outer<int>::Inner instance;
    instance.hello();
    return 0;

}
