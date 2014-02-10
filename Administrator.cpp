/**
* Lab2 Prog. Part - COMP 2710.
* Administrator.cpp
* @author  Shawn Burris (spb0015@tigermail.auburn.edu)
* @version 2013-04-23
*
* Source File for class Administrator. Contains functions definitions.
* Used with Administrator.h.
* Compile normally using g++.
*/  
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include "Administrator.h"
#include "Staff.h"

   using namespace std;   
	//Generates Main Menu.
	//DON'T THINK I NEED THESE GETTERS AND SETTERS. MIGHT TAKE
	//THEM OUT LATER.	
	
   //Administrator::Administrator(string name, string pass)
   //{
      //adminName = name;
      //adminPass = pass;
   //}
   void Administrator:: deleteStaff(Staff& b)
   {
      cout << "Delete a user - User Name: ";
      cin >> deleteUser;
      cout << "1) Confirm " << endl << "2) Cancel " << endl;
      cout << "Please choose an option: ";
      //deleteStaffChoice - dSC
      cin >> dSC;
      if (dSC == "1")
      {
         b.deleteStaff(deleteUser);
      }
      //writeBackToFileAdmin();
      //b.writeBackToFileStaff();
   }
   
   void Administrator:: writeBackToFileAdmin()
   {
      outputFile.open("staffList.txt", std::fstream::trunc);
      //"file", std::fstream::out | std::fstream::trunc
      for (int i = 0; i < addName.size(); i++)
      {
         outputFile << addName.at(i) << " " << addPass.at(i) << " 1 " << "\n";
      }
      outputFile.close();
   }
	
   void Administrator:: addStaff(Staff& b)
   {
      char staffType;
      bool isFull = false;
      cout << "Please select role: 1-Branch Administrator | 2-Branch Staff: ";
      cin >> staffType;
      if (staffType == '2')
      {
         cin.ignore();
         do
         {
            cout << "Please enter user name of new staff employee: ";
            getline(cin,employeeName);
            cout << "Please enter pass for new staff employee: ";
            getline(cin,employeePass);
            if (employeeName.empty() || employeePass.empty())
            {
               cout << "A field was left blank, please resubmit information." << endl;
               isFull = false;
            }
            else
            {
               isFull = true;
            }
         } while (isFull != true);
         b.tempAddStaff(employeeName, employeePass);
         cout << "A new branch member has been added!" << endl;
         cout << "User Name: " << employeeName << " Role: Staff Member" << endl;
         isFull = false;
      }
      else
      {
         cin.ignore();
         do
         {
            cout << "Please enter user name of new staff employee: ";
            getline(cin,employeeName);
            cout << "Please enter pass for new staff employee: ";
            getline(cin,employeePass);
            if (employeeName.empty() || employeePass.empty())
            {
               cout << "A field was left blank, please resubmit information." << endl;
               isFull = false;
            }
            else
            {
               isFull = true;
            }
         }
            while (isFull != true);
         addAdmin(employeeName, employeePass);
         cout << "A new branch member has been added!" << endl;
         cout << "User Name: " << employeeName << " Role: Branch Administrator" << endl;
         isFull = false;
      }
   }
	
   void Administrator:: addAdmin(string staffN, string staffP)
   {
      addName.push_back(staffN);
      addPass.push_back(staffP);
   }
   
   void Administrator:: changePass(string user, Staff& b)
   {
   //check user position so I can get pass position.
      for (int i = 0; i < addName.size(); i++)
      {
         if (addName.at(i) == user)
         {
            USERID = i;
            break;
         }
      }
      cout << "Please enter your current password: ";
      cin >> USERPASS;
      if (USERPASS != addPass.at(USERID))
         do
         {
            cout << "Password is incorrect, please try again: ";
            cin >> USERPASS;
         }while (USERPASS != addPass.at(USERID));
      
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
      addPass.at(USERID) = USERPASS;
   }
	
   void Administrator:: displayAdmin(Staff & b)
   {
      int n = addName.size() + b.staffN.size();
      cout << "There are " << n << " users in the system. " << endl;
      for (int i = 0; i < addName.size(); i++)
      {
         cout << addName.at(i) << " - Branch Administrator" << endl;
      }
      
      for (int i = 0; i < b.staffN.size(); i++)
      {
         cout << b.staffN.at(i) << " - Branch Staff" << endl;
      }
   }
   
   bool Administrator:: isAdmin(string staff, string password)
   {  
      for (int i = 0; i < addName.size(); i++)
      {
         if (addName.at(i) == staff && addPass.at(i) == password)
         {
            checkAdmin = true;
            return checkAdmin;
         }
      }
      checkAdmin = false;
      return checkAdmin;
   }
