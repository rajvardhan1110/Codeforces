#include <iostream>
#include <cstdlib>
#include  <ctime>
#include <algorithm>
#include <vector>

using namespace std;

void quicksort(int i, int j,vector<int>& arr){
    if(i > j){
        return;
    }

    int pivot = arr[i];

    int left = i+1;
    int right = j;

    while(left <= right){
        if(arr[left] <= pivot){
            left++;
        }else if(arr[right] > pivot){
            right--;
        }else{
            swap(arr[left],arr[right]);
            left++;
            right--;
        }
    }

    swap(arr[i],arr[right]);

    quicksort(i,right-1,arr);
    quicksort(right+1,j,arr);
}

int main(){

    int n = 1000000;
    vector<int> arr(n);

    srand(42);

    for(int i = 0; i<n; i++){
        arr[i] = rand();
    }

    quicksort(0,n-1,arr);

    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;

    return 0;
}
