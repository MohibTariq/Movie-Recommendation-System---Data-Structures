#include<iostream>
//#include "linkedlist.h"
using namespace std;
class Movie
{
	int rank;
	string title;
//	string genre[3];
	string genre;
	string description;
	string director;
	string actors;
	int year;
	int runtime;
	float rating;
	int votes;
	float revenue;
	int metascore;
	
	public:
	
	Movie()
	{
		rank=0;
		year=0;
		runtime=0;
		rating=0;
		votes=0;
		revenue=0;
		metascore=0;
	}
	
	void set_rank(int r)
	{
		rank=r;
//		check_rank(rank);
	}
	
	int get_rank()
	{
		return rank;
	}
	
	void set_title(string t)
	{
		title=t;
	}
	
	string get_title()
	{
		return title;
	}
	void update()
	{
		int choice;
		cout<<"Choose field to update : \n 1.REVENUE \n2.RATING "<<endl;
		cin>>choice;
		float r;
		if(choice==1)
		{
			cout<<"Enter Revenue to update : "<<endl;
			cin>>r;
			set_revenue(r);
		}
		
		else if(choice==2)
		{
			cout<<"Enter Rating to update : "<<endl;
			cin>>r;
			set_rating(r);
		}
	}	
//	void set_genres(string g[])
//	{
//		for(int i=0;i<3;i++)
//		{
//			genre[i]=g[i];
//		}		
//	}
	
	void set_genre(string g)
	{
		genre=g;
	}
	string get_genre()
	{
		return genre;
	}
	
//	string get_genre1()
//	{
//		return genre[0];
//	}
//	string get_genre2()
//	{
//		return genre[1];
//	}
//	string get_genre3()
//	{
//		return genre[2];
//	}
	
	void set_description(string d)
	{
		description=d;
	}
	
	string get_description()
	{
		return description;
	}
	
	void set_director(string d)
	{
		director=d;
	}
	
	string get_director()
	{
		return director;
	}
	
	set_actors(string a)
	{
		actors=a;
	}

	string get_actors()
	{
//		bool x=true;
//		for(int i=0;i<actors.length();i++)
//		{
//			if(actors[i]==' ')
//			{
//				if(x==false)
//				{			
//					actors[i]=',';
//					x=true;
//					continue;
//				}
//				x=false;
//			}
//			
//		}
		return actors;
	}
//	string get_actors2()
//	{
//		return actors[1];
//	}
//	string get_actors3()
//	{
//		return actors[2];
//	}
//	string get_actors4()
//	{
//		return actors[3];
//	}
	
	void set_year(int y)
	{
		year=y;
		check_year(year);
	}
	
	int get_year()
	{
		return year;
	}
	
	void set_runtime(int r)
	{
		runtime=r;
		check_runtime(runtime);
	}
	
	int get_runtime()
	{
		return runtime;
	}
	
	void set_rating(float r)
	{
		rating=r;
		check_rating(rating);
	}
	
	float get_rating()
	{
		return rating;
	}
	
	void set_votes(int v)
	{
		votes=v;
		check_votes(votes);
	}
	
	int get_votes()
	{
		return votes;
	}
	
	void set_revenue(int r)
	{
		revenue=r;
		check_revenue(revenue);
	}
	
	float get_revenue()
	{
		return revenue;
	}
	
	void set_metascore(int m)
	{
		metascore=m;
		check_metascore(metascore);
	}
	
	int get_metascore()
	{
		return metascore;
	}
	
	void display_details()
	{
		cout<<"Rank : "<<get_rank()<<endl;
		cout<<"Title : "<<get_title()<<endl;
//		cout<<"Genres :"<<get_genre1()<<","<<get_genre2()<<","<<get_genre3()<<endl;
		cout<<"Genres :"<<get_genre()<<endl;
		cout<<"Description :"<<get_description()<<endl;
		cout<<"Director :"<<get_director()<<endl;
		cout<<"Actors :"<<get_actors()<<endl;
		cout<<"Year :"<<get_year()<<endl;
		cout<<"Runtime :"<<get_runtime()<<" minutes"<<endl;
		cout<<"Rating :"<<get_rating()<<endl;
		cout<<"Votes :"<<get_votes()<<endl;
		cout<<"Revenue : $"<<get_revenue()<<" million"<<endl;
		cout<<"MetaScore :"<<get_metascore()<<endl;
	
	}
	
	// Exception Handling
	
	void check_rank(int &rank) throw(int)
	    {
	    	try
	    	{
	    		if(!((rank>0) && (rank<=1001)))
	    		{
	    			throw 1;
				}
			}
			catch(int x)
			{
				if(x==1)
				{
					cout<<"Invalid Rank - Enter Again :"<<endl;
					cin>>rank;
					check_rank(rank);
				}
			}
		}
		
		void check_year(int &year) throw(int)
	    {
	    	try
	    	{
	    		if(!((year>=2000) && (year<=2020)))
	    		{
	    			throw 1;
				}
			}
			catch(int x)
			{
				if(x==1)
				{
					cout<<"Invalid Year - Enter Again :"<<endl;
					cin>>year;
					check_year(year);
				}
			}
		}
		
		void check_runtime(int &runtime) throw(int)
	    {
	    	try
	    	{
	    		if(!((runtime>=0) && (runtime<=200)))
	    		{
	    			throw 1;
				}
			}
			catch(int x)
			{
				if(x==1)
				{
					cout<<"Invalid Runtime - Enter Again :"<<endl;
					cin>>runtime;
					check_runtime(runtime);
				}
			}
		}
		
	
		
		void check_rating(float &rating) throw(int)
	    {
	    	try
	    	{
	    		if(!((rating>=0) && (rating<=10)))
	    		{
	    			throw 1;
				}
			}
			catch(int x)
			{
				if(x==1)
				{
					cout<<"Invalid Rating - Enter Again :"<<endl;
					cin>>rating;
					check_rating(rating);
				}
			}
		}
		
		void check_votes(int &votes) throw(int)
	    {
	    	try
	    	{
	    		if(!(votes>=0) )
	    		{
	    			throw 1;
				}
			}
			catch(int x)
			{
				if(x==1)
				{
					cout<<"Invalid Votes - Enter Again :"<<endl;
					cin>>votes;
					check_votes(votes);
				}
			}
		}
		
		void check_revenue(float &revenue) throw(int)
	    {
	    	try
	    	{
	    		if(!(revenue>=0) )
	    		{
	    			throw 1;
				}
			}
			catch(int x)
			{
				if(x==1)
				{
					cout<<"Invalid Revenue - Enter Again :"<<endl;
					cin>>revenue;
					check_revenue(revenue);
				}
			}
		}
		
		void check_metascore(int &metascore) throw(int)
	    {
	    	try
	    	{
	    		if(!((metascore>=0) && (metascore<=100)))
	    		{
	    			throw 1;
				}
			}
			catch(int x)
			{
				if(x==1)
				{
					cout<<title;
					
					cout<<"Invalid MetaScore - Enter Again :"<<endl;
					cin>>metascore;
					check_metascore(metascore);
				}
			}
		}	
};
