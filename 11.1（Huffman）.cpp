#include<iostream>
#include <iomanip>
using namespace std;

struct element{
	int weight;     
	int lchild, rchild, parent;  
};

void selectMin(element a[], int n, int& s1, int& s2){
	for (int i = 0; i < n; i++){
		if (a[i].parent == -1){
			s1 = i;
			break;
		}
	}
	for (int i = 0; i < n; i++){
		if (a[i].parent == -1 && a[s1].weight > a[i].weight)
			s1 = i;
	}
	for (int j = 0; j < n; j++){
		if (a[j].parent == -1 && j != s1){
			s2 = j;
			break;
		}
	}
	for (int j = 0; j < n; j++){
		if (a[j].parent == -1 && a[s2].weight > a[j].weight && j != s1)
			s2 = j;
	}
}

void HuffmanTree(element huftree[], int w[], int n){
	for (int i = 0; i < 2 * n - 1; i++){
		huftree[i].parent = -1;
		huftree[i].lchild = -1;
		huftree[i].rchild = -1;
	}
	for (int i = 0; i < n; i++)    
		huftree[i].weight = w[i];
	for (int k = n; k < 2 * n - 1; k++) {
		int i1, i2;
		selectMin(huftree, k, i1, i2); 
		huftree[i1].parent = k;
		huftree[i2].parent = k;
		huftree[k].lchild = i1;
		huftree[k].rchild = i2;
		huftree[k].weight = huftree[i1].weight + huftree[i2].weight;
	}
}

void print(element hT[], int n){
	cout << "index weight parent lChild rChild" << endl;
	cout << left;    
	for (int i = 0; i < n; ++i){
		cout << setw(5) << i << " ";
		cout << setw(6) << hT[i].weight << " ";
		cout << setw(6) << hT[i].parent << " ";
		cout << setw(6) << hT[i].lchild << " ";
		cout << setw(6) << hT[i].rchild << endl;
	}
}

int main(){
	int x[] = { 5,29,7,8,14,23,3,11 };      
	element* hufftree = new element[2 * 8 - 1]; 
	HuffmanTree(hufftree, x, 8);
	print(hufftree, 15);
	system("pause");
	return 0;
}
