#include <bits/stdc++.h>
using namespace std;

//made by Arnav Gupta 23/SE/34
int main()
{
    vector<int> arr;
    int counter = 0;
    cout << "1. for adding element" << endl;
    cout << "2. for deleting element" << endl;
    cout << "3. largest element" << endl;
    cout << "4. smallest element" << endl;
    cout << "***********************" << endl;
    do
    {
        cout << "enter the counter : ";
        cin >> counter;
        if (counter == 1)
        {
            int n;
            cout << "enter the number of elements" << endl;
            cin >> n;
            int num;
            for (int i = 0; i < n; i++)
            {
                cin >> num;
                arr.push_back(num);
            }
            cout<<endl;
        }
        else if (counter == 2)
        {
            int index = -1;
            cout << "enter the index : ";
            cin >> index;
            arr.erase(arr.begin() + index);
            cout<<"the remaining array is "<<endl;
            for(int i=0;i<arr.size();i++){
                cout<<arr[i]<<" ";
            }
        }
        else if (counter == 3)
        {
            int maxm = INT_MIN;
            int n = arr.size();
            for (int i = 0; i < n; i++)
            {
                if (arr[i] > maxm)
                {
                    maxm = max(arr[i], maxm);
                }
            }
            cout << "largest element is : " << maxm << endl;
        }
        else if (counter == 4)
        {
            int minm = INT_MAX;
            int n = arr.size();
            for (int i = 0; i < n; i++)
            {
                if (arr[i] < minm)
                {
                    minm = min(arr[i], minm);
                }
            }
            cout << "smallest element is : " << minm << endl;
        }
        else
        {
            cout << "invalid choice";
            break;
        }
    } while (counter > 0 && counter < 5);

    return 0;
}