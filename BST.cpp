#include<iostream>
using namespace std;

struct node{
	node *left,*right;
	int data;
};

class BST{
	public:
		node *root,*nnode,*temp;
		BST(){
			root=NULL;
		}
		
		void create(){
			char choice;
			do{
				nnode=new node;
				cout<<"Enter data:";
				cin>>nnode->data;
				nnode->left=nnode->right=NULL;
				if(root==NULL){
					root=nnode;
				}else{
					temp=root;
					while(1){
						if(nnode->data<temp->data){
							if(temp->left==NULL){
								temp->left=nnode;
								break;
							}
							temp=temp->left;
						}else{
							if(temp->right==NULL){
								temp->right=nnode;
								break;
							}
							temp=temp->right;
						}
					}
				}
				cout<<"Do you want to continue(y/n):";
				cin>>choice;
			}while(choice=='y');
		}
		void inorder(node *temp){
			if(temp!=NULL){
				inorder(temp->left);
				cout<<" "<<temp->data;
				inorder(temp->right);
			}	
		}
		void minimum(){
			temp=root;
			while(temp->left!=NULL){
				temp=temp->left;
			}
			cout<<"\n\nMinimum value:"<<temp->data<<endl;
		}
		bool search(int key) {
        node* temp = root;
        while (temp != NULL) {
            if (key == temp->data) return true;
            else if (key < temp->data) temp = temp->left;
            else temp = temp->right;
        }
        return false;
   		}		
		
		int maxlen(node *temp){
			int nleft,nright,n;
			if(temp==NULL){
				return 0;
			}else{
				nleft=maxlen(temp->left);
				nright=maxlen(temp->right);
				n=max(nleft,nright)+1;
				return n;
			}
		}
		void mirror(node *root){
			node *temp1;
			if(root!=NULL){
				temp1=root->left;
				root->left=root->right;
				root->right=temp1;	
				mirror(root->left);
				mirror(root->right);
			}
		}
};
int main(){
	int key;
	char choice;
	BST b;
	b.create();
	cout<<"\n*****OUTPUT*****"<<endl;
	b.inorder(b.root);
	b.minimum();
	
	do{
		while(1){
			cout<<"\nEnter Key to search:";
			cin>>key;
			int f=b.search(key);	
			if(f==1){
				cout<<"Element found..."<<endl;
				break;
			}else{
				cout<<"Element not found..."<<endl;
				break;
			}
		}
		cout<<"Do you want to search more element(y/n):";
		cin>>choice;
	}while(choice=='y');
	
	cout<<"\nMaxlength of tree is:"<<b.maxlen(b.root)<<endl;
	
	b.mirror(b.root);
	cout<<"\nOutput after mirroring:"<<endl;
	b.inorder(b.root);
	return 0;
}
