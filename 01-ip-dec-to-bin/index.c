#include <stdio.h>
#include <stdbool.h>

void decimalToBinary(bool ip[], int num)
{
  for (int i = 7; i >= 0; i--)
  {
    ip[7 - i] = ((num >> i) & 1) == 1 ? true : false;
  }
}

void convertToBinary(int decimalIP[], bool binaryIP[][8])
{
  for (int i = 0; i < 4; i++)
  {
    decimalToBinary(binaryIP[i], decimalIP[i]);
  }
}

int main()
{
  int decimalIP[4];
  bool binaryIP[4][8];

  printf("Enter your IPv4 address: ");
  scanf("%d.%d.%d.%d", &decimalIP[0], &decimalIP[1], &decimalIP[2], &decimalIP[3]);

  convertToBinary(decimalIP, binaryIP);

  printf("Your IP in binary is:\t");
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      printf("%d ", binaryIP[i][j]);
    }
    printf("\t");
  }
  printf("\n\n");

  return 0;
}