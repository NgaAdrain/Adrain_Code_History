//학번: 201524582
//이름(한글): 정희석
//Name(English): JeongHeeSeok
//3. Satisfiable Tree
//logical expression 대신에 A= B*C-D*E + F를 연산자 우선순위에 따라 tree로 표현하고 A 값을 계산하는 프로그램 작성한다. A,B,C,D,E,F는 정수임
//변수 값은 화면에서 입력받는다
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;


void full_combine(vector<int*>* result, int *data, int cur, int len)
{
	if (cur == len) {
		int* newCombination = new int[len];
		for (int i = 0; i < len; i++) {
			newCombination[i] = data[i];
			//cout << data[i];
		}
		//cout << endl;
		result->push_back(newCombination);
	}
	else {
		data[cur] = 1;
		full_combine(result, data, cur + 1, len);
		data[cur] = 0;
		full_combine(result, data, cur + 1, len);
	}
}

void full_combine(int size, vector<int*> *result) {
	int *data = new int[size];

	full_combine(result, data, 0, size);

	delete[]data;
}


enum TypesOfData {
	PLUS,MINUS,DIV,POW,INVALID
};

class SatTree;

class SatNode {
	friend class SatTree;
private:
	SatNode * LeftChild;
	TypesOfData data;
	int value;
	char notation;
	SatNode *RightChild;
	SatNode() { LeftChild = RightChild = 0; };

	SatNode(TypesOfData tod) {
		data = tod;
	}

	SatNode(TypesOfData tod, char notation) {
		data = tod;
		this->notation = notation;
	}

	SatNode(TypesOfData tod, SatNode *Lefty, SatNode *Righty)
	{
		data = tod;
		LeftChild = Lefty;
		RightChild = Righty;
	}
};

class SatTree {
private:
	SatNode * root;
	void PostOrderEval(SatNode *);

	vector<SatNode*> leafNodeList;//store references of all leaves in the tree
	SatNode * MakeSatTree(string prefixNotation, int &index);
	void clear(SatNode * currNode);
public:
	void PostOrderEval();
	SatTree() { root = 0; };
	void setup();
	void setup2();

	void MakeSatTree(string prefixNotation);
	void Satisfiable();

	void rootvalue() {
		cout << "result: ";
		if (root->value) {
			cout << "true" << endl;
		}
		else {
			cout << "false" << endl;
		}
	};

	void clear() {
		clear(root);
		leafNodeList.clear();

	}

	~SatTree() { clear(); }
};



void SatTree::PostOrderEval()
{
	PostOrderEval(root);
}

void SatTree::PostOrderEval(SatNode *s)
{
	if (s) {
		
	}
}

//(False|True)&(!False), result = True
/*void SatTree::setup()
{
	root = new SatNode(LogicalAnd);
	root->LeftChild = new SatNode(LogicalOr);
	root->LeftChild->LeftChild = new SatNode(LogicalFalse);
	root->LeftChild->RightChild = new SatNode(LogicalTrue);
	root->RightChild = new SatNode(LogicalNot);
	root->RightChild->RightChild = new SatNode(LogicalFalse);

	cout << "set up: (False|True)&(!False)" << endl;
}

//(False & True) | (False)
void SatTree::setup2() {
	root = nullptr;

	root = new SatNode(LogicalOr);
	SatNode * n1 = new SatNode(LogicalAnd);
	root->LeftChild = n1;
	n1->LeftChild = new SatNode(LogicalFalse);
	n1->RightChild = new SatNode(LogicalTrue);
	root->RightChild = new SatNode(LogicalFalse);

	cout << "set up: (False & True) | (False)" << endl;
}
*/

bool isLeafNode(char c) {
	if (c == '!' || c == '&' || c == '|') return false;
	return true;
}


TypesOfData transfromCharToLogic(char c) {
	switch (c) {
	case '+': return PLUS;
	case '-': return MINUS;
	case '*': return POW;
	case '/': return DIV;
	default: return INVALID;
	}
}

