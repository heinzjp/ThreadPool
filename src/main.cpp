#include "Timer.hpp"
#include "ThreadPool.hpp"
#include <iostream>
#include <vector>
#include <future>

// slow_fibonacci like before
int slow_fibonacci(int n) {
    if (n <= 1) return n;
    return slow_fibonacci(n - 1) + slow_fibonacci(n - 2);
}

int main() {
    constexpr int start = 30;
    constexpr int count = 5;

    // Single-threaded version
    {
        Timer t("Single-threaded Fibonacci");

        for (int i = 0; i < count; ++i) {
            int result = slow_fibonacci(start + i);
            std::cout << "fib(" << (start + i) << ") = " << result << "\n";
        }
    }

    std::cout << "\n";

    // ThreadPool version
    {
        Timer t("ThreadPool Fibonacci with 4 threads");

        ThreadPool pool(4);
        std::vector<std::future<int>> results;

        for (int i = 0; i < count; ++i) {
            results.emplace_back(pool.enqueue(slow_fibonacci, start + i));
        }

        for (int i = 0; i < count; ++i) {
            std::cout << "fib(" << (start + i) << ") = " << results[i].get() << "\n";
        }
    }

        {
        Timer t("ThreadPool Fibonacci with 2 threads");

        ThreadPool pool(2);
        std::vector<std::future<int>> results;

        for (int i = 0; i < count; ++i) {
            results.emplace_back(pool.enqueue(slow_fibonacci, start + i));
        }

        for (int i = 0; i < count; ++i) {
            std::cout << "fib(" << (start + i) << ") = " << results[i].get() << "\n";
        }
    }

    return 0;
}
