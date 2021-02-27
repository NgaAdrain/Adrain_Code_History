
//학번: 201524582
//이름(한글): 정희석
//Name(English): JeongHeeSeok
// 2. Threaded Tree

//Tree 5.13 Threaded binary tree
/*
* C++ Program to Implement Threaded Binary Tree\
화면에서 입력받을 때 leaf node 에 insert가 아닌 non-leaf node로 insert, 단 right child보다 작거나 left child 보다 클 경우에만 해당
*/
#include <iostream>
#include <cstdlib>
#define MAX_VALUE 65536
using namespace std;


class ThreadedTree;

class ThreadedNode {
	friend class ThreadedTree;
	friend class ThreadedInorderIterator;
private:
	bool LeftThread;
	ThreadedNode *LeftChild;
	char data;
	ThreadedNode *RightChild;
	bool RightThread;
public:
	ThreadedNode() { LeftChild = RightChild = 0; };
	ThreadedNode(char ch) { data = ch; };
	ThreadedNode(char ch, ThreadedNode *lefty, ThreadedNode *righty,
		bool lthread, bool rthread)
	{
		data = ch; LeftChild = lefty; RightChild = righty;
		LeftThread = lthread;  RightThread = rthread;
	};
};

class ThreadedTree {
	friend class ThreadedInorderIterator;
private:
	ThreadedNode * root;
	void Inorder(ThreadedNode *, bool);
public:
	/* Constructor */
	ThreadedTree() {
		root = new ThreadedNode;
		root->RightChild = root->LeftChild = root;
		root->data = 'z';
		root->LeftThread = true; root->RightThread = false;
	};
	void InsertRight(ThreadedNode*, char);
	bool Insert(char data);
	void Delete(char data);
	void Inorder();
	void PrintTree();
	bool Search(char data);
	ThreadedNode* InorderSucc(ThreadedNode*);
};


ThreadedNode* ThreadedTree::InorderSucc(ThreadedNode *current)//unused//
{
	ThreadedNode *temp = current->RightChild;
	if (!current->RightThread)
		while (!temp->LeftThread) temp = temp->LeftChild;
	return temp;
}


/* Fuction to delete an element */
void ThreadedTree::Delete(char data)
{
	ThreadedNode *dest = root->LeftChild, *p = root;
	for (;;)
	{
		if (dest->data < data)
		{
			/* not found */
			if (dest->RightThread)
				return;
			p = dest;
			dest = dest->RightChild;
		}
		else if (dest->data > data)
		{
			/* not found */
			if (dest->LeftThread)
				return;
			p = dest;
			dest = dest->LeftChild;
		}
		else
		{
			/* found */
			break;
		}
	}
	ThreadedNode *target = dest;
	if (!dest->RightThread && !dest->LeftThread)
	{
		/* dest has two children*/
		p = dest;
		/* find largest node at left child */
		target = dest->LeftChild;
		while (!target->RightThread)
		{
			p = target;
			target = target->RightChild;
		}
		/* using replace mode*/
		dest->data = target->data;
	}
	if (p->data >= target->data)
	{
		if (target->RightThread && target->LeftThread)
		{
			p->LeftChild = target->LeftChild;
			p->LeftThread = true;
		}
		else if (target->RightThread)
		{
			ThreadedNode *largest = target->LeftChild;
			while (!largest->RightThread)
			{
				largest = largest->RightChild;
			}
			largest->RightChild = p;
			p->LeftChild = target->LeftChild;
		}
		else
		{
			ThreadedNode *smallest = target->RightChild;
			while (!smallest->LeftThread)
			{
				smallest = smallest->LeftChild;
			}
			smallest->LeftChild = target->LeftChild;
			p->LeftChild = target->RightChild;
		}
	}
	else
	{
		if (target->RightThread && target->LeftThread)
		{
			p->RightChild = target->RightChild;
			p->RightThread = true;
		}
		else if (target->RightThread)
		{
			ThreadedNode *largest = target->LeftChild;
			while (!largest->RightThread)
			{
				largest = largest->RightChild;
			}
			largest->RightChild = target->RightChild;
			p->RightChild = target->LeftChild;
		}
		else
		{
			ThreadedNode *smallest = target->RightChild;
			while (!smallest->LeftThread)
			{
				smallest = smallest->LeftChild;
			}
			smallest->LeftChild = p;
			p->RightChild = target->RightChild;
		}
	}
	//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ//
}void ThreadedTree::Inorder()
{
	Inorder(root, root->LeftThread);
}

