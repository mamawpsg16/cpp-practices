#include <iostream>
#include <thread>
#include <chrono>
#include <future>
#include <mutex>
#include <condition_variable>

// Function for processing data
// void processData(int id) {
//     for (int i = 1; i <= 5; ++i) {
//         std::cout << "Processing data in thread " << id << ": step " << i << "\n";
//         std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Simulate work with a delay
//     }
// }

// Function for logging messages
// void logMessages() {
//     for (int i = 1; i <= 5; ++i) {
//         std::cout << "Logging message " << i << "\n";
//         std::this_thread::sleep_for(std::chrono::milliseconds(700)); // Simulate work with a delay
//     }
// }

/** ASYNC */
// Function to compute a long-running task
int compute(int x) {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate delay
    return x * x;
}

int func1(){
    return 1;
}

/** CONDITION VARIABLE */
std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void worker() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return ready; }); // Wait until 'ready' is true
    std::cout << "Worker thread is running!\n";
}

int main() {
    // Create two threads: one for processing data, one for logging messages
    // std::thread workerThread(processData, 1);
    // std::thread loggerThread(logMessages);

    // Wait for both threads to complete before proceeding
    // workerThread.join();  // Ensures the main thread waits for workerThread to finish
    // loggerThread.join();  // Ensures the main thread waits for loggerThread to finish

    // std::cout << "All tasks completed.\n";

    /** ASYNC */
    // Launch the task asynchronously
    // std::future<int> result = std::async(std::launch::async, compute, 10);
    // std::cout << func1() << '\n';
    // std::cout << "Doing other work while computation runs...\n";

    // Retrieve the result (blocks if computation isn't finished yet)
    // std::cout << "Result: " << result.get() << std::endl;

    /** CONDITION VARIABLE */
    std::thread t(worker);

    std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate work
    {
        std::lock_guard<std::mutex> lock(mtx);
        ready = true; // Set condition
    }
    cv.notify_one(); // Notify the worker thread

    t.join();
    return 0;
}
