#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;

    auto toMinutes = [](int hhmm) {
        return (hhmm / 100) * 60 + (hhmm % 100);
    }; 

    for (int i = 0; i < timelogs.size(); i++) {
        int deadline = toMinutes(schedules[i]) + 10;
        int cnt = 0;

        for (int j = 0; j < timelogs[i].size(); j++) {
            int dow = (startday + j) % 7;
            if (dow == 6 || dow == 0)
                continue;

            int curTime = toMinutes(timelogs[i][j]);
            if (0 <= curTime && curTime <= deadline) {
                cnt++;
            }
        }

        if (cnt == 5)
            answer++;
    }

    return answer;
}