/**
* Lab2 Prog. Part - COMP 2710.
* Account.cpp
* @author  Shawn Burris (spb0015@tigermail.auburn.edu)
* @version 2013-04-23
*
* Source File for class Account. Contains functions definitions.
* Used with Account.h.
* Compile normally using g++.
*/  
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Account.h"
#include "Client.h"

   using namespace std;   
	//Generates Main Menu.	
	
	
   void Account:: addAccount(string name, string number, string type, string balance)
   {
      accountName.push_back(name);
      accountNumber.push_back(number);
      accountType.push_back(type);
      accountBalance.push_back(balance);
   }
   
   void Account:: writeBackToFileAccount()
   {
      outputFile.open("account-info.txt", std::fstream::trunc);
      for (int i = 0; i < accountName.size(); i++)
      {
         outputFile << accountName.at(i) << endl
            << accountNumber.at(i) << endl
            << accountType.at(i) << endl
            << accountBalance.at(i) << endl;
      }
      outputFile.close();
   }
   
   void Account:: manageAccount(string acctNum)
   {
      bool inSystem;
      bool isCancel = false;
      char choice;
      int placement;
      int accountBal;
      string accountBal2;
      for (int i = 0; i < accountNumber.size(); i++)
      {
         if (accountNumber.at(i) == acctNum)
         {
            placement = i;
            accountBal2 = accountBalance.at(placement);
            inSystem = true;
            stringstream convert(accountBal2);
            convert >> accountBal;
            break;
         }
         inSystem = false;
      }
      
   	
      if (inSystem)
      {
         stringstream convert;
         int sub, add;
         do
         {
            cout << "Manage Account " << accountNumber.at(placement) << " for " << accountName.at(placement) << "..." << endl;
            cout << "1) Deposit" << endl << "2) Withdraw" << endl << "3) Cancel" << endl;
            cout << "Please choose an option: "; 
            cin  >> choice;
         
            if (choice == '1')
            {
               cout << "Deposit Amount: ";
               cin >> add;
               accountBal = accountBal + add;
               convert << accountBal;
               accountBal2 = convert.str();
               accountBalance.at(placement) = accountBal2;
               cout << "Balance of account is $" << accountBalance.at(placement) << "."<< endl;
               convert.str("");
            }
            else if (choice == '2')
            {
               cout << "Withdraw Amount: ";
               cin >> sub;
               accountBal = accountBal - sub;
               convert << accountBal;
               accountBal2 = convert.str();
               accountBalance.at(placement) = accountBal2;
               cout << "Balance of account is $" << accountBalance.at(placement) << "."<< endl;
               convert.str("");
            }
            else
            {
               isCancel = true;
            }
         }
         
         while (isCancel != true);
      }
      else
         cout << "Account " << acctNum << " is not in the system!" << endl;
   }