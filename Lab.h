#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <deque>
#include <vector>
#include <memory>
#include <map>

class Lab {
    private:
        std::string lab_name;
        std::string professor_name;
        std::string career;
        std::string URL;
        std::string field1;
        std::string field2;
        std::string field3;

        
    public:
        Lab();

        virtual ~Lab();

        Lab(std::string i_lab_name, std::string i_professor_name);

        Lab(std::vector<std::string> input_information);

        std::string get_lab_name();

        std::string get_professor_name();

        std::string get_career();

        std::string get_URL();

        std::string get_field1();

        std::string get_field2();

        std::string get_field3();

        void show_lab_information();

        int score = 0;

        void init_score();

        void calculate_score(const std::map<std::string, int>& w_fields);
};

class E3_ICE: public Lab{
    private:
        std::string major = "E3";

    public:
        E3_ICE(std::vector<std::string> information);
        E3_ICE(std::string lab_name,std::string professor_name);

        virtual ~E3_ICE() {};

        std::string get_major();
};

class E5_ROBOT: public Lab{
    private:
        std::string major = "E5";

    public:
        E5_ROBOT(std::vector<std::string> information);
        E5_ROBOT(std::string lab_name,std::string professor_name);

        virtual ~E5_ROBOT() {};

        std::string get_major();
};