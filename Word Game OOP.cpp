//Max  Zubkov, Georgii Moiseev
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<conio.h>
#include<windows.h>
using namespace std;

HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );

class Damage{
	private:
		int sword, bareFists, bow; 
	protected:
		
	public:
		void SetValue(int arrow, int sw, int def)
		{
			bow = arrow;
			sword = sw;
			bareFists = def; 
		}
		int BowKill()
		{
			return bow;
		}
		int SwordKill()
		{
			return sword;
		}
		int	FistsKill()
		{
			return bareFists;
		 } 
		 
		 void DefineDamage()
		 {
		 	cout<<"\n Your damage now : ";
		 }
		
		void display()
		{
			cout<<"\n Damage of bow: "<<bow<<"; \n Damage of sword: "<<sword
			<<"; \n Damage with bare fists: "<<bareFists<<";";
		}
			
};

void Game(Damage, int);
void GameOver(int );
void setDamage(Damage *, int);

int main()
{
	Damage obj;
	int choice;
	string name, answer;
	cout<<"\n Input your Name ";
	getline(cin, name);
	cout<<"\n Greetings, "<<name<<", your adventure starts here. Pick the level of difficulty of your game";
	cout<<"\n Difficulty Levels:	"
		<<"\n1. super easy"
		<<"\n2. easy "
		<<"\n3. not easy"
		<<"\n4. not easy at all\n5.Exit ";
		cin>>choice;
	switch(choice)
	{
		case 1:
				{
					setDamage(&obj, choice);
					Game(obj, choice);
					break;
				}
		case 2:
			{
				setDamage(&obj, choice);
				Game(obj, choice);
				break;
			}
		case 3:
			{
				setDamage(&obj, choice);
				Game(obj, choice);
				break;
			}
		case 4:
			{
				GameOver(choice);
				break;
			}
			default:	cout<<"\n Not right choice";
	} 

	
	
	cout<<"\n\n"; 
	return 0;
}

void GameOver(int choice)
{
	if(choice==4)
	{
		cout<<"\n You lost this game automatically";
	}
	
	else {
		SetConsoleTextAttribute(h, 1);
	cout<<"\n Game is over";
		SetConsoleTextAttribute(h, 7);
	}
}

void setDamage(Damage *s, int choice)
{
	if(choice==1)
	{
		s->SetValue(17, 25, 14);
	}
	else if(choice==2)
	{
		s->SetValue(12, 19, 8);
	}
	else if(choice==3)
	{
		s->SetValue(7, 13, 3);
	}
}

void Game(Damage obj, int choice)
{
	bool win = false;
	string answer;
	int rampage;							//damage of main character																								(at least somewhere I got rampage)
	int charHeal;							//health of main character
	int ratHeal = 25;						//health of the rat
	srand(time(0));
		cout<<"\n Peasants came to you and screaming for the help. One of peasants says - ";
	cout<<" 'The castle in on fire. The princess is locked on the top of tower. You are a great knight. You must go on top and rescue her'";
	cout<<"\n Are you going to save her(yes/no/later)? ";

	cin>>answer;
	back:
	if(answer=="yes"||answer=="yea")
	{
		string pick;
		cout<<"\n You broke into firing castle and there you saw a huge rat. It jumped on you. But in your inventory you have";
		obj.display();
		cout<<"\n pick the weapon(bow/sword/bare fists) ";
		cin.ignore();
		getline(cin,pick);
		if(pick=="bow")
		{
			obj.DefineDamage();
			cout<<obj.BowKill();
			rampage = obj.BowKill();
		}
		else if(pick=="sword")
		{
			obj.DefineDamage();
			cout<<obj.SwordKill();
			rampage = obj.SwordKill();
		}
		else if(pick=="bare fists")
		{
			obj.DefineDamage();
			cout<<obj.FistsKill();
			rampage = obj.FistsKill();
		}
		if(choice==1)
		{
			charHeal = 100;
		}
		if(choice==2)
		{
			charHeal = 75;
		}
		if(choice==3)
		{
			charHeal  = 50;
		}
		int x = rand()%20+3;			//random damage of the rat
	
		for(int i=0;i<=10;i++)
		{
			
  			SetConsoleTextAttribute(h, 12);
			cout<<"\n\n RAT damage = "<<x<<"\t\t health = "<<ratHeal;
	
  			SetConsoleTextAttribute(h, 10);
			cout<<"\n\n your damage = "<<rampage<<"\t\t health = "<<charHeal;
			charHeal -= x;
			ratHeal  -= rampage;
			if(ratHeal<=0)
			{
				win = true;
				break;
			}
			else if(charHeal<=0)
			{
				break;
			}
		}
		SetConsoleTextAttribute(h, 15);
		if(win)
		{
			cout<<"\n\n You used your weapon to kill this rat";
		cout<<"\n You won this fight. You rescued the princess. Congratulations!!!! ";
	}
		else {
		cout<<"\n You lost the fight ";
		GameOver(0);
	}

	}
	else if(answer=="no"||answer=="nope"||answer=="nah")
	{
		cout<<"\n Peasants got angry and killed you ";
		GameOver(choice);
}
	else if(answer=="later"||answer=="l8r")
	{
		cout<<"\n Peasants can't wait long. They ask for your decision again. \n What is your choice now(yes, no)? ";
		cin>>answer;
		goto back;
	}
	else cout<<"\n Not right choice ";
}
