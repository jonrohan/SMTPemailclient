///<summary>
///AUTHOR: Jon Rohan
///TITLE: SMTP/POP3 email client
///DATE: 3.29.2005
///PURPOSE: The purpose of this class is to handle all the pop3 operations of the form
///</summary>
#include <winsock2.h>
#include <stdio.h>
#include "pop3lib.h"

#define BUFFER_DEFAULT_SIZE 4096 //Set up the Buffer size

using namespace System;
using namespace System::Runtime;

Pop3Msg pMsg; //type_def struct that holds information about the message 
Pop3Server pSrv; //type_def struct that holds info about the server
Pop3User pUsr; //type_def struct that holds info about the user
SOCKET ppop3; //this is the socket we will be connecting to

char szPop3Buffer[BUFFER_DEFAULT_SIZE]; //Buffer to get response from server

///<summary>
/// This function sets the Pop3Server type_def struct instance that was specified
/// at the login form. 
///</summary>
void setPop3ServerAddress(String *address, int port)
{

	pSrv.address = (char*)(void*)InteropServices::Marshal::StringToHGlobalAnsi(address);
	pSrv.port = port;

} ///end void setPop3ServerAddress(String* address, int port)

///<summary>
/// This function logs in the user to the pop3 server specified in the 
/// login form.
///</summary>
String* loginToPop3Server()
{
	char outBuffer[BUFFER_DEFAULT_SIZE]; //the data buffer sent to the server
	char inBuffer[BUFFER_DEFAULT_SIZE]; //the data buffer recieved from the server
	char* CRLF = "\r\n"; //this is the standard CRLF that is sent to the server

	initPop3Conn (pSrv.address, pSrv.port, &ppop3); //this creates the ppop3 socket & a connection to the server
	
	// This block creats the "USER <username>" string and then sends it to
	// the server.
	strcpy (outBuffer, "USER ");
	strcat (outBuffer, pUsr.username);
	strcat (outBuffer, CRLF);
	sendPop3Data (outBuffer, ppop3, inBuffer);

	// This block creats the "PASS <password>" string and then sends it to
	// the server.
	strcpy (outBuffer, "PASS ");
	strcat (outBuffer, pUsr.password);
	strcat (outBuffer, CRLF);
	sendPop3Data (outBuffer, ppop3, inBuffer);
	
	// If the login was successful the server will send back "+OK ..."
	// this line retreives that information.
	recv(ppop3, inBuffer, BUFFER_DEFAULT_SIZE, 0);

	return static_cast<String*>(inBuffer); // return server response
	
} ///end String* loginToPop3Server()

///<summary>
/// This function gets the STAT from the server specifing the number
/// of new messages on the server.
///</summary>
int getNumberOfNewItems()
{
	int count; //number of new messages
	char* line; //
	char outBuffer[BUFFER_DEFAULT_SIZE]; //the data buffer sent to the server
	char inBuffer[BUFFER_DEFAULT_SIZE]; //the data buffer recieved from the server
	char* CRLF = "\r\n"; //this is the standard CRLF that is sent to the server

	// This block creats the "STAT" string and then sends it to
	// the server. Then it retrieves the number of new messages
	// and changes it to an int.
	strcpy (outBuffer, "STAT ");
	strcat (outBuffer, CRLF);
	sendPop3Data (outBuffer, ppop3, inBuffer);
	line = inBuffer;
	line = strtok(line,"+OK ");
	count = atoi(line);
	return count;
} ///end int getNumberOfNewItems()


///<summary>
/// This function is used to set the user info for the pop3 server.
///</summary>
void setUserInfo(String* username, String* password)
{

	pUsr.username = (char*)(void*)InteropServices::Marshal::StringToHGlobalAnsi(username);
	pUsr.password = (char*)(void*)InteropServices::Marshal::StringToHGlobalAnsi(password);
	
}/// end void setUserInfo(String* username, String* password)

