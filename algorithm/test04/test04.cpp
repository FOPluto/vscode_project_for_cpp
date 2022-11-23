#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1000010;
int arr[N];
int n;

void Qsort(int l, int r, int arr[]){
	if(l >= r) return;
	int i = l - 1;
	int j = r + 1;
	int mid = i + j + 1 >> 1;
	while(i < j){
		do i++; while(arr[i] < arr[mid]);
		do j--; while(arr[j] > arr[mid]);
		if(i < j) swap(arr[i], arr[j]);
	}
	Qsort(l, i - 1, arr);
	Qsort(i, r, arr);
}

int main(){
	scanf("%d", &n);
	for(int i = 0;i < n;i++){
		scanf("%d", &arr[i]);
	}
	Qsort(0, n - 1,  arr);
	for(int i = 0;i < n;i++){
		printf("%d ",arr[i]);
	}
	printf("%d", arr[n - 1] - arr[0]);
	return 0;
}