#include "Lexer.h"
#include <iostream>

Lexer::Lexer() {
	//scanf("%*[ \n\t]%c",&c); 
	for(int i = 0; scanf("%c[ \n\t\n", &input[i]) != EOF; i++) { cout << input[i]; }
	cout << endl;
	cout << endl;
	index = 0;
	lastChar = ' ';
}

Token Lexer::nextToken() {
	string lexeme;
	cout << "input right now: ";
	for(int i = index; i < 50; i++) {
		cout << input[i];
	}
	cout << endl;

	if(isValid(lastChar)) {
		cout << "token2(): " << lastChar << endl;
		index++;
		lastChar = input[index];
		return Token();
	}

	while(input[index] == ' ' || input[index] == '\n') {
		index++;
	}
	
	for(; stopScanning(input[index]); index++) {
		lexeme += input[index];
	}

	if(lexeme != "") {
		cout << "token1(): " << lexeme << endl;
	}

	lastChar = input[index];

	return Token();
}

bool Lexer::stopScanning(char nextChar) {
	if((nextChar == '+') || (nextChar == '-') ||
		(nextChar == '*') || (nextChar == ';') ||
		(nextChar == '(') || (nextChar == ')') ||
		(nextChar == '=') || (nextChar == '\n') ||
		(nextChar == ' ')) {
		return false;
	}
	return true;
}

bool Lexer::isValid(char nextChar) {
	if((nextChar == '+') || (nextChar == '-') ||
		(nextChar == '*') || (nextChar == ';') ||
		(nextChar == '(') || (nextChar == ')') ||
		(nextChar == '=')) {
		return true;
	}
	return false;
}