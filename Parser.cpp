#include "Parser.h"
#include <iostream>

Parser::Parser() { }

Parser::Parser(Lexer lexer) : lexer(lexer) { }

// enum TokenCode {ID, ASSIGN, SEMICOL, INT, PLUS, MINUS, MULT, LPAREN, RPAREN, PRINT, END, ERROR};

void Parser::parse() {
	Token nextToken = lexer.nextToken();
	if(nextToken.getToken() == LPAREN) {
		nextToken = lexer.nextToken();
		expr();
		if(nextToken.getToken() == RPAREN) {
			nextToken = lexer.nextToken();
		} else {
			error();
		}
	} else {
		if(nextToken.getToken() == ID) {

		} else if(nextToken.getToken() == PRINT) {

		} else if(nextToken.getToken() == END) {

		} else if(nextToken.getToken() == ERROR) {
			error();
			return;
		}
	}
}

void Parser::expr() {

}

void Parser::error() {
	cout << "Syntax error!" << endl;
}