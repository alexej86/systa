#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#include "udp.hpp"

static int sockfd;
static char buffer[BUFFER_SIZE];
static struct sockaddr_in server_addr, client_addr;

int udp_create()
{
   // create a UDP-Socket
   sockfd = socket(AF_INET, SOCK_DGRAM, 0);
   if (sockfd == -1) {
      perror("Error creating socket");
      exit(EXIT_FAILURE);
   }

   // set the socket address
   memset(&server_addr, 0, sizeof(server_addr));
   server_addr.sin_family = AF_INET;
   server_addr.sin_addr.s_addr = INADDR_ANY;
   server_addr.sin_port = htons(PORT);

   // bind the socket to the address
   if (bind(sockfd, (const struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
      perror("Error binding socket");
      close(sockfd);
      exit(EXIT_FAILURE);
   }

   printf("Wait for messages on port %d...\n", PORT);
   return 0;
}

int udp_receive(Clbk my_clbk)
{

   // wait for new message
   socklen_t client_len = sizeof(client_addr);
   ssize_t recv_size = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&client_addr, &client_len);

   if (recv_size == -1) {
      perror("Error in receiving message");
      close(sockfd);
      exit(EXIT_FAILURE);
   }

   // announce the message
   ssize_t bytes_to_send = my_clbk(buffer, recv_size);
   if (bytes_to_send > 0)
   {
      // send response if necessary
      ssize_t send_size = sendto(sockfd, buffer, bytes_to_send, 0, (const struct sockaddr*)&client_addr, client_len);

      if (send_size == -1) {
         perror("Error in sending answer");
         close(sockfd);
         exit(EXIT_FAILURE);
      }
   }

   return 0;
}

int udp_close()
{
   // clean up
   close(sockfd);
   return 0;
}
