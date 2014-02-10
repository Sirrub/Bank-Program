/**
* Lab2 Prog. Part - COMP 2710.
* Account.h
* @author  Shawn Burris (spb0015@tigermail.auburn.edu)
* @version 2013-04-23
*
* Header File for class Account. Contains variables and functions.
* Used with MainMenu.cpp.
* Compile normally using g++.
*/

#ifndef ACCOUNT
#define ACCOUNT
#include <string>
#include <fstream>
#include "Client.h"

   using namespace std;

   class Client;
   class Account
      {
      friend class Client;
      public:
      Client newClient;
      ofstream outputFile;
      void addAccount(string name, string number, string type, string balance);
      void writeBackToFileAccount();
      void manageAccount(string acctNum);
      void output();  
      private:
      vector<string> accountName;
      vector<string> accountNumber;
      vector<string> accountType;
      vector<string> accountBalance;
      string clientName;
      string number;
      string type;
      string balance;
      };
   
	#endif