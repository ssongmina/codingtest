#include <bits/stdc++.h>

using namespace std;

bool flag;
string str;
int vowel_num, v_idx, e_idx;

bool isVowel(char c){
	return c == 'a' || c == 'e' || c == 'i' || c == 'u' || c == 'o';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	while(true){
		cin >> str;
		if(str == "end") break;
		flag = true;
		vowel_num = 0, v_idx = 0, e_idx = 0;
		int prev = -1;
		for(int i=0; i<str.size(); i++){
			if(isVowel(str[i])){
				vowel_num++;
				if(v_idx == 0) e_idx = 0;
				v_idx++;
				if(v_idx >= 3){
					flag = false;
					break;
				}
			}
			else{
				if(e_idx == 0) v_idx = 0;
				e_idx++;
				if(e_idx >= 3){
					flag = false;
					break;
				}
			}
			if(i >= 1 &&str[i] == str[prev] && (str[i] != 'e' && str[i] != 'o')){
				flag = false;
				break;
			}
			prev = i;
		}
		if(vowel_num == 0) flag = false;
		
		if(flag) cout << "<" << str << "> is acceptable.\n";
		else cout << "<" << str << "> is not acceptable.\n";
	}
	
	return 0;
}