#include<string>
#include<iostream>
#include<time.h>
#include"Looter.h"
#include"User.h"
#include<cctype>
using namespace std;

int main()
{
	string name;
	char roll;
	char choice;
	int numChoice;
	int accu = 1;


	cout << "Enter Username: ";
	getline(cin, name);
	User* profile = new User(name);

	accu = 1;
	cout << "\t   Menu\n";
	cout << "------------------------\n";
	cout << accu << ")Roll Weapon" << endl; accu++;
	cout << accu << ")View Inventory" << endl; accu++;
	cout << accu << ")Change User" << endl; accu++;
	cout << accu << ")Exit" << endl;
	numChoice = 0;
	cin >> numChoice;
	
	if (numChoice > 0 && numChoice < accu)
	{
		while (numChoice > 0 && numChoice < accu)
		{
			accu = 1;

			switch (numChoice)
			{
			case 1:
			{
				Looter* prize = new Looter();
				prize->setWeight();
				prize->setWorth();
				prize->setWeapon();
				prize->setDamage();

				cout << "\tWeapon stats.\n";
				cout << "------------------------\n";
				cout << "Weapon: " << prize->getWeapon() << endl;
				cout << "lvl: "    << prize->getLvl()    << endl;
				cout << "Weight: " << prize->getWeight() << "lbs" << endl;
				cout << "Value: "  << prize->getWorth()  << "GP" << endl;
				cout << "Damage: " << prize->getDamage() << endl;

				cout << "Would you like to save to inventory?: ";
				cin >> choice;

				if (choice == 'y' || choice == 'Y')
				{
					profile->setPrize(prize->getWeapon(),
					prize->getLvl(), prize->getWeight(),
					prize->getWorth(), prize->getDamage());

					profile->fileWrite();
					cout << "Weapon Saved!" << endl;
					break;
				}
				else if (choice == 'n' || choice == 'N')
				{
					cout << "Cleared." << endl;
				}
				else
					cout << "Invalid....\n";
				delete prize;
				cout << "Loading Menu.... \n";
				
			}
			break;
			case 2:
				cout << "Reading inventory...\n" << endl;
				profile->fileRead();
				break;
			case 3:
			{
				delete profile;
				cin.ignore();
				cout << "Enter Username: ";
				getline(cin, name);
				User* profile = new User(name);
			}
				break;
			case 4:
				cout << "Exiting...." << endl;
				break;
			default:
				cout << "Invalid choice..." << endl;

			}

			cout << "\t   Menu\n";
			cout << "------------------------\n";
			cout << accu << ")Roll Weapon" << endl; accu++;
			cout << accu << ")View Inventory" << endl; accu++;
			cout << accu << ")Change User" << endl; accu++;
			cout << accu << ")Exit" << endl;
			cin >> numChoice;
		}

	}
	else
		cout << "....";
		
	cout << "Exiting.... " << endl;

	system("pause");
	return 0;

}