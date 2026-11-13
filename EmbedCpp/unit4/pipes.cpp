#include <iostream>
#include <unistd.h>   // Required for pipe(), fork(), read(), write(), close()
#include <sys/types.h>
#include <string.h>

using namespace std;

int main() {
    int fd[2]; 
    // fd[0] will be the READ end of the pipe
    // fd[1] will be the WRITE end of the pipe

    // 1. Create the pipe
    // pipe(fd)
    if (pipe(fd) == -1) {
        perror("Pipe creation failed");
        return 1;
    }

    // 2. Fork the process (creates a Child process cloned from Parent)
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    // --- PARENT PROCESS (The Sender) ---
    if (pid > 0) {
        close(fd[0]); // Close the read end in the parent (we only want to write)

        string message = "Hello from Parent process via Pipe!";
        
        cout << "[Parent] Sending message to child..." << endl;
        write(fd[1], message.c_str(), message.size() + 1); // Write data into pipe
        
        close(fd[1]); // Close write end after sending
    }
    
    // --- CHILD PROCESS (The Receiver) ---
    else {  // pid=0
        close(fd[1]); // Close the write end in the child (we only want to read)

        char buffer[100];
        read(fd[0], buffer, sizeof(buffer)); // Read data from pipe

        cout << "[Child] Received message: " << buffer << endl;
        
        close(fd[0]); // Close read end after reading
    }

    return 0;
}