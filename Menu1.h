/**
* Lab2 Prog. Part - COMP 2710.
* Menu1.h
* @author  Shawn Burris (spb0015@tigermail.auburn.edu)
* @version 2013-04-23
*
* Header File for class Menu1. Contains variables and functions.
* Used with Menu1.cpp.
* Compile normally using g++.
*/

#ifndef MENU1
#define MENU1
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <ctype.h>
#include <string>
#include "Administrator.h"
#include "Staff.h"
#include "Client.h"
#include "Account.h"


   using namespace std;
	
   class Administrator;
   class Staff;
   class Menu1
      {
      friend class Staff;
      friend class Client;
      friend class Administrator;
      friend class Account;
      public:   
      void firstMenu();
      int mygetch(void);
      int ch;
      void outputAdmin(Administrator& a, string user, Staff& b, Client& c, Account& d);
      void outputStaff(Administrator& a, string currentUser, Staff& b, Client& c, Account& d);
      void outputClient(Administrator& a, Staff& b, Client& c, Account& d);
      void adminChoice1();
      void getClientChoice(char choice, Administrator& a, Staff& b, Client& c, Account& d);
      void getAdminChoice(char choice, Administrator& a, string user, Staff& b, Client& c, Account& d);
      void getStaffChoice(char choice, Administrator& a, string user, Staff& b, Client& c, Account& d);
      int getInput(char input, Administrator& a, Staff& b, Client& c, Account& d);
      private:
      string userName;
      bool isOff, isOff2, isOff3;
      string userPass;
      string enteredName, enteredAddress, enteredSocial, enteredEmployer,enteredIncome;
      char choice;
      char input;
      };
   
	#endif
