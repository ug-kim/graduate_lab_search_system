#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <deque>
#include <vector>
#include <memory>

class Lab{
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
        Lab(std::string i_lab_name, std::string i_professor_name);

        Lab(std::vector<std::string> input_information);

        std::string get_lab_name();

        std::string get_professor_name();

        std::string get_career();

        std::string get_URL();

        std::string get_field1();

        std::string get_field2();

        std::string get_field3();

        int score = 0;

        void calculate_score();
};

class E3_ICE: public Lab{
    private:
        std::string major = "E3";

    public:
        E3_ICE(std::vector<std::string> information);
        std::string get_major();
};

class E5_ICE: public Lab{
    private:
        std::string major = "E5";

    public:
        E5_ICE(std::vector<std::string> information);
        std::string get_major();
};