#include<iostream>
#include<string>
using namespace std;
class hashtable{
	public:
		struct table{
			int uid;
			string name;
		};
		table linbook[20];
		table quadbook[20];
		int size=10;
		
		hashtable(){
			for(int i=0;i<size;i++){
				linbook[i].uid=-1;
				linbook[i].name="NULL";
				quadbook[i].uid=-1;
				quadbook[i].name="NULL";
			}
		}
		
		void insertlin(int uid,string name){
			int hash=uid%size;
			int i=0;
			while(linbook[hash].uid != -1 && i<size){
				hash=(hash+1)%size;
				i++;
			}
			if(i==size){
				cout<<"Linear table full..";
			}else{
				linbook[hash].name=name;
				linbook[hash].uid=uid;
			}
		}
		
		void insertquad(int uid,string name){
			int hash=uid%size;
			int i=0;
			while(quadbook[(hash+i*i)%size].uid!=-1 && i<size){
				i++;
			}
			if(i==size){
				cout<<"quad table full..";
			}else{
				int pos=(hash+i*i)%size;
				quadbook[pos].name=name;
				quadbook[pos].uid=uid;
			}
		}
		
		void input(){
			char ch;
			do{
				int uid;
				string name;
				cout<<"Enter uid:";
				cin>>uid;
				cout<<"Enter name";
				cin>>name;
				insertlin(uid,name);
				insertquad(uid,name);
				
				cout<<"do you want to enter another user(y/n):";
				cin>>ch;
			}while(ch=='y');
		}
		
		void search(){
			int uid;
			cout<<"Enter the uid to search:"; cin>>uid;
			int flag=0;
			for(int i=0;i<size;i++){
				if(linbook[i].uid==uid){
					cout<<"User found in linear book..."<<endl;
					cout<<"Name:-"<<linbook[i].name;
					flag=1;
					break;
				}
			}
			if(flag==0){
				cout<<"User cannot be found in linear book...";
			}
			
			flag=0;
			for(int i=0;i<size;i++){
				if(quadbook[i].uid==uid){
					cout<<"User found in quad book..."<<endl;
					cout<<"Name:-"<<quadbook[i].name;
					flag=1;
					break;
				}
			}
			if(flag==0){
				cout<<"User cannot be found in quad book...";
			}
		}
		
		void display(){
	        cout << "\nLinear Hash Table:\nID\tName" << endl;
	        for (int i = 0; i < size; i++) {
	            cout << linbook[i].uid << "\t" << linbook[i].name << endl;
	        }
	
	        cout << "\nQuadratic Hash Table:\nID\tName" << endl;
	        for (int i = 0; i < size; i++) {
	            cout << quadbook[i].uid << "\t" << quadbook[i].name << endl;
	        }
    	}		
};
int main(){
	hashtable h;
	h.input();
	h.display();
	h.search();
	return 0;
}
