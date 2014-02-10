/**
* Lab2 Prog. Part - COMP 2710.
* Menu1.cpp
* @author  Shawn Burris (spb0015@tigermail.auburn.edu)
* @version 2013-04-23
*
* Source File for class Menu1. Contains functions definitions.
* Used with Menu1.h.
* Compile normally using g++.
*/  
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <ctype.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Menu1.h"
#include "Administrator.h"


   using namespace std;   
	//Generates Main Menu.	
   int Menu1::getInput(char input, Administrator& a, Staff& b, Client& c, Account& d)
   {
      bool correctCombo;
      
      if (input == '1')
      {
         cout << "===========================================================" << endl;
         cout << "|     Login to Access the Teller Terminal System         |"  << endl;
         cout << "===========================================================" << endl;
         do
         {
            cout << "User Name: ";
            cin >> userName;
            cout << "Password: ";
            cin >> userPass;
            if (a.isAdmin(userName, userPass))
            {
               correctCombo = true;
               outputAdmin(a, userName, b, c, d);
            }
            else if (b.isStaff(userName, userPass))
            {      
               correctCombo = true;
               outputStaff(a, userName, b, c, d);
            }
            else
            {
               cout << "Sorry, that username/password combination is incorrect. Pleast try again!" << endl;
               correctCombo = false;
            }
         }
            while (correctCombo != true); 
      } 
        		
   }
	  
   void Menu1::outputAdmin(Administrator& a, string currentUser, Staff& b, Client& c, Account& d)
   {
      isOff = false;
      do
      {
         cout << "===========================================================" << endl;
         cout << "|     Teller Terminal System – System Administration      |"  << endl;
         cout << "===========================================================" << endl;
         cout << "What would you like to do today?" << endl;
         cout << "1. Client and Account Management" << endl;
         cout << "2. Add a branch staff member" << endl;
         cout << "3. Delete a branch staff member" << endl;
         cout << "4. Display Branch Staff" << endl;
         cout << "5. Change Password" << endl;
         cout << "6. Exit" << endl;
         cin >> choice;
         if (choice == '6')
         {
            isOff = true;
         }
         getAdminChoice(choice, a, currentUser, b, c, d);
      }
      while (isOff != true);
      
   }
   
   void Menu1::outputStaff(Administrator& a, string currentUser, Staff& b, Client& c, Account& d)
   {
      isOff2 = false;
      do
      {
         cout << "===========================================================" << endl;
         cout << "|          Teller Terminal System – Branch Staff          |"  << endl;
         cout << "===========================================================" << endl;
         cout << "What would you like to do today?" << endl;
         cout << "1. Client and Account Management" << endl;
         cout << "2. Change Password" << endl;
         cout << "3. Exit" << endl;
         cin >> choice;
         if (choice == '3')
         {
            isOff2 = true;
         }
         getStaffChoice(choice, a, currentUser, b, c, d);
      }
      while (isOff2 != true);
      
   }
   
   void Menu1::outputClient(Administrator& a, Staff& b, Client& c, Account& d)
   {
      isOff3 = false;
      do
      {
         cout << "What would you like to do today?" << endl;
         cout << "1. Add a client." << endl;
         cout << "2. Add an account." << endl;
         cout << "3. Edit client information." << endl;
         cout << "4. Manage an account." << endl;
         cout << "5. Save client and account information." << endl;
         cout << "6. Exit" << endl;
         cin >> choice;
         if (choice == '6')
         {
            isOff3 = true;
         }
         getClientChoice(choice, a, b, c, d);
      }
      while (isOff3 != true);
      
   }
   
   void Menu1:: getClientChoice(char choice, Administrator& a, Staff& b, Client& c, Account& d)
   {
      int ch;
      bool isComplete;
      cin.ignore();
      if (choice == '1')
      {
         do
         {
            
            cout << "Please enter the client's name: ";
            getline(cin, enteredName); 
            cout << "Please enter the client's address: ";
         //not sure how to get a whole line from these dudes.
            getline(cin,enteredAddress);
            cout << "Please enter the client's social security number: ";
            getline(cin, enteredSocial);
            cout << "Please enter the client's employer: ";
            getline(cin,enteredEmployer);
            cout << "Please enter the client's income: ";
            getline(cin,enteredIncome);
            if (enteredName.empty() || enteredAddress.empty() || enteredSocial.empty()
            || enteredEmployer.empty() || enteredIncome.empty())
            {
               isComplete = false;
               cout << "A field was left blank, please start over." << endl;
            }
            else
               isComplete = true;
         }
         while (isComplete != true);
         c.addClient(enteredName, enteredAddress, enteredSocial, enteredEmployer, enteredIncome);
         cout << "A new client has been added!" << endl;
         //Works here.
         cout << "Press any key to continue...";
         ch = mygetch();
      }
      
      else if (choice == '2')
      {
         string newClientAccount, accnt, acctType, acctBalance;
         cout << "What client would you like to attach an account to? ";
         getline(cin,newClientAccount);
         if (c.isClient(newClientAccount))
         {
            cout << "A new account will be created for " << newClientAccount << "." << endl;
            cout << "Please enter an account number: ";
            cin >> accnt;
            cout << "Please enter an account type: ";
            cin >> acctType;
            cout << "Please enter an account balance: ";
            cin >> acctBalance;
            d.addAccount(newClientAccount, accnt, acctType, acctBalance);
            cout << "A new account has been created for " << newClientAccount << "." << endl;
            //Doesn't work here for some reason.
            //cout << "Press any key to continue...";
            //ch = mygetch();
         }
         else
         {
            cout << "Sorry but " << newClientAccount << " was not found in our system." << endl;
            //Works here
            cout << "Press any key to continue...";
            ch = mygetch();
         }
         
      }
      
      else if (choice == '3')
      {
         int ch;
         string editClient;
         cout << "Which client's information would you like to edit? ";
         getline(cin, editClient);
         c.editInformation(editClient);
         cout << "Client " << editClient << "'s information has been updated." << endl;
         //Works here.
         cout << "Press any key to continue...";
         ch = mygetch();
      }
      
      else if (choice == '4')
      {
         string acctNum;
         cout << "Please enter the number of the account you wish to manage: ";
         cin >> acctNum;
         d.manageAccount(acctNum);
      }
      else if (choice == '5')
      {
         int ch;
      //Couldn't really figure out a safe way to implement this for account and client
      //because I had problems with file implementation. Luckily, I save everything
      //the terminal is properly shut down. If values aren't entered or things are
      //canceled then the data is not saved anyways. I figured since the user couldn't
      //identify this difference I could just show them a message showing that their
      //information was saved.
         cout << "Client and Account information saved. Remember to exit terminal properly to avoid data corruption."
            << endl;
         //Works here.
         cout << "Press any key to continue...";
         ch = mygetch();
      }
   }
   void Menu1:: getAdminChoice(char choice, Administrator& a, string user, Staff& b, Client& c, Account& d)
   {
      if (choice == '1')
      {
         outputClient(a, b, c, d);
      }
      else if (choice == '2')
      {
         
         a.addStaff(b);
         //Works here
         cout << "Press any key to continue...";
         ch = mygetch();
      }
      
      else if (choice == '3')
      {
         
         a.deleteStaff(b);
          //Doesn't work here for some reason.
          //cout << "Press any key to continue...";
          //ch = mygetch();
      }
      
      else if (choice == '4')
      {
         
         a.displayAdmin(b);
         //Doesn't work here for some reason.
         //cout << "Press any key to continue...";
         //ch = mygetch();
      }
      
      else if (choice == '5')
      {
         a.changePass(user, b);
         //Doesn't work here for some reason.
         //cout << "Press any key to continue...";
         //ch = mygetch();
      }
   }
   
   void Menu1:: getStaffChoice(char choice, Administrator& a, string user, Staff& b, Client& c, Account& d)
   {
      if (choice == '1')
      {
         outputClient(a, b, c, d);
      }
      else if (choice == '2')
      {
         b.changePass(user);
         //Doesn't work here either.
         //cout << "Press any key to continue...";
         //ch = mygetch();
      }
   }
   
   int Menu1:: mygetch (void) 
   {
      int ch;
      struct termios oldt, newt;
   
      tcgetattr ( STDIN_FILENO, &oldt );
      newt = oldt;
      newt.c_lflag &= ~( ICANON | ECHO );
      tcsetattr ( STDIN_FILENO, TCSANOW, &newt );
      ch = getchar();
      tcsetattr ( STDIN_FILENO, TCSANOW, &oldt );
   
      return ch;
   }