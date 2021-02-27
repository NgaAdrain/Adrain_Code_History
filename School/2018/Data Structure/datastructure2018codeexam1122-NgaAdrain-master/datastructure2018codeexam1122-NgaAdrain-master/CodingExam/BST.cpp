//학번: 201524582
//이름(한글): 정희석
//Name(English): JeongHeeSeok

//1. Binary Search Tree
//화면에서 입력받아 BST를 만든다
//입력후 BalancingFactor = left subtree의 노드 수 – right subtree의 노드 수;
// BalancingFactor => 3(<= -3)이면 +2 or -2가 되는 subtree와 나머지로 split한후에 join하는 adjust하는 프로그램 작성
// 10 20 30 40 50 60 또는 5 4 3 2 1로 입력시에 대하여만 동작해도 됨

#include <iostream>

using namespace std;

class Element {
public:
	int key;
	Element() {}
	Element(int key) :key(key) {}
};

class BstNode {
	friend class BST;
public:
	void display(int i);
	void treeprint(int i);
private:
	int BalancingFactor; //BF가 추가됨
	Element data;
	BstNode *LeftChild, *RightChild;
};


class BST {
public:
	BST(BstNode *init = 0) { root = init; };

	//   BST& operator=(const BST&);

	bool Insert(const Element& x);
	//bool Delete(const Element&);
	BstNode* Search(BstNode*, const Element&);
	BstNode* Search(const Element&);
	BstNode* IterSearch(const Element&);

	BST* ThreeWayJoin(BST *A, Element *x, BST *B);
	BST* TwoWayJoin(BST *A, BST *B);

	void treeprint() { cout << "\n"; root->treeprint(1); }

	void display() {
		cout << "\n";
		if (root) root->display(1);
		else cout << "0\n";
	};
	Element* Split(int i, BST& B, BST& C, Element &x);
private:
	BstNode * root;

private:
	bool DeleteLargestElement(Element& outElement);
};



void BstNode::display(int i)
{
	cout << "Position " << i << ": data.key " << data.key << "\n";
	if (LeftChild) LeftChild->display(2 * i);
	if (RightChild) RightChild->display(2 * i + 1);
};


Element* BST::Split(int i, BST& B, BST& C, Element &x)
// Split the binary search tree with respect to key i
{
	if (!root) {// empty tree
		B.root = C.root = 0;
		return 0;
	}

	BstNode *Y = new BstNode;
	BstNode *L = Y;
	BstNode *Z = new BstNode;
	BstNode *R = Z;
	BstNode *t = root;
	while (t)
		if (i == t->data.key) {  // split at t
			L->RightChild = t->LeftChild;
			R->LeftChild = t->RightChild;
			x = t->data;
			B.root = Y->RightChild; delete Y;
			C.root = Z->LeftChild; delete Z;
			return &x;
		}
		else if (i < t->data.key) {
			R->LeftChild = t;
			R = t;
			t = t->LeftChild;
		}
		else {
			L->RightChild = t;
			L = t;
			t = t->RightChild;
		}
		L->RightChild = R->LeftChild = 0;
		B.root = Y->RightChild;
		delete Y;
		C.root = Z->LeftChild;
		delete Z;
		return 0;
}


void BstNode::treeprint(int l)
{
	if (this) {
		(this->RightChild)->treeprint(l + 1);
		for (int i = 1; i <= l; i++) cout << "   ";
		cout << this->data.key << "\n";
		(this->LeftChild)->treeprint(l + 1);
	};
};


BstNode* BST::Search(BstNode* b, const Element &x)
{
	if (!b) return 0;
	if (x.key == b->data.key) return b;
	if (x.key < b->data.key) return Search(b->LeftChild, x);
	return Search(b->RightChild, x);
};


BstNode* BST::Search(const Element& x)
{
	return Search(root, x);
}


BstNode* BST::IterSearch(const Element& x)
{
	for (BstNode *t = root; t; )
	{
		if (x.key == t->data.key) return t;
		if (x.key < t->data.key) t = t->LeftChild;
		else t = t->RightChild;
	}
	return 0;
}

