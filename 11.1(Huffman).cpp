#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
class node{
public:
	node* left, * right;	
	int val, ID;			
	string code;			
	node(int val, int ID){
		this->ID = ID;
		this->val = val;
		this->left = this->right = nullptr;
		this->code = "";
	}
	node(int val, node* L, node* R){
		this->val = val;
		this->left = L;
		this->right = R;
		code = "";
	}
	bool morethan(const node* p) const{
		return this->val > p->val;
	}
};
class nodeCompare{
public:
	nodeCompare() {}
	bool operator () (const node* p1, const node* p2) const{
		return p1->morethan(p2);
	}
};
priority_queue<node*,vector<node*>,nodeCompare>que;
void TravelTree(node* root){
	if (root) {
		if (root->left)root->left->code = root->code + "1";
		if (root->right)root->right->code = root->code + "0";
		if (!root->left && !root->right)printf("%d %s\n", root->ID, root->code.c_str());
		TravelTree(root->left);
		TravelTree(root->right);
	}
}
node* createHuffmanTree(int fqy[], int n){
	for (int i = 1; i <= n; i++){
		node* tmp = new node(fqy[i - 1], i);
		que.push(tmp);
	}
	while (que.size() != 1){
		node* L = que.top();
		que.pop();
		node* R = que.top();
		que.pop();
		node* newNode = new node(L->val + R->val, L, R);
		que.push(newNode);
	}
	TravelTree(que.top());
	return nullptr;
}
int main() {
	int fqy[] = { 5,5,10,10,10,15,20,25 };
	createHuffmanTree(fqy, 8);
}
