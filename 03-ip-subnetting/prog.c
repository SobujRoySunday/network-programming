#include <stdio.h>
#include <stdbool.h>

void decimalToBinary(bool ip[], int num)
{
  for (int i = 7; i >= 0; i--)
  {
    ip[7 - i] = ((num >> i) & 1) == 1 ? true : false;
  }
}

void convertToBinary(bool ip[][8], int o1, int o2, int o3, int o4)
{
  decimalToBinary(ip[0], o1);
  decimalToBinary(ip[1], o2);
  decimalToBinary(ip[2], o3);
  decimalToBinary(ip[3], o4);
}

char detectClass(bool ip[][8])
{
  if (ip[0][0] == 0)
  {
    return 'A';
  }
  else if (ip[0][0] == 1 && ip[0][1] == 0)
  {
    return 'B';
  }
  else if (ip[0][0] == 1 && ip[0][1] == 1 && ip[0][2] == 0)
  {
    return 'C';
  }
  else if (ip[0][0] == 1 && ip[0][1] == 1 && ip[0][2] == 1 && ip[0][3] == 0)
  {
    return 'D';
  }
  else
  {
    return 'E';
  }
}

void printIpBinaryToDecimal(bool ip[][8])
{
  int decIp[4];
  for (int i = 0; i < 4; i++)
  {
    int temp = 0;
    for (int j = 0; j < 8; j++)
    {
      int bin = ip[i][j] ? 1 : 0;
      temp += (bin << (7 - j));
    }
    decIp[i] = temp;
  }

  printf("%d.%d.%d.%d\n", decIp[0], decIp[1], decIp[2], decIp[3]);
}

int main()
{
  int o1, o2, o3, o4, cidr, num_net, num_host;
  bool ip[4][8], subnet_mask[4][8], network_addr[4][8], broadcast_addr[4][8];
  char class;

  printf("Enter your IPv4 address: ");
  scanf("%d.%d.%d.%d/%d", &o1, &o2, &o3, &o4, &cidr);

  convertToBinary(ip, o1, o2, o3, o4);
  class = detectClass(ip);

  num_net = (1 << cidr);
  num_host = (1 << (32 - cidr)) - 2;

  // Generating subnet mask
  int count = 0;
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      if (count < cidr)
      {
        subnet_mask[i][j] = true;
      }
      else
      {
        subnet_mask[i][j] = false;
      }
      count++;
    }
  }

  // Generating addresses
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      network_addr[i][j] = ip[i][j] & subnet_mask[i][j];
      broadcast_addr[i][j] = ip[i][j] | (!subnet_mask[i][j]);
    }
  }

  // printing results
  printf("\nNumber of networks: %d\n", num_net);
  printf("Number of hosts: %d\n\n", num_host);

  printf("Subnet mask: ");
  printIpBinaryToDecimal(subnet_mask);
  printf("Network address: ");
  printIpBinaryToDecimal(network_addr);
  printf("Broadcast address: ");
  printIpBinaryToDecimal(broadcast_addr);

  return 0;
}