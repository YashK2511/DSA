#include<iostream>
using namespace std;
struct node
{   
 public:
 string name;
 int count;
 node* child[10]; 
};
class book
{   
    public:
        node *nnode,*root,*temp;
        int ch;
        book()
        {
            root=NULL;
        }
 
 
    void creation()
    { 
	    int choice;
        nnode=new node;
        cout<<"Enter the Book name:"<<endl;
        cin>>nnode->name;
        cout<<"Enter number of chapter:"<<endl;
        cin>>nnode->count;
        for(int i=0;i<nnode->count;i++)
        {
            nnode->child[i]=new node;
            cout<<"Enter the chapter name : ";
            cin>>nnode->child[i]->name;
            cout<<"Enter the no of section :";
            cin>>nnode->child[i]->count;
            for(int j=0;j<nnode->child[i]->count;j++) 
			{
                nnode->child[i]->child[j]=new node;
                cout<<"Enter section name :";
                cin>>nnode->child[i]->child[j]->name;
                cout<<"Enter the no of subsection :";
                cin>>nnode->child[i]->child[j]->count;
                for(int k=0;k<nnode->child[i]->child[j]->count;k++) 
				{
                    nnode->child[i]->child[j]->child[k]=new node;
                    cout<<"Enter subsection name :";
                    cin>>nnode->child[i]->child[j]->child[k]->name;
                }
            }
	    }
             
    if(root==NULL)
    {
        root=nnode;
    }
}
void display()
{ 
    cout<<"\n OUTPUT\n";
    do{
        cout<<"\n ";
        cout<<nnode->name;
        cout<<"\n\t"<<""; 
        for(int i=0;i<nnode->count;i++)
        {
            cout<<"\n\t\t"<<nnode->child[i]->name;
            cout<<"\n\t\t"<<"";
             
            for(int j=0;j<nnode->child[i]->count;j++) 
			{
              
                cout<<"\n \t\t\t"<<nnode->child[i]->child[j]->name;
               
             
                for(int k=0;k<nnode->child[i]->child[j]->count;k++)
			    {
                    cout<<"\n\t\t\t\t";
                    cout<<nnode->child[i]->child[j]->child[k]->name;
                 
                }
			}
        }
    }while(root==NULL); 
 }
};
int main()
{
    book ob1;
    ob1.creation();
    ob1.display();
	return 0; 
}