///<summary>
/// This function gets the message number n from the server
/// and parses the useful information. It also determines if 
/// the message can be read by my form.
///</summary>
String* getPop3Message(int messageNumber_int)
{
	char outBuffer[BUFFER_DEFAULT_SIZE] = ""; //the data buffer sent to the server
	char inBuffer[BUFFER_DEFAULT_SIZE] = ""; //the data buffer recieved from the server
	char* CRLF = "\r\n"; //this is the standard CRLF that is sent to the server
	char messageNumber_char[100]; //this is used to hold the char value of the message number
	char* temp;
	String* sTemp, *sTemp2;
	String* delimStr = S"\r\n";
	Char delimiter[] = delimStr->ToCharArray();
			
	sprintf(messageNumber_char, "%i", messageNumber_int); //this command turns the messageNumber_int into a char
	
	// This block of text sends the "RETR 1" command to recieve the 
	// message number 1 from the server
	strcpy (outBuffer, "TOP ");
	strcat (outBuffer, messageNumber_char);
	strcat (outBuffer, " 50");
	strcat (outBuffer, CRLF);
	sendPop3Data (outBuffer, ppop3, inBuffer);
	//recv (ppop3, inBuffer, BUFFER_DEFAULT_SIZE, 0);

	temp = inBuffer;
	sTemp = static_cast<String*>(temp);
	sTemp2 = sTemp;

	// this line error checks to make sure that our messages contains the correct fields
	if(sTemp->IndexOf(S"From: ")==-1||sTemp->IndexOf(S"Subject: ")==-1||sTemp->IndexOf(S"Date: ")==-1)
		return S"Invalid email";

	// collect the date information
	sTemp = sTemp2->Remove(0,sTemp2->IndexOf(S"Date: "));
	pMsg.date = (char*)(void*)InteropServices::Marshal::StringToHGlobalAnsi(sTemp->Substring(6,sTemp->IndexOf(S"\r\n")-6));
	sTemp = sTemp->Remove(0,sTemp->IndexOf(S"\r\n"));
	
	// collect the from address information
	sTemp = sTemp2->Remove(0,sTemp2->IndexOf(S"From: "));
	pMsg.FromAdd = (char*)(void*)InteropServices::Marshal::StringToHGlobalAnsi(sTemp->Substring(6,sTemp->IndexOf(S"\r\n")-6));
	sTemp = sTemp->Remove(0,sTemp->IndexOf(S"\r\n"));

	// collect the subject information
	sTemp = sTemp2->Remove(0,sTemp2->IndexOf(S"Subject: "));
	pMsg.Subject = (char*)(void*)InteropServices::Marshal::StringToHGlobalAnsi(sTemp->Substring(9,sTemp->IndexOf(S"\r\n")-9));
	sTemp = sTemp->Remove(0,sTemp->IndexOf(S"\r\n"));
	
	// collect the body of the text (unformated)
	sTemp = sTemp->Remove(0,sTemp->IndexOf(S"\r\n\r\n")+4);
	pMsg.MsgBody = (char*)(void*)InteropServices::Marshal::StringToHGlobalAnsi(sTemp);

	// I use this to concat the four fields into one string to 
	// send it back to the mainEmailForm. This was the 
	// easiest way I could think of
	String* str1 = static_cast<String*>(pMsg.FromAdd);
	String* str2 = static_cast<String*>(pMsg.date);
	String* str3 = static_cast<String*>(pMsg.Subject);
	String* str4 = static_cast<String*>(pMsg.MsgBody);
	
	str1 = str1->Concat(str1,S"|",str2,S"|");
	str1 = str1->Concat(str1,str3,S"|");
	str1 = str1->Concat(str1,str4);

	return str1;
}///end String* getPop3Message(int messageNumber_int);

///<summary>
/// This function is used to close the socket to the server
///</summary>
void closePop3()
{
	char outBuffer[BUFFER_DEFAULT_SIZE]; //the data buffer sent to the server
	char inBuffer[BUFFER_DEFAULT_SIZE]; //the data buffer recieved from the server
	char* CRLF = "\r\n"; //this is the standard CRLF that is sent to the server
	
	// This block of text sends the "RETR 1" command to recieve the 
	// message number 1 from the server
	strcpy (outBuffer, "QUIT");
	strcat (outBuffer, CRLF);
	sendPop3Data (outBuffer, ppop3, inBuffer);
	recv (ppop3, inBuffer, BUFFER_DEFAULT_SIZE, 0);

	closePop3Conn(ppop3);

}///end void closePop3()