void ThreadedTree::Inorder(ThreadedNode *CurrentNode, bool b)
{
	if (!b) {
		Inorder(CurrentNode->LeftChild, CurrentNode->LeftThread);
		cout << " " << CurrentNode->data;
		cout << "Inorder:" << "rightthread=" << CurrentNode->RightThread;
		if (CurrentNode->RightChild != root) Inorder(CurrentNode->RightChild, CurrentNode->RightThread);
	}
}

/*
* C++ Program to Implement Threaded Binary Tree\
화면에서 입력받을 때 leaf node 에 insert가 아닌 non-leaf node로 insert, 단 right child보다 작거나 left child 보다 클 경우에만 해당
*/
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ//

bool ThreadedTree::Insert(char d)
{
	ThreadedNode *check;
	ThreadedNode *p = root;
	ThreadedNode *q = p;
	ThreadedNode *tmp;
	check = root->LeftChild;
	bool temp = p->LeftThread;
	while (!temp) {
		q = p;
		if (d == p->data) return false;
		if (d < p->data) { temp = p->LeftThread; p = p->LeftChild; }
		else { temp = p->RightThread; p = p->RightChild; }
		cout << "Insert:: while" << endl;
	}
	p = new ThreadedNode;//새로운 노드 생성
	p->data = d;
	//if (q->LeftChild == q){ q->LeftChild = p;q->LeftThread = false;}
	//else
	if (q == root) {//root에서는 무조건 왼쪽
		p->RightChild = q; p->RightThread = true;
		p->LeftChild = q->LeftChild; p->LeftThread = q->LeftThread;
		q->LeftChild = p; q->LeftThread = false;
		cout << "Insert:: go left";
		return true;
	}
	else if((q->LeftChild == root) ||(q->RightChild == root )){//여기부터 작성시작! //일단 root내려간 root2는 왼쪽 오른쪽 다 True인 상태!
		if (d < q->data) //goto left
		{
			p->RightChild = q; p->RightThread = true;
			p->LeftChild = check; p->LeftThread = q->LeftThread;
			q->LeftChild = p; q->LeftThread = false;
			cout << "Insert:: go left";
		}
		else
		{
			p->RightChild = check; p->RightThread = q->RightThread;
			p->LeftChild = q; p->LeftThread = true;
			q->RightChild = p; q->RightThread = false;
			cout << "Insert:: go right";
		}
		return true;
	}
	else {//여기서 부터는 thread연결을 check로 한다! // 구분짓기 위해서!
		//p는 새로 만들어진 노드!
		if (d < q->data) //goto left
		{
			if (q->RightChild == check) { //오른쪽 가지에서 가지 바꿔치기
				tmp = q->LeftChild;
				p->RightChild = q; p->RightThread = false;
				p->LeftChild = tmp; p->LeftThread = true;
				q->LeftChild = p; //q->LeftThread = true;
				//q->RightChild = check; q->RightThread = true;

			}
			else{//왼쪽 가지 그대로 진행
				p->RightChild = q; p->RightThread = true;
				p->LeftChild = q->LeftChild; p->LeftThread = q->LeftThread;
				q->LeftChild = p; q->LeftThread = false;
				cout << "Insert:: go left";
			}
		}
		else //goto right
		{
			if (q->LeftChild == check) {//왼쪽가지에서 가지 바꿔치기
				tmp = q->RightChild;
				p->LeftChild = q; p->LeftThread = false;
				p->RightChild = tmp; p->RightThread = true;
				q->RightChild = p;//q->RightThread = true;
				//q->LeftChild = check; q->LeftThread = true;
			}
			else{
				p->RightChild = q->RightChild; p->RightThread = q->RightThread;
				p->LeftChild = q; p->LeftThread = true;
				q->RightChild = p; q->RightThread = false;
				cout << "Insert:: go right";
			}
		}
		return true;
	}
}

