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
  int server_fd = socket(AF_INET, SOCK_DGRAM, 0);

  struct sockaddr_in server_addr, client_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  server_addr.sin_port = htons(PORT);

  int binding_stat = bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (binding_stat < 0)
  {
    printf("Port binding failed.\n\n");
    exit(0);
  }

  char send_buffer[MAX], recv_buffer[MAX];
  while (1)
  {
    // Receive message
    socklen_t client_len = sizeof(client_addr);
    recvfrom(server_fd, recv_buffer, sizeof(recv_buffer), 0, (struct sockaddr *)&client_addr, &client_len);
    printf("Client: %s\n", recv_buffer);

    // Compose message
    printf("Server: ");
    int n = 0;
    char temp;
    while ((temp = getchar()) != '\n')
      send_buffer[n++] = temp;
    send_buffer[n] = '\0';
    if (strncmp("exit", send_buffer, 4) == 0)
    {
      printf("Server closing.\n");
      break;
    }
    // Send message
    sendto(server_fd, send_buffer, sizeof(send_buffer), 0, (const struct sockaddr *)&client_addr, sizeof(client_addr));

    strcpy(send_buffer, "");
    strcpy(recv_buffer, "");
  }

  close(server_fd);
  return 0;
}