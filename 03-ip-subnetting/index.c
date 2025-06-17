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

void generateSubnetMask(bool subnetMask[][8], int cidr)
{
  int count = 0;
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      if (count < cidr)
      {
        subnetMask[i][j] = true;
      }
      else
      {
        subnetMask[i][j] = false;
      }
      count++;
    }
  }
}

void generateNetworkAddress(bool networkAddr[][8], bool subnetMask[][8], bool binaryIP[][8])
{
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      networkAddr[i][j] = binaryIP[i][j] & subnetMask[i][j];
    }
  }
}

void generateBroadcastAddress(bool broadcastAddr[][8], bool subnetMask[][8], bool binaryIP[][8])
{
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      broadcastAddr[i][j] = binaryIP[i][j] | (!subnetMask[i][j]);
    }
  }
}

int binaryToDecimal(bool oct[])
{
  int temp = 0;
  for (int i = 0; i < 8; i++)
  {
    int bin = oct[i] ? 1 : 0;
    temp += (bin << (7 - i));
  }
  return temp;
}

void printIpBinaryToDecimal(bool binaryIP[][8])
{
  int decimalIP[4];
  for (int i = 0; i < 4; i++)
  {
    decimalIP[i] = binaryToDecimal(binaryIP[i]);
  }
  printf("%d.%d.%d.%d\n", decimalIP[0], decimalIP[1], decimalIP[2], decimalIP[3]);
}

int main()
{
  int decimalIP[4];
  int cidr, num_net, num_host;
  bool binaryIP[4][8], subnetMask[4][8], networkAddr[4][8], broadcastAddr[4][8];
  char class;

  printf("Enter your IPv4 address: ");
  scanf("%d.%d.%d.%d/%d", &decimalIP[0], &decimalIP[1], &decimalIP[2], &decimalIP[3], &cidr);

  convertToBinary(decimalIP, binaryIP);
  generateSubnetMask(subnetMask, cidr);
  generateNetworkAddress(networkAddr, subnetMask, binaryIP);
  generateBroadcastAddress(broadcastAddr, subnetMask, binaryIP);

  class = ipClass(binaryIP);
  num_net = (1 << cidr);
  num_host = (1 << (32 - cidr)) - 2;

  printf("\nNumber of networks: %d\n", num_net);
  printf("Number of hosts: %d\n", num_host);
  printf("Subnet mask: ");
  printIpBinaryToDecimal(subnetMask);
  printf("Network address: ");
  printIpBinaryToDecimal(networkAddr);
  printf("Broadcast address: ");
  printIpBinaryToDecimal(broadcastAddr);

  return 0;
}