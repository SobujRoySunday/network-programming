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
  int bind_stat = bind(server_sock, (struct sockaddr *)&serv_addr, serv_addr_size);
  if (bind_stat < 0)
  {
    printf("Error connecting to the remote socket\n\n");
    exit(0);
  }

  listen(server_sock, 5);

  while (1)
  {
    int client_sock = accept(server_sock, NULL, NULL);
    if (client_sock < 0)
    {
      continue;
    }

    int fork_stat = fork();
    if (fork_stat == 0)
    {
      close(server_sock);

      char recv_buffer[MAX];
      recv(client_sock, recv_buffer, sizeof(recv_buffer), 0);
      printf("Client: %s\n", recv_buffer);

      char buffer[] = "response from server";
      printf("Server: %s", buffer);
      send(client_sock, buffer, sizeof(buffer), 0);
    }
    else if (fork_stat < 0)
    {
      printf("Failed to create sub process to handle incoming request\n\n");
      close(client_sock);
    }
    else
    {
      close(client_sock);
    }
  }

  close(server_sock);
  return 0;
}