#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include "project_graphic.h"
#include"pq.h"
#include<conio.h>
#include<cstdio>
#include<windows.h>
#include"login.h"
#include <iomanip>
void first_page(LinkedList *lst,BST *b);
void check(string movies1[],string movies2[], BST *b)
{	
	Priority_Queue pq;
	string str;
	float x=0;
	for(int i=0;;i++)
	{
		str=movies1[i];
		if(str=="")
			break;
		for(int j=0;;j++)
		{
			if(str==movies2[j])
			{
				x=b->get_rating(b->root,str);
				pq.insert(str,x);
			}
			if(movies2[j]=="")
				break;
		}
	}
	for(int i=0;i<3;i++)
	{
		str=pq.get_front();
		b->search(b->root,str);
		pq.del();
		cout <<"\n**************************************************************************************************************************************************************************************************\n" << endl;
	}
}
void next_page(LinkedList *lst,BST *b)
{
	Movie m3;
	int x;
	string mov;
	system("cls");
	cout <<"\t\t\t\t\t\t ****************** Admin Page ******************" << endl;
	cout << "\n\t\t\t<1> Add a Movie\n\t\t\t<2> Delete A movie \n\t\t\t<3> Update A Movie \n\t\t\t<4> Sort By Rating \n\t\t\t<5> Update DataSet \n\t\t\t<0> Exit\n\t\t\t";
	cin>>x;
	if(x==1)
	{
		lst->input_movie(m3);
	}
	
	else if(x==2)
	{
		cout<<"Enter movie name: ";
//		cin>>mov;
		fflush(stdin);
		getline(cin,mov);
		lst->deleteNodeAtGivenPos(&lst->head,mov);
	}
	
	else if(x==3)
	{
		cout<<"Enter movie name: ";
		fflush(stdin);
		getline(cin,mov);
		b->updating(b->root,mov);
		b->inorder(b->root);
	}
	
	else if(x==4)
	{
		lst->MergeSort(&lst->head);
	}
	else if(x==5)
	{
		lst->output();
	}
	else if(x==0)
		first_page(lst,b);
				
	system("pause");
	next_page(lst,b);
}
void analyst_page(LinkedList *lst,BST *b)
{
	int x;
	float rating,sum;
	system("cls");
	cout <<"\t\t\t\t\t\t****************** Analyst Page ******************" << endl;
	cout << "\n\t\t\t<1> Revenue Predictor by Rating\n\t\t\t<2> Average rating of Actor's Movies \n\t\t\t<3> Average Rating of Director\n\t\t\t<4> Revenue Predictor by Cast\n\t\t\t<0> Exit\n\t\t\t";
	cin>>x;
	string s1,s2,dir;
	if(x==1)
	{
		cout<<"Enter rating of Movie: ";
		cin>>rating;
		cout<<"Predicted Revenue: $"<<lst->predictor(rating)<<" Millions"<<endl;
	}
	if(x==2)
	{
		cout<<"Enter Actor's Full Name: ";
		cin>>s1;
		cin>>s2;	
		cout<<"Actor's Movies Average Rating : " <<setprecision(2)<<b->get_average_rating_actor(b->root,s1,s2)<<endl;
	}
	if(x==3)
	{
		cout<<"Enter Directors's Full Name: ";
		fflush(stdin);
		getline(cin,dir);
		cout<<"Director's Movie Average Rating : "<< setprecision(2)<<b->get_director_average(b->root,dir)<<endl;		
	}
	if(x==4)	
	{
		sum=0;
		for(int i=0;i<3;i++)
		{
			cout<<"Enter Actor's Full Name: ";
			cin>>s1;
			cin>>s2;	
			sum+=b->get_average_rating_actor(b->root,s1,s2);
		}
		cout<<"Enter Directors's Full Name: ";
		fflush(stdin);
		getline(cin,dir);
		sum+=b->get_director_average(b->root,dir);
		sum/=4;
		cout<<"Predicted Revenue: $"<<setprecision(2)<<lst->predictor(sum)<<" Millions"<<endl;
	}
	if(x==0)
		first_page(lst,b);
	system("pause");
	analyst_page(lst,b);
}
void search_page(LinkedList *lst,BST *b)
{
	string m1[1000];
	string m2[1000];
	int x;
	string mov,actor;
	system("cls");
	cout <<"\t\t\t\t\t\t****************** Search Page ******************" << endl;
	cout << "\n\t\t\t<1> Random Movie\n\t\t\t<2> Movies of Actors\n\t\t\t<3> Search by name\n\t\t\t<4> Get a recommendation\n\t\t\t<0> Exit\n\t\t\t";
	cin>>x;
	if(x==1)
	{		
		lst->random_rank();
	}	
	else if(x==2)
	{
		system("cls");
		cout<<"Enter Actor's Full Name You Want To Search"<<endl;
		cin>>actor;
		cin>>mov;
		lst->movie_of_actor(actor,mov);
	}
	else if(x==3)
	{
		system("cls");
		cout<<"Enter Name of movie: ";
		cin>>mov;
		b->search(b->root,mov);
	}
	
	else if(x==4)
	{
		system("cls");
		cout<<"Enter full name of actor: ";
		string s1,s2,s3;
		cin>>s1;
		cin>>s2;
		cout<<"Enter genre: ";
		cin>>s3;
		lst->recommend(s1,s2,s3,m1,m2);
		check(m1,m2,b);
	}
	else if(x==0)
		first_page(lst,b);
	system("pause");
	search_page(lst,b);
}

