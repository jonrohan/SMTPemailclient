
#include <windows.h>
#include <stdlib.h>
#include <winsock2.h>

#define BUFFER_DEFAULT_SIZE 4096

typedef struct
{
	char* date;
	char* FromAdd;
	char* Subject;
	char* MsgBody;

}Pop3Msg;

typedef struct
{
	char* address;
	int port;

}Pop3Server;

typedef struct
{
	char* username;
	char* password;

}Pop3User;

bool initPop3Conn (char* address, int port, SOCKET* sock2use)
{
	//The InitConnToSmtpServer() is used to create socket of ssmtp and create a connection to the SMTP server also.
	
	WSADATA wsdata;
	struct sockaddr_in server;
	struct hostent *host=NULL;

	if (WSAStartup(MAKEWORD (2,2), &wsdata) !=0)
	{
		printf("Failed when loading Winsock library!");
		return false;
	}

	*sock2use = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (*sock2use == INVALID_SOCKET)
	{
		printf("socket() failed with error: " + WSAGetLastError());
		return false;
	}

	server.sin_family = AF_INET;
	server.sin_port = htons(port);
	server.sin_addr.s_addr = inet_addr(address);

	if (server.sin_addr.s_addr == INADDR_NONE)
	{
		host = gethostbyname(address);
		if (host == NULL)
		{
			printf("Server name cannot be resolved!");
			return false;
		}
		CopyMemory (&server.sin_addr, host->h_addr_list[0], host->h_length);
	}

	if (connect(*sock2use, (struct sockaddr *) &server, sizeof(server)) == SOCKET_ERROR)
	{
		printf("Error connecting to server: " + WSAGetLastError());
		return false;
	}
    
	printf("Connection to server is now OK");

	
	return true;
}

bool sendPop3Data (const char* msg, SOCKET sockInUse, char* rcvBuff)
{
	const char* MSG;
	int ret;

	ZeroMemory (rcvBuff, BUFFER_DEFAULT_SIZE);
	MSG = msg;

	size_t msgLength;
	msgLength = strlen(MSG);

	send (sockInUse, MSG, msgLength, 0);
    ret = recv (sockInUse, rcvBuff, BUFFER_DEFAULT_SIZE, 0);

	if (ret != 0)
		if (ret == SOCKET_ERROR)
			printf("Connection to SMTP server is now OK" + WSAGetLastError());

    return true;
}

bool closePop3Conn(SOCKET socket2end)
{
	closesocket (socket2end);
	WSACleanup();

	printf("Socket closed!");
	return true;
}