 /**
* Lab 2 - Program Part - COMP 2710.
* spb0015_Lab2.cpp
* @author  Shawn Burris (spb0015@tigermail.auburn.edu)
* @version 2013-04-23
*
* Driver program for Lab 2.
* Put on desktop and runs fine.
* Created with jGrasp.
* Compile(+) then compile and link (++).
* Compile normally using g++.
*/ 

#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include "Menu1.h"
#include "Menu1.cpp"
#include "Client.h"
#include "Client.cpp"
#include "Administrator.h"
#include "Administrator.cpp"
#include "Staff.h"
#include "Staff.cpp"
#include "Account.h"
#include "Account.cpp"


   using namespace std;

   int main()
   {
      using namespace std;
      bool isOff = false;
      Account account;
      Menu1 firstMenu;
      Administrator admin;
      Client client;
      Staff staff;
      //take this one out when its ready to all be read from file.
   	
     
      std::ifstream infile("staffList.txt");
      string userName, userPass, isAdmin;
      while (infile >> userName >> userPass >> isAdmin)
      {
         if (isAdmin == "1")
            admin.addAdmin(userName, userPass);
         else
         {
            staff.tempAddStaff(userName, userPass);
         }
      }
      infile.close();
   	
   	
      std::ifstream infile2("client-info.txt");
      string clientName, clientAddress, clientSocial, clientEmployer, clientIncome;
      while (infile2)
      {
         getline(infile2,clientName);
         getline(infile2,clientAddress);
         getline(infile2,clientSocial);
         getline(infile2,clientEmployer);
         getline(infile2,clientIncome);
         if (!clientName.empty())
            client.addClient(clientName, clientAddress, clientSocial, clientEmployer, clientIncome);
      }
      infile2.close();
   	
      std::ifstream infile3("account-info.txt");
      string accountName, accountNumber, accountType, accountBalance;
      while (infile3)
      {
         getline(infile3,accountName);
         getline(infile3,accountNumber);
         getline(infile3,accountType);
         getline(infile3,accountBalance);
         if (!accountName.empty())
            account.addAccount(accountName, accountNumber, accountType, accountBalance);
      }
      infile3.close();
      
     
      
      do
      {
         char input;
         cout << "===========================================================" << endl;
         cout << "|     Welcome to the Auburn Branch of Tiger Bank!         |"  << endl;
         cout << "===========================================================" << endl;
         cout << "1) Login" << endl;
         cout << "2) Quit" << endl;
         cout << "	Please choose an option: ";
         cin >> input;
         if (input == '2')
         {
            isOff = true;
         }
         firstMenu.getInput(input, admin, staff, client, account);
      }
      while (isOff != true);
      
   	//TEST
      admin.writeBackToFileAdmin();
      staff.writeBackToFileStaff();
      client.writeBackToFileClient();
      account.writeBackToFileAccount();
      
   }
   
