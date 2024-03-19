#pragma once

#include "Lab9.hpp"
#include "Stack.hpp"

class PostfixEvaluator {

private:

	std::string expression;
	double value;

public:

	/// <summary>
	/// Creates a default PostfixEvaluator object.
	/// </summary>
	PostfixEvaluator() {
		expression = "";
		value = 0.0;
	}

	/// <summary>
	/// Creates and initializes a PostfixEvaluator object.
	/// </summary>
	/// <param name="nExp">The expression to evaluate.</param>
	PostfixEvaluator(std::string nExp) {
		expression = nExp;
		value = evaluate();
	}

	/// <summary>
	/// Gets the expression.
	/// </summary>
	/// <returns>The current expression.</returns>
	string getExpression() {
		return expression;
	}

	/// <summary>
	/// Sets the expression.
	/// </summary>
	/// <param name="nExp">The new expression.</param>
	void setExpression(std::string nExp) {
		expression = nExp;
	}

	/// <summary>
	/// Gets the value.
	/// </summary>
	/// <returns>The current value.</returns>
	double getValue() {
		return value;
	}

	/// <summary>
	/// Evaluates the current expression.
	/// </summary>
	/// <returns>The updated value of the expression.</returns>
	double evaluate() {

		// create temp string from expression
		std::string str = expression;

		// clean expression of spaces
		str.erase(std::remove(str.begin(), str.end(), ' '), str.end());

		// check for '=' sign or too short of a string
		if (str.find('=') == std::string::npos || str.length() <= 3) {
			// not found or no valid string
			return -1.0;
		}
		
		Stack<double> stack;

		// create character array from cleaned expression
		const char* exp = str.c_str();
		int i = 0;

		// the current character to analyze
		char current = exp[i];

		while (current != '=') {

			if (isDigit(current)) {
				double x = current - 48; // converts using ascii value
				stack.push(x);
			}
			else if (isOperator(current)) {

				double x = 0.0;
				double y = 0.0;

				// make sure there are at least two values in the stack
				if (!stack.pop(x) || !stack.pop(y)) {
					// malformed expression
				}
				else {
					double z = 0.0;
					switch (current) {
					case '+':
						z = y + x;
						break;
					case '-':
						z = y - x;
						break;
					case '*':
						z = y * x;
						break;
					case '/':
						z = y / x;
						break;
					case '^':
						z = pow(y, x);
						break;
					}

					stack.push(z);
				}
			}

			// update current for next loop
			current = exp[++i];
		}

		stack.pop(value);
		return value;
	}

	/// <summary>
	/// Evaluates a postfix expression.
	/// </summary>
	/// <param name="str">The expression to evaluate.</param>
	/// <returns>The result of the expression.</returns>
	double evaluate(std::string str) {

		// clean expression of spaces
		str.erase(std::remove(str.begin(), str.end(), ' '), str.end());

		// check for '=' sign or too short of a string
		if (str.find('=') == std::string::npos || str.length() <= 3) {
			// not found or no valid string
			return -1.0;
		}

		Stack<double> stack;

		// create character array from cleaned expression
		const char* exp = str.c_str();
		int i = 0;

		// the current character to analyze
		char current = exp[i];

		while (current != '=') {

			if (isDigit(current)) {
				double x = current - 48; // converts using ascii value
				stack.push(x);
			}
			else if (isOperator(current)) {

				double x = 0.0;
				double y = 0.0;

				// make sure there are at least two values in the stack
				if (!stack.pop(x) || !stack.pop(y)) {
					// malformed expression
				}
				else {
					double z = 0.0;
					switch (current) {
					case '+':
						z = y + x;
						break;
					case '-':
						z = y - x;
						break;
					case '*':
						z = y * x;
						break;
					case '/':
						z = y / x;
						break;
					case '^':
						z = pow(y, x);
						break;
					}

					stack.push(z);
				}
			}

			// update current for next loop
			current = exp[++i];
		}

		double val = 0.0;
		stack.pop(val);
		return val;
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