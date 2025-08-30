#include <bits/stdc++.h>

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

    std::vector<std::string> parts;
    parts.reserve(8);

    std::string cur;
    bool has_double = false;    
    int double_pos = -1;        

    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == ':') {
            if (!cur.empty()) {                 
                parts.push_back(pad4(cur));
                cur.clear();
            }
            if (i + 1 < s.size() && s[i + 1] == ':') { 
                has_double = true;
                double_pos = (int)parts.size(); 
                i++;                            
            }
        }
        else {
            char ch = s[i];

            if ('A' <= ch && ch <= 'Z') 
                ch = (char)(ch - 'A' + 'a');
            cur.push_back(ch);
        }
    }
    if (!cur.empty()) 
        parts.push_back(pad4(cur)); 

    if (has_double) {
        int missing = 8 - (int)parts.size();     
        parts.insert(parts.begin() + double_pos, missing, std::string("0000"));
    }

    for (int i = 0; i < 8; ++i) {
        if (i) 
            std::cout << ':';
        std::cout << parts[i];
    }

    std::cout << '\n';
    return 0;
}