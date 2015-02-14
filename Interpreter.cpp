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
			if(cin >> s) {
				myIDs.push(s);
			} else {
				cout << "Error for operator: " << s << endl;
				exit(0);
			}
		} else if (s == "ASSIGN") {
			if(myIDs.size() < 2) {
				cout << "Error for operator: " << s << endl;
				exit(0);
			}

			string first, second;
			int number;
			first = myIDs.top();
			myIDs.pop();
			second = myIDs.top();
			myIDs.pop();

			if(myMap.count(first) > 0) {
				number = myMap.find(first)->second;
			} else {
				number = stoi(first);
			}
			
			myMap.insert(pair<string, int>(second, number));
		} else if (s == "PRINT") {
			if(myMap.empty()) {
				cout << "Error for operator: " << s << endl;
				exit(0);
			}
			cout << myMap.find(myIDs.top())->second << endl;
			myIDs.pop();
		} else if((s == "SUB") || (s == "ADD") || (s == "MULT")) {
			if(myIDs.size() < 2) {
				cout << "Error for operator: " << s << endl;
				exit(0);
			}

			string first, second;
			int firstnumber, secondnumber;
			first = myIDs.top();
			myIDs.pop();
			second = myIDs.top();
			myIDs.pop();

			if(myMap.count(first) > 0) {
				firstnumber = myMap.find(first)->second;
			} else {
				firstnumber = stoi(first);
			}

			if(myMap.count(second) > 0) {
				secondnumber = myMap.find(second)->second;
			} else {
				secondnumber = stoi(second);
			}

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
			cout << "Error for operator: " << s << endl;
			exit(0);
		}
	}

	return 0;
}
