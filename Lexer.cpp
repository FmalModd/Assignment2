#include "Lexer.h"
#include <iostream>
#include <string>

Lexer::Lexer() {
	for(int i = 0; scanf("%c[ \n\t\n", &input[i]) != EOF; i++) { 
		cout << input[i]; 
	}
	index = 0;
	last = ' ';
	cout << "starting index: " << index << endl;
	cout << "starting last: " << last << endl;
	cout << endl;
}

Token Lexer::nextToken() {
	return Token();
}