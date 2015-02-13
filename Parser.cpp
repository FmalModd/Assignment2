#include "Parser.h"
#include <iostream>

Parser::Parser() { }

Parser::Parser(Lexer lexer) : lexer(lexer) { }

// enum TokenCode {ID, ASSIGN, SEMICOL, INT, PLUS, MINUS, MULT, LPAREN, RPAREN, PRINT, END, ERROR};

Token nextToken;

void Parser::parse() {
	nextToken = lexer.nextToken();
	statements();
}

void Parser::statements() {
	if(nextToken.getToken() == END) {
		cout << "the lexeme: " << nextToken.getLexeme() << " - " << "the token: " << nextToken.getToken() << endl;
		return;
	} else {
		statement();
		if(nextToken.getToken() == SEMICOL) {
			cout << "the lexeme: " << nextToken.getLexeme() << " - " << "the token: " << nextToken.getToken() << endl;
			nextToken = lexer.nextToken();
			statements();
		} else {
			error();
		}
	}
}

void Parser::statement() {
	if(nextToken.getToken() == ID) {
		cout << "the lexeme: " << nextToken.getLexeme() << " - " << "the token: " << nextToken.getToken() << endl;
		nextToken = lexer.nextToken();
		if(nextToken.getToken() == ASSIGN) {
			cout << "the lexeme: " << nextToken.getLexeme() << " - " << "the token: " << nextToken.getToken() << endl;
			nextToken = lexer.nextToken();
			expr();
		} else {
			error();
		}
	} else if(nextToken.getToken() == PRINT) {
		cout << "the lexeme: " << nextToken.getLexeme() << " - " << "the token: " << nextToken.getToken() << endl;
		nextToken = lexer.nextToken();
		if(nextToken.getToken() == ID) {
			// TODO
			cout << "the lexeme: " << nextToken.getLexeme() << " - " << "the token: " << nextToken.getToken() << endl;
			nextToken = lexer.nextToken();
			return;
		} else {
			error();
		}
	} else {
		error();
	}
}

void Parser::expr() {
	term();
	if(nextToken.getToken() == PLUS) {
		cout << "the lexeme: " << nextToken.getLexeme() << " - " << "the token: " << nextToken.getToken() << endl;
		nextToken = lexer.nextToken();
		expr();
	} else if(nextToken.getToken() == MINUS) {
		cout << "the lexeme: " << nextToken.getLexeme() << " - " << "the token: " << nextToken.getToken() << endl;
		nextToken = lexer.nextToken();
		expr();
	} 
}

void Parser::term() {
	factor();
	if(nextToken.getToken() == MULT) {
		cout << "the lexeme: " << nextToken.getLexeme() << " - " << "the token: " << nextToken.getToken() << endl;
		nextToken = lexer.nextToken();
		term();
	}
}

void Parser::factor() {
	if(nextToken.getToken() == INT) {
		// TODO
		cout << "the lexeme: " << nextToken.getLexeme() << " - " << "the token: " << nextToken.getToken() << endl;
		nextToken = lexer.nextToken();
		return;
	} else if(nextToken.getToken() == ID) {
		// TODO
		cout << "the lexeme: " << nextToken.getLexeme() << " - " << "the token: " << nextToken.getToken() << endl;
		nextToken = lexer.nextToken();
		return;
	} else if(nextToken.getToken() == LPAREN) {
		cout << "the lexeme: " << nextToken.getLexeme() << " - " << "the token: " << nextToken.getToken() << endl;
		nextToken = lexer.nextToken();
		expr();
		if(nextToken.getToken() == RPAREN) {
			// TODO
			cout << "the lexeme: " << nextToken.getLexeme() << " - " << "the token: " << nextToken.getToken() << endl;
			nextToken = lexer.nextToken();
			return;
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


