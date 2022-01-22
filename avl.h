#include "movie.h"
#include<fstream>
#include<cstring>

class NodeAvl
{
	public:
	Movie m;
	NodeAvl *left;
	NodeAvl *right;
	int height;
	NodeAvl(){
		
	}
	NodeAvl(Movie m){
		this->m=m;
		height=1;
		left=right=NULL;
	}
};
class BST
{
	public:
	NodeAvl *root;
	BST(){
		root=NULL;
		ofstream fout;
		fout.open("New2.csv",ios::out);
		fout.close();
	}
	~BST()
	{
		delete root;
	}
	private:
	int getheight(NodeAvl *ptr){
		if(ptr==NULL){
			return 0;
		}else{
			return ptr->height;
		}
	}
	int getmax(int x,int y){
		return (x > y)? x : y;
	}
	int getBalance(NodeAvl *ptr)
	{
		if (ptr == NULL) 
			return 0;
		else
			return (getheight(ptr->left) - getheight(ptr->right)); 
	}
	NodeAvl *rotateleft(NodeAvl *x)
	{ 
		NodeAvl *y = x->right; 
		NodeAvl *T2 = y->left; 
		y->left = x; 
		x->right = T2; 
		x->height = getmax(getheight(x->left),getheight(x->right)) + 1; 
		y->height = getmax(getheight(y->left),getheight(y->right)) + 1;  
		return y; 
	} 
	
	NodeAvl *rotateright(NodeAvl *y){ 
		NodeAvl *x = y->left; 
		NodeAvl *T2 = x->right;
		x->right = y; 
		y->left = T2;
		y->height = getmax(getheight(y->left),getheight(y->right)) + 1; 
		x->height = getmax(getheight(x->left),getheight(x->right)) + 1;
		return x; 
	}
	void inordertraverse(NodeAvl *ptr){
		if(ptr!=NULL){
			inordertraverse(ptr->right);
			ptr->m.display_details();
			inordertraverse(ptr->left);
		}
	}
	void get_rating_average_by_director(NodeAvl *n,string title,float &sum,int &count)
	{
		if(n==NULL)
			return ;
		get_rating_average_by_director(n->left,title,sum,count);
		if(n->m.get_director()==title)
		{
			sum+=n->m.get_rating();
			count++;
		}
		get_rating_average_by_director(n->right,title,sum,count);
	}
	
	public:
	NodeAvl* insertion(NodeAvl* node,Movie m){  
	    if (node == NULL)
	    {
//	    	m.display_details();
		    return new NodeAvl(m) ;
		}
	    if (m.get_title() < node->m.get_title())  
	        node->left = insertion(node->left,m);  
	    else if (m.get_title() > node->m.get_title())  
	        node->right = insertion(node->right,m);  
	    else   
	        return node;  
	        
	    node->height = 1 + max(getheight(node->left),getheight(node->right));
	    int balance = getBalance(node); 
	    if (balance > 1 && m.get_title() < node->left->m.get_title())  
	        return rotateright(node);  
	    if (balance < -1 && m.get_title() > node->right->m.get_title())  
	        return rotateleft(node);    
	    if (balance > 1 && m.get_title() > node->left->m.get_title())  
	    {  
	        node->left = rotateleft(node->left);  
	        return rotateright(node);  
	    } 
	    if (balance < -1 && m.get_title() < node->right->m.get_title())  
	    {  
	        node->right = rotateright(node->right);  
	        return rotateleft(node);  
	    }  
	    return node;  
	}  

	void updating(NodeAvl *n,string title)
	{
		if(n==NULL)
		{
			cout<<"No such movie in dataset"<<endl;
			return;
		}
		
		if(n->m.get_title()==title)
			n->m.update();

		else if(n->m.get_title()>title)		
		{
			updating(n->left,title);
		}
		else
			updating(n->right,title);
	}
	 	
	void search(NodeAvl *n,string title)
	{
		if(n==NULL)
		{
			cout<<"No such movie in dataset"<<endl;
			return;
		}
		
		if(n->m.get_title()==title)
			n->m.display_details();

		else if(n->m.get_title()>title)		
		{
			search(n->left,title);
		}
		else
			search(n->right,title);
	}
	float get_rating(NodeAvl *n,string title)
	{
		if(n==NULL)
			return -1;
		
		if(n->m.get_title()==title)
			return n->m.get_rating();

		else if(n->m.get_title()>title)		
		{
			get_rating(n->left,title);
		}
		else
			get_rating(n->right,title);
	}
	
	void inorder(NodeAvl* n)
	{
		if(n==NULL)
			return;
		inorder(n->left);
//		cout<<n->m.get_title()<<endl;
		output(n->m);
		inorder(n->right);
	}
	void output(Movie obj)
	{
		ofstream fout;
		fout.open("New2.csv",ios::app);
		fout<<obj.get_rank()<<',';
		fout<<obj.get_title()<<',';
		fout<<obj.get_genre()<<',';
		fout<<obj.get_description()<<',';
		fout<<obj.get_director()<<',';
		fout<<obj.get_actors()<<',';
		fout<<obj.get_year()<<',';
		fout<<obj.get_runtime()<<',';
		fout<<obj.get_rating()<<',';
		fout<<obj.get_votes()<<',';
		fout<<obj.get_revenue()<<',';
		fout<<obj.get_metascore()<<endl;
	}
	float get_director_average(NodeAvl *n,string s)
	{
		int count=0;
		float sum=0;
		get_rating_average_by_director(root,s,sum,count);
		return sum/count;
	}
		
	float get_average_rating_actor(NodeAvl *n,string actor_name,string actor_name2)
	{
		string str;
    	static float sum=0;
    	static int count=0;
		if(n!=NULL)
	    {
	        get_average_rating_actor(n->left,actor_name,actor_name2);
	        str=n->m.get_actors();
	       	if(strstr(str.c_str(),actor_name.c_str()) && strstr(str.c_str(),actor_name2.c_str()))
	        {
	        	sum+=n->m.get_rating();
	        	count++;
			}
	        get_average_rating_actor(n->right,actor_name,actor_name2);
	    }
			
		return sum/count;
		
	}
};

