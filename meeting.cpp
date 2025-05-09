#include <bits/stdc++.h>
using namespace std;

bool canPlaceStations(vector<pair<long long, long long>>& roadSections, long long minGap) {
    long long lastStation = roadSections[0].first;
    for (int i = 1; i < roadSections.size(); i++) {
        long long placeHere = max(roadSections[i].first, lastStation + minGap);
        if (placeHere > roadSections[i].second) {
            return false;
        }
        lastStation = placeHere;
    }
    return true;
}

long long maxMinDistance(int sections, vector<pair<long long, long long>>& roadSections) {
    sort(roadSections.begin(), roadSections.end());
    long long low = 0, high = 1e14, bestGap = 0;

    while (low <= high) {
        long long mid = (low + high) / 2;
        if (canPlaceStations(roadSections, mid)) {
            bestGap = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return bestGap;
}

int main() {
    int sections;
    cin >> sections;
    vector<pair<long long, long long>> roadSections(sections);
    for (int i = 0; i < sections; i++) {
        cin >> roadSections[i].first >> roadSections[i].second;
    }
    cout << maxMinDistance(sections, roadSections) << endl;
    return 0;
}
