//Problem 1 – 3장
//bag의 subclass로서 stack을 구현하고 이를 토대로 postfix(), prefix(), eval()를 구현
#include <iostream>
#include <memory>
using namespace std;
typedef char* Expression;
class Bag {
public:
	Bag(int bagCapacity = 10);
	~Bag();

	int Size() const;
	bool IsEmpty() const;
	int& Element() const;

	void Push(const int&);
	void Pop();

protected:
	int* array = nullptr;
	int capacity;
	int top;
};


Bag::Bag(int bagCapacity) : capacity(bagCapacity)
{
	if (capacity < 1) throw "Capacity must be > 0";
	array = new int[capacity];
	top = -1;
}


Bag::~Bag() { delete[] array; }


void ChangeSizeID(int*& a, const int oldSize, const int newSize)
{
	if (newSize < 0) throw "New length must be >= 0";

	int* temp = new int[newSize];
	int number = oldSize;
	if (oldSize > newSize) number = newSize;
	//copy(a, a + number, temp);
	memcpy(temp, a, number);
	delete[] a;
	a = temp;
}

int Bag::Size() const {
	return top + 1;
}


bool Bag::IsEmpty() const {
	return top < 0;
}


int& Bag::Element() const {
	if (top == -1)throw "index out of bound";
	return this->array[top];
}



void Bag::Push(const int& x)
{
	if (top == capacity - 1)
	{
		ChangeSizeID(array, capacity, 2 * capacity);
		capacity *= 2;
	}
	array[++top] = x;
}


void Bag::Pop()
{
	if (IsEmpty()) throw "Bag is empty, cannot delete";
	int deletePos = top / 2;
	//copy(array + deletePos + 1, array + top + 1, array + deletePos);
	memcpy(array + deletePos, array + deletePos, top + 1);
	top--;
}

class Stack : public Bag
{
public:
	Stack(int stackCapacity = 10);
	~Stack();
	int Top() const;
	void Pop();
	//stack에 Push()는 no duplicate를 구현, 단 Bag::Push()를 재사용한 코딩 구현
};

Stack::Stack(int stackCapacity) : Bag(stackCapacity) {}

Stack::~Stack() { }

int Stack::Top() const
{
	if (IsEmpty()) throw "Stacak is empty";
	return array[top];
}

void Stack::Pop()
{
	if (IsEmpty()) throw "Stack is empty. Cannot delete";
	top--;
}

int index = 0;

char NextToken(char* e)
{
	char token = e[index];
	index++;
	return token;
}

bool isOperand(char x) // &&,|| !, > < 연산자 추가해야함!
{
	if (x == '+' || x == '-' || x == '*' || x == '/' ||
		x == '(' || x == ')' || x == '%' || x == '#' ||
		x == '!' || x == '<' || x == '=' || x == '>' ||
		x == '&' || x == '|')
		return false;
	else
		return true;
}

int isp(char a)
{
	if (a == '(')
		return 1;
	else if (a == ')')
		return 19;
	else if (a == '+' || a == '-')
		return 12;
	else if (a == '*' || a == '%' || a == '/')
		return 13;
	else if (a == '<' || a == '>')
		return 11;
	else if (a == '!')
		return 14;
	else if (a == '&')
		return 9;
	else if (a == '|')
		return 8;
	else
		return 0;
}

int icp(char a)
{
	if (a == '(')
		return 1;
	else if (a == ')')
		return 19;
	else if (a == '+' || a == '-')
		return 12;
	else if (a == '*' || a == '%' || a == '/')
		return 13;
	else if (a == '=')
		return 10;
	else if (a == '!')
		return 14;
	else if (a == '&')
		return 9;
	else if (a == '|')
		return 8;
	else
		return 0;
}

