///<summary>
///AUTHOR: Jon Rohan
///TITLE: SMTP/POP3 email client
///DATE: 3.29.2005
///PURPOSE: The purpose of this class is to handle all the smtp operations of the form
///</summary>
#include <winsock2.h>
#include <stdio.h>
#include "smtplib.h"

#define BUFFER_DEFAULT_SIZE 4096 //Set up the Buffer size

using namespace System;
using namespace System::Runtime;

SmtpMsg msg; //type_def struct that holds information about the message
TCPServer srv; //type_def struct that holds info about the server
SOCKET ssmtp; //this is the socket we will be connecting to

///<summary>
/// This function sends the email to the addresses that it is specified
///</summary>
bool sendSmtpMessage (String* addresses[])
{
	char outBuffer[BUFFER_DEFAULT_SIZE]; //the data buffer sent to the server
	char inBuffer[BUFFER_DEFAULT_SIZE]; //the data buffer recieved from the server
	char* CRLF = "\r\n"; //this is the standard CRLF that is sent to the server
	char* temp;
	String* sTemp;

	//HELO command session
	//Used to identify the sender-SMTP to the receiver-SMTP
	//The sender-SMTP establishes a two-way transmission channel to a receiver-SMTP
	strcpy (outBuffer, "HELO ");
	strcat (outBuffer, srv.address);
	strcat (outBuffer, CRLF);
	sendData (outBuffer, ssmtp, inBuffer);
	
	//MAIL command session
	//SMTP-sender sends a MAIL command indicating the sender of the mail.  
	//If the SMTP-receiver can accept mail it responds with an OK reply.
	strcpy (outBuffer, "MAIL FROM:");
	strcat (outBuffer, msg.FromAdd);
	strcat (outBuffer, CRLF);
	sendData (outBuffer, ssmtp, inBuffer);
	
	//RCPT command session
	//The SMTP-sender sends a RCPT command identifying a recipient of the mail.  
	//If the SMTP-receiver can accept mail for that recipient it responds with an OK reply
	for(int i = 0;i < addresses->Count; i++)
	{
		strcpy (outBuffer, "RCPT TO:");
		strcat (outBuffer, (char*)(void*)InteropServices::Marshal::StringToHGlobalAnsi(addresses[i]));
		strcat (outBuffer, CRLF);
		sendData (outBuffer, ssmtp, inBuffer);
	}

	//DATA command session
	//The SMTP-sender sends the mail data, terminating with a special sequence.  
	//If the SMTP-receiver successfully processes the mail data it responds with an OK reply.
	strcpy (outBuffer, "DATA ");
	strcat (outBuffer, CRLF);
	sendData (outBuffer, ssmtp, inBuffer);
	
	strcpy (outBuffer, "SUBJECT: ");
	strcat (outBuffer, msg.Subject);
	strcat (outBuffer, CRLF);
	strcat (outBuffer, msg.MsgBody);
	strcat (outBuffer, CRLF);
	strcat (outBuffer, ".");
	strcat (outBuffer, CRLF);
	sendData (outBuffer, ssmtp, inBuffer);
	recv (ssmtp, inBuffer, BUFFER_DEFAULT_SIZE, 0);
	temp = inBuffer;
	sTemp = static_cast<String*>(temp);
	if(sTemp->StartsWith(S"250"))
		return true;

	//End of SMTP message sending
    return false;
}

///<summary>
/// This function sets the SmtpServer type_def struct instance that was specified
/// at the login form. 
///</summary>
void setSmtpServerAddress(String* address, int port)
{
	srv.address = (char*)(void*)InteropServices::Marshal::StringToHGlobalAnsi(address);
	srv.port = port;
}///end setSmtpServerAddress(String* address, int port)

///<summary>
/// This function is used to close the socket to the server
///</summary>
void quit()
{
	char outBuffer[BUFFER_DEFAULT_SIZE]; //the data buffer sent to the server
	char inBuffer[BUFFER_DEFAULT_SIZE]; //the data buffer recieved from the server
	char* CRLF = "\r\n"; //this is the standard CRLF that is sent to the server
	
	// This block of text sends the "RETR 1" command to recieve the 
	// message number 1 from the server
	strcpy (outBuffer, "QUIT");
	strcat (outBuffer, CRLF);
	sendData (outBuffer, ssmtp, inBuffer);
	recv (ssmtp, inBuffer, BUFFER_DEFAULT_SIZE, 0);

	closeConn(ssmtp);
}///end quit()

///<summary>
/// This function connects to the smtp server using the address and port
/// specified at the login form
///</summary>
bool connectToSmtp()
{
	
	return initConn (srv.address, srv.port, &ssmtp);

}/// end void connectToSmtp()

///<summary>
/// This function sets up the message created in the new message form
///</summary>
void setSmtpMessage(String *from, String *subject, String *body)
{
	msg.FromAdd = (char*)(void*)InteropServices::Marshal::StringToHGlobalAnsi(from);
	msg.Subject = (char*)(void*)InteropServices::Marshal::StringToHGlobalAnsi(subject);
	msg.MsgBody = (char*)(void*)InteropServices::Marshal::StringToHGlobalAnsi(body);
}///end void setSmtpMessage(String* from, String* subject, String* body)

