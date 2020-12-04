#include "Lab.h"

Lab::Lab() {}
Lab::Lab(std::string i_lab_name, std::string i_professor_name)
{
    lab_name = i_lab_name;
    professor_name = i_professor_name;
}

Lab::Lab(std::vector<std::string> input_information)
{
    lab_name = input_information[0];
    professor_name = input_information[1];
    career = input_information[2];
    URL = input_information[3];
    field1 = input_information[4];
    field2 = input_information[5];
    field3 = input_information[6];
}

std::string Lab::get_lab_name()
{
    return lab_name;
}

std::string Lab::get_professor_name()
{
    return professor_name;
}

E3_ICE::E3_ICE(std::vector<std::string> information) : Lab(information) {}
std::string E3_ICE::get_major()
{
    return major;
}