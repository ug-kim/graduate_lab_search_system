#include "query.h"

#include <iostream>

Akinator::Akinator(std::string q, std::vector<std::string> y, std::vector<std::string> n) {
    question = q;
    yes_list = y;
    no_list = n;
}

Query::Query() {
    // init counts
    for (auto key : unions) {
        union_counts.insert(std::make_pair(key, 0));
    }

    // init_no_major_querys();
    // init_question();
    // print();
}

void Query::init_question() {
    std::cout << "Do you have favorite majors? \n1. yes\t2. No" << std::endl;
    int num = 0;
    try {
        std::cin >> num;
        if (num < 1 || num > 2) {
            throw num;
        }
    }
    catch (int i) {
        std::cout << "Something Wrong" << std::endl;
    }
    
    if (num == 1) {
        have_major_query();
    }
    else if (num == 2) {
        major = "none";
        no_major_query();
    }
}

/////////////////////////////////////////////////////////////////////////
// Case 1 - Has major
/////////////////////////////////////////////////////////////////////////

void Query::have_major_query() {
    int check = 0;
    std::cout << "\nSelect Major\n1. E3 (Information and Communication Engineering)\n2. E5 (Robotics Engineering)" << std::endl;
    
    try {
        std::cin >> check;
        if (check < 1 || check > 2) {
            throw check;
        }
    }
    catch (int i) {
        std::cout << "Something Wrong" << std::endl;
    }

    if (check == 1) {
        major = "E3";
        select_ice();
    }
    else if (check == 2) {
        major = "E5";
        select_robotics();
    }
}

void Query::select_ice() {
    int idx;
    std::cout << "\nChoice List" << std::endl;
    for (int i = 0; i < size(ice_fields); i++) {
        std::cout << (i + 1) << ". " << ice_fields[i] << std::endl;
    }

    std::cout << "\nChoose 3 fields in order of preference" << std::endl;
    for (int i = 0; i < 3; i++) {
        if (i == 0) std::cout << i + 1 << "st preference : ";
        if (i == 1) std::cout << i + 1 << "nd preference : ";
        if (i == 2) std::cout << i + 1 << "rd preference : ";

        // TODO: idx ���� ó��
        std::cin >> idx;
        fields.push_back(ice_fields[idx - 1]);
    }

    update_fields_weights();
}

void Query::select_robotics() {
    int idx;
    std::cout << "\nChoice List" << std::endl;
    for (int i = 0; i < size(robot_fields); i++) {
        std::cout << (i + 1) << ". " << robot_fields[i] << std::endl;
    }

    std::cout << "\nChoose 3 fields in order of preference" << std::endl;
    for (int i = 0; i < 3; i++) {
        if (i == 0) std::cout << i + 1 << "st preference : ";
        if (i == 1) std::cout << i + 1 << "nd preference : ";
        if (i == 2) std::cout << i + 1 << "rd preference : ";

        // TODO :idx ���� ó��
        std::cin >> idx;
        fields.push_back(robot_fields[idx - 1]);
    }

    update_fields_weights();
}

/////////////////////////////////////////////////////////////
// Case 2 - No Major
/////////////////////////////////////////////////////////////

