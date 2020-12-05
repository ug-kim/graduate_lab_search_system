#include <algorithm>

#include "Labcontroller.h"
#include "Lab.h"

Labcontroller::Labcontroller(){}
Labcontroller::~Labcontroller(){
    for(auto& iter : E3_list){
        delete iter;
    }

    E3_list.clear();

    for(auto& iter : E5_list){
        delete iter;
    }

    E5_list.clear();
    
}
void Labcontroller::E3_sync_lab(std::vector<std::string> information)
{
    E3_ICE *ptr = new E3_ICE(information); // Lab* ptr = new E3_ICE(information)
    E3_list.push_back(ptr);
}

void Labcontroller::E5_sync_lab(std::vector<std::string> information)
{
    Lab *ptr = new Lab(information); // Lab* ptr = new E5_ROBOT(information)
    E5_list.push_back(ptr);
}

void Labcontroller::add_lab(std::string major, std::string lab_name, std::string professor_name)
{
    if (major == "E3"){
        Lab *newone = new E3_ICE(lab_name, professor_name);
        E3_list.push_back(newone);
    }

    if (major == "E5"){
        Lab *newone = new E5_ROBOT(lab_name, professor_name);
        E5_list.push_back(newone);
    }
}

void Labcontroller::sub_lab()
{
    std::cout << "Which major of Lab do you want to delete?" << std::endl;
    std::string answer1, answer2;
    std::getline(std::cin, answer1);
    std::cout << "What is the name of Lab?" << std::endl;
    std::getline(std::cin, answer2);

    if (answer1 == "E3");
    {
        delete_lab(E3_list, answer2);
    }

    if (answer1 == "E5"){
        delete_lab(E5_list, answer2);
    }
} 

void Labcontroller::delete_lab(std::vector<Lab*> list, std::string answer){
    for (auto iter = list.begin(); iter != list.end(); iter++)
    {
        if ((*iter)->get_professor_name() == answer)
        {
            delete *iter;
            list.erase(iter);
            std::cout << list.size() << std::endl;
            std::cout << "complete" << std::endl;
            break;
        }
        else{
            continue;
        }
    }
}

void Labcontroller::show_lab(Lab* lab)
{
    lab->show_lab_information();    
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

    for (auto v = E5_list.begin(); v != v+3; v++) {
        show_lab(*v);
    }


}
