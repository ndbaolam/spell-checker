#include <bits/stdc++.h>
using namespace std;

vector<pair<string, int>> sug;
string inp;

int countDifference(string x, string y){
	int n = x.size(), m = y.size();
	int f[n+1][m+1];
	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= m; j++)
		{
			if(i == 0) f[i][j] = j;
			else if(j == 0) f[i][j] = i;
			else
			{
				if(x[i-1] == y[j-1])
					f[i][j] = f[i-1][j-1];
				else
					f[i][j] = min({f[i-1][j], f[i-1][j-1], f[i][j-1]}) + 1;
			}
		}
	}
	return f[n][m];
}

void loadFile(){
	string line;
	ifstream file("words.txt");

	if(file.is_open()){
		while(getline(file, line)){
			int distance = countDifference(line, inp);
			sug.push_back({line, distance});
		}
		sort(sug.begin(), sug.end(), [](pair<string, int> a, pair<string, int> b){
			return a.second < b.second;
		});

		file.close();
	}
	else 
		cout << "Unable to open file" << endl;
}

int main(){
	//ifstream fin("input.txt");
	cin >> inp;
	loadFile();

	ofstream fout("suggestion.txt");

	for (int i = 0; i < 10; ++i){
		fout << sug[i].first << endl;
	}

	return 0;
}