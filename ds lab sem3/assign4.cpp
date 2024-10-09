#include <iostream>
using namespace std;

//Made By ARNAV RANA 23/SE/35


int main(){
	cout<<"Enter the number of elements in array:";
	int n;
	cin>>n;
	int arr[n];
	int a;
	cout<<endl;
	cout<<"Enter the elements of the array:";
	for(a=0;a<n;a++){
		cin>>arr[a];
	}
	cout<<endl;
	cout<<"Enter the element to be changed:";
	int temp1;
	cin>>temp1;
	cout<<endl;
	cout<<"enter the new element to be updated:";
	int temp2;
	cin>>temp2;
	cout<<endl;
	for(a=0;a<n;a++){
		if(arr[a]==temp1){
			arr[a]=temp2;
			break;	
		}
	}
	cout<<"New array after updation is:";
	for(a=0;a<n;a++){
		cout<<arr[a]<<" ";
	}





	return 0;
}