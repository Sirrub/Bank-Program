/**
* Lab2 Prog. Part - COMP 2710.
* Staff.h
* @author  Shawn Burris (spb0015@tigermail.auburn.edu)
* @version 2013-04-23
*
* Header File for class Staff. Contains variables and functions.
* Used with Staff.cpp.
* Compile normally using g++.
*/  
#ifndef STAFF
#define STAFF
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <ctype.h>
#include <string>
#include <vector>
#include <fstream>

   using namespace std;

   //class Staff;
   class Staff
      {
      //friend class Client;
      public:
      //Staff();
      //Staff(string name, string pass);
      //Client newClient;
      //void output();
      ofstream outputFile;
      bool isStaff(string name, string password);
      bool isStaff(string name);
      //used for testing.
      void tempAddStaff(string name, string pass);
      bool deleteStaff(string user);
      void writeBackToFileStaff();
      void changePass(string pass);
      vector<string> staffN;
      //void addStaff(
      private:
      vector<string> staffP;    
      string staffName;
   	
      string staffPass;
      bool checkStaff;
      };
   
	#endif