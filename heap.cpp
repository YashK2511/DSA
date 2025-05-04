#include<iostream>
using namespace std;
class heap{
	public:
		int n,min[50],max[50];
		void input(){
			cout<<"Enter number of total numbers:";
			cin>>n;
			for(int i=0;i<n;i++){
				cout<<"Enter individual numbers:";
				cin>>min[i];
				max[i]=min[i];
			}
		}
		void maxHeap(){
			for(int i=(n/2)-1;i>=0;i--){
				while((2*i+1)<n){
					int child=2*i+1;
					if(child+1<n && max[child]<max[child+1]){
						child++;
					}
					if(max[i]<max[child]){
						swap(max[i],max[child]);
						i=child;
					}else{
						break;
					}
				}
			}
			for(int i=0;i<n;i++){
				cout<<max[i]<<" ";
			}
			cout<<endl;
		}
		void minHeap(){
			for(int i=(n/2)-1;i>=0;i--){
				while((2*i+1)<n){
					int child=2*i+1;
					if(child+1<n && max[child]<max[child+1]){
						child++;
					}
					if(min[i]>min[child]){
						swap(min[i],min[child]);
						i=child;
					}else{
						break;
					}
				}
			}
			for(int i=0;i<n;i++){
				cout<<min[i]<<" ";
			}
			cout<<endl;
		}
};
int main(){
	heap h;
	h.input();

	h.maxHeap();
	
	h.minHeap();

	return 0;
}
