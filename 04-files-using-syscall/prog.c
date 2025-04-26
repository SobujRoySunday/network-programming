#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
  char text[] = "Hello world\n";
  char buffer[256];

  int fd = open("text.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
  write(fd, text, sizeof(text) - 1);
  printf("File written successfully. Open text.txt to view the data\n\n");
  close(fd);

  fd = open("text.txt", O_RDONLY);
  int n = read(fd, buffer, sizeof(buffer) - 1);
  buffer[n] = '\0';
  printf("File read. The data is: %s\n", buffer);
  close(fd);

  return 0;
}