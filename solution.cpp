#include <bits/stdc++.h>
using namespace std;

struct Instr {
    string turn;
    int dist;
};

pair<int,int> simulatePath(const vector<Instr>& instr, pair<int,int> start,
                           int wrongIndex = -1, const string& newTurn = "") {
    // Directions: 0 = North, 1 = East, 2 = South, 3 = West
    int dir = 0;
    int x = start.first, y = start.second;

    for (int i = 0; i < (int)instr.size(); ++i) {
        string t = instr[i].turn;
        int d = instr[i].dist;
        if (i == wrongIndex) t = newTurn;

        if (t == "left") dir = (dir + 3) % 4;
        else if (t == "right") dir = (dir + 1) % 4;
        else if (t == "back") dir = (dir + 2) % 4;
        // straight -> no change

        if (dir == 0) y += d;       // north
        else if (dir == 1) x += d;  // east
        else if (dir == 2) y -= d;  // south
        else if (dir == 3) x -= d;  // west
    }
    return {x, y};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<Instr> instr;
    instr.reserve(N);
    for (int i = 0; i < N; ++i) {
        string turn;
        int dist;
        cin >> turn >> dist;
        instr.push_back({turn, dist});
    }

    int sx, sy, tx, ty;
    cin >> sx >> sy;
    cin >> tx >> ty;

    pair<int,int> start = {sx, sy};
    pair<int,int> target = {tx, ty};

    vector<string> allTurns = {"left", "right", "straight", "back"};

    for (int i = 0; i < N; ++i) {
        for (const string &alt : allTurns) {
            if (alt == instr[i].turn) continue; // must change to a different turn

            pair<int,int> finalPos = simulatePath(instr, start, i, alt);
            if (finalPos == target) {
                cout << "Yes\n";
                cout << instr[i].turn << " " << instr[i].dist << "\n";
                cout << alt << " " << instr[i].dist << "\n";
                return 0;
            }
        }
    }

    cout << "No\n";
    return 0;
}
