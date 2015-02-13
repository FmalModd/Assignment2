#include "Parser.h"
#include <iostream>
#include <stdlib.h>

Parser::Parser() { }

Parser::Parser(Lexer lexer) : lexer(lexer), nextToken(Token()), assign(false) { }

void Parser::parse() {
	nextToken = lexer.nextToken();
	statements();
}

void Parser::statements() {
	if(nextToken.getToken() == END) {
		return;
	} else {
		statement();
		if(nextToken.getToken() == SEMICOL) {
			if(assign) {
				cout << "ASSIGN" << endl;
				assign = false;
			}
			nextToken = lexer.nextToken();
			statements();
		} else {
			error();
		}
	}
}

void Parser::statement() {
	if(nextToken.getToken() == ID) {
		cout << "PUSH " << nextToken.getLexeme() << endl;
		nextToken = lexer.nextToken();
		if(nextToken.getToken() == ASSIGN) {
			nextToken = lexer.nextToken();
			expr();
			assign = true;
		} else {
			error();
		}
	} else if(nextToken.getToken() == PRINT) {
		nextToken = lexer.nextToken();
		if(nextToken.getToken() == ID) {
			cout << "PUSH " << nextToken.getLexeme() << endl;
			nextToken = lexer.nextToken();
		} else {
			error();
		}
		
		cout << "PRINT" << endl;
	} else {
		error();
	}
}

void Parser::expr() {
	term();
	if(nextToken.getToken() == PLUS) {
		nextToken = lexer.nextToken();
		expr();
		cout << "ADD" << endl;
	} else if(nextToken.getToken() == MINUS) {
		nextToken = lexer.nextToken();
		expr();
		cout << "SUB" << endl;
	} 
}

void Parser::term() {
	factor();
	if(nextToken.getToken() == MULT) {
		nextToken = lexer.nextToken();
		term();
		cout << "MULT" << endl;
	}
}

void Parser::factor() {
	if(nextToken.getToken() == INT) {
		cout << "PUSH " << nextToken.getLexeme() << endl;
		nextToken = lexer.nextToken();
	} else if(nextToken.getToken() == ID) {
		cout << "PUSH " << nextToken.getLexeme() << endl;
		nextToken = lexer.nextToken();
	} else if(nextToken.getToken() == LPAREN) {
		nextToken = lexer.nextToken();
		expr();
		if(nextToken.getToken() == RPAREN) {
			nextToken = lexer.nextToken();
		} else {
			error();
		}
	} else {
		error();
	}
}

void Parser::error() {
	cout << "Syntax error!" << endl;
	exit(0);
}


