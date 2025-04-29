#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX 256

int main()
{
  int server_sock = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in serv_addr;
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(PORT);

  socklen_t serv_addr_size = sizeof(serv_addr);
  int conn_stat = connect(server_sock, (struct sockaddr *)&serv_addr, serv_addr_size);
  if (conn_stat < 0)
  {
    printf("Error connecting to the remote socket\n\n");
    exit(0);
  }

  printf("Client: ");
  int n = 0;
  char buffer[MAX], temp;
  while ((temp = getchar()) != '\n')
    buffer[n++] = temp;
  buffer[n] = '\0';
  send(server_sock, buffer, sizeof(buffer), 0);

  char recv_buffer[MAX];
  recv(server_sock, recv_buffer, sizeof(recv_buffer), 0);
  printf("Server: %s\n", recv_buffer);

  close(server_sock);
  return 0;
}