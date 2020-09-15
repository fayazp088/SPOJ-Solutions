#include<bits/stdc++.h>
#define int long long

using namespace std;


int inversionCount = 0;


void merge(int* array, int start, int midPoint, int end){
	//Creating 2 temp array

	int leftArraySize = midPoint - start + 1;
	int rightArraySize = end - midPoint;

	int leftArray[leftArraySize], rightArray[rightArraySize]; // Temp arrays

	//Copying the content actual array content into the temp arrays

	for(int i = 0; i < leftArraySize; ++i)
		leftArray[i] = array[start + i];

	for(int i = 0; i < rightArraySize; ++i)
		rightArray[i] = array[midPoint + i + 1];

	int i = 0, j = 0, k = start; //Creating 3 pointer variables

	while(i < leftArraySize and j < rightArraySize){
		if(leftArray[i] <= rightArray[j]){
			array[k] = leftArray[i];
			i++;
		}else{
			array[k] = rightArray[j];
			j++;
			inversionCount += (leftArraySize - i);
		}
		k++;
	}

	//Copying the remaining elements
	while(i < leftArraySize){
		array[k] = leftArray[i];
		i++;
		k++;
	}

	while(j < rightArraySize){
		array[k] = rightArray[j];
		j++;
		k++;
	}
}


void mergeSort(int array[], int start, int end){
		if(start < end){
			int midPoint = start + (end - start) / 2;

			mergeSort(array, start, midPoint);
			mergeSort(array, midPoint + 1, end);

			merge(array, start, midPoint, end);
		}
}

int32_t main(){
	int testCases; cin >> testCases;

	while(testCases--){
		int arraySize; cin >> arraySize;

		int array[arraySize];

		for(int i = 0; i < arraySize; ++i) cin >> array[i];

		inversionCount = 0;

		mergeSort(array, 0, arraySize - 1);

		cout << inversionCount << endl;
	}

	return 0;
}
