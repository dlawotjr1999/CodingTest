#include <string>
#include <vector>

using namespace std;

int stringToTime(const string& t) {
    int hour;
    int minute;
    
    auto pos = t.find(':');
    if(pos != string::npos) {
        hour = stoi(t.substr(0, pos));
        minute = stoi(t.substr(pos + 1));
    }
    return (hour * 60) + minute;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    int cur_time = stringToTime(pos);
    int video_length = stringToTime(video_len);
    int start_op = stringToTime(op_start);
    int end_op = stringToTime(op_end);
    
    auto OpeningSkip = [&]() {
        if (cur_time >= start_op && cur_time < end_op) {
            cur_time = end_op;
        }
    };
    OpeningSkip();
    
    for(auto& elm : commands) {
        if(elm == "next") {
            cur_time += 10;        
            if(cur_time > video_length) 
                cur_time = video_length;
            
            // 오프닝 건너뛰기
            if(start_op <= cur_time && cur_time < end_op) {
                cur_time = end_op;
            }
        } else {
            cur_time -= 10;
            if(cur_time < 0)
                cur_time = 0;
        }
        OpeningSkip();
    }
    
    int hour = cur_time / 60;
    int minute = cur_time % 60;
    
    auto pad = [](int x) {
        return (x < 10 ? "0" : "") + to_string(x);
    };
    
    answer = pad(hour) + ":" + pad(minute);
    return answer;
}