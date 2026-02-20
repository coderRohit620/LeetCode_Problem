#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;


void findMaxMin(int arr[], int n){

    
    int smallest = INT_MAX;
    int largest = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        smallest = min(arr[i],smallest);
        largest = max(arr[i],largest);
    }
    
    cout<<"Smallest ="<<smallest<<endl;
    cout<<"Largest ="<<largest;

}
int main(){

    int arr[] = {10, 20, 5, 30, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    findMaxMin(arr, n);
    return 0;
}

