#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib,"ws2_32.lib ")
#include "winsock2.h"
#include "stdio.h"
#include "string.h"
void main(void)
{
 WSADATA wsaData;
 int ret=0;
 ret = WSAStartup(MAKEWORD(2,2),&wsaData);
 if (ret!=0)
 {
   printf("WSAStartup() ��������:%d \n",WSAGetLastError());
	  exit(-1);
 }
printf("������%s,״̬��%s \n",wsaData.szDescription,
	                   wsaData.szSystemStatus);
  char name[80];
  struct hostent * host;
  char ** temp;
  //strcpy(name,"www.sina.com.cn");

  //host = gethostbyname(NULL);//�൱�ڣ�gethostbyname("jnscomputer1");
//host = gethostbyname("www.sina.com.cn");
host = gethostbyname("jwc.njnu.edu.cn");
  if (host==NULL)
  {
	  printf("gethostbyname() ��������:%s ��Ӧ�������Ҳ����� \n",name);
	  WSACleanup();
	  exit(-1);
  }
  printf("��ʽ��������%s\n��ַ���ȣ�%d\n��ַ���ͣ�%d\n",
	  host->h_name,host->h_length,host->h_addrtype);
  printf("�����ı����б����£�\n");
  for (temp=host->h_aliases;*temp!=NULL;temp++)
  {
	  printf("%s\n",*temp);
  }
  printf("������IP�б����£�\n");
  for ( temp=host->h_addr_list;*temp!=NULL;temp++)
  {
	  printf("%s\n",inet_ntoa(*(struct in_addr *)(*temp)));
  }
  WSACleanup();
}
