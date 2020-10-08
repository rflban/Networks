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

void print_num(int number, int base);

int main(void)
{
    int sockfd;
    char buffer[MSG_LEN];
    
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) 
    {
        perror("socket");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    memset(&client_addr, 0, sizeof(client_addr));

    server_addr.sin_family      = AF_INET;
    server_addr.sin_port        = htons(PORTNUM);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (const struct sockaddr *)&server_addr,
             sizeof(server_addr)) < 0)
    {
        perror("bind");
        return 1;
    }

    ssize_t n;
    socklen_t len;

    len = sizeof(client_addr);
    n   = recvfrom(
        sockfd, (char *)buffer, MSG_LEN, MSG_WAITALL,
        ( struct sockaddr *) &client_addr, &len
    );
    close(sockfd);

    buffer[n] = 0;

    int num;
    num = atoi(buffer);

    print_num(num, 10);
    print_num(num,  2);
    print_num(num, 16);
    print_num(num,  8);
    print_num(num, 14);

    return 0;
}

void print_num(int number, int base)
{
    int digs[256] = { 0 };
    int sign = 1;
    int idx  = 1;
    
    if (number < 0)
    {
        sign   *= -1;
        number *= -1;
    }

    printf("%3d number system: %c", base, (sign < 0 ? '-' : ' '));

    for (idx = 0; number; number /= base, ++idx)
        digs[idx] = number % base;

    if (!idx)
        printf("0");

    while (idx--)
        printf("%c", digs[idx] + (digs[idx] < 10 ? '0' : ('A' - 10)));

    printf("\n");
}
