#include "Looter.h"
#include "User.h"
#include<string>
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

Looter::Looter()
{
	lvl = rollbot(20, 1);
	weight = 0;
	worth = 0;
	
}

void Looter::setWeapon()
{
	int r = rollbot(4, 0);

	weapon = item[r];

}
string Looter::getWeapon()
{
	return weapon;
}

void Looter::setWeight()
{
	weight = rollbot(20, 4);

}

void Looter::setLevel()
{
	lvl = rollbot(20, 1);
}

void Looter::setWorth()
{
	int top = 0;
	int bottom = 0;


	if (lvl > 0 && lvl < 6)
	{
		top = 100;
		bottom = 1;
		worth = rollbot(top, bottom);

	}
	else if (lvl > 5 && lvl < 11)
	{
		top = 200;
		bottom = 100;
		worth = rollbot(top, bottom);

	}
	else if (lvl > 9 && lvl < 16)
	{
		top = 300;
		bottom = 170;
		worth = rollbot(top, bottom);

	}
	else if (lvl > 14 && lvl < 21)
	{
		top = 500;
		bottom = 250;
		worth = rollbot(top,bottom);

	}

	else
		cout << "Error calculating worth....." << endl;

}

void Looter::setDamage()
{	
	int amount = rollbot(6,1);
	string die;
	int dice = 0;
	
	if (lvl > 0 && lvl < 6)
	{
		 dice = 1;


	}
	else if (lvl > 5 && lvl < 11)
	{
		dice = rollbot(3, 1);
		amount = rollbot(3, 1);

	}
	else if (lvl > 9 && lvl < 16)
	{
		dice = rollbot(4, 2);
		amount = rollbot(6, 3);

	}
	else if (lvl > 14 && lvl < 21)
	{
		dice = rollbot(6, 2);
		amount = rollbot(6, 4);
	}

	else
		cout << "Error calculating worth....." << endl;

	switch (dice)
	{
	case 1: die = "d4";
		damage = to_string(amount) + die;
		break;
	case 2: die = "d6";
		damage = to_string(amount) + die;
		break;
	case 3: die = "d8"; 
		damage = to_string(amount) + die;
		break;
	case 4: die = "d10"; 
		damage = to_string(amount) + die;
		break;
	case 5:die = "d12";
		damage = to_string(amount) + die;
		break;
	case 6: die = "d20"; 
		damage = to_string(amount) + die;
		break;
	default:
		cout << "Error calculating damage...." << endl;
	}


}

int Looter::rollbot(int max, int min)
{
	unsigned seed = time(0);
	srand(seed);

	int roll = (rand() % (max - min + 1)) + min;

	return roll;
}


int Looter::getWeight() const
{
	return weight;
}
int Looter::getWorth() const
{
	return worth;
}
string Looter::getDamage() const
{
	return damage;
}




