#include "Lexer.h"
#include "Parser.h"
#include <iostream>

int main() {
	Lexer myLexer;
	//Parser myParser = Parser(myLexer); 
	//myParser.parse();
	for(int i = 0; i < 10; i++) {
		cout << "i: " << i << endl;
		myLexer.nextToken();
	}
	return 0;
}