void Postfix(char* e)
{
	Stack stack;
	int count = 0;
	stack.Push('#');
	for (char x = NextToken(e); x != NULL; x = NextToken(e))
	{
		//cout << "x = " << x << endl;
		if (isOperand(x))
			cout << x;
		else if (x == ')')//(3*4)+9#
		{
			while (stack.Top() != '(')
			{
				cout << (char) stack.Top();
				stack.Pop();
			}
			if (!stack.IsEmpty()) stack.Pop();
		}
		else if (x == '(') {
			stack.Push(x);
			count = 0;
		}
		else
		{
			for (; !stack.IsEmpty() && isp(stack.Top()) >= icp(x); stack.Pop()) {
				if ((stack.Top() == '&') && (x == '&')) {
					if (count == 1) {
						cout << (char) stack.Top();
						stack.Pop();
						count = 0;
					}
					else {
						count++;
						break;
					}

				}
				else if ((stack.Top() == '|') && (x == '|')) {
					if (count == 1) {
						cout << (char)stack.Top();
						stack.Pop();
						count = 0;
					}
					else {
						count++;
						break;
					}

				}
				else if ((stack.Top() == '&') && (x == '|')) {
					cout << (char) stack.Top();
					stack.Pop();
					count = 0;
				}
				else if ((stack.Top() == '&') && (x != '&'))
					count = 0;
				else if ((stack.Top() == '|') && (x == '&'))
					count = 0;
				else if ((stack.Top() == '|') && (x != '|'))
					count = 0;
				else if ((stack.Top() == '(')) {
					break;
				}
				cout << (char) stack.Top();
			}
			stack.Push(x);

		}
	}

	char x;
	while ((x = stack.Top()) != '#')
	{
		cout << x;
		stack.Pop();
	}
	cout << endl;
}
/*
void Prefix(char* e)
{
	Stack stack;
	stack.Push('#');
	for (char x = NextToken(e); x != NULL; x = NextToken(e))
	{
		//cout << "x = " << x << endl;
		if (isOperand(x))
			cout << x;
		else if (x == ')')
		{
			while (stack.Top() != '(')
			{
				cout << (char)stack.Top();
				stack.Pop();
			}
			stack.Pop();
			if (!stack.IsEmpty()) stack.Pop();
		}
		else if (x == '(')
			stack.Push(x);
		else
		{
			for (; isp(stack.Top()) <= icp(x); stack.Pop())
				cout << (char)stack.Top();
			stack.Push(x);
		}
	}

	char x;
	while ((x = stack.Top()) != '#')
	{
		cout << x;
		stack.Pop();
	}
	cout << endl;
}
*/
/*
double Operate(double first, double second, char operand) {
	double result=0;
	switch (operand) {
	case '+':

		break;
	case '-':

		break;
	case '*':

		break;
	case '/':

		break;
	default:

		break;
	}
	return result;
}
*/
/*
void Eval(Expression e){
	Stack stack;
	double result = 0;
	stack.Push('#');
	for (char x = NextToken(e); x != '#'; x = NextToken(e))
		if (isOperand(x)) stack.Push(x);
		else {
			if (isOperand(stack.Top()))
				stack.Push(x);
			else {
				for (; !stack.IsEmpty() && isp(stack.Top()) >= icp(x); stack.Pop()){
					double temp[10];
					index = 0;
					if (isOperand(stack.Top()))
						temp[index++] = stack.Top();
					else if (index != 0)
						result += Operate(temp[index], temp[index - 1], stack.Top()) ;
				}
				stack.Push(x);
			}
			//remove the correct number of operands for operator x from stack;
			//perform the operation x and store the result onto the stack;
	}
		cout << result;
}
*/
void main()
{
	index = 0;
	Postfix("2+3*4+9");
	//165페이지, Exercises 1의 (a) ~ (f)에 대하여 동작하게 debugging
	index = 0;
	//Prefix("A*(B+C)/(D-E)+F");
	Postfix("A/B-C+D*E-A*C");//bug 발생-debugging
	//Eval("2*4 + 5*7");
	int end;
	cin >> end;
}
