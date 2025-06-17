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

char ipClass(bool binaryIP[][8])
{
  if (binaryIP[0][0] == 0)
  {
    return 'A';
  }
  else if (binaryIP[0][1] == 0)
  {
    return 'B';
  }
  else if (binaryIP[0][2] == 0)
  {
    return 'C';
  }
  else if (binaryIP[0][3] == 0)
  {
    return 'D';
  }
  return 'E';
}

int main()
{
  int decimalIP[4];
  bool binaryIP[4][8];

  printf("Enter your IPv4 address: ");
  scanf("%d.%d.%d.%d", &decimalIP[0], &decimalIP[1], &decimalIP[2], &decimalIP[3]);

  convertToBinary(decimalIP, binaryIP);

  printf("IP Class: %c\n", ipClass(binaryIP));

  return 0;
}