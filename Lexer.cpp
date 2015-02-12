#include "Lexer.h"
#include <iostream>

Lexer::Lexer() {
	for(int i = 0; scanf("%c\n", &input[i]) != EOF; i++) { 
		//cout << input[i] << endl;
	}
	index = 0;
	lastChar = ' ';
}

Token Lexer::nextToken() {
	string lexeme;

	if(isValid(lastChar)) {
		cout << "token(): " << lastChar << endl;
		lastChar = ' ';
		index++;
		return Token();
	}
	
	for(; stopScanning(input[index]); index++) {
		lexeme += input[index];
	}

	cout << "token(): " << lexeme << endl;
	lastChar = input[index];
	index++;

	return Token();
}

bool Lexer::stopScanning(char nextChar) {
	if((nextChar == ' ') || (nextChar == '+') ||
		(nextChar == '-') || (nextChar == '*') ||
		(nextChar == ';') || (nextChar == '\n') ||
		(nextChar == '(') || (nextChar == ')') ||
		(nextChar == '=')) {
		return false;
	}
	return true;
}

bool Lexer::isValid(char nextChar) {
	if((nextChar == '+') || (nextChar == '-') ||
		(nextChar == '*') || (nextChar == ';') ||
		(nextChar == '(') || (nextChar == ')') ||
		(nextChar == '=')) {
		cout << "is it true?" << endl;
		return true;
	}
	cout << "is it false?" << endl;
	return false;
}