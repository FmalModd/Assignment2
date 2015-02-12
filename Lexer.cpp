#include "Lexer.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <ctype.h>

Lexer::Lexer() {
	char tmp;
	for(int i = 0; scanf("%c", &tmp) != EOF; i++) {
		input.push_back(tmp);
	}

	last = ' ';
	index = 0;

	// helping stuff
	/*
	for(int i = 0; i < size; i++) {
		if(input[i] == '\n') {
			cout << " newline" << endl;
		} else if(input[i] == ' ') {
			cout << " space ";
		} else {
			cout << input[i];
		}
	}
	*/
}

Token Lexer::nextToken() {
	string lexeme;
	if(valid(last)) {
		lexeme += last;
		TokenCode token = getToken(lexeme);
		//cout << "Token1: " << lexeme << endl;
		last = ' ';
		return Token(lexeme, token);
	}

	while(!stop(input[index])) {
		lexeme += input[index];
		index++;
	}

	if(lexeme != "") {
		TokenCode token = getToken(lexeme);
		//cout << "Token2: " << lexeme << endl;
		return Token(lexeme, token);
	}
	
	last = input[index];
	index++;

	return Token();
}

bool Lexer::valid(char c) {
	if((c == '+') || (c == '-') || (c == '*') ||
		(c == ';') || (c == '(') || (c == ')') ||
		(c == ')')) {
		return true;
	} else {
		return false;
	}
}

bool Lexer::stop(char c) {
	if((c == '+') || (c == '-') || (c == '*') ||
		(c == ';') || (c == '(') || (c == ')') ||
		(c == ')') || (c == '\n') || (c == ' ')) {
		return true;
	} else {
		return false;
	}
}

TokenCode Lexer::getToken(string lexeme) {
	if(lexeme == "(") return LPAREN;
	if(lexeme == ")") return RPAREN;
	if(lexeme == "+") return PLUS;
	if(lexeme == "-") return MINUS;
	if(lexeme == "*") return MULT;
	if(lexeme == ";") return SEMICOL;
	if(lexeme == "=") return ASSIGN;
	if(lexeme == "+") return PLUS;
	if(lexeme == "print") return PRINT;
	if(lexeme == "end") return END;
	if(isdigit(lexeme[0])) {
		for(int i = 0; i < lexeme.size(); i++) {
			if(!isdigit(lexeme[i])) {
				return ERROR;
			}
		}
		return INT;
	}
	if(isalpha(lexeme[0])) {
		for(int i = 0; i < lexeme.size(); i++) {
			if(!isalpha(lexeme[i])) {
				return ERROR;
			}
		}
		return ID;
 	}
 	return ERROR;
}




