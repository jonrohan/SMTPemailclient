# SMTPemailclient

### PURPOSE OF PROJECT:
To create a SMTP/POP3 email client in Visual C++

### DATE:
2005.03.28

### HOW TO START THIS PROJECT:
simply run the SMTPemailclient.exe

### Problem Description

Write a menu driven email client for the Windows platform using visual C++ that has only two menu options: File, Help. Implement three submenu options under File (send mail, view mail, and exit). Display a help-about under the Help option. Part-A below describes the requirement for send mail option and Part-B describes the view mail option. The option send mail composes and sends an email and the view mail option receives and displays list of emails received which can then be selected and viewed.

When invoked the program must ask for the user name and password as shown in the message box below. The server name can be specified in the command line or entered in the message box. The username and password are your username and password on the email server.

### PART A

Use SMTP (Simple Mail Transfer Protocol defined in RFC 821 dated August 1982 – can be found at the website of The Internet Engineering Task Force http://www.ietf.org/rfc/rfc0821.txt) to implement the send mail option. Allow the user to send an email to one or more specified email user(s) (email addresses separated by semicolon or comma – implement as depicted below). SMTP uses a well known TCP port 25. Once you have opened a channel at port 25 on the mail server (e.g., mail.westga.edu is the mail server in the UWG network) you can start a SMTP protocol transaction session to send commands to the server. The node wishes to send mail identifies itself by sending a HELO command. The format is HELO <SP> <domain mail server> <CRLF>. After identification of the sender node the transaction session begins. There are three steps to SMTP mail transactions. The transaction is started with a MAIL command which gives the sender identification. A series of one or more RCPT commands follows giving the receiver information. Then a DATA command gives the mail data. And finally, the end of mail data indicator confirms the transaction.

The format of the MAIL command is:
          MAIL <SP> FROM:<reverse-path> <CRLF>
The format of the RCPT (recipient) command is:
          RCPT <SP> TO:<forward-path> <CRLF>
The format of the DATA command is:
DATA <CRLF>
This command will follow the text of the email. Note here that the mail data includes the memo
header items such as Date, Subject, To, Cc, From, etc. The format for the memo headers are as
follows:
The mail data is terminated by a line containing only a period that is the character sequence "<CRLF>.<CRLF>". A QUIT command terminates the SMTP session. The format of the command is QUIT<CRLF>.
Here are some requirements for part A of the application:
1. Allow only one “From” address to be typed but more than one “To” addresses (recipient) can
be provided.
2. When more than one “To” addresses is provided they must be separated by semi-colon or
comma.
3. Once the send button is pressed after a valid email is composed, display a message box (ok button) with text “Email sent to the recipient address provided.” The user must click the ok button to continue.
4. After an email is sent erase the content and the email addresses and provide a blank form for the user to compose and send a new email message. User closes the window by choosing cancel button which will also allow the user to abandon an email from sending.
### PART B
1. Implement the receive option using POP3 (Post Office Protocol version-3 defined in RFC1939 dated May 1996 – can be found at the website of The Internet Engineering Task Force http://www.ietf.org/rfc/rfc1939.txt).
Here are some requirements for this application:
1. Implement as above, allow scrolling of the messages. Display only “From”, “Subject” and
“Received” (time of message receipt) columns (mail icon optional). Whenever a message bar
is clicked a window will display the message as in Microsoft Outlook.
2. Store the messages in a depository (e.g., a database or file system).
3. Implement a menu driven GUI where the “Inbox” display is just one of the menu options.
4. Use your imagination to provide any additional features (which will be considered as extra
credit – of course after implementing the minimum requirement.)
Submission Guidelines:
Please observe the submission guidelines given in the course outline and in the assignment sheet for programming assignment #1.

