#include<ctime>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include "avl.h"
#include<fstream>
using namespace std;


class Node
{
	public:
		
	Movie obj;
	Node *next;
	Node* prev;
	
	Node(Movie m)
	{
		obj=m;
		next=NULL;
		prev=NULL;
	}
	Node()
	{
		next=NULL;
		prev=NULL;
	}
	void set_m(Movie m)
	{
		obj=m;
	}
	
};
class LinkedList
{
    
    public:
    Node *head, *tail;
    LinkedList()
    {
        head=NULL;
        tail=NULL;
    }
       
    void add_node_tail(Movie m)
    {
    	Node* newnode= new Node(m);
     	if(isempty())
     	{
		 	head=newnode;
		 	tail=head;
     	}
     	tail->next=newnode;
	    newnode->next=NULL;
        newnode->prev=tail;
        tail=newnode;
    }
    
    bool isempty()
    {
        return head==NULL;
    }
    void traverse_head()
	{
    	Node *temp=head;
		
		while(temp!=NULL)
		{
			temp->obj.display_details();
			temp=temp->next;
		}
	}
	float predictor(float r)
	{
		 int n=1000, i;
		 float x[1000], y[1000], sumX=0, sumX2=0, sumY=0, sumXY=0, a, b;
		 Node* temp= head;
		 for(i=1;i<n && temp!=NULL;i++)
		 {
			x[i]=temp->obj.get_rating();
			y[i]=temp->obj.get_revenue();
			temp=temp->next;
		 }
		
		 for(i=1;i<=n;i++)
		 {
			  sumX = sumX + x[i];
			  sumX2 = sumX2 + x[i]*x[i];
			  sumY = sumY + y[i];
			  sumXY = sumXY + x[i]*y[i];
		 }
	
		 b = (n*sumXY-sumX*sumY)/(n*sumX2-sumX*sumX);
		 a = (sumY - b*sumX)/n;
		check_rating(r);
		return a+(b*r);	
	}	
	
	void deleteNode(struct Node** head_ref, struct Node* del)
	{
	    if (*head_ref == NULL || del == NULL)
	        return;
	 

	    if (*head_ref == del)
	        *head_ref = del->next;

	    if (del->next != NULL)
	        del->next->prev = del->prev;
	 

	    if (del->prev != NULL)
	        del->prev->next = del->next;

	    del=NULL;
	    free(del);
	}
	 
	void deleteNodeAtGivenPos(struct Node** head_ref, string title)
	{
	    if (*head_ref == NULL || title=="")
	        return;
	 
	    struct Node* current = *head_ref;
	    int i;
	 
	    for (int i = 1; current != NULL && title!=current->obj.get_title(); i++)
	    {
		    current = current->next;
	 	}
//	 	cout<<current->obj.get_title();
	    if (current == NULL)
	        return;
	 
	    deleteNode(head_ref, current);
	}	
	void movie_of_actor(string actor_name,string actor_name2)
	{
    	Node *temp=head;
		string str;
		bool flag=false;
		while(temp!=NULL)
		{
			str=temp->obj.get_actors();
			if(strstr(str.c_str(),actor_name.c_str()) && strstr(str.c_str(),actor_name2.c_str()))
			{
				cout<<temp->obj.get_title()<<endl;
				flag=true;
			}
			temp=temp->next;
		}
		if(flag==false)
			cout<<"No movie found"<<endl;
	}
	
