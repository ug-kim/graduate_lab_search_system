#include "Labcontroller.h"
#include "Lab.h"

Labcontroller::Labcontroller(){}
void Labcontroller::E3_sync_lab(std::vector<std::string> information)
{
    E3_ICE *ptr = new E3_ICE(information);
    E3_list.push_back(ptr);
}

void Labcontroller::E5_sync_lab(std::vector<std::string> information)
{
    E5_ROBOT *ptr = new E5_ROBOT(information);
    E5_list.push_back(ptr);
}

// void Labcontroller::add_lab(std::string major, std::string lab_name, std::string professor_name)
// {
//     if(major == "E3"){


//     }


//     if(major == "E5")
//     Lab *newone = new Lab(lab_name, professor_name);
//     list.push_back(newone);
// }

// void Labcontroller::sub_lab()
// {
//     std::cout << "Which Lab do you want to delete?" << std::endl;
//     std::string answer;
//     std::getline(std::cin, answer);

//     for (auto iter = list.begin(); iter != list.end(); iter++)
//     {
//         if ((*iter)->get_professor_name() == answer)
//         {
//             delete *iter;
//             list.erase(iter);
//             std::cout << this->get_size() << std::endl;
//             std::cout << "complete" << std::endl;
//             break;
//         }
//     }
// }

void Labcontroller::show_lab(Lab* lab)
{
    lab->show_lab_information();    
}


