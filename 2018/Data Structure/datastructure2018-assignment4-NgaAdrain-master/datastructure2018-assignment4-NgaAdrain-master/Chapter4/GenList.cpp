//Gen List

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int GetData();
//GetNode(); //Node생성
//RetNode(); //Node삭제? 반환?
class GenList; // forward declaration

class GenListNode
{
	friend class GenList;
	friend int operator==(const GenList&, const GenList&);
	friend int equal(GenListNode*, GenListNode*);
private:
	bool tag;
	union {
		int data;
		GenListNode *dlink; //down node!
	};
	GenListNode *link; // next node!
};

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ//

class GenList
{
	friend int operator==(const GenList&, const GenList&);
	friend int equal(GenListNode*, GenListNode*);
	friend GenList* operator>>(istream& input, GenList& list);
private:
	GenListNode *first;
	GenListNode*  Copy(GenListNode*);
	void Visit(GenListNode*);
	int depth(GenListNode*);
	GenListNode* MakeList(GenListNode*);
	int index = 0;
	void GetNode();
	void RetNode();
	//    void Delete(GenListNode*);
public:
	void Copy(const GenList&);
	void Visit(const GenList&);
	//    ~GenList();
	int depth();
	void MakeList();
	char NextToken(char* e);
};

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ//

/*

void GenList::Delete(GenListNode* x)
{
x->ref--;
if (!x->ref)
{
GenListNode *y = x;
while (y->link) { y = y->link; if (y->tag) Delete(y->dlink);}
y->link = av;
av = x;
}
}




GenList::~GenList()
{
Delete(first);
first = 0;
}
*/

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ//

void GenList::MakeList()
{
	first = MakeList(first);
}

GenListNode* GenList::MakeList(GenListNode *s)
{
	GenListNode *p, *q, *r;
	bool tag_head = true;
	q = new GenListNode;
	r = q;
	while (int x = GetData())//if x == 0, no more entry
	{
		if (x == 1) //make down link
		{
			if (tag_head) {
				q->dlink = MakeList(q);
				q->tag = true;
				q->link = 0;
				tag_head = false;
				continue;
			}
			else
			{
				p = new GenListNode;
				q->link = p;
				p->tag = true;
				p->link = 0;
				q = p;
				q->dlink = MakeList(q);
				return r;
			}
		}
		else {
			if (tag_head) {
				q->data = x; q->tag = false; q->link = 0;
				tag_head = false;
			}
			else {
				p = new GenListNode;
				p->data = x; p->tag = false; p->link = 0;
				q->link = p;
				q = p;
			}
		}
	}
	return r;
}

int GetData() {
	cout << endl << "0: exit, 1: input List(down), 2: input Data(right) " << endl;
	cout << "input a select (number): ";
	int n;
	cin >> n;
	return n;
}
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ//
//과제부분//
/*
GenList* operator>>(istream& input , GenList& list) { // use : cin >> new outputList;
	char* symbol;
	cout << "Input Expression -> ex) A(B,(C,D),(),E)" << endl;
	input >> symbol;
	switch (Selection()) {
	case(0):
		break;
	case(1):
		//Get();
		break;
	case(2):
		//Put(name,tag,alink);
		break;
	default:
		cout << "Error!";
		break;
	}
	
}

int Selection() {
	int selection;
	cout << "0: quit, 1: findData, 2: putList";
	cin >> selection;
	return selection;
}

int Get(char a) {
	int result = -1;
	


	return result;
}

void Put(int n, bool t, GenListNode* a) {

}

char GenList::NextToken(char* e)
{
	char token = e[index];
	index++;
	return token;
}

//과제부분//

void GenList::GetNode() {
	GenListNode *newnode = new GenListNode();
	int select = GetData();
	switch (select) {
	case(0):
		break;
	case(1): // down(newList)
		tag_head = true;
		newnode->dlink = new GenListNode();
		break;
	case(2): // right(newNode)
		tag_head = false;
		break;
	default:
		cout << "Error!";
		break;
	}
}

void GenList::RetNode() {

}
*/
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ//

void GenList::Copy(const GenList& l)
{
	first = Copy(l.first);
}

GenListNode* GenList::Copy(GenListNode* p)
{
	GenListNode *q = 0;
	if (p) {
		q = new GenListNode;
		q->tag = p->tag;
		if (!p->tag) q->data = p->data;
		else q->dlink = Copy(p->dlink);
		q->link = Copy(p->link);
	}
	return q;
}

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ//

void GenList::Visit(const GenList& l)
{
	cout << "(";
	Visit(l.first);
	cout << ")";
}
void GenList::Visit(GenListNode* p)
{
	if (p != nullptr) {
		cout << p->tag << ":";
		if (!p->tag)
			cout << p->data << ",";
		else {
			cout << " (";
			Visit(p->dlink);
			cout << ") ";
		}
		Visit(p->link);
	}
}

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ//

int GenList::depth()
{
	return depth(first);
}
int GenList::depth(GenListNode *s)
{
	if (!s) return 0;
	GenListNode *p = s; int m = 0;
	while (p) {
		if (p->tag) {
			int n = depth(p->dlink);
			if (m < n) m = n;
		}
		p = p->link;
	}
	return m + 1;
}

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ//

int operator==(const GenList& l, const GenList& m)
{
	return equal(l.first, m.first);
}

int equal(GenListNode* s, GenListNode *t)
{
	int x;
	if ((!s) && (!t)) return 1;
	if (s && t && (s->tag == t->tag)) {
		if (!s->tag)
			if (s->data == t->data) x = 1; else x = 0;
		else x = equal(s->dlink, t->dlink);
		if (x) return  equal(s->link, t->link);
	}
	return 0;
}



//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ//
int main(void)
{
	GenList l;
	char select = 'i';
	int max = 0, x = 0;
	while (select != 'q')
	{
		cout << "Select command m: make, c: copy, d: depth, v: visit, q : quit =>";
		cin >> select;
		switch (select)
		{
		case 'm':
			l.MakeList();
			break;
		case 'c':
			GenList m;
			m.Copy(l);
			cout << "Copy Result" << endl;
			l.Visit(m);
			cout << endl;
			break;
		case 'd':
			cout << "depth: " << l.depth();
			cout << endl;
		case 'v':
			cout << "tag : data (link)" << endl;
			l.Visit(l);
			cout << endl;
			break;
		case 'q':
			cout << "Quit" << endl;
			break;

		default:
			cout << "WRONG INPUT  " << endl;
			cout << "Re-Enter" << endl;
			break;
		}
	}

	system("pause");
	return 0;
}
