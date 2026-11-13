#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

#define PORT 8080

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    // ==================== CHILD PROCESS (THE CLIENT) ====================
    if (pid == 0) {
        // Sleep briefly to ensure the server starts listening first
        sleep(1);

        // 1. Create socket
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);

        // 2. Prepare server address
        sockaddr_in addr{};
        addr.sin_family = AF_INET;
        addr.sin_port = htons(PORT);
        inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);

        // 3. Connect to server
        connect(sockfd, (struct sockaddr*)&addr, sizeof(addr));

        // 4. Send message
        const char *msg = "Hello Server";
        send(sockfd, msg, strlen(msg), 0);
        cout << "[Client] Message sent!" << endl;

        // 5. Close socket
        close(sockfd);
    } 
    // ==================== PARENT PROCESS (THE SERVER) ====================
    else {
        // 1. Create socket
        int server_fd = socket(AF_INET, SOCK_STREAM, 0);

        // 2. Prepare server address
        sockaddr_in addr{};
        addr.sin_family = AF_INET;
        addr.sin_port = htons(PORT);
        addr.sin_addr.s_addr = INADDR_ANY;

        // 3. Bind socket
        bind(server_fd, (struct sockaddr*)&addr, sizeof(addr));

        // 4. Listen for clients
        listen(server_fd, 5);
        cout << "[Server] Waiting for client..." << endl;

        // 5. Accept one client
        int client_fd = accept(server_fd, nullptr, nullptr);

        // 6. Receive client message
        char buffer[100];
        ssize_t n = recv(client_fd, buffer, sizeof(buffer) - 1, 0);

        if (n > 0) {
            buffer[n] = '\0';
            cout << "[Server] Client says: " << buffer << endl;
        }

        // 7. Close sockets
        close(client_fd);
        close(server_fd);
    }

    return 0;
}