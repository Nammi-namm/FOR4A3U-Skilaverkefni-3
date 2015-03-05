#include<iostream>
using namespace std;

/*
Benedikt M. Scheving-Thorsteinsson



Skrifið forrit sem vinnur með kviklegt fyrlki (dynamic array).

Forritið á að geta:
- Bæta tölu aftast í fylkið
- Reikna meðaltal af öllum tölunum í fylkinu
- Sortera fylkið
- Þjappa fylkinu
- Sækja tölu í staki
- Skrifa út capacity og size

Dæmi um útfærslu væri að byrja með fylki af stærðinni 10 og vera með tvær int breytur til að halda utan um capacity og count. capacity er þá raunveruleg stærð á fylkinu meðan count er fjöldi staka sem er verið að nota í fylkinu.
Þegar notandi er búinn að fylla fylkið er búið til nýtt sem er af stærðinni capacity*2 og allt úr gamla kóperað yfir í nýja og pointerinn látinn benda á réttan stað.
Passa að það sé ekki minnisleki!!!

Fáið gefins main.cpp skránna. Þurfið "bara" að útfæra öll föllin í henni svo hún keyri.
Henti henni bara upp í flýti svo mögulega breytist hún eitthvað í kvöld eða á morgun.
Ef svo er þá verður það ekki mikil breyting.
*/

// Í þessu verkefni fáið þið leyfi til að nota þessar 2 global breytur.
int Capacity = 10;
int Size = 0;

// Tekur inn fylkið
// Tvöfaldar capacity 
// returnar pointer á nýtt fylki sem helmingi stærra en gamla. 
int* increase(int* arr){
	Capacity = Capacity * 2;
	int *foo = new int[Capacity];
	for (int i = 0; i < Capacity; i++) {
		foo[i] = arr[i];
	}
	return foo;
}

// Bætir item aftast í arr.
void push(int* arr, int item){
	Size += 1;
	arr[Size - 1] = item;
	if (Size > Capacity) {
		increase(arr);
	}
}

// Skrifar út á skjá meðaltalið
void average(int* arr){
	int total = 0;
	for (int i = 0; i < Size; i++) {
		total += arr[i];
	}
	total = total / Size;
	cout << "Average is " << total << endl;
}

// Sorterar fylkið
void sort(int* arr){
	for (int i = 0; i < Size; i++) {
		for (int y = i + 1; y < Size; y++) {
			if (arr[i] > arr[y]) {
				// swap
				int t = arr[i];
				arr[i] = arr[y];
				arr[y] = t;
			}
		}
	}
}

// Minkar capacity niður í size og breytir stærðinni á fylkinu samkvæmt því
void compress(int* arr){
	Capacity = Size;
	arr[Capacity] = 0;
	
}

// Skrifar út öll stök í fylkinu í eina línu með bil á milli talna
void printArr(int* arr){
	for (int i = 0; i < Size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

// Skrifar út capacity og size
void printInfo(){
	cout << "Size: " << Size << " - Capacity: " << Capacity << endl;
}

// Skilar öllu minni sem var notað
void returnMem(int* arr){
	cout << "Memory used is: " << sizeof(arr) << endl;
}

int main() {
	int *arr = new int[Capacity];
	push(arr, 10);
	push(arr, 8);
	push(arr, 6);
	printArr(arr); //10 8 6
	sort(arr);
	printArr(arr); //6 8 10
	printInfo(); //Size: 3 - Capacity: 10
	compress(arr);
	printInfo(); //Size: 3 - Capacity: 3
	push(arr, 4);
	printArr(arr); //6 8 10 4
	printInfo(); //Size: 4 - Capacity: 6
	average(arr); //7
	arr = increase(arr);
	printInfo(); //Size: 4 - Capacity: 12
	returnMem(arr);
	return 0;
}