///////////////////////////////////////////////////////////////////////////////////
void ThreadedTree::InsertRight(ThreadedNode *s, char ch) //unused//
// Create node r; store ch in r; insert r as the right child of s
{
	ThreadedNode *r = new ThreadedNode(ch);
	r->RightChild = s->RightChild;
	r->RightThread = s->RightThread;
	r->LeftChild = s;
	r->LeftThread = true; // LeftChild is a thread
	s->RightChild = r; // attach r to s
	s->RightThread = false;
	if (!r->RightThread) {
		ThreadedNode *temp = InorderSucc(r); // returns the inorder successor of r
		temp->LeftChild = r;
	}
}

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ//

/* Function to print tree */
void ThreadedTree::PrintTree()
{
	ThreadedNode *tmp = root, *p;
	for (;;)
	{
		p = tmp;
		tmp = tmp->RightChild;
		if (!p->RightThread)
		{
			while (!tmp->LeftThread)
			{
				tmp = tmp->LeftChild;
			}
		}
		if (tmp == root)
			break;
		cout << tmp->data << "   ";
	}
	cout << endl;
}

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ//
class ThreadedInorderIterator {
public:
	void Inorder();
	char *Next();
	ThreadedInorderIterator(ThreadedTree tree) : t(tree) {
		CurrentNode = t.root;
	};
private:
	ThreadedTree t;
	ThreadedNode *CurrentNode;
};

char* ThreadedInorderIterator::Next()
// Find the inorder successor of \fICurrentNode\fR in a threaded binary tree
{
	ThreadedNode *temp = CurrentNode->RightChild;
	if (!CurrentNode->RightThread)
		while (!temp->LeftThread) temp = temp->LeftChild;
	CurrentNode = temp;
	if (CurrentNode == t.root) return 0; // all tree nodes have been traversed
	else return &CurrentNode->data;
}

void ThreadedInorderIterator::Inorder()
{
	for (char *ch = Next(); ch; ch = Next())
		cout << *ch << endl;
}


//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ//
/* Main Contains Menu */

int main()
{
	ThreadedTree t;
	ThreadedInorderIterator ti(t);
	cout << "ThreadedTree Test\n";
	char ch;
	int choice;
	/*  Perform tree operations  */
	do
	{
		cout << "\nThreadedTree Operations\n";
		cout << "1. Insert list " << endl;
		cout << "2. Delete" << endl;
		cout << "3. recursive Inorder" << endl;
		cout << "4. iteratorInorder" << endl;
		cout << "5. PrintTree" << endl;
		cout << "6. exit" << endl;
		cout << "Enter Your Choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			int m;
			cout << "1. Insert::The number of data = ";
			cin >> m;
			for (int i = 0; i < m; i++)
			{
				cout << endl << "The next char element = ";
				cin >> ch;
				if (!t.Insert(ch)) cout << "Duplicate data already" << endl;
				//insert() body가 수정되어야 한다. BF를 check하여 해당 노드의 right child, left child로 insert 되어야 한다.
			}
			break;
		case 2:
			cout << "Enter integer element to delete: ";
			cin >> ch;
			t.Delete(ch);
			break;
		case 3:
			cout << "Recursive Inorder" << endl;
			t.Inorder();
			break;
		case 4:
			cout << "IteratorInorder" << endl;
			ti.Inorder();
			break;
		case 5:
			cout << "PrintTree " << endl;
			t.PrintTree();
			break;
		case 6:
			exit(0);
			break;
		default:
			cout << "Wrong Entry" << endl;
			break;
		}
		/*  Display tree  */
		cout << "Tree = ";
		t.PrintTree();
	} while (choice != 7);

	system("pause");
	return 0;
}
