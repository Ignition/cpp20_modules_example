module;

#include <iostream>

export module Lib;
export import :B; // re-export from partition B

namespace test {
    // external linkage
    export [[gnu::visibility("default")]] void printMessage();
}

module : private;

// module linkage
int hidden3() {
    return 2;
}

namespace {
    // internal linkage
    int hidden() {
        return hidden2() * 2 + hidden3();
    }
}

void test::printMessage() {
    std::cout << "The hidden value is " << hidden() << "\n";
}
