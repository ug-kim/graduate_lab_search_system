#include <algorithm>

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
    Lab *ptr = new Lab(information);
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
    // std::string answer;
    // std::getline(std::cin, answer);

    
}

bool cmp(const Lab* a, const Lab* b) {
    if (a->score == b->score) return a->score > b->score;
    return a->score > b->score;
}

void Labcontroller::sort_lab(std::vector<Lab*>& input_list) {
    sort(input_list.begin(), input_list.end(), cmp);
}

void Labcontroller::execute_controller() {
    std::cout << "Lab controller" << std::endl;
    for (auto v : E5_list) {
        v->calculate_score(w_fields);
    }

    sort_lab(E5_list);

    for (auto v : E5_list) {
        std::cout << "-------------------------" << std::endl;
        std::cout << "name:  " << v->get_lab_name() << std::endl;
        std::cout << v->score << std::endl;
        std::cout << v->get_field1() << v->get_field2() << v->get_field3() << std::endl;
        std::cout << "-------------------------" << std::endl;
    }
}

