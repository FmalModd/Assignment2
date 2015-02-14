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
	//if last is not some type of space character
	//we add that as lexeme and return that token
	if(!isspace(last)) {
		lexeme += last;
		TokenCode token = getToken(lexeme);
		last = ' ';
		return Token(lexeme, token);
	}

	//continue if we encounter a space
	while(isspace(input[index])) {
		index++;
	}

	//creating the lexeme while we are reading a letter or digit
	if(isalpha(input[index]) || (isdigit(input[index]))) {
		while((isalpha(input[index]) || (isdigit(input[index]))) && (index < input.size())) {
			lexeme += input[index];
			index++;
		}
	}

	//If we have a lexeme we return the corresponding token
	if(lexeme != "") {
		TokenCode token = getToken(lexeme);
		return Token(lexeme, token);
	}
	
	//update last and index
	last = input[index];
	index++;
	
	return nextToken();
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
	//INT could be a multi-digit number, so we make
	//sure that the number is comprised only of digits
	//else we have an error (f.x.: 12ab is not an INT)
	if(isdigit(lexeme[0])) {
		for(int i = 0; i < lexeme.size(); i++) {
			if(!isdigit(lexeme[i])) {
				return ERROR;
			}
		}
		return INT;
	}
	//ID could be a multi-letter word, so we make
	//sure that the word is comprised only of letters
	//else we have an error (f.x.: AB12 is not an ID)
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




