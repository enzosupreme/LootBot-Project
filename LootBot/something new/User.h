#pragma once
#ifndef USER_H
#define USER_H
#include<fstream>
#include<string>
#include<iostream>
using namespace std;

 class User
{
private:
	fstream File;
	string filename;
	char line = ' ';
	string weapon;
	int lvl;
	int weight;
	int worth;
	string damage;
	
public:
	User(string);
	void setPrize(string weap, int l, int we, int wor, string dam)
	{
		weapon = weap;
		lvl = l;
		weight = we;
		worth = wor;
		damage = dam;
	}
	void fileWrite();
	void fileRead();
	void setFileName(string);
	string getFileName();
	friend class Looter;

};
 

#endif
