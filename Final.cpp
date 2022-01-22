#include "main.cpp"
using namespace std;

int main()
{
	project_graphics::start();
	BST *b=new BST();
	LinkedList *lst= new LinkedList;
	input_tree(b);
	input_list(lst);
	first_page(lst,b);
	delete b;
	delete lst;
}
