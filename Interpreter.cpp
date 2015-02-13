#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

int main(){
	stack<string> myIDs;
	map<string, int> myMap;
	string s;

	//for(int i = 0; scanf("%s", &s) != EOF; i++) {
	while(cin >> s) {
		if (s == "PUSH") {
			cin >> s;
			myIDs.push(s);
		} else if (s == "ASSIGN") {
			int number = stoi(myIDs.top());
			myIDs.pop();
			string var = myIDs.top();
			myIDs.pop();
			myMap.insert(pair<string, int>(var, number));
		} else if (s == "SUB") {
			string first = myIDs.top();
			myIDs.pop();
			string second = myIDs.top();
			myIDs.pop();
			int firstnumber, secondnumber;
			if(isdigit(first[0])) {
				firstnumber = stoi(first);
			} else {
				firstnumber = myMap.find(first)->second;
			}
			if(isdigit(second[0])) {
				secondnumber = stoi(first);
			} else {
				secondnumber = myMap.find(second)->second;
			}
			int result = secondnumber - firstnumber;
			string myString = to_string(result);
			myIDs.push(myString);
		} else if (s == "PLUS") {
			
		} else if (s == "MULT") {
			
		} else if (s == "PRINT") {
			cout << myIDs.top() << endl;
			myIDs.pop();
		}
	}


	return 0;
}