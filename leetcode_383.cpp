#include<iostream>
using namespace std;
/*
 * string find() 
 * return value:
 * The position of the first character of the first match.
 * If no matches were found, the function returns string::npos.
 * */
bool canConstruct(string ransomNote, string magazine) {
	for(auto ch : ransomNote){
		cout << magazine << endl;
		if(magazine.length() == 0)
			return false;
		if(magazine.find(ch) == string::npos)
			return false;
		magazine.erase(magazine.find(ch), 1);
	}
	return true;
}
int main(){
	canConstruct("aa", "aab");
	return 0;
}
