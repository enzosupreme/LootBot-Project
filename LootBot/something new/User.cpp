#include"User.h"
#include"Looter.h"

class Looter;

 User::User(string f)
 {
	 filename = f + ".txt";
 }
 void User::fileWrite()
 {
	 File.open(filename, ios::out | ios::app);
	 char line = ' ';

	 while (line != '*')
	 {
		 File <<"Weapon: " << weapon << "*";
		 File <<"Level: "  << lvl << "*";
		 File <<"Weight: " <<  weight << "lbs*";
		 File <<"Worth: "  << worth << "GP*";
		 File <<"Damage: "  <<damage << "*";
		 File << "*";
		 line = '*';
		 File.close();
	 }

 }
 void User::fileRead()
 {
	 string input;
	 File.open(filename, ios::in);
	 if (File)
	 {
		 getline(File, input, '*');
		 while (File)
		 {
			 cout << input << endl;
			 getline(File, input, '*');
		 }
		 File.close();
	 }
	 else
	 {
		 cout << "ERROR: No inventory found. Roll weapon to create one." << endl;

	 }
	 

 }

 string User::getFileName()
 {
	 return filename;
 }