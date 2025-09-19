#include <bits/stdc++.h>

// �־��� ����� IPv6 �ּҸ� ������ ������ IPv6 �ּҷ� ��ȯ��Ű�� ����
// 0���θ� �̷���� �׷��� �ִ� ��� �� �� �̻� ���ӵ� �׷��� ��� "::"�� �ٲ� �� ����

// �� �׷��� �� �ڸ����� �ƴ� ���, �� �ڸ����� �ǵ��� �տ� 0�� ä������
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

    // �� �׷��� �и��Ͽ� ����
    std::vector<std::string> parts;
    parts.reserve(8);

    std::string cur;
    bool has_double = false;    // "::" ���� ����
    int double_pos = -1;        // "::"�� �߰ߵ� ��ġ
     
    for (int i = 0; i < s.size(); ++i) {
        // �� �׷��� Ȯ�εǸ� �ʿ��� ��� padding�� ä��
        if (s[i] == ':') {
            if (!cur.empty()) {                 
                parts.push_back(pad4(cur));
                cur.clear();
            }
            // "::"�� �߰ߵǸ� ��������� �׷� ������ ��ġ�� ����
            if (i + 1 < s.size() && s[i + 1] == ':') { 
                has_double = true;
                double_pos = (int)parts.size(); 
                i++;                            
            }
        }
        // �׷� �� ������ ���(':'�� �ƴ� ���) �״�� �߰��ϸ�, �ʿ� �� tolower ����
        else {
            char ch = s[i];

            if ('A' <= ch && ch <= 'Z') 
                ch = (char)(ch - 'A' + 'a');
            cur.push_back(ch);
        }
    }

    // ������ �׷� ó��
    if (!cur.empty()) 
        parts.push_back(pad4(cur)); 

    // "::"�� �ִ� ��� ������ �׷��� ������ ����ؼ� "0000"�� ä��
    if (has_double) {
        int missing = 8 - (int)parts.size();     
        parts.insert(parts.begin() + double_pos, missing, std::string("0000"));
    }

    // �� ���� �����ϰ� �׷츶�� ':'�� ����
    for (int i = 0; i < 8; ++i) {
        if (i) 
            std::cout << ':';
        std::cout << parts[i];
    }

    std::cout << '\n';
    return 0;
}