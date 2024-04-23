#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <iomanip>

using namespace std;

class Equipment
{
	int hpmax;
	int atk;
	int def;

public:
	Equipment(int, int, int);
	vector<int> getStat();
};

Equipment::Equipment(int h, int a, int d)
{
	hpmax = h;
	atk = a;
	def = d;
}

vector<int> Equipment::getStat()
{
	vector<int> get;
	get.push_back(hpmax);
	get.push_back(atk);
	get.push_back(def);
	return get;
}

class Unit
{
	string name;
	string type;
	int hp;
	int hpmax;
	int atk;
	int def;
	bool guard_on;
	bool dodge_on;
	Equipment *equipment;

public:
	Unit(string, string);
	void showStatus();
	void newTurn();
	int attack(Unit &);
	int ultimateAttack(Unit &);
	int beAttacked(int);
	int heal();
	void guard();
	void dodge();
	bool isDead();
	void equip(Equipment *);
};

Unit::Unit(string t, string n)
{
	type = t;
	name = n;
	if (type == "Hero")
	{
		hpmax = rand() % 20 + 120;
		atk = rand() % 5 + 14;
		def = rand() % 3 + 9;
	}
	else if (t == "Monster")
	{
		hpmax = rand() % 20 + 250;
		atk = rand() % 5 + 25;
		def = rand() % 3 + 5;
	}
	hp = hpmax;
	guard_on = false;
	dodge_on = false;
	equipment = NULL;
}

void Unit::equip(Equipment *newE)
{
	if (equipment)
	{
		vector<int> oldE = equipment->getStat();
		hpmax -= oldE[0];
		atk -= oldE[1];
		def -= oldE[2];
	}

	vector<int> E = newE->getStat();

	hpmax += E[0];
	atk += E[1];
	def += E[2];

	if (hp > hpmax)
	{
		hp = hpmax;
	}

	equipment = newE;
}

void Unit::showStatus()
{
	if (type == "Hero")
	{
		cout << "---------------------------------------\n";
		cout << name << "\n";
		cout << "HP: " << hp << "/" << hpmax << "\tATK: " << atk << "\t\tDEF: " << def;
		cout << "\n---------------------------------------\n";
	}
	else if (type == "Monster")
	{
		cout << "\t\t\t\t---------------------------------------\n";
		cout << "\t\t\t\t" << name << "\n";
		cout << "\t\t\t\tHP: " << hp << "\t\tATK: " << atk << "\t\tDEF: " << def;
		cout << "\n\t\t\t\t---------------------------------------\n";
	}
}

void Unit::newTurn()
{
	guard_on = false;
	dodge_on = false;
}

int Unit::beAttacked(int oppatk)
{
	int dmg;
	if (oppatk > def)
	{
		if (guard_on)
		{
			dmg = (oppatk - def) / 3;
		}
		else if (dodge_on)
		{
			if (rand() % 2 == 0)
			{
				dmg = 0;
			}
			else
			{
				dmg = (oppatk - def) * 2;
			}
		}
		else
		{
			dmg = oppatk - def;
		}
	}
	else
	{
		dmg = 0;
	}
	hp -= dmg;
	if (hp <= 0)
	{
		hp = 0;
	}
	return dmg;
}

int Unit::attack(Unit &opp)
{
	return opp.beAttacked(atk);
}

int Unit::ultimateAttack(Unit &opp)
{
	return opp.beAttacked(2 * atk);
}

int Unit::heal()
{
	int h = rand() % 21 + 10;
	if (hp + h > hpmax)
		h = hpmax - hp;
	hp = hp + h;
	return h;
}

void Unit::dodge()
{
	dodge_on = true;
}

void Unit::guard()
{
	guard_on = true;
}

bool Unit::isDead()
{
	if (hp <= 0)
		return true;
	else
		return false;
}

void drawScene(char p_action, int p, char m_action, int m)
{
	cout << "                                                       \n";
	if (p_action == 'A')
	{
		cout << "                                       " << -p << "\n";
	}
	else
	{
		cout << "                                                       \n";
	}
	cout << "                                *               *      \n";
	cout << "                                **  *********  **      \n";
	cout << "                                ****         ****      \n";
	if (m_action == 'A')
	{
		cout << "                 " << setw(5) << -m << "           *** **   ** ***       Attack!\n";
	}
	else if (m_action == 'G')
	{
		cout << "                                 *** **   ** ***       Guard!\n";
	}
	else if (m_action == 'D')
	{
		cout << "                                 *** **   ** ***       Dodge!\n";
	}
	else if (m_action == 'U')
	{
		cout << "                 " << setw(5) << -m << "           *** **   ** ***       Ultimate Attack!\n";
	}
	else
	{
		cout << "                                 *** **   ** ***       \n";
	}
	cout << "                                  ** **   ** **        \n";
	cout << "                   ***             *         *         \n";
	if (p_action == 'A')
	{
		cout << "        Attack!    ***  *           *********          \n";
	}
	else if (p_action == 'H')
	{
		cout << "      Heal! +" << setw(2) << p << "    ***  *           *********          \n";
	}
	else if (p_action == 'G')
	{
		cout << "         Guard!    ***  *           *********          \n";
	}
	else if (p_action == 'D')
	{
		cout << "         Dodge!    ***  *           *********          \n";
	}
	else
	{
		cout << "                   ***  *           *********          \n";
	}
	cout << "                    *  *       ***  *  *  *            \n";
	cout << "                  *****           **   *   *           \n";
	cout << "                    *                  *    ***        \n";
	cout << "                   * *               **        *       \n";
	cout << "                  *   *                                \n";
	cout << "                                                       \n";
};

void playerWin()
{
	cout << "*******************************************************\n";
	for (int i = 0; i < 3; i++)
		cout << "*                                                     *\n";
	cout << "*                   YOU WIN!!!                        *\n";
	for (int i = 0; i < 3; i++)
		cout << "*                                                     *\n";
	cout << "*******************************************************\n";
};

void playerLose()
{
	cout << "*******************************************************\n";
	cout << "*                                                     *\n";
	cout << "*                   YOU LOSE!!!                       *\n";
	cout << "*                                                     *\n";
	cout << "*******************************************************\n";
};