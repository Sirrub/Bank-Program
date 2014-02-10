/**
* Lab2 Prog. Part - COMP 2710.
* Client.cpp
* @author  Shawn Burris (spb0015@tigermail.auburn.edu)
* @version 2013-04-23
*
* Source File for class Client. Contains functions definitions.
* Used with Client.h.
* Compile normally using g++.
*/  
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Client.h"

   using namespace std;   
	//Generates Main Menu.	
		
   void Client:: addClient(string name, string address, string social, string employer, string income)
   {
      clientName.push_back(name);
      clientAddress.push_back(address);
      clientSocial.push_back(social);
      clientEmployer.push_back(employer);
      clientIncome.push_back(income);
   }
   
   bool Client:: isClient(string name)
   {   
      for (int i = 0; i < clientName.size(); i++)
      {
         if (clientName.at(i) == name)
         {
            checkClient = true;
            return checkClient;
         }
      }
      checkClient = false;
      return checkClient;
   }
	
   void Client:: writeBackToFileClient()
   {
      outputFile.open("client-info.txt", std::fstream::trunc);
      //"file", std::fstream::out | std::fstream::trunc
      for (int i = 0; i < clientName.size(); i++)
      {
         outputFile << clientName.at(i) << endl
            << clientAddress.at(i) << endl
            << clientSocial.at(i) << endl 
            << clientEmployer.at(i) << endl
            << clientIncome.at(i) << endl;
      }
      outputFile.close();
   }
	
   void Client:: editInformation(string name)
   {
      bool inSystem;
      char choice;
      int placement;
      string updatedAddress, updatedSSN, updatedIncome, updatedEmployer;
      for (int i = 0; i < clientName.size(); i++)
      {
         if (clientName.at(i) == name)
         {
            placement = i;
            inSystem = true;
            break;
         }
         inSystem = false;
      }
      if (inSystem)
      {
         cout << "Display " << name << "'s information: " << endl;
         cout << "Address: " << clientAddress.at(placement) << endl;
         cout << "SSN: " << clientSocial.at(placement) << endl;
         cout << "Employer: " << clientEmployer.at(placement) << endl;
         cout << "Annual Income: " << clientIncome.at(placement) << endl;
         cout << "This information will be updated..." << endl;
         cout << "1) Confirm " << endl << "2) Cancel " << endl;
         cout << "Please choose an option: ";
         cin >> choice;
         cin.ignore();
         if (choice == '1')
         {
            cout << "Address: ";
            getline(cin, updatedAddress);
            cout << "SSN: ";
            getline(cin, updatedSSN);
            cout << "Employer: ";
            getline(cin, updatedEmployer);
            cout << "Annual Income: ";
            getline(cin, updatedIncome);
            if (!updatedAddress.empty())
            {
               clientAddress.at(placement) = updatedAddress;
            }
            if (!updatedSSN.empty())
            {
               clientSocial.at(placement) = updatedSSN;
            }
            if (!updatedEmployer.empty())
            {
               clientEmployer.at(placement) = updatedEmployer;
            }
            if (!updatedIncome.empty())
            {
               clientIncome.at(placement) = updatedIncome;
            }
         }
         
      }
      
      
      
      
      else
         cout << "Client does not exist in our system!" << endl;
   
   
   }