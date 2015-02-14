#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

int main(){
	stack<string> myIDs;
	map<string, int> myMap;
	string s;

	while(cin >> s) {
		if (s == "PUSH") {
			//We have to get another argument if the operator is PUSH, 
			//else we have an error
			if(cin >> s) {
				myIDs.push(s);
			} else {
				cout << "Error for operator: " << s << endl;
				exit(0);
			}
		} else if (s == "ASSIGN") {
			//If we want to ASSIGN, there must be at least 
			//two elements on the stack
			if(myIDs.size() < 2) {
				cout << "Error for operator: " << s << endl;
				exit(0);
			}
			int number;
			string first = myIDs.top();
			myIDs.pop();
			string second = myIDs.top();
			myIDs.pop();
			//If first is an ID, we get the value associated with it
			if(myMap.count(first) > 0) {
				number = myMap.find(first)->second;
			} else {
				number = stoi(first);
			}
			//second now has the value "number" assigned to it
			myMap.insert(pair<string, int>(second, number));
		} else if (s == "PRINT") {
			//Only print if we have something on the stack
			if(myMap.empty()) {
				cout << "Error for operator: " << s << endl;
				exit(0);
			}
			cout << myMap.find(myIDs.top())->second << endl;
			myIDs.pop();
		} else if((s == "SUB") || (s == "ADD") || (s == "MULT")) {
			//We only do these operations if we have at least
			//two elements on the stack
			if(myIDs.size() < 2) {
				cout << "Error for operator: " << s << endl;
				exit(0);
			}
			int firstnumber, secondnumber;
			string first = myIDs.top(); 
			myIDs.pop();
			string second = myIDs.top();
			myIDs.pop();
			//If first is an ID, we get the value associated with it
			if(myMap.count(first) > 0) {
				firstnumber = myMap.find(first)->second;
			} else {
				firstnumber = stoi(first);
			}
			//The same with second
			if(myMap.count(second) > 0) {
				secondnumber = myMap.find(second)->second;
			} else {
				secondnumber = stoi(second);
			}
			//We then correctly make the result and push it
			//back on the stack
			int result = 0;
			if(s == "SUB") {
				result = secondnumber - firstnumber;
			} else if(s == "ADD") {
				result = secondnumber + firstnumber;
			}
			else if(s == "MULT") {
				result = secondnumber * firstnumber;
			}
			myIDs.push(to_string((long long) result));
		} else {
			//If we reach this place, we can be sure we have an error
			cout << "Error for operator: " << s << endl;
			exit(0);
		}
	}
	return 0;
}
