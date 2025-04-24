#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
  // composing the server response
  char server_res[] = "You are connected with the remote socket";

  // creating the socket
  int server_fd = socket(AF_INET, SOCK_STREAM, 0);

  // defining socket addr
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(9001);

  // binding the port with the socket
  int binding_stat = bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (binding_stat < 0)
  {
    printf("Port binding failed.\n\n");
    exit(0);
  }

  // listen
  listen(server_fd, 5);

  // accept the client socket
  int client_fd = accept(server_fd, NULL, NULL);
  printf("Client connected.\n\n");

  // send the message
  send(client_fd, server_res, sizeof(server_res), 0);

  // close the socket
  close(server_fd);
  return 0;
}