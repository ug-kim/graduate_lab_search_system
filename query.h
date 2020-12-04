#ifndef QUERY_H
#define QUERY_H

#include <string>
#include <vector>
#include <algorithm>
#include <map>


////////////////////////////////////////////////////////////////
// Akinator is for no major (case 2)
////////////////////////////////////////////////////////////////

class Akinator {
public:
    std::string question;
    std::vector<std::string> yes_list;
    std::vector<std::string> no_list;

    Akinator(std::string q, std::vector<std::string> y, std::vector<std::string> n);
};

////////////////////////////////////////////////////////////////////////////////////////
// Fields is mini db for ice, robotics fields and their unions (ice + robotics)
////////////////////////////////////////////////////////////////////////////////////////

class Fields {
public:
    std::vector<std::string> ice_fields = { "vr", "hci", "computer architecture", "electronics", "autonomous driving", "operating system", "embedded system", "hardware", "cloud", "ai", "biomedical", "machine learning", "network", "security", "cyber-physical", "image processing", "mobile", "deep learning", "flexible devices", "circuit", "edge computing" };
    std::vector<std::string> robot_fields = { "image processing", "autonomous driving", "embedded system", "vr", "machine learning", "control", "ar", "mechanics", "electronics", "biomedical" };
    std::vector<std::string> unions = { "vr", "machine learning", "network", "security", "control", "ar", "hci", "computer architecture", "cyber-physical", "electronics", "autonomous driving", "operating system", "image processing", "mobile", "deep learning", "embedded system", "mechanics", "flexible devices", "circuit", "hardware", "cloud", "ai", "edge computing", "biomedical" };

};

////////////////////////////////////////////////////////////////////////////////////////
// Query is for initial query flow
////////////////////////////////////////////////////////////////////////////////////////

class Query : public Fields {
public:
    // top 3 results
    std::vector<std::string> fields;
private:
    // counting fields at case 2
    std::map<std::string, int> union_counts;

    // "none" - no major, "E3" and "E5"
    std::string major;

    std::vector<Akinator> no_major_questions;

public:
    Query();
    void init_question();
    void print();
private:
    // Case 1 - has major
    void have_major_query();
    void select_ice();
    void select_robotics();

    // Case 2 - no major
    void init_no_major_querys();
    void count_fields(std::vector<std::string> candidates);
    void no_major_query();
    void update_fields();
};

#endif