#pragma once
#ifndef LOOTER_H
#define LOOTER_H
#include<string>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include"User.h"
using namespace std;

const int WEAPONS = 5;

class Looter
{
private:
	fstream file;
	string fileName;
	int lvl;
	int weight;
	int worth;
	string damage;
	string weapon;
	string item[WEAPONS] = { "Sword", "Hammer","Axe","Bow","BowGun" };

public:
	Looter();
	int getLvl() const
	{
		return lvl;
	}
	void setWeapon();
	void setLevel();
	void setWeight();
	void setWorth();
	int getWeight() const;
	int getWorth() const;
	void setDamage();
	string getDamage() const;
	int rollbot(int, int);
	string getWeapon();
	friend class User;
	
	
};
#endif