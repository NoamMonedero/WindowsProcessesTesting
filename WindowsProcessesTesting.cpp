#include <iostream>
#include <windows.h>
#include <thread>
#include <mutex> // Include for mutex

// Global mutex (demonstrates a potential deadlock scenario)
std::mutex g_MyMutex;

// Function that simulates some work (and a potential deadlock)
DWORD WINAPI MyThreadFunction(LPVOID lpParam) {
    std::cout << "Thread running!\n";

    // Simulate some work that requires a lock
    {
        std::lock_guard<std::mutex> lock(g_MyMutex); // Acquire the mutex
        std::cout << "Thread acquired mutex.\n";
        Sleep(1000); // Simulate some work
    } // Mutex is released automatically here

    return 0;
}

int main() {
    // --- Potential Deadlock Scenario ---
    // The main thread and the created thread both try to acquire the same mutex.
    // If the order of acquisition is unfortunate, a deadlock can occur.

    // Create a thread
    HANDLE hThread = CreateThread(NULL, 0, MyThreadFunction, NULL, 0, NULL);

    // Simulate some work in the main thread (that also needs the mutex)
    {
        std::lock_guard<std::mutex> lock(g_MyMutex); // Main thread tries to acquire mutex
        std::cout << "Main thread acquired mutex.\n";
        Sleep(1000); // Simulate some work
    } // Mutex is released automatically here


    // --- DLL Loading (Unrelated to Deadlock, but kept for completeness) ---
    HINSTANCE hDLL = LoadLibrary(L"LibExampleDll\\x64\\Debug\\LibExampleDll.dll");

    if (hDLL != NULL) {
        typedef int (*AddFunc)(int, int);
        AddFunc add = (AddFunc)GetProcAddress(hDLL, "Add");

        if (add != NULL) {
            int result = add(5, 3);
            std::cout << "Console App: Result from DLL: " << result << std::endl;
        }
        else {
            std::cerr << "Could not find Add function.\n";
        }

        FreeLibrary(hDLL);
    }
    else {
        std::cerr << "Could not load DLL.\n";
    }

    // Wait for the thread to finish (important for observing deadlock)
    WaitForSingleObject(hThread, INFINITE);
    CloseHandle(hThread);

    std::cout << "Main thread finished.\n";
    return 0;
}