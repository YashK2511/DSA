#include<iostream>
#include<string>
#include<queue>
using namespace std;

class object {
	public:
		queue<int> q1;
		int n,p,q,c,finalk;
		int pi[10],
		qi[10];
      
		string names,name[10];
		int W[10][10],
		C[10][10],
		R[10][10];
		void input(){
			cout<<"Enter the number of keys:";
			cin>>n;
			for(int i=1;i<=n;i++)
			{
				cout<<"Enter the key name:";
				cin>>names;
				name[i]=names;
			}
			cout<<endl;
			for(int i=1;i<=n;i++)
			{
				cout<<"Enter probablity of successfull:";
				cin>>p;
				pi[i]=p;
			}
			cout<<endl;
			for(int i=0;i<=n;i++){
				cout<<"Enter probablity of unsuccessfull:";
				cin>>q;
				qi[i]=q;
			}
		}
		void display(){
			cout<<"Keys:";
			for(int i=0;i<n;i++)
			{
				cout<<name[i]<<" ";
			}
			cout<<"\nprobablity of successful:";
			for(int i=1;i<=n;i++)
			{
				cout<<pi[i]<<" ";
			}
			cout<<"\nprobablity of unsuccessful:";
			for(int i=0;i<=n;i++)
			{
				cout<<qi[i]<<" ";
			}
		}
		int mink(int i,int j){
			c=999;
			for(int k=i+1;k<=j;k++){
				int cost=C[i][k-1]+C[k][j]+W[i][j];
				if(cost<c){
					c=cost;
					finalk=k;
				
				}
			}
		}
		void table(){
			for(int i=0;i<=n;i++){
				W[i][i]=qi[i];
				C[i][i]=R[i][i]=0;
			}
			for(int i=0;i<=n-1;i++){
				int j=i+1;
				W[i][j]=pi[j]+qi[j]+W[i][i];
				C[i][j]=W[i][j];
				R[i][j]=j;
			}
			for(int d=2;d<=n;d++){
				for(int i=0;i+d<=n;i++){
					 int j=i+d;
					 W[i][j]=pi[j]+qi[j]+W[i][j-1];
					 mink(i,j);
					 C[i][j]=c;
					 R[i][j]=finalk;
				}
			}
		}
		void displaytable(){
			cout<<"\n";
			for(int dif=0;dif<=n;dif++){
				cout<<"\nDiff "<<dif<<":"<<endl;
				for(int ii=0;ii<=n-dif;ii++){
					int jj=ii+dif;
					cout<<ii<<jj<<"->"<<W[ii][jj]<<"->"<<C[ii][jj]<<"->"<<R[ii][jj]<<endl;
				}
			}
		}
		void displaytree(){
			cout<<"\nROOT\t\tLEFT CHILD\t\tRIGHT CHILD\n";
			q1.push(0);
			q1.push(n);
			while(!q1.empty()){
				int i1=q1.front();
				q1.pop();
				int j1=q1.front();
				q1.pop();
				int k1=R[i1][j1];
				cout<<name[k1]<<"\t\t";
				if(R[i1][k1-1]!=0){
					cout<<name[R[i1][k1-1]]<<"\t\t";
					q1.push(i1);
					q1.push(k1-1);
				}else{
					cout<<"NULL"<<"\t\t";
				}
				if(R[k1][j1]!=0){
					cout<<name[R[k1][j1]]<<"\t\t";
					q1.push(k1);
					q1.push(j1);
				}else{
					cout<<"NULL"<<"\t\t";
				}
				cout<<endl;
			}
		}
};
int main(){
	object ob;
	ob.input();
	ob.display();
	ob.table();
	ob.displaytable();
	ob.displaytree();
	return 0;
}
