export module Lib:B;

namespace test {
    // external linkage
    export void test_func() {}
}

// module linkage
int hidden2() {
    return 20;
}

