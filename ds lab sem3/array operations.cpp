#include <iostream>
using namespace std;


// Made by Arnav Rana 23/SE/35



int main(){
	int n;
	cin>>n;
	int arr[n];
	cout<<"Enter the elements of array :";
	int a;
	for(a=0;a<n;a++){
		cin>>arr[a];
	}
	cout<<endl;
	cout<<"Enter the position of element to be deleted :";
	int k;
	cin>>k;
	int temp=arr[k-1];
	for(a=k-1;a<n-1;a++){
		arr[a]=arr[a+1];
	}
	arr[n-1]=temp;
	cout<<endl;
	cout<<"New array after deletion is:"<<endl;
	for(a=0;a<n-1;a++){
		cout<<arr[a]<<" ";
	}
	cout<<endl;
	temp=arr[0];
	int temp2=arr[0];
	for(a=0;a<n-1;a++){
		if(arr[a]<=temp){
			temp=arr[a];
		}
		else if(arr[a]>=temp2){
			temp2=arr[a];
		}
		else{
			continue;
		}
	}
	cout<<"The smallest element is :";
	cout<<temp<<endl;
	cout<<"The largest element is :";
	cout<<temp2<<endl;


	return 0;
}