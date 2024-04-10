#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Team {
    int programmer;
    int mathematician;
    int totalScore;

    Team(int programmer, int mathematician, int totalScore)
        : programmer(programmer), mathematician(mathematician), totalScore(totalScore) {}
};

bool compareTeams(const Team& team1, const Team& team2) {
    return team1.totalScore > team2.totalScore;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> programmerScores(N);
    vector<int> mathematicianScores(N);

    for (int i = 0; i < N; ++i) {
        cin >> programmerScores[i];
    }

    for (int i = 0; i < N; ++i) {
        cin >> mathematicianScores[i];
    }

    vector<Team> teams; 

    for (int i = 0; i < M; ++i) {
        int programmer, mathematician;
        cin >> programmer >> mathematician;

        teams.emplace_back(programmer, mathematician, programmerScores[programmer - 1] + mathematicianScores[mathematician - 1]);
    }

    sort(teams.begin(), teams.end(), compareTeams);

    for (int i = 0; i < M - 1; ++i) {
        for (int j = i + 1; j < M; ++j) {
            if (teams[i].programmer != teams[j].programmer && teams[i].programmer != teams[j].mathematician &&
                teams[i].mathematician != teams[j].programmer && teams[i].mathematician != teams[j].mathematician) {
                cout << teams[i].programmer << " " << teams[i].mathematician<<endl << teams[j].programmer << " " << teams[j].mathematician << endl;
                return 0;
            }
        }
    }

    return 0;
}