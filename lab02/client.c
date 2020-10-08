#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORTNUM 8080
#define MSG_LEN 128
#define S_FLAGS 0
  
int main(void)
{
    int sockfd;
    char *message[MSG_LEN];
    struct sockaddr_in server_addr;

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) 
    {
        perror("socket");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family      = AF_INET;
    server_addr.sin_port        = htons(PORTNUM);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    printf("Enter integer: ");
    scanf("%s", (char *)message);
    
    sendto(
        sockfd, (const char *)message,
        strlen((const char *)message), S_FLAGS,
        (const struct sockaddr *)&server_addr, sizeof(server_addr)
    );
    close(sockfd);

    return 0;
}
