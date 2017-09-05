#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

//  exam2.cpp 

using namespace std;

int q1(vector<int> v){
	sort(v.begin(), v.end());
	int minDist = INT_MAX;
	for (int i = 1; i < v.size(); i++)
		if (abs(v[i] - v[i - 1]) < minDist)
			minDist = abs(v[i] - v[i - 1]);
	return minDist;
}

vector<int> q2(multimap<char, int>& m, char c){
	vector<int> retval;
	for (multimap<char, int>::iterator i = m.begin(); i != m.end(); i++)
		if (i->first == c)
			retval.push_back(i->second);
	return retval;
}

vector<pair<double, double>> q3a(vector<double> m, vector<double> w){ //O(N^2)
	vector<pair<double, double>> retval;
	for (int i = 0; i < m.size(); i++){
		int minMan = 0;
		int minWoman = 0;
		for (int j = 1; j < m.size(); j++)
			if (m[j] < m[minMan])
				minMan = j;
		for (int j = 1; j < w.size(); j++)
			if (w[j] < w[minWoman])
				minWoman = j;
		pair<double, double> temp(m[minMan], w[minWoman]);
		m[minMan] = DBL_MAX;
		w[minWoman] = DBL_MAX;
		retval.push_back(temp);
	}
	return retval;
}

vector<pair<double, double>> q3c(vector<double> m, vector<double> w){ //O(N log N)
	sort(m.begin(), m.end());
	sort(w.begin(), w.end());
	vector<pair<double, double>> retval;
	pair<double, double> couple;
	for (int i = 0; i < m.size(); i++){
		couple.first = m[i];
		couple.second = w[i];
		retval.push_back(couple);
	}
	return retval;
}

class Elephant{
	int size;
public:
	bool operator<(const Elephant& rhs){
		return size < rhs.size;
	}
};

void q5a(vector<Elephant*>& v){ //O(N^2)
	for (int i = 1; i < v.size(); i++){
		Elephant* temp = v[i];
		int j = i;
		for (j = i; j > 0 && *(temp)<*(v[j - 1]); j--)
			v[j] = v[j - 1];
		v[j] = temp;
	}
}

void q5b(vector<Elephant>& v){
	vector<Elephant*> vep;
	for (int i = 0; i < v.size(); i++)
		vep.push_back(&v[i]);

	//for (Elephant& e : v)
	//	vep.push_back(&e);
	q5a(vep);
	vector<Elephant> temp;
	for (Elephant* ptr : vep)
		temp.push_back(*ptr);
	v = temp;
}
