#include <iostream>
using namespace std;
class CircDbList; //Complete!

class DbListNode {
	friend class CircDbList;
	friend class CircDbListIterator;
	DbListNode() {};
	DbListNode(int data);
private:
	int data;
	DbListNode *llink, *rlink;
};

DbListNode::DbListNode(int d) {
	data = d;
}

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ//

class CircDbList {
	friend class CircDbListIterator;
public:
	CircDbList() { first = new DbListNode; first->rlink = first; first->llink = first; first->data = NULL; last = first; };
	CircDbList(const CircDbList&);
	~CircDbList();
	void Attach(int k);
	void Delete(DbListNode *x);
	void Insert(DbListNode *p, DbListNode *x);
	void Merge(const CircDbList &l);
private:
	DbListNode  *first;
	DbListNode  *last;
	static DbListNode  *av;
};

CircDbList::CircDbList(const CircDbList &l) //생성자!
{
	if (l.first == NULL) { first = NULL; return; }//circDbList가 존재 하지 않을 때
	first = new DbListNode(l.first->data);
	DbListNode  *newnode = first;
	for (DbListNode *current = l.first->rlink; current != l.first; current = current->rlink)
	{
		newnode->rlink = new DbListNode(current->data);
		newnode->rlink->llink = newnode; //circular 양방향성 구현
		newnode = newnode->rlink;
	}
	newnode->rlink = first;
	first->llink = newnode;
	last = newnode;
}



CircDbList ::~CircDbList() //파괴자!
{
	if (first)
	{
		DbListNode  *second = first->rlink;
		first->rlink = av;
		av = second;
		first = 0;
	}
}


void CircDbList::Delete(DbListNode *x) //삭제
{
	if (x == NULL) cerr << "Deletion of head node not permitted" << endl;
	else if (x == last){
		last = x->llink;
		x->llink->rlink = x->rlink;
		x->rlink->llink = x->llink;
		delete x;
	}
	else{
		x->llink->rlink = x->rlink;
		x->rlink->llink = x->llink;
		delete x;
	}
}

void CircDbList::Insert(DbListNode *p, DbListNode *x) //삽입
//insert node p to the right of node x
{
	p->llink = x;
	p->rlink = x->rlink;
	x->rlink->llink = p;
	x->rlink = p;
}

void CircDbList::Attach(int k) //node추가
{
	DbListNode  *newnode = new DbListNode(k);
	if (first == NULL) return;
	if (first->data == NULL) { //first가 없으면 만듬
		first = newnode; 
		newnode->rlink = newnode;
		newnode->llink = newnode;
		last = newnode;
	}
	else {
		newnode->rlink = first;
		first->llink = newnode;
		newnode->llink = last;
		last->rlink = newnode;
		last = newnode; //newnode가 마지막 노드가 되기 때문 이를 표현해야함!
	}
}

void CircDbList::Merge(const CircDbList &l) { //두 원형더블리스트를 정렬해서 합하기
	
	if (l.first == NULL) { first = NULL; return; }//circDbList가 존재 하지 않을 때
	l.first->llink = last; last->rlink = l.first; //입력받은 list와 기존 list병합
	first->llink = l.last; l.last->rlink = first;
	DbListNode *current = first;
	do {
		int temp = current->data;
		for (DbListNode *current_2 = current->rlink; current_2 != first; current_2 = current_2->rlink)
		{
			if (temp > current_2->data) {
				current->data = current_2->data;
				current_2->data = temp;
				temp = current->data;
			}
		}
		current = current->rlink;
	} while (current != first);
	DbListNode *newnode = first;
	for (current = first->rlink; current!= first;current = current->rlink) {
			newnode->rlink = new DbListNode(current->data);
			newnode->rlink->llink = newnode;
			newnode = newnode->rlink;
	}
	newnode->rlink = first;
	newnode->rlink->llink = newnode;
	last = newnode;
}

DbListNode * CircDbList::av = 0;
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ//

class CircDbListIterator { //반복자!
public:
	CircDbListIterator(const CircDbList & l) : list(l) { current = l.first; }
	int* RightNext(); //오른쪽
	int* LeftNext();  //왼쪽
	int* Current(int index); //index의 data
	int* First(); //맨앞의 data
	DbListNode* Last(); //마지막노드
	bool NotNull(); 
	bool NextNotNull();
private:
	const CircDbList  &list;
	DbListNode *current;
};

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ//

int* CircDbListIterator::First() {
	if (current == list.first) return &current->data;
	else return 0;
}

int* CircDbListIterator::Current(int index) {
	current = list.first;
	for (int count = 0; count < index; count++){ 
		current = current->rlink; 
		if (current == list.first) return 0;
	}
	return &current->data;
}

int* CircDbListIterator::RightNext() {
	current = current->rlink;
	if (current != list.first) return &current->data;
	else return 0;
}

int* CircDbListIterator::LeftNext() {
	current = current->llink;
	if (current != list.first) return &current->data;
	else return 0;
}

DbListNode* CircDbListIterator::Last() {
	if (list.last == list.first) return NULL;
	else if (list.first == NULL) return NULL;
	else return list.last;
}

bool CircDbListIterator::NotNull()
{
	if (current != list.first) return true;
	else return false;
}


bool CircDbListIterator::NextNotNull()
{
	if (current->rlink != list.first) return true;
	//else if (current->llink != list.first) return true;
	else return false;
}

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ//

ostream& operator<<(ostream& os, const CircDbList& l)
{
	CircDbListIterator li(l);
	if (li.NotNull()) return os;
	os << *li.First();
	while (li.NextNotNull())
		os << " + " << *li.RightNext();
	os << endl;
	return os;
}

int main()
{
	//page 219, Fig 4.31, circular list with head node
		// page 220, Exercise 3. Programming project 3
		//implement doubly linked circular list with head nodes
	char select;
	char select_2 = 'y';
	CircDbList a = CircDbList();
	cout << endl << "Select command: a: Add, d: Delete, m: Merge, D: DisplayAll, q: exit" << endl;
	cin >> select;
	while (select != 'q')
	{
		CircDbList temp = CircDbList();
		CircDbListIterator tempList(a);
		switch (select)
		{
		case 'a':
			int input;
			cout << "Add integer to Node" << endl;
			cin >> input;
			a.Attach(input);
			break;
		case 'd':
			cout << "Delete Last Node" << endl;
			a.Delete(tempList.Last());
			break;
		case 'm': //a+b // use insert!
			while(select_2 != 'n'){
				cout << "input data you want to insert!" << endl;
				cin >> input;
				temp.Attach(input);
				cout << "continue?[y/n] : ";
				cin >> select_2;
			}
			cout << a << endl;
			cout << temp << endl;
			a.Merge(temp);
			break;
		case 'D':
			cout << "display all: " << endl;
			cout << a << endl;
			break;
		default:
			cout << "WRONG INPUT  " << endl;
			cout << "Re-Enter" << endl;
		}
		cout << endl << "Select command: a: Add, d: Delete, m: Merge, D: DisplayAll, q: exit" << endl;
		cin >> select;
	}
	system("pause");
	return 0;
}