//BstNode* BST::Search(int k){//Search by rank;
//	BstNode *t = root;
//	while (1)
//	{
//		if (k == t->LeftSize) return t;
//		if (k < t->LeftSize) t = t->LeftChild;
//		else {
//			k -= LeftSize;
//			t = t->RightChild;
//		}
//	}
//	return 0;
//}

bool BST::Insert(const Element& x)
{
	BstNode *p = root;
	BstNode *q = 0;
	while (p) {
		q = p;
		if (x.key == p->data.key) return false; //x.key is already in t
		if (x.key < p->data.key) p = p->LeftChild;
		else p = p->RightChild;
	};
	p = new BstNode;
	p->LeftChild = p->RightChild = 0; p->data = x;
	if (!root) root = p;
	else if (x.key < q->data.key) q->LeftChild = p;
	else q->RightChild = p;
	return true;
}

bool BST::DeleteLargestElement(Element& outElement) {
	BstNode * deletedNode = nullptr;
	if (!root) return false;

	if (!root->RightChild) {//the tree does not have right sub-tree
		deletedNode = root;
		root = root->LeftChild;
	}
	else {
		BstNode * parentNode = root, *currNode = root;
		while (currNode->RightChild) {
			parentNode = currNode;
			currNode = currNode->RightChild;
		}
		if (currNode->LeftChild) {//the largest node has left child
			parentNode->RightChild = currNode->LeftChild;
			deletedNode = currNode;
		}
		else {//the larget node is a leaf node.
			deletedNode = currNode;
			parentNode->RightChild = nullptr;
		}
	}
	outElement = deletedNode->data;
	delete deletedNode;
	deletedNode = nullptr;
	return true;
}

BST* BST::ThreeWayJoin(BST *A, Element *x, BST *B) {
	//To be implemented
	BstNode * newNode = new BstNode;
	newNode->data = *x;
	newNode->LeftChild = A->root;
	newNode->RightChild = B->root;

	BST * newTree = new BST;
	newTree->root = newNode;
	return newTree;
}

BST* BST::TwoWayJoin(BST *A, BST *B)
{
	if (!A) return B;
	if (!B) return A;

	Element midEle;
	A->DeleteLargestElement(midEle);

	//x = largest element of A or smallest element of B
	return ThreeWayJoin(A, &midEle, B);
}



int main() {
	int select = 0;
	int data = 0;
	BST tree;
	BST splitTree1;
	BST splitTree2;
	BST *joinTree = nullptr;
	Element ele;

	Element *tempEle;

	do {
		cout << "binary search tree. Select: 1 insert, 2 display, 3 split and join, >=5 exit" << endl;
		cin >> select;
		switch (select) {
		case 1:
			cout << "input value: ";
			cin >> data;
			tree.Insert(Element(data));// Insert()에서 BF를 체크하여 split하는 것을 호출해야 한다.
			tree.treeprint();
			break;
		case 2:
			tree.display();
			break;
		case 3:
			cout << "intput splited tree note: ";
			cin >> data;
			tempEle = tree.Split(data, splitTree1, splitTree2, ele);
			if (tempEle != 0) {
				cout << "------------ThreeWayJoinTree-------------------" << endl;
				cout << "mid element = " << data << endl;
				cout << "splited tree 1: " << endl;
				splitTree1.treeprint();
				cout << "splited tree 2: " << endl;
				splitTree2.treeprint();
				cout << "join the splited trees: " << endl;
				joinTree = tree.ThreeWayJoin(&splitTree1, tempEle, &splitTree2);
				joinTree->treeprint();
				cout << "------------TwoWayJoinTree-------------------" << endl;
				cout << "splited tree 1: " << endl;
				splitTree1.treeprint();
				cout << "splited tree 2: " << endl;
				splitTree2.treeprint();
				cout << "join the splited trees: " << endl;
				joinTree = tree.TwoWayJoin(&splitTree1, &splitTree2);
				joinTree->treeprint();
			}
			break;
		case 5:
			exit(1);
			break;

		}
	} while (select < 5);

	return 0;
}
