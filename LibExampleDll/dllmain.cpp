
// Compile: cl /LD DllExample.cpp
#include <iostream>
#include <windows.h>

// Define a simple function that the main application can call
extern "C" __declspec(dllexport) int Add(int a, int b) {
    int result = a + b;
    std::cout << "DLL: Add function called. Result: " << result << std::endl;  // Output for debugging
    return result;
}

// Global variable in the DLL
int g_MyGlobalVar = 0;

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
        std::cout << "DLL: Attached to process.\n";
        g_MyGlobalVar = 10; // Initialize global variable
        break;
    case DLL_PROCESS_DETACH:
        std::cout << "DLL: Detached from process.\n";
        g_MyGlobalVar = 0;  // Reset global variable
        break;
    case DLL_THREAD_ATTACH:
        std::cout << "DLL: Thread attached.\n";
        break;
    case DLL_THREAD_DETACH:
        std::cout << "DLL: Thread detached.\n";
        break;
    }
    return TRUE;
}