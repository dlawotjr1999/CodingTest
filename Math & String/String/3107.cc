#include <bits/stdc++.h>

// 주어진 축약형 IPv6 주소를 완전한 형태의 IPv6 주소로 변환시키는 문제
// 0으로만 이루어진 그룹이 있는 경우 한 개 이상 연속된 그룹을 골라 "::"로 바꿀 수 있음

// 한 그룹이 네 자릿수가 아닌 경우, 네 자릿수가 되도록 앞에 0을 채워넣음
inline std::string pad4(std::string t) {
    for (auto& ch : t) 
        ch = (char)tolower((unsigned char)ch);
    if (t.size() < 4) 
        t = std::string(4 - t.size(), '0') + t;
    
    return t;
}

int main() {
    std::string s;
    std::cin >> s;

    // 각 그룹을 분리하여 저장
    std::vector<std::string> parts;
    parts.reserve(8);

    std::string cur;
    bool has_double = false;    // "::" 압축 여부
    int double_pos = -1;        // "::"가 발견된 위치
     
    for (int i = 0; i < s.size(); ++i) {
        // 한 그룹이 확인되면 필요한 경우 padding을 채움
        if (s[i] == ':') {
            if (!cur.empty()) {                 
                parts.push_back(pad4(cur));
                cur.clear();
            }
            // "::"이 발견되면 현재까지의 그룹 갯수를 위치로 저장
            if (i + 1 < s.size() && s[i + 1] == ':') { 
                has_double = true;
                double_pos = (int)parts.size(); 
                i++;                            
            }
        }
        // 그룹 내 숫자인 경우(':'가 아닌 경우) 그대로 추가하며, 필요 시 tolower 수행
        else {
            char ch = s[i];

            if ('A' <= ch && ch <= 'Z') 
                ch = (char)(ch - 'A' + 'a');
            cur.push_back(ch);
        }
    }

    // 마지막 그룹 처리
    if (!cur.empty()) 
        parts.push_back(pad4(cur)); 

    // "::"가 있는 경우 부족한 그룹의 갯수를 계산해서 "0000"을 채움
    if (has_double) {
        int missing = 8 - (int)parts.size();     
        parts.insert(parts.begin() + double_pos, missing, std::string("0000"));
    }

    // 맨 앞을 제외하고 그룹마다 ':'로 연결
    for (int i = 0; i < 8; ++i) {
        if (i) 
            std::cout << ':';
        std::cout << parts[i];
    }

    std::cout << '\n';
    return 0;
}