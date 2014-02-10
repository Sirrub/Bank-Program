/**
* Lab2 Prog. Part - COMP 2710.
* Administrator.h
* @author  Shawn Burris (spb0015@tigermail.auburn.edu)
* @version 2013-04-23
*
* Header File for class Administrator. Contains variables and functions.
* Used with Administrator.cpp.
* Compile normally using g++.
*/

#ifndef ADMINISTRATOR
#define ADMINISTRATOR
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <ctype.h>
#include <string>
#include <vector>
#include <fstream>
#include "Staff.h"

   using namespace std;

   class Staff;
   class Administrator
      {
      friend class Client;
      public:
      //Administrator();
      //Administrator(string name, string pass);
      //Client newClient;
      //void output();
      ofstream outputFile;
      string getName();
      void setName(string username);
      string getPass();
      void setPass(string password);
      bool isAdmin(string name, string pass);
      void deleteStaff(Staff& b);
      void addAdmin(string a, string b);
      void addStaff(Staff& b);
      void displayAdmin(Staff& b);
      void changePass(string user, Staff& b);
      void writeBackToFileAdmin();
      //void addStaff(
      private:
      vector<string> addName;
      int USERID;
      string USERPASS;
      string deleteUser, dSC;
      vector<string> addPass;
      string adminName;
      string employeeName;
      string employeePass;
      string confirmPass;
      string adminPass;
      bool checkAdmin;
      };
   
	#endif