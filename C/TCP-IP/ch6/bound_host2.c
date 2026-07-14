#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define BUFFER_SIZE 30

void error_handling(char *message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}

int main(int argc, char** argv) {
    int sock;
    char message1[] = "Hi!";
    char message2[] = "I'm another UDP host!";
    char message3[] = "Nice to meet you!";
    socklen_t your_adr_sz;
    struct sockaddr_in your_adr;

    if(argc != 3) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    sock = socket(PF_INET, SOCK_DGRAM, 0);
    if(sock == -1)
        error_handling("socket() error");

    memset(&your_adr, 0, sizeof(your_adr));
    your_adr.sin_family = AF_INET;
    your_adr.sin_addr.s_addr = inet_addr(argv[1]);
    your_adr.sin_port = htons(atoi(argv[2]));

    if(bind(sock, (struct sockaddr*)&your_adr, sizeof(your_adr)) == -1)
        error_handling("bind() error");
    
    sendto(sock, message1, sizeof(message1), 0, (struct sockaddr*)&your_adr, sizeof(your_adr));
    sendto(sock, message2, sizeof(message2), 0, (struct sockaddr*)&your_adr, sizeof(your_adr));
    sendto(sock, message3, sizeof(message3), 0, (struct sockaddr*)&your_adr, sizeof(your_adr));
    close(sock);
    return 0;
}