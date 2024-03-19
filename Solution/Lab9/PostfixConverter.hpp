#pragma once

#include "Lab9.hpp"
#include "Stack.hpp"

class PostfixConverter {

private:
	std::string infix;
	std::string postfix;

public:

	PostfixConverter() {
		infix = postfix = "";
	}

	PostfixConverter(std::string exp) {
		infix = exp;
		postfix = convert(exp);
	}

	std::string getInfix() {
		return infix;
	}

	std::string getPostfix() {
		return postfix;
	}

	void setInfix(std::string exp) {
		infix = exp;
	}

	std::string convert(std::string expression) {

		// create temp string from expression
		std::string str = expression;

		// clean expression of spaces and equal signs
		str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
		str.erase(std::remove(str.begin(), str.end(), '='), str.end());

		// check for invalid string length
		if (str.length() < 3) {
			return "";
		}

		Stack<char> stack;

		// the character array to build into
		char* cstring = (char*)malloc(sizeof(char) * (str.length() + 2));
		int j = 0;

		// create character array from cleaned expression
		const char* exp = str.c_str();
		int i = 0;

		// the current character to analyze
		char current = exp[i];
		
		while (i < str.length()) {

			if (isDigit(current)) { // append operands to output
				cstring[j++] = current;
			}
			else if (isOperator(current)) { // operator stack interaction

				if (current == '+' || current == '-') { // easier case: lower precedance

					// remove older operators from stack and appent to postfix expression
					while (!stack.isEmpty()) {
						stack.pop(cstring[j++]);
					}

					// push current operator onto stack
					stack.push(current);
				}
				else { // + or - operator

					char c = '/0';
					stack.peek(c);

					if (c == '+' || '-') { // operator with lower precedance is on top
						stack.push(current);
					}
					else {
						// until empty stack or operator with equal precedance
						while (!stack.isEmpty() && c != '*' && c != '/' && c != '^') {
							stack.pop(cstring[j++]);
							stack.peek(c);
						}
					}
				}
			}

			// update current for next loop
			current = exp[++i];
		}

		// empty stack to output
		while (!stack.isEmpty()) {
			stack.pop(cstring[j++]);
		}

		cstring[str.length()] = '=';
		cstring[str.length() + 1] = '\0';

		// convert cstring to std::string
		return std::string(cstring);
	}

	std::string convert() {

		// create temp string from expression
		std::string str = infix;

		// clean expression of spaces and equal signs
		str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
		str.erase(std::remove(str.begin(), str.end(), '='), str.end());

		// check for invalid string length
		if (str.length() < 3) {
			return "";
		}

		Stack<char> stack;

		// the character array to build into
		char* cstring = (char*)malloc(sizeof(char) * (str.length() + 2));
		int j = 0;

		// create character array from cleaned expression
		const char* exp = str.c_str();
		int i = 0;

		// the current character to analyze
		char current = exp[i];

		while (i < str.length()) {

			if (isDigit(current)) { // append operands to output
				cstring[j++] = current;
			}
			else if (isOperator(current)) { // operator stack interaction

				if (current == '+' || current == '-') { // easier case: lower precedance

					// remove older operators from stack and appent to postfix expression
					while (!stack.isEmpty()) {
						stack.pop(cstring[j++]);
					}

					// push current operator onto stack
					stack.push(current);
				}
				else { // + or - operator

					char c = '/0';
					stack.peek(c);

					if (c == '+' || '-') { // operator with lower precedance is on top
						stack.push(current);
					}
					else {
						// until empty stack or operator with equal precedance
						while (!stack.isEmpty() && c != '*' && c != '/') {
							stack.pop(cstring[j++]);
							stack.peek(c);
						}
					}
				}
			}

			// update current for next loop
			current = exp[++i];
		}

		// empty stack to output
		while (!stack.isEmpty()) {
			stack.pop(cstring[j++]);
		}

		cstring[str.length()] = '=';
		cstring[str.length() + 1] = '\0';

		// convert cstring to std::string
		postfix = std::string(cstring);
		return postfix;
	}


	bool isDigit(char c) {
		switch (c) {
		case '0':
			return true;
		case '1':
			return true;
		case '2':
			return true;
		case '3':
			return true;
		case '4':
			return true;
		case '5':
			return true;
		case '6':
			return true;
		case '7':
			return true;
		case '8':
			return true;
		case '9':
			return true;
		default:
			return false;
		}
	}

	bool isOperator(char c) {
		switch (c) {
		case '+':
			return true;
		case '-':
			return true;
		case '*':
			return true;
		case '/':
			return true;
		case '^':
			return true;
		default:
			return false;
		}
	}
};