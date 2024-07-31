#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

map <string, long long> int_vars;
map <string, double> float_vars;
map <string, bool> bool_vars;
map <string, char> char_vars;
map <string, string> string_vars;
map <string, int> vars_type;
vector <string> vars_name;

void CreateIntVari(string name, int value) {
	int_vars[name] = value;
	vars_type[name] = 0;
	vars_name.push_back(name);
}

void CreateDoubleVari(string name, double value) {
	float_vars[name] = value;
	vars_type[name] = 1;
	vars_name.push_back(name);
}

void CreateBoolVari(string name, bool value) {
	bool_vars[name] = value;
	vars_type[name] = 2;
	vars_name.push_back(name);
}

void CreateCharVari(string name, char value) {
	char_vars[name] = value;
	vars_type[name] = 3;
	vars_name.push_back(name);
}

void CreateStringVari(string name, string value) {
	string_vars[name] = value;
	vars_type[name] = 4;
	vars_name.push_back(name);
}

int callVari(string name) {
	bool is_in = false;
	for (int i = 0; i<vars_name.size(); i++) {
		if (vars_name[i] == name) {
			is_in = true;
		}
	}
	if (is_in == false) return -1;
	int ty = vars_type[name];
	
	if (ty==0) 
		return int_vars[name];
	else if (ty==1) 
		return float_vars[name];
	else if (ty==2) 
		return bool_vars[name];
	else if (ty==3) 
		return char_vars[name];
	
	return -2;
}

string callVariString(string name) {
	bool is_in = false;
	for (int i = 0; i<vars_name.size(); i++) {
		if (vars_name[i] == name) {
			is_in = true;
		}
	}
	if (is_in == false) return "-1";
	
	if (vars_type[name]==4)
		return string_vars[name];
	
	return "-3";
}

int ChangeValue(string name, string value) {
	bool is_in = false;
	for (int i = 0; i<vars_name.size(); i++) {
		if (vars_name[i] == name) {
			is_in = true;
		}
	}
	if (is_in == false) return -1;
	
	int ty = vars_type[name];
	
	if (ty==0) 
		try {
			int_vars[name] = stoll(value);
		} catch (const invalid_argument&e) {
			cout << "Error Occurred! \nErrorType : InvalidArgument\n"; 
		} catch (const out_of_range&e) {
			cout << "Error Occurred! \nErrorType : OutOfRange\n";
		} catch(...) {
			cout << "Error Occurred! \nErrorType : UnexpectedErrorFound\n";
		}
	else if (ty==1) 
		try {
			float_vars[name] = stod(value);
		} catch (const invalid_argument&e) {
			cout << "Error Occurred! \nErrorType : InvalidArgument\n"; 
		} catch (const out_of_range&e) {
			cout << "Error Occurred! \nErrorType : OutOfRange\n";
		} catch(...) {
			cout << "Error Occurred! \nErrorType : UnexpectedErrorFound\n";
		}
	else if (ty==2) {
		if (value=="true") bool_vars[name] = true;
		else bool_vars[name] = false;
	}
	else if (ty==3)
		char_vars[name] = value[0];
	else 
		string_vars[name] = value;
	
	return 0;
}
