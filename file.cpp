#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class studata{
	public:
		int roll;
		char name[20], add[30];
		
		void read(){
			cout<<"Enter roll:"; cin>>roll;
			cout<<"Enter name:"; cin>>name;
			cout<<"Enter add:"; cin>>add;
		}
		void display(){
			cout<<"ROLL :-"<<roll;
			cout<<"NAME :-"<<name;
			cout<<"ADD :-"<<add;
		}
		
};
int main(){
	studata s;
	ofstream fout,temp;
	ifstream fin;
	char choice;
	int ch,flag;
	do{
		cout<<"\n 1.Write data \n 2.append data \n 3.read data \n 4.search data \n 5.deleton of data";
		cout<<"\n Enter the your choice";
		cin>>ch;
		switch(ch){
			case 1://Write data
				int n;
				fout.open("student.txt",ios::out);
				cout<<"enter number of students to enter:"; cin>>n;
				for(int i=0;i<n;i++){
					s.read();
					fout.write((char*)&s,sizeof(s));
				}
				fout.close();
				break;
			case 2:
				fout.open("student.txt",ios::app);
				s.read();
				fout.write((char*)&s,sizeof(s));
				fout.close();
				break;
			case 3:
				cout<<"Reading data from file...";
				fin.open("student.txt");
				while(fin.read((char*)&s,sizeof(s))){
					s.display();
				}
				fin.close();
				break;
			case 4:
				int r;
				flag=0;
				cout<<"Enter roll to search:"; cin>>r;
				fin.open("student.txt");
				while(fin.read((char*)&s,sizeof(s))){
					if(s.roll==r){
						cout<<"Data found..."<<endl;
						s.display();
						flag=1;
						break;
					}
				}
				if(flag==0){
					cout<<"Data cannot be found...";
				}
				fin.close();
				break;
			case 5:
				int d;
				flag=0;
				cout<<"\n Enter the rollno to be deleted:"; cin>>d;
				fin.open("student.txt");
				temp.open("temp.txt", ios::out);
				while (fin.read((char*)&s, sizeof(s))) {
				    if (s.roll != d) {
				        temp.write((char*)&s, sizeof(s));
				    } else {
				        cout << "Deleted";
				        flag = 1;
				    }
				}
				fin.close();
				temp.close();
				remove("student.txt");
				rename("temp.txt", "student.txt");
				if(flag==0){
					cout<<"Data not available...";
				}
				break;
			default: cout<<"\n Your choice is wrong";
		}
		cout<<"\nDo you want to continue ";
		cin>>choice;
	}
	while(choice=='y');
	return 0;
}
