#include "Labcontroller.h"
#include "Lab.h"

Labcontroller::Labcontroller(){}
void Labcontroller::sync_lab(std::vector<std::string> information)
{
    E3_ICE *ptr = new E3_ICE(information);
    list.push_back(ptr);
}
void Labcontroller::add_lab(std::string major, std::string lab_name, std::string professor_name)
{
    Lab *newone = new Lab(lab_name, professor_name);
    list.push_back(newone);
}

void Labcontroller::sub_lab()
{
    std::cout << "Which Lab do you want to delete?" << std::endl;
    std::string answer;
    std::getline(std::cin, answer);

    for (auto iter = list.begin(); iter != list.end(); iter++)
    {
        if ((*iter)->get_professor_name() == answer)
        {
            delete *iter;
            list.erase(iter);
            std::cout << this->get_size() << std::endl;
            std::cout << "complete" << std::endl;
            break;
        }
    }
}

int Labcontroller::get_size()
{
    return list.size();
}

void Labcontroller::show_lab()
{
    std::cout << "Which Lab do you want to show?" << std::endl;
    std::string answer;
    std::getline(std::cin, answer);

    for (auto iter = list.begin(); iter != list.end(); iter++)
    {
        if ((*iter)->get_professor_name() == answer)
        {
            std::cout << (*iter)->get_lab_name();
            break;
        }
    }
}
