#include <iostream>
#include<map>
#include<string>
#include<set>
using namespace std;

int main() {
	int Q;
	map<string, string> dictionary;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		string input;
		cin >> input;
		if (input == "CHANGE_CAPITAL") {
			string country, capital;
			cin >> country >> capital;
			if (dictionary.count(country) == 0) {
				cout << "Introduce new country " << country << " with capital " << capital << endl;
			}
			else { const string& old_capital=dictionary[capital];
			if (old_capital == capital) {
				cout << "Country " << country << " hasn't changed its capital" << endl;
			}
			else cout << "Country " << country << " has changed its capital from " << old_capital << " to " << capital << endl;
			}
			dictionary[country] = capital;
		}
		else if (input == "RENAME") {
			string old_country, country;
			cin >> old_country >> country;
			if (old_country == country || dictionary.count(old_country) == 0 || dictionary.count(country) == 1) {
				cout << "Incorrect rename, skip\n";
			}
			else {
				cout << "Country " << old_country << " with capital " << dictionary[old_country] << " has been renamed to " << country << endl;
				dictionary[old_country] = dictionary[country];
				dictionary(old_country).erase;
			}
		}
		else if (input == "ABOUT") {
			string country;
			cin >> country;
			if (dictionary.count(country) == 0) {
				cout << "Country " << country << " doesn't exist\n";
			}
			else {
				count << "Country " << country << " has capital " << dictionary[country] << endl;
			}
		}
		else if (input == "DUMP") {
			if (dictionary.empty()) {
				cout << "There ara no cuntries in the world\n";
			}
			else {
				for (const auto& now : dictionary) {
					cout << now.first << "/" << now.second << " ";
				}
			}
		}
	}
return 0;
}