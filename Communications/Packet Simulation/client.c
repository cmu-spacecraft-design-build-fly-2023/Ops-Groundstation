/**
 * client.c
 * 
 * Simple socket client from geeksforgeeks.org
 * Link -> https://www.geeksforgeeks.org/socket-programming-cc/
 * 
 * Purpose: Utilizing a simple socket client to simulate Cubesat 
 * message sending and receiving. 
 * 
 * Files edited by: D.J. Morvay (dmorvay@andrew.cmu.edu)
*/

/* Includes */
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdint.h>
#define PORT 8080

/**
 * main
 * 
 * Purpose: Main routine for client tasks.
 * Sets up a socket client to send and receive information from the server.
 * 
 * Inputs:
 *  argc
 *  argv[]
 * 
 * Return: NONE
 * 
 * Saved States: NONE
*/
int main(int argc, char const* argv[])
{
    /* Client configuration variables */
    int status, valread, client_fd;
    struct sockaddr_in serv_addr;

    /* Sent or received values */
    uint8_t send_num = 25;

    /* Create client socket */
    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }
  
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
  
    /* Convert IPv4 and IPv6 addresses from text to binary form */
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
  
    /* Connect client to the server */
    if ((status = connect(client_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)))< 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    send(client_fd, &send_num, sizeof(send_num), 0);
    printf("Initial number sent!\n");
    valread = recv(client_fd, &send_num, sizeof(send_num),0);
    printf("%u\n", send_num);
  
    /* closing the connected socket */
    close(client_fd);
    return 0;
}