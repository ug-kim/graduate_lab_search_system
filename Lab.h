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
};

class E3_ICE: public Lab{
    private:
        std::string major = "E3";
    public:
        E3_ICE(std::vector<std::string> information);
        std::string get_major();
};