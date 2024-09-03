#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

bool visited[52];

set<int> collectTeam(map<int,set<int>> adjacencyList, int student){
    visited[student] = true;
    set<int> team;
    team.insert(student);

    // Base case: if the student has only one teammate and that teammate is already visited
    if ( adjacencyList[student].size() == 1 && visited[*adjacencyList[student].begin()] ){
        return team;
    }

    // Explore the teammates recursively
    for(auto teammate : adjacencyList[student]){
        if (visited[teammate]){
            continue; // Skip already visited teammates
        }
        set<int> result;
        team.merge(collectTeam(adjacencyList,teammate)); // Merge the teammate set into the current team
    }
    return team;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int numStudents,numPairs;
    cin >> numStudents >> numPairs;
    // Adjacency list to store student pair preferences
    map<int, set<int>> adjacencyList;
    map<int,set<int>>::iterator it, it2;
    
    // Set to store all student numbers
    set<int> allStudents;

    // Vector to store the final teams
    vector<string> teams;

    // Initialize the set of all students from 1 to numStudents
    for(int i = 1 ; i <= numStudents ; i ++){
        allStudents.insert(i);
    }

    // Reading the student pairs who want to be on the same team
    for (int i = 0, a, b ; i < numPairs ; i++){
        cin >> a >> b;
        adjacencyList[a].insert(b);
        adjacencyList[b].insert(a);
    }


    if ( numPairs > 0 ){
        vector<int> toErase;
        // Collecting teams based on preferences
        for(int i = 1 ; i <= numStudents ; i++) {
            set<int> fillers = collectTeam(adjacencyList, i);
            for(auto filler: fillers) {
                if(i != filler) {
                    adjacencyList[i].insert(filler); // Add teammate to the current student's list
                    toErase.push_back(filler); // Mark teammate for removal later
                } else {
                    adjacencyList[i].erase(i); // Remove self-reference from the adjacency list
                }
            }
        }

        // Remove students already assigned to teams from the adjacency list
        for(auto key : toErase) {
            adjacencyList.erase(key);
        }

        // check if there is a team with more than 3 players
        for (it = adjacencyList.begin(); it != adjacencyList.end(); it++){
            int player = it->first;
            set<int> colleages = it->second;
            if(colleages.size() >= 3) {
                break;
            }
        }
        if ( it != adjacencyList.end() ){
            cout << -1 << endl ;
            return 0;
        }

        // remove the teams with 3 players
        for (it = adjacencyList.begin(); it != adjacencyList.end(); it++){
            int player = it->first;
            set<int> colleages = it->second;
            string team = "";
            if(colleages.size() == 2) {
                allStudents.erase(player);
                team += to_string(player) + " "; 
                for ( auto x: colleages ){
                    allStudents.erase(x);
                    team += to_string(x) + " ";
                }
                team.pop_back();
                teams.push_back(team);
            }
        }

        // Handle cases with 2-member teams and add 1 more member from remaining students
        for (it = adjacencyList.begin(); it != adjacencyList.end(); it++){
            int player = it->first;
            set<int> colleages = it->second;
            string team = "";
            if(colleages.size() == 1) {
                allStudents.erase(player);
                team += to_string(player) + " "; 
                for ( auto x: colleages ){
                    allStudents.erase(x);
                    team += to_string(x) + " ";
                }
                // Find a third member to complete the team of 3
                for (it2 = adjacencyList.begin(); it2 != adjacencyList.end(); it2++){
                    int player2 = it2->first;
                    set<int> anotherColleages = it2->second;
                    if (anotherColleages.size() == 0 && player != player2 && player2 != *colleages.begin() && allStudents.count(player2)){
                        team += to_string(player2);
                        teams.push_back(team);
                        allStudents.erase(player2);
                        break;
                    }
                }
                if ( it2 == adjacencyList.end() ){
                    cout << -1 << endl;  // If no valid third member found, output -1 and exit
                    return 0;
                }
            }   
        }
    }

    // Assign remaining students into teams of 3
    int i = 0;
    string team = "";

    for (auto x: allStudents){
        i ++;
        team += to_string(x) + " ";
        if ( i % 3 == 0 ){
            team.pop_back();
            teams.push_back(team);
            i = 0;
            team = "";
        }
    }

    // Output all formed teams
    for (auto t : teams) {
        cout << t << endl;
    }

    return 0;
}
