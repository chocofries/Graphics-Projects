/**************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand

(c) 2005 - 2018 Media Design School

File Name	:	socket.h
Description	:	Class for socketing operations
Author   	:	Zheng Yu Bu
mail		:	zheng.yu5315@mediadesign.school.nz
**************************************************/

#ifndef __SOCKET_H__
#define __SOCKET_H__

// Library Includes
#include <windows.h>
#include <string>


class Socket
{
public:
	// Default Constructors/Destructors
	Socket();
	~Socket();

	//This function call does the act of creating a socket and binding it to the supplied port number on the local machine.
	bool Initialise(unsigned short _usPortNumber);

	//Accessor methods
	SOCKET GetSocketHandle();

	//Additional Methods to enable broadcasting
	void SetRemotePort(unsigned short _usRemotePort);
	void SetRemoteAddress(unsigned long _ulRemoteAddress);

	//Question 7 : Broadcast to detect a server
	int EnableBroadcast();
	int DisableBroadcast();

private:
	//Get the local IP Address to which the socket is bound to
	std::string GetLocalAddress(); //Used for printing the local addrerss in the console window.
private:
	//A handle to as of yet unbound socket
	SOCKET handleSocket;
	//A sockaddr structure containing the local address and port to bind the socket to.
	sockaddr_in socketAddress;

	//Additional member variables : Details of the remote machine which is sending/receving data via this socket object.
	unsigned long remoteIPAddress;
	unsigned short remotePort;
};

#endif