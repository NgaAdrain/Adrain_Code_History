#include <iostream>
#include <assert.h>
#include "postfix.h"
//#include "Stack.h"
#include "prefix.h" // stack, postfix 모두 include되어있음!

/*
void Eval(Expression e)
Stack<Token> stack;
for (Token x = NextToken(e); x != '#"; x = NextToken(e))
if (x is operand) stack.Push(x);
else {
//remove the correct number of operands for operator x from stack;
//perform the operation x and store the result onto the stack;
}
}
*/
using std::string;

void stackTest1() {
	Stack<int> s(2);
	s.Push(3);
	s.Push(2);
	s.Push(1);
	assert(s.Top() == 1);//3 2 1
	s.Pop();//3 2
	assert(s.Top() == 2);
	assert(s.IsEmpty() != true);
	s.Pop();
	s.Pop();
	assert(s.IsEmpty() == true);
	s.Push(4);
	s.Push(6);
	assert(s.Top() == 6);
	s.Pop();
	assert(s.Top() == 4);
}

/*
//165페이지, Exercises 1의 (a) ~ (f)에 대하여 동작하게 debugging
index = 0;
Postfix("A/B-C+D*E-A*C");//화면에서 입력받는 것으로 수정
//Eval("2*4 + 5*7"); 구현
int end;
cin >> end;
}

//코딩 과제:
//페이지 166, 문제 3번과 4번: prefix and postfix을 만드는 문제
// 괄호() 사용시에도 처리하는 코딩으로 수정하는 것
*/
void main()
{
	stackTest1();
	//Postfix p1("2+(3*4)+9#");//2
	// Exercise 1 (a) ~ (f) debugging
	char* polya = "A*B*C#";
	char* polyb = "-A+B-C+D#";
	char* polyc = "A*-B+C#";
	char* polyd = "(A+B)*D+E/(F+A*D)+C#";
	char* polye = "A&&B||C||!(E>F)#";
	char* polyf = "!(A&&!((B<C)||(C>D)))||(C<E)#";
	Postfix pa(polya);	//165페이지, Exercises 1의 (a) ~ (f)에 대하여 동작하게 debugging
	pa.getPostfix();
	Postfix pb(polyb);
	pb.getPostfix();
	Postfix pc(polyc);
	pc.getPostfix();
	Postfix pd(polyd);
	pd.getPostfix();
	Postfix pe(polye);
	pe.getPostfix();
	Postfix pf(polyf);
	pf.getPostfix();
	// 기존 확인 코드
	Postfix p1("(3*4)+9#");
	p1.getPostfix();
	Postfix p2("A/B-C+D*E-A*C#");
	p2.getPostfix();
	Postfix p3("4*7+3-1#");
	p3.getPostfix();
	//Postfix p4("/*ABC");
	//p4.getPostfix();
	//
	/*
	while (1) {
		cout << "후위표기형태로 바꿀 다항식을 입력하고 마지막에 #을 붙이세요" << endl;
		cout << "종료는 q or Q : ";
		char* input ;
		cin >> input;
		Postfix pinput(input);
		if ((input == "q") || (input == "Q"))
			break;
		else {
			pinput.getPostfix();
		}
	}
	*/
	//Eval("2*4 + 5*7");
	system("pause");
}