void first_page(LinkedList *lst,BST *b)
{
	int x;
	system("cls");
    system("Color E2");
	cout <<"\t\t\t\t\t\t****************** MOVIESUGESSTIONS ******************" << endl;
	cout << "\n\t\t\tType of User" << endl;
	cout << "\n\t\t\t<1> Normal\n\t\t\t<2> Aunthorized\n\t\t\t<3> Analyst\n\t\t\t<0> Exit\n\t\t\t";
	cin>>x;
	if(x==1)
	{
		search_page(lst,b);
	}
	else if(x==2)
	{
		system("cls");
		LOGIN::admin_login();
		next_page(lst,b);
	}
	if(x==3)
	{
		analyst_page(lst,b);
	}
	else if(x==0)
		exit(1);
	
}

void input_list(LinkedList *lst)
{	
    	int intrank,intyear,intruntime,intvotes,x;
    	float floatmeta,floatrating,floatrev;
    	string title,genre,desc,dir,act,garbage,rank,year,runtime,votes,meta,rating,rev;
    	ifstream fin("Cleaned.csv");
		int i=0;
		Movie m;
		while(i!=1000)
		{
			i++;
			fin>>intrank;		
			m.set_rank(intrank);
			
			fin.ignore();
			
    		getline(fin,title,',');
    		m.set_title(title);
     		getline(fin,genre,',');
    		m.set_genre(genre);   		
    		getline(fin,desc,',');
    		m.set_description(desc);

    		getline(fin,dir,',');
    		m.set_director(dir);

    		getline(fin,act,',');
    		m.set_actors(act);
						
			fin>>intyear;    		
			m.set_year(intyear);
			fin.ignore();
    		
 			fin>>intruntime;   		
    		m.set_runtime(intruntime);
    		getline(fin,rating,',');
			
			fin>>floatrating;
    		m.set_rating(floatrating);
			
			
			fin.ignore();
						
			fin>>intvotes;
    		m.set_votes(intvotes);							
	
			fin.ignore();					
			fin>>floatrev;			
			m.set_revenue(floatrev);
			fin.ignore();
    		fin>>floatmeta;
    		m.set_metascore(floatmeta);
			lst->add_node_tail(m);
		}
//		lst->MergeSort(&lst->head);
//		lst->output();
}


void input_tree(BST *b)
{	
    	int intrank,intyear,intruntime,intvotes,x;
    	float floatmeta,floatrating,floatrev;
    	string title,genre,desc,dir,act,garbage,rank,year,runtime,votes,meta,rating,rev;
    	ifstream fin("Cleaned.csv");
		int i=0;
		Movie m;
		while(i!=1000)
		{
			i++;
			fin>>intrank;		
			m.set_rank(intrank);
			
			fin.ignore();
			
    		getline(fin,title,',');
    		m.set_title(title);
     		getline(fin,genre,',');
    		m.set_genre(genre);   		
    		getline(fin,desc,',');
    		m.set_description(desc);

    		getline(fin,dir,',');
    		m.set_director(dir);

    		getline(fin,act,',');
    		m.set_actors(act);
						
			fin>>intyear;    		
			m.set_year(intyear);
			fin.ignore();
    		
 			fin>>intruntime;   		
    		m.set_runtime(intruntime);
    		getline(fin,rating,',');
			
			fin>>floatrating;
    		m.set_rating(floatrating);
			
			
			fin.ignore();
						
			fin>>intvotes;
    		m.set_votes(intvotes);							
	
			fin.ignore();					
			fin>>floatrev;			
			m.set_revenue(floatrev);
			fin.ignore();
    		fin>>floatmeta;
    		m.set_metascore(floatmeta);
			b->root=b->insertion(b->root,m);
		}
}

