#include <mutex>
#include <thread>

int global = 0;
std::mutex mtx;

void do_something()
{
    for (int i = 0; i < 1'000'000; ++i) {
        // std::lock_guard<std::mutex> lock(mtx);
        ++global;
    }
}

int main()
{
    std::thread t1{do_something};
    std::thread t2{do_something};

    t1.join();
    t2.join();
}
