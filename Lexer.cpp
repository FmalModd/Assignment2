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
}

Token Lexer::nextToken() {
	string lexeme = "";
	if(valid(last)) {
		lexeme += last;
		TokenCode token = getToken(lexeme);
		last = ' ';
		return Token(lexeme, token);
	}

	while(isspace(input[index])) {
		index++;
	}

	if(isalpha(input[index])) {
		while(isalpha(input[index])) {
			lexeme += input[index];
			index++;
		}
	} else if(isdigit(input[index])) {
		while(isdigit(input[index])) {
			lexeme += input[index];
			index++;
		}
	}

	if(lexeme != "") {
		TokenCode token = getToken(lexeme);
		return Token(lexeme, token);
	}
	
	last = input[index];
	index++;

	return nextToken();
}

bool Lexer::valid(char c) {
	if((c == '+') || (c == '-') || (c == '*') ||
		(c == ';') || (c == '(') || (c == ')') ||
		(c == ')') || (c == '=')) {
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




