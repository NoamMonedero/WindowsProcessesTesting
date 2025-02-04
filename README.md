# Windows Internals Exploration Exercise (Based on a YouTube Course)

This repository contains a simple C++ exercise designed to complement a YouTube course on Windows Internals (linked below). It provides hands-on experience with key concepts related to processes, threads, and DLLs, encouraging the use of debugging and system analysis tools for deeper understanding.

## Related Course

*   [Link to the YouTube Course](https://www.youtube.com/watch?v=I_nJltUokE0&t=269s)  

## Code Overview

The code demonstrates core concepts like process creation, thread management (including potential deadlock scenarios), and DLL loading/interaction, offering a practical context for exploring topics such as PE/PEB/TEB structures, calling conventions, DLL callbacks, and system calls.  By using debugging tools (like Visual Studio's debugger) and system analysis tools (like Process Monitor), learners can gain a deeper understanding of these Windows internals concepts through observation and experimentation with the provided code.

## How to Build and Run

1.  **Visual Studio:** Requires Visual Studio with the "Desktop development with C++" workload.
2.  **Build the DLL:** Build the DLL project first.
3.  **Build the Console Application:** Build the console application project.
4.  **Copy the DLL:** Copy the DLL to the same directory as the console application executable (or adjust the path in the code accordingly).
5.  **Run the Executable:** Run the console application.

## Debugging and Analysis (Crucial for Learning)

This exercise is *most effective* when combined with active debugging and system analysis:

1.  **Visual Studio Debugger:** Set breakpoints in the code (both the console application and the DLL). Step through the execution, inspect variables, and examine the call stack.  Pay close attention to how the DLL is loaded and how the function call is made.
2.  **Process Monitor (Sysinternals):** Run Process Monitor while the application is running. Observe the file system activity (DLL loading), process activity, and any other system calls made by the application.  Correlate these observations with the code execution.

By actively using these tools, you'll gain a much deeper understanding of the Windows Internals concepts discussed in the YouTube course.  The code provides the practical foundation, and the debugging/analysis tools provide the insights.

## Further Exploration

Refer to the linked YouTube course for detailed explanations of the concepts.  The suggested resources there (books, documentation) will also be helpful.

## Contributing

Contributions and feedback are welcome!

## License

This project is licensed under the terms of the [MIT License](LICENSE).
