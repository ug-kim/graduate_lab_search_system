#include "Lab.h"
#include "Labcontroller.h"
#include "query.h"
#include <iostream>

int main(){
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;


    ifstream file;

    Labcontroller Labcontrol;
    
    file.open("/Users/ChoiDaeGun/Desktop/robotics_lab_db_final.csv");
    if(file.is_open()){
        while(!file.eof()){
        std::string content;
        std::vector<std::string> input_information;
        for(int i = 0; i < 7; i++){
            if(i == 6){
                std::getline(file, content, '\n');
                input_information.push_back(content);
            }
            else{
                std::getline(file, content, ',');
                input_information.push_back(content);
            }

        }
        Labcontrol.sync_lab(input_information);
        }
    }
  
    Query query;
    query.init_question();

    query.print();

}