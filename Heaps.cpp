/* Array implementation of Heaps.
   It would be much better to implement using vectors.
*/

#include<iostream>
#include<algorithm>
using namespace std;

int find_max(int ar[],int size){
	return ar[size];
}

void insert(int ar[],int ele, int size,int &ctr){
	int temp;	
	if(ctr>size){
		cout<<"Cannot insert. Max limit overload!"<<endl;
		break;
	}
	else{
		ar[ctr]=ele;
		ctr++;
		int i=ctr;	
		while(i/2>=1 && ar[i/2]<ar[i]){
			temp=ar[i/2];
			ar[i/2]=ar[i];
			ar[i/2]=temp;
			i=i/2;
		}
	}
}

void max_heapify(int ar[],int i,int size){
	int temp;	
	if((2*i+1)<=size){
		if(ar[2*i+1]>ar[i]){
			temp=ar[i];
			ar[i]=ar[2*i+1];
			ar[2*i+1]=temp;
		}
	}
	if((2*i)<=size){
		if(ar[2*i]>ar[i]){
			temp=ar[i];
			ar[i]=ar[2*i];
			ar[2*i]=temp;
		}
	}
}
	

void build_heap(int ar[],int size){
	for(int i=size/2;i>=1;i--){
		max_heapify(ar,i,size);
	}
}	

void delete_max(int ar[],int &last){
	int i=1;
	int temp;
	ar[1]=ar[last];
	ar[last]=0;
	last--;
	while(i<=(last-1)/2 && (ar[i]<ar[2*i] || ar[i]<ar[2*i+1])){
		if(ar[2*i+1]>ar[2*i]){
			temp=ar[i];
			ar[i]=ar[2*i+1];
			ar[2*i+1]=temp;
			i=2*i+1;
		}
		else{
			temp=ar[i];
			ar[i]=ar[2*i];
			ar[2*i]=temp;
			i=2*i;
		}
	}		
}



int main(){
	
