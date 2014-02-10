/**
* Lab2 Prog. Part - COMP 2710.
* Client.h
* @author  Shawn Burris (spb0015@tigermail.auburn.edu)
* @version 2013-04-23
*
* Header File for class Client. Contains variables and functions.
* Used with Client.cpp.
* Compile normally using g++.
*/

#ifndef CLIENT
#define CLIENT
#include <string>
#include <vector>
#include <fstream>

   using namespace std;

   
   class Client
   {
   public:
      ofstream outputFile;
      void addClient(string name, string address, string social, string employer, string income);
      bool isClient(string name);
      void writeBackToFileClient();
		void editInformation(string name);
      vector<string> clientName;
      vector<string> clientAddress;
      vector<string> clientSocial;
      vector<string> clientEmployer;
      vector<string> clientIncome;
       private:
      bool checkClient;
   //could possibly make it a vector of clients.
      string name;
      string address;
      string socialSecurity;
      string income;
      string employer;
   };
   
	#endif
