/**
* Lab2 Prog. Part - COMP 2710.
* Staff.cpp
* @author  Shawn Burris (spb0015@tigermail.auburn.edu)
* @version 2013-04-23
*
* Source File for class Staff. Contains functions definitions.
* Used with Staff.h.
* Compile normally using g++.
*/  
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Staff.h"

   using namespace std;   
	//Generates Main Menu.	
	
   bool Staff:: isStaff(string staff, string password)
   {   
      for (int i = 0; i < staffN.size(); i++)
      {
         if (staffN.at(i) == staff && staffP.at(i) == password)
         {
            checkStaff = true;
            return checkStaff;
         }
      }
      checkStaff = false;
      return checkStaff;
   }
   
   bool Staff:: isStaff(string staff)
   {   
      for (int i = 0; i < staffN.size(); i++)
      {
         if (staffN.at(i) == staff)
         {
            checkStaff = true;
            return checkStaff;
         }
      }
      checkStaff = false;
      return checkStaff;
   }
   
   void Staff:: tempAddStaff(string a, string b)
   {
      staffN.push_back(a);
      staffP.push_back(b);
   }
	
   bool Staff:: deleteStaff(string user)
   {
      for (int i = 0; i < staffN.size(); i++)
      {
         if (staffN.at(i) == user)
         {
            staffN.erase(staffN.begin() + i);
            staffP.erase(staffP.begin() + i);
            cout << "User " << user << " has been deleted from the system." << endl;
            return true;
         }
      }
      cout << "Warning - User " << user << " is not in the system. No user is deleted!" << endl;
      return false;
   }
   
   void Staff:: writeBackToFileStaff()
   {
      outputFile.open("staffList.txt", ios::app);
      for (int i = 0; i < staffN.size(); i++)
      {
         outputFile << staffN.at(i) << " " << staffP.at(i) << " 0 " << "\n";
      }
      outputFile.close();
   }
   
   void Staff:: changePass(string user)
   {
      int USERID;
      string USERPASS, confirmPass;
      for (int i = 0; i < staffN.size(); i++)
      {
         if (staffN.at(i) == user)
         {
            USERID = i;
            break;
         }
      }
      cout << "Please enter your current password: ";
      cin >> USERPASS;
      if (USERPASS != staffP.at(USERID))
         do
         {
            cout << "Password is incorrect, please try again: ";
            cin >> USERPASS;
         }while (USERPASS != staffP.at(USERID));
      
      cout << "Please enter your new password: ";
   	//might need to change to a new variable if causing problems.
      cin >> USERPASS;
      cout << "Please confirm your new password: ";
      cin >> confirmPass;
      if (confirmPass != USERPASS)
         do
         {
            cout << "The passwords do not match, please confirm again: ";
            cin >> confirmPass;
         }while (confirmPass != USERPASS);
      cout << "Your password has been successfully changed." << endl;
      staffP.at(USERID) = USERPASS;
   
   }