#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<pair<long long, long long>>& road, long long minGap) {
    long long lastStation = road[0].first;
    for (int i = 1; i < road.size(); i++) {
        long long placeHere = max(road[i].first, lastStation + minGap);
        if (placeHere > road[i].second) {
            return false;
        }
        lastStation = placeHere;
    }
    return true;
}

long long maxMinDistance(int sections, vector<pair<long long, long long>>& road) {
    sort(road.begin(), road.end());
    long long low = 0, high = 1e14, bestGap = 0;

    while (low <= high) {
        long long mid = (low + high) / 2;
        if (canPlace(road, mid)) {
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
    vector<pair<long long, long long>> road(sections);
    for (int i = 0; i < sections; i++) {
        cin >> road[i].first >> road[i].second;
    }
    cout << maxMinDistance(sections, road) << endl;
    return 0;
}
