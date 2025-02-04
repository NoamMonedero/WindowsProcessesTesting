#include <iostream>
#include <windows.h>
#include <thread>

DWORD WINAPI MyThreadFunction(LPVOID lpParam) {
    std::cout << "Thread running!\n";
    return 0;
}

int main() {
    // Load the DLL
    HINSTANCE hDLL = LoadLibrary(L"LibExampleDll\\x64\\Debug\\LibExampleDll.dll"); // Replace with the actual path

    if (hDLL != NULL) {
        // Get the address of the Add function
        typedef int (*AddFunc)(int, int); // Define a type for the function pointer
        AddFunc add = (AddFunc)GetProcAddress(hDLL, "Add"); // "Add" is the function name

        if (add != NULL) {
            // Call the Add function
            int result = add(5, 3);
            std::cout << "Console App: Result from DLL: " << result << std::endl;
        }
        else {
            std::cerr << "Could not find Add function.\n";
        }

        // Unload the DLL
        FreeLibrary(hDLL);
    }
    else {
        std::cerr << "Could not load DLL.\n";
    }

    return 0;
}