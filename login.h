#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


using namespace std;

bool firstattempt=true;
class LOGIN{
	
	public:
		void Loginmain()
		{
			int ch;
			cout<<"\n\t\t\t1.Admin";
			cout<<"\n\t\t\t2.Customer\n\t\t\t";
			cin>>ch;
			
			if(ch==1)
			{
				system("cls");
		    system("Color E3");
		    bool firstattempt=true;
			admin_login();
			}
			
			else if(ch==2)
			{
				system("cls");
		        system("Color E4");
				customer_login();
			}
			
		}

static void admin_login()
{
	/// username : admin
	//  password : admin123
	if(firstattempt){
		cout<<"\t\t\t\t****************** ADMIN  ******************\n"<<endl;
	}
	int ch;
	int flag=0;
	START:
    char radmin[20];
    cout<<"\n\t\t\tEnter username:\n\t\t\t ";
    cin.ignore();
    cin.getline(radmin,19);
    cout<<"\n\t\t\tEnter Password:\n\t\t\t ";
    char apass[20];//to store password.
    int i = 0;
    char a;//a Temp char
    for(i=0;;)//infinite loop
    {
        a=getch();//stores char typed in a
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
            //check if a is numeric or alphabet
        {
            apass[i]=a;//stores a in pass
            ++i;
            cout<<"*";
        }
        if(a=='\b'&&i>=1)//if user typed backspace
            //i should be greater than 1.
        {
            cout<<"\b \b";//rub the character behind the cursor.
            --i;
        }
        if(a=='\r')//if enter is pressed
        {
            apass[i]='\0';//null means end of string.
            break;//break the loop
        }
    }
    
    if((strcmp(apass,"admin123")==0) && (strcmp(radmin,"admin"))==0)
    {
    	flag=1;
	}
	
	if (flag==1)
	{
		cout<<"\n\t\t\tWELCOME"<<endl;
	}
	
	else{
		system("cls");
		cout<<"\t\t\t\t****************** ADMIN  ******************\n"<<endl;
		firstattempt=false;
		cout<<"\n\t\t\tIncorrect ID or Password";
		cout<<"\n\t\t\tEnter Again:\n\t\t\t ";
		admin_login();
	}
	
}

void customer_login()
{
	system("cls");
	int ch;

	cout<<"\t\t\t****************** CUSTOMER LOGIN ******************\n";
	cout<<"\n\n\t\t\t<1> Login\n\t\t\t<2> Sign Up\n\t\t\t<3> Forgot Username/Password\n\t\t\t";
	cin>>ch;
	switch(ch)
	{
	    case 1:
		login();
		break;
		
        case 4:
		cout<<"\n\t\t\tThankyou!";
		break;
		
		default:
		cout<<"\n\t\t\tWrong choice selected.Enter again:\n\t\t\t";
	    customer_login();
		
	}
}

void login()
{
	START:
	int exist;
	char user[20];
	char pass[20];
	char u[20];
	char p[20];
	
	system("cls");
	cout<<"\n\t\t\tEnter username: ";
	cin.ignore();
	cin.getline(user,19);
	cout<<"\n\t\t\tEnter password: ";
	
	int i = 0;
    char a;//a Temp char
    for(i=0;;)//infinite loop
    {
        a=getch();//stores char typed in a
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
            //check if a is numeric or alphabet
        {
            pass[i]=a;//stores a in pass
            ++i;
            cout<<"*";
        }
        if(a=='\b'&&i>=1)//if user typed backspace
            //i should be greater than 1.
        {
            cout<<"\b \b";//rub the character behind the cursor.
            --i;
        }
        if(a=='\r')//if enter is pressed
        {
            pass[i]='\0';//null means end of string.
            break;//break the loop
        }
    }
    
	
	
	ifstream fin("login.txt");
	while(fin>>u>>p)
	{
		if((!strcmp(u,user)) && (!strcmp(p,pass)))
		{
			exist=1;
		}
	}
	fin.close();
	if(exist==1)
	{
		cout<<"\n\t\t\tHELLO "<<user<<"! "<<"Welcome to our XYZ Resort.\n"<<endl;
		cin.get();
		cin.get();
	}
	else
	{
		cout<<"\n\t\t\tLogin ERROR.Please try again!"<<endl;
		cin.get();
		cin.get();
		Loginmain();
	}
}


    
	
	
	

		
};




