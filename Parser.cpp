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
		//If statements was not end, then it must be
		//"statement ; statements" which we cover here
		statement();
		if(nextToken.getToken() == SEMICOL) {
			if(assign) {
				cout << "ASSIGN" << endl;
				assign = false;
			}
			nextToken = lexer.nextToken();
			statements();
		} else {
			//If this wasn't fulfilled we have encountered an error
			error();
		}
	}
}

void Parser::statement() {
	//statement can either be "id = expr" or "print id"
	//we cover "id = expr" here...
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
	}
	//...and "print id" here
	else if(nextToken.getToken() == PRINT) {
		nextToken = lexer.nextToken();
		if(nextToken.getToken() == ID) {
			cout << "PUSH " << nextToken.getLexeme() << endl;
			nextToken = lexer.nextToken();
		} else {
			error();
		}
		cout << "PRINT" << endl;
	} else {
		//If this wasn't fulfilled we have encountered an error
		error();
	}
}

void Parser::expr() {
	//expr can only be "term",...
	term();
	//... "term + expr"...
	if(nextToken.getToken() == PLUS) {
		nextToken = lexer.nextToken();
		expr();
		cout << "ADD" << endl;
	} 
	//... or "term - expr"
	else if(nextToken.getToken() == MINUS) {
		nextToken = lexer.nextToken();
		expr();
		cout << "SUB" << endl;
	} 
}

void Parser::term() {
	//term may only be "factor"...
	factor();
	//... or "factor * term"
	if(nextToken.getToken() == MULT) {
		nextToken = lexer.nextToken();
		term();
		cout << "MULT" << endl;
	}
}

void Parser::factor() {
	//factor can only be "int",...
	if(nextToken.getToken() == INT) {
		cout << "PUSH " << nextToken.getLexeme() << endl;
		nextToken = lexer.nextToken();
	} 
	//..."id"...
	else if(
		nextToken.getToken() == ID) {
		cout << "PUSH " << nextToken.getLexeme() << endl;
		nextToken = lexer.nextToken();
	} 
	//...or "(expr)"
	else if(nextToken.getToken() == LPAREN) {
		nextToken = lexer.nextToken();
		expr();
		if(nextToken.getToken() == RPAREN) {
			nextToken = lexer.nextToken();
		} 
		//error if we read left paren, expr, but not a right paren
		else {
			error();
		}
	} 
	//If this wasn't fulfilled we have encountered an error
	else {
		error();
	}
}

void Parser::error() {
	cout << "Syntax error!" << endl;
	exit(0);
}


