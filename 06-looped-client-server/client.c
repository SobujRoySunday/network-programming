#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define MAX 256
#define PORT 8001

int main()
{
  int server_sock = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in sock_addr;
  sock_addr.sin_family = AF_INET;
  sock_addr.sin_port = htons(PORT);
  sock_addr.sin_addr.s_addr = INADDR_ANY;

  int conn_stat = connect(server_sock, (struct sockaddr *)&sock_addr, sizeof(sock_addr));
  if (conn_stat < 0)
  {
    printf("Error connecting to remote socket\n\n");
    exit(0);
  }

  char send_buffer[MAX], recv_buffer[MAX];
  while (1)
  {
    // Receive message
    recv(server_sock, recv_buffer, sizeof(recv_buffer), 0);
    printf("Server: %s\n", recv_buffer);

    // Compose message
    printf("Client: ");
    int n = 0;
    char temp;
    while ((temp = getchar()) != '\n')
      send_buffer[n++] = temp;
    send_buffer[n] = '\0';
    if (strncmp("exit", send_buffer, 4) == 0)
    {
      printf("Client closing.\n");
      break;
    }
    // Send message
    send(server_sock, send_buffer, sizeof(send_buffer), 0);

    strcpy(send_buffer, "");
    strcpy(recv_buffer, "");
  }

  close(server_sock);
  return 0;
}