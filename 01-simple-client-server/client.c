#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
  // Creating the socket
  int server_fd = socket(AF_INET, SOCK_STREAM, 0);

  // Defining server socket address
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(9001);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  // Connecting to the server
  int connect_stat = connect(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
  // checking if connection to the server was failed
  if (connect_stat < 0)
  {
    printf("Failed to connect to the remote socket\n\n");
    exit(0);
  }

  // receive data from remote socket
  char buffer[256];
  int n = recv(server_fd, &buffer, sizeof(buffer), 0);
  buffer[n] = '\0';
  printf("Server response: %s\n\n", buffer);

  // close the socket
  close(server_fd);
  return 0;
}