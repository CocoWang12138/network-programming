#pragma comment(lib,"ws2_32.lib ")

#include "winsock2.h"
#include "stdio.h"

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd)
{
  WSADATA wsaData;
  
  int r = WSAStartup
	  (MAKEWORD(2,2),
	  &wsaData);
  if( r != 0 )
  {
    char err[80];
	sprintf_s(err,"Winsock2 װ�س�����!����ţ�%d ",WSAGetLastError());
    MessageBox(NULL,err,"Winsock2����",0);	
	return -1;
  }//if
  
  if ( LOBYTE( wsaData.wVersion ) != 2 ||
        HIBYTE( wsaData.wVersion ) != 2 ) 
  {
   
    MessageBox(NULL,"Winsock2 װ�صİ汾���ԣ�","Winsock2����",0);
    WSACleanup();                           
    return -1;
  }//if
 
   char data[80];
   sprintf_s(data,"WSAStartup װ�سɹ�!\n�汾�ǣ�%d.%d \n������%s\n״̬��%s\n ",
	   HIBYTE( wsaData.wVersion ),LOBYTE( wsaData.wVersion ),
	   wsaData.szDescription,wsaData.szSystemStatus);
   MessageBox(NULL,data,"WSAStartup",0);
   WSACleanup();  
   return 0;
}//winmain

