#include <iostream>
#include "ThreadPool.hpp"

int main() {
    ThreadPool pool(4);

    // auto result = pool.enqueue([] {
    //     std::cout << "Hello from the thread pool!" << std::endl;
    //     return 42;
    // });

    std::cout << "hello " << std::endl;

    return 0;
}
