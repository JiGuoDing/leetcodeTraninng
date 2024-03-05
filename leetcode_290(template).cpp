#include<iostream>
#include<sstream>
#include<vector>
#include<map>
using namespace std;
bool wordPattern(string pattern, string s) {
	istringstream ss(s);
	vector<string> vec;
	string element;
	map<char, string> ch2str;
	map<string, char> str2ch;
	while(ss >> element)
		vec.push_back(element);
	if(vec.size() != pattern.length())
		return false;
	else{
		for(int i = 0; i < pattern.length(); i++){
			if(ch2str.find(pattern[i]) == ch2str.end()){
				if(str2ch.find(vec[i]) == str2ch.end()){
					ch2str.insert({pattern[i], vec[i]});
					str2ch.insert({vec[i], pattern[i]});
				}
				else return false;
			}
			else{
				if(ch2str[pattern[i]] != vec[i])
					return false;
			}
		}
	}
	return true;
}
int main(){
	cout << wordPattern("abba", "dog cat cat dog") << endl;
	return 0;
}
