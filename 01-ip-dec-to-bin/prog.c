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

  printf("Your IP in binary is: \n");
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      printf("%d ", ip[i][j]);
    }
    printf("\t");
  }
  printf("\n");

  return 0;
}