//calculate and print out all possible satisfiable combinations.
void SatTree::Satisfiable() {
	bool hasSatisfied = false;

	vector<int*> combinationVector;//store all kinds of combination
	full_combine(leafNodeList.size(), &combinationVector);//calculate all combination

	for (int * arr : combinationVector) {//"arr" is one kind of combination
										 //update the logic of leaves nodes based on the new combination.
		/*
		for (int i = 0; i < leafNodeList.size(); i++) {
			if (arr[i]) leafNodeList[i]->data = LogicalTrue;
			else leafNodeList[i]->data = LogicalFalse;
		}
		*/

		PostOrderEval(root);

		if (root->value) {//if it is satisfied, print out
			cout << "satisfiable combination" << endl;
			for (SatNode * node : leafNodeList) {
				cout << ((char)node->notation) << " = ";
				if (node->value) cout << "True" << ", ";
				else cout << "False" << ", ";

				hasSatisfied = true;
			}
			cout << endl;
		}
	}

	if (!hasSatisfied)
		cout << "no satisfiable combination" << endl;
}

//input: expression x = prefix notation
void SatTree::MakeSatTree(string prefixNotation) {
	if (prefixNotation.size() < 1) throw "empty notation";

	int index = 0;
	//a sign # indecates a empty node connected to a leaf node of the tree.
	stringstream newNotation;
	for (int i = 0; i < prefixNotation.size(); i++) {
		newNotation << prefixNotation[i];
		if (isLeafNode(prefixNotation[i])) {
			newNotation << "##";
		}
		else if (prefixNotation[i] == '!') {
			newNotation << "#";
		}
	}

	root = MakeSatTree(newNotation.str(), index);
}

SatNode * SatTree::MakeSatTree(string prefixNotation, int& index) {
	if (index >= prefixNotation.size()) return nullptr;
	char c = prefixNotation[index++];
	if (c == '#') return nullptr;

	SatNode * currRootNode = new SatNode(transfromCharToLogic(c), c);;

	if (isLeafNode(c)) this->leafNodeList.push_back(currRootNode);

	currRootNode->LeftChild = MakeSatTree(prefixNotation, index);
	currRootNode->RightChild = MakeSatTree(prefixNotation, index);
	return currRootNode;
}

void SatTree::clear(SatNode * currNode) {
	if (currNode) {
		clear(currNode->LeftChild);
		clear(currNode->RightChild);
		currNode->LeftChild = nullptr;
		currNode->RightChild = nullptr;
		delete currNode;
		currNode = nullptr;
	}
}

int main()
{
	//test cases
	//&&AB|CD
	//|&ABC
	//&|AB!C

	SatTree t;

	string prefixNotation = "";

	int select = 0;
	cout << "input: expression x = prefix notation, example:" << endl;
	cout << "example 1: &&AB|CD" << endl;
	cout << "example 2: |&ABC" << endl;
	cout << "example 3: &|AB!C" << endl;

	do {
		cout << "\nSatisfactionTree. Select: 1 useDefaultInput, 2 customInput, >=3 exit" << endl;
		cin >> select;
		switch (select) {
		case 1:
			cout << "input: expression x = prefix notation" << endl << "Default input 1: " << "|&ABC" << endl;
			t.MakeSatTree("|&ABC");
			t.Satisfiable();
			t.clear();

			cout << endl << "Default input 2: " << "&|AB!C" << endl;
			t.MakeSatTree("&|AB!C");
			t.Satisfiable();
			t.clear();
			break;
		case 2:
			cout << "input: expression x = prefix notation" << endl;
			cout << "input: ";
			cin >> prefixNotation;
			if (prefixNotation.size() < 1) {
				cout << "input proper prefix notation!";
				break;
			}
			t.MakeSatTree(prefixNotation);
			t.Satisfiable();
			t.clear();
			break;

		default:
			exit(1);
			break;

		}
	} while (select < 3);

	system("pause");
	return 0;
}
