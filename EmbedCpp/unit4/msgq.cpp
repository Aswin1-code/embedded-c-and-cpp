#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

using namespace std;

// Define the message structure
struct MyMessage {
    long mtype;       // Must be first (Message Type)
    char text[50];    // Message payload
};

int main() {
    // 1. Generate a unique key
    key_t key = ftok("app_file", 65);

    // 2. Create the message queue
    int msgid = msgget(key, 0666 | IPC_CREAT);

    // 3. Prepare and send a message
    MyMessage sendMsg;
    sendMsg.mtype = 1; // Type 1 message
    strcpy(sendMsg.text, "Hello Embedded World!");
    
    msgsnd(msgid, &sendMsg, sizeof(sendMsg.text), 0);
    cout << "Message Sent successfully." << endl;



    // 4. Receive the message
    MyMessage recvMsg;
    msgrcv(msgid, &recvMsg, sizeof(recvMsg.text), 1, 0);
    
    cout << "Message Received: " << recvMsg.text << endl;

    // 5. Delete the message queue
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}