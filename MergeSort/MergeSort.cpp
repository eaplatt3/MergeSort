#include <iostream>

using namespace std;

//Merges the two halves 
void Merge(int *a, int low, int high, int mid) {

	int i;
	int j;
	int k;
	int temp[high - low + 1];

	i = low;
	k = 0;
	j = mid + 1;

	//Merges the two parts into a temp array
	while (i <= mid && j <= high) {
		if (a[i] < a[j]) {
			temp[k] = a[i];
			k++;
			i++;
		}
		else {
			temp[k] = a[j];
			k++;
			j++;
		}

	}

	//Inserts all left over values in i to mid into temp array
	while (i <= mid) {
		temp[k] = a[i];
		k++;
		i++;
	}

	//Inserts all left over values in j to high into temp array
	while (j <= high) {
		temp[k] = a[j];
		k++;
		j++;
	}

	//Assigns sorted data in temp array into a array
	for (i = low; i <= high; i++) {
		a[i] = temp[i - low];
	}
}

//Function to split array into two parts
void MergeSort(int* a, int low, int high) {

	int mid;
	if (low < high) {
		mid = (low + high) / 2;
		MergeSort(a, low, mid);
		MergeSort(a, mid + 1, high);

		Merge(a, low, high, mid);
	}
}

int main()
{
	//Variables
	int rNum;
	int arr[10]; //creates array with 10 slots

	//Loop to fill array with random numbers & prints them 
	for (int i = 1; i < 10; i++) {

		arr[i] = 1 + rand() % 10;
		cout << " " << arr[i];
	}

	//Call to MergeSort to sort random numbers in order & prints them 
	MergeSort(arr, 0, rNum - 1);
	for (int i = 0; i < rNum; i++) {
		cout << "->" << arr[i];
	}

	//cout << "Loop Finished!";

	return 0;
}


