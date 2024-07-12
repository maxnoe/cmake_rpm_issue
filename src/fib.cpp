#include "fib/fib.h"

namespace fib {
    unsigned long long fib(unsigned int n) {
        if (n < 2) return n;
        return fib(n - 1) + fib(n - 2);
    }
}