	void recommend(string actor_name,string actor_name2,string genre_name,string movies1[],string movies2[])
	{
    	Node *temp=head;
		string str;
		int i=0;
		while(temp!=NULL)
		{
			
			str=temp->obj.get_actors();
			if(str.find(actor_name)!= std::string::npos && str.find(actor_name2)!= std::string::npos)
			{
				movies1[i]=temp->obj.get_title();
//				cout<<movies1[i]<<endl;
				i++;
			}
			temp=temp->next;
		}
    	temp=head;
    	i=0;
    	string str2;
		while(temp!=NULL)
		{	
			string x=temp->obj.get_title();
			str2=temp->obj.get_genre();
			if(str2.find(genre_name)!= std::string::npos)
			{
				movies2[i]=x;
				i++;
			}
			temp=temp->next;
		}
	}
	float check_rating(float &rating) throw(int)
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
		return rating;
	}

	Node * middle(Node *start,Node *last){
	    Node *temp1;
		Node *temp2;
		temp1=temp2=start;
	    if (start!=NULL){
	        while (temp2 != last && temp2->next != last){
	            temp2 = temp2->next->next;
	            temp1 = temp1->next;
	        }
	        return temp1;
	    }
	}
	template <typename T>
	void binarySearch(T value){ 
    	Node* start = head; 
    	Node* last = tail; 
	    do
	    { 
	        Node* mid = middle(start, last);  
	        if (mid == NULL){
	            return ;	
			}
	        else if (mid->obj.get_rank()== value){
	        	mid->obj.display_details();
				return ;
			}
	        else if (mid->obj.get_rank() < value){
	        	start = mid -> next;	
			} 
	        else{
	        	last = mid;	
			}
	    }while (last == NULL || last != start);
	    return ;
	}	
            
    void random_rank()
	{
		srand(time(0));
		int trank;
		
		trank=rand() % 1000 +1;
	    binarySearch(trank);
		
	}	


	void MergeSort(Node** headRef) 
	{		
		Node* temp;
	    temp= *headRef;
	    Node* a; 
	    Node* b; 
	  
	    if ((temp == NULL) || (temp->next == NULL)) 
		{ 
	        return; 
	    } 
	  
	    FrontBackSplit(temp, &a, &b); 
	  
	    MergeSort(&a); 
	    MergeSort(&b); 
	  
	    *headRef=SortedMergeRating(a, b); 
	}
	  
	Node* SortedMergeRating(Node* a, Node* b) 
	{ 
	    Node* result = NULL; 
	  
	    if (a == NULL) 
	        return (b); 
	    else if (b == NULL) 
	        return (a); 
	  
	    if (a->obj.get_rating()>b->obj.get_rating()) 
		{ 
	        result = a; 
	        result->next = SortedMergeRating(a->next, b); 
	    } 
	    else 
		{ 
	        result = b; 
	        result->next = SortedMergeRating(a, b->next); 
	    } 
	    return (result); 
	} 
	  
	void FrontBackSplit(Node* source, Node** frontRef, Node** backRef) 
	{ 
	    Node* fast; 
	    Node* slow; 
	    slow = source; 
	    fast = source->next; 
	  
	    while (fast != NULL) { 
	        fast = fast->next; 
	        if (fast != NULL) { 
	            slow = slow->next; 
	            fast = fast->next; 
	        } 
	    } 
	  
	    *frontRef = source; 
	    *backRef = slow->next; 
	    slow->next = NULL; 
	}
	void output()
	{
		ofstream fout;
		fout.open("New.csv",ios::out);
		
			for(Node *temp=head;temp!=NULL;temp=temp->next)
			{
				fout<<temp->obj.get_rank()<<',';
				fout<<temp->obj.get_title()<<',';
				fout<<temp->obj.get_genre()<<',';
				fout<<temp->obj.get_description()<<',';
				fout<<temp->obj.get_director()<<',';
				fout<<temp->obj.get_actors()<<',';
				fout<<temp->obj.get_year()<<',';
				fout<<temp->obj.get_runtime()<<',';
				fout<<temp->obj.get_rating()<<',';
				fout<<temp->obj.get_votes()<<',';
				fout<<temp->obj.get_revenue()<<',';
				fout<<temp->obj.get_metascore()<<endl;
			}
	}
	void input_movie(Movie m2)
    {
	    int movie_rank;
	    string movie_title;
	    string movie_genre;
	    string movie_description;
	    string movie_director;
	    string movie_actors;
	    int movie_year;
	    int movie_rating;
	    int movie_runtime;
	    int movie_votes;
	    float movie_revenue;
	    int movie_metascore;
	   
	    cout<<"Enter Rank : "<<endl;
	    cin>>movie_rank;
	    m2.set_rank(movie_rank);
	   
	    cout<<"Enter Movie Title : "<<endl;
	    cin>>movie_title;
	    m2.set_title(movie_title);
	   
	    cout<<"Enter Genre : "<<endl;
	    cin>>movie_genre;
	    m2.set_genre(movie_genre);
	   
	    cout<<"Enter Description : "<<endl;
	    cin>>movie_description;
	    m2.set_description(movie_description);
	   
	    cout<<"Enter Director : "<<endl;
	    cin>>movie_director;
	    m2.set_director(movie_director);
	   
	//     cout<<"Enter Actors "<<endl;
	//     cin>>movie_actors;
	//     m2.set_actors;
	   
	    cout<<"Enter Year : "<<endl;
	    cin>>movie_year;
	    m2.set_year(movie_year);
	   
	    cout<<"Enter Runtime : "<<endl;
	    cin>>movie_runtime;
	    m2.set_runtime(movie_runtime);
	   
	    cout<<"Enter Rating : "<<endl;
	    cin>>movie_rating;
	    m2.set_rating(movie_rating);
	   
	    cout<<"Enter Votes : "<<endl;
	    cin>>movie_votes;
	    m2.set_votes(movie_votes);
	   
	    cout<<"Enter Revenue : "<<endl;
	    cin>>movie_revenue;
	    m2.set_revenue(movie_revenue);
	   
	    cout<<"Enter Metascore : "<<endl;
	    cin>>movie_metascore;
	    m2.set_metascore(movie_metascore); 
   
    }
};




