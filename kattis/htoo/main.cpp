#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long LL;

int is_a_number(char x){
    if(x>='0' && x<='9'){
        // convert to int
        return x-'0';
    }
    else{
        return -1;
    }
}

unordered_map<char, LL> convert_molecule_to_atoms(string s, int factor = 1){
    unordered_map<char, LL> atoms;
    char last_atoms = '-';
    LL value = 1;
    string num_str;
    for (int i = 0; i < s.size(); i++) {
        while (i < s.size() && is_a_number(s[i]) != -1) {
            num_str += s[i];
            i++;
        }
        if (num_str != "") {
            value = stoull(num_str);
            num_str = "";
        }
        // check if last_atoms is initialised
        if (last_atoms != '-') {
             if ( atoms[last_atoms] != 0 ){
                atoms[last_atoms] += value * factor;
            } else {
                atoms[last_atoms] = value * factor;
            }
        }
        last_atoms = s[i];
        value = 1;
    }
    if ( atoms[last_atoms] != 0 ){
        atoms[last_atoms] += value * factor;
    } else {
        atoms[last_atoms] = value * factor;
    }
    // clear map from atoms with key not between 'A' and 'Z'
    for (auto it = atoms.begin(); it != atoms.end();) {
        if (it->first < 'A' || it->first > 'Z') {
            it = atoms.erase(it);
        }
        else {
            ++it;
        }
    }
    return atoms;
}

int main(){
    string intput, output;
    int number;
    LL molecules = -1 ;
    cin >> intput;
    cin >> number;
    cin >> output;
    unordered_map<char, LL> input_atoms, output_atoms;
    input_atoms = convert_molecule_to_atoms(intput, number);
    output_atoms = convert_molecule_to_atoms(output);
    for (auto& it : output_atoms) {
        if ( input_atoms.find(it.first) == input_atoms.end()) {
            molecules = 0;
            break;
        }
        if (molecules == -1) {
            molecules = input_atoms[it.first] / it.second;
        } else {
            molecules = min(molecules, input_atoms[it.first] / it.second);
        }
    }
    cout << molecules << endl;
}