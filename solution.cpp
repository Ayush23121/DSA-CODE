#include <bits/stdc++.h>
using namespace std;

struct Slide {
    int x1, y1, x2, y2;
};

double getY(const Slide &s, double x) {
    // get y-coordinate on line at given x
    if (s.x1 == s.x2) return 1e9; // vertical shouldn't happen
    double m = (double)(s.y2 - s.y1) / (s.x2 - s.x1);
    double c = s.y1 - m * s.x1;
    return m * x + c;
}

int main() {
    int n;
    cin >> n;
    vector<Slide> slides(n);
    for (int i = 0; i < n; i++) {
        cin >> slides[i].x1 >> slides[i].y1 >> slides[i].x2 >> slides[i].y2;
    }

    double x, y;
    int energy;
    cin >> x >> y >> energy;

    while (energy > 0 && y > 0) {
        // find slide just below current position
        double bestY = -1;
        int bestIdx = -1;

        for (int i = 0; i < n; i++) {
            int x1 = slides[i].x1, x2 = slides[i].x2;
            int y1 = slides[i].y1, y2 = slides[i].y2;
            if ((x >= min(x1, x2) - 1e-9) && (x <= max(x1, x2) + 1e-9)) {
                double slideY = getY(slides[i], x);
                if (slideY < y && slideY > bestY) {
                    bestY = slideY;
                    bestIdx = i;
                }
            }
        }

        if (bestIdx == -1) {
            // fall to ground
            y = 0;
            break;
        }

        // fall vertically to slide
        y = bestY;

        // slide along it
        Slide s = slides[bestIdx];
        double len = hypot(s.x2 - s.x1, s.y2 - s.y1);
        if (energy < len) {
            // partial slide
            double ratio = energy / len;
            x = s.x1 + (s.x2 - s.x1) * ratio;
            y = s.y1 + (s.y2 - s.y1) * ratio;
            energy = 0;
            break;
        } else {
            x = s.x2;
            y = s.y2;
            energy -= (int)len;
        }

        // check stuck condition
        if (energy > 0) {
            bool below = false;
            for (int i = 0; i < n; i++) {
                if (i == bestIdx) continue;
                int x1 = slides[i].x1, x2 = slides[i].x2;
                if (x >= min(x1, x2) - 1e-9 && x <= max(x1, x2) + 1e-9) {
                    double slideY = getY(slides[i], x);
                    if (slideY < y) below = true;
                }
            }
            if (!below && y > 0) {
                int cost = (int)(x * y);
                energy -= cost;
                if (energy <= 0) break;
            }
        }
    }

    cout << (int)round(x) << " " << (int)round(y);
    return 0;
}