void Query::init_no_major_querys() {
    std::vector<std::string> yes;
    std::vector<std::string> no;

    yes = { "vr", "machine learning", "control", "ar", "electronics", "autonomous driving", "image processing", "deep learning", "ai" };
    no = { "network", "security", "hci", "computer architecture", "cyber-physical", "operating system", "mobile", "embedded system", "mechanics", "flexible devices", "circuit", "hardware", "cloud", "edge computing", "biomedical" };
    static Akinator a("1. Do you like math?\t(1) yes\t(2) no", yes, no);
    no_major_questions.push_back(a);

    yes = { "biomedical" };
    no = { "vr", "machine learning", "network", "security", "control", "ar", "hci", "computer architecture", "cyber-physical", "electronics", "autonomous driving", "operating system", "image processing", "mobile", "deep learning", "embedded system", "mechanics", "flexible devices", "circuit", "hardware", "cloud", "ai", "edge computing" };
    static Akinator a2("2. Are you interested in medical fields?\t(1) yes\t(2) no", yes, no);
    no_major_questions.push_back(a2);

    yes = { "network", "mobile", "cloud" };
    no = { "vr", "machine learning", "security", "control", "ar", "hci", "computer architecture", "cyber-physical", "electronics", "autonomous driving", "operating system", "image processing", "deep learning", "embedded system", "mechanics", "flexible devices", "circuit", "hardware", "ai", "edge computing", "biomedical" };
    static Akinator a3("3. Are you interested in communication (like network)??\t(1) yes\t(2) no", yes, no);
    no_major_questions.push_back(a3);

    yes = { "machine learning", "deep learning", "ai" };
    no = { "vr", "network", "security", "control", "ar", "hci", "computer architecture", "cyber-physical", "electronics", "autonomous driving", "operating system", "image processing", "mobile", "embedded system", "mechanics", "flexible devices", "circuit", "hardware", "cloud", "edge computing", "biomedical" };
    static Akinator a4("4. Would you like to make Alpha-Go?\t(1) yes\t(2) no", yes, no);
    no_major_questions.push_back(a4);

    yes = { "vr", "ar", "hci", "mobile" };
    no = { "machine learning", "network", "security", "control", "computer architecture", "cyber-physical", "electronics", "autonomous driving", "operating system", "image processing", "deep learning", "embedded system", "mechanics", "flexible devices", "circuit", "hardware", "cloud", "ai", "edge computing", "biomedical" };
    static Akinator a5("5. Would you like to make Pocketmon Go?\t(1) yes\t(2) no", yes, no);
    no_major_questions.push_back(a5);

    yes = {"computer architecture", "operating system", "cloud" };
    no = { "vr", "machine learning", "network", "security", "control", "ar", "hci", "cyber-physical", "electronics", "autonomous driving", "image processing", "mobile", "deep learning", "embedded system", "mechanics", "flexible devices", "circuit", "hardware", "ai", "edge computing", "biomedical"};
    static Akinator a6("6. Do you like linux operating system?\t(1) yes\t(2) no", yes, no);
    no_major_questions.push_back(a6);

    yes = { "vr", "machine learning", "network", "security", "control", "ar", "cyber-physical", "electronics", "autonomous driving", "image processing", "deep learning", "mechanics", "circuit", "hardware", "ai" };
    no = { "hci", "computer architecture", "operating system", "mobile", "embedded system", "flexible devices", "cloud", "edge computing", "biomedical"};
    static Akinator a7("7. Are you interested in autuodriving system?\t(1) yes\t(2) no", yes, no);
    no_major_questions.push_back(a7);

}

void Query::count_fields(std::vector<std::string> candidates) {
    int idx;
    int count = 0;
    int value;
    for (auto iter = candidates.begin(); iter != candidates.end(); iter++) {
        union_counts[*iter] += 1;
    }
}

void Query::no_major_query() {
    int num;

    // std::vector<Akinator>::iterator iter;
    for (auto iter = no_major_questions.begin(); iter != no_major_questions.end(); iter++) {
        std::cout << iter->question << std::endl;
        try {
            //TODO : num index
            std::cin >> num;
            if (num == 1) {
                count_fields(iter->yes_list);
            }
            else if (num == 2) {
                count_fields(iter->no_list);
            }
            else {
                // TODO: there are something wrong
                throw num;
            }
        }
        catch (int i) {
            std::cout << "Unavailable number" << std::endl;
        }
    }
    update_fields();
    update_fields_weights();
}

bool cmp(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
    if (a.second == b.second) return a.first > b.first;
    return a.second > b.second;
}

void Query::update_fields() {
    std::vector<std::pair<std::string, int>> vec(union_counts.begin(), union_counts.end());
    sort(vec.begin(), vec.end(), cmp);

    int count = 0;
    for (auto num : vec) {
        if (count == 3) break;
        // std::cout << "key: " << num.first << " value: " << num.second << std::endl;
        fields.push_back(num.first);
        count++;
    }
}

void Query::update_fields_weights() {
    int count = 0;
    for (auto v : fields) {
       if (count == 0 ) {
           // first preference, so weight is 10
           w_fields.insert(std::make_pair(v, 10));
       }
       else if (count == 1) {
           // second preference, so weight is 7
           w_fields.insert(std::make_pair(v, 7));
       }
       else {
           // third preference, so weight is 5
           w_fields.insert(std::make_pair(v, 5));
       }
       count++;
    }
}

void Query::print() {
    std::cout << "------------------------" << std::endl;
    std::cout << "top 3 fields" << std::endl;

    for (auto it = fields.begin(); it != fields.end(); it++) {
        std::cout << *it << std::endl;
    }

    for (auto v : w_fields) {
        std::cout << v.first << " " << v.second << std::endl;
    }
    std::cout << "------------------------" << std::endl;
}

void Query::init_fields() {
    fields.clear();
    w_fields.clear();
}