#pragma once
#include <iostream>
#include "Stack.h"

typedef char* Expression;
using namespace std;
/*
class Prefix {
private:
	Expression expression;
	int index = 0;
	int count = 0;
public:
	Prefix(Expression expression) : expression(expression) {}
	void getPrefix() // 손봐야함!
	{
		Stack<char> stack;
		stack.Push('#');
		for (char x = NextToken(expression); x != NULL; x = NextToken(expression))
		{
			if (isOperand(x))
				cout << x;
			else if (x == ')')//(3*4)+9#
			{
				while (stack.Top() != '(')
				{
					cout << stack.Top();
					stack.Pop();
				}
				if (!stack.IsEmpty()) stack.Pop();
			}
			else
			{
				for (; !stack.IsEmpty() && isp(stack.Top()) >= icp(x); stack.Pop())
					cout << stack.Top();
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

	double Eval() {

	}
*/
};