#include <stdio.h>
#include <stdbool.h>

void decimalToBinary(bool ip[], int num)
{
  for (int i = 7; i >= 0; i--)
  {
    ip[7 - i] = ((num >> i) & 1) == 1 ? true : false;
  }
}

int main()
{
  int o1, o2, o3, o4;
  printf("Enter your IPv4 address: ");
  scanf("%d.%d.%d.%d", &o1, &o2, &o3, &o4);

  bool ip[4][8];
  decimalToBinary(ip[0], o1);
  decimalToBinary(ip[1], o2);
  decimalToBinary(ip[2], o3);
  decimalToBinary(ip[3], o4);

  char class;
  if (ip[0][0] == 0)
  {
    class = 'A';
  }
  else if (ip[0][0] == 1 && ip[0][1] == 0)
  {
    class = 'B';
  }
  else if (ip[0][0] == 1 && ip[0][1] == 1 && ip[0][2] == 0)
  {
    class = 'C';
  }
  else if (ip[0][0] == 1 && ip[0][1] == 1 && ip[0][2] == 1 && ip[0][3] == 0)
  {
    class = 'D';
  }
  else
  {
    class = 'E';
  }
  printf("IP Class: %c\n", class);

  return 0;
}