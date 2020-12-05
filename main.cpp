#include "Lab.h"
#include "Labcontroller.h"
#include "query.h"
#include <iostream>
#include <fstream>
#include <sstream>

int main(){
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;
    
    Start:

    std::ifstream file;

    Labcontroller Labcontrol;
    
    file.open("robotics_lab_db_final.csv");
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
            // Labcontrol.E3_sync_lab(input_information);
            Labcontrol.E5_sync_lab(input_information); //E3, E5 구분해서 넣기
        }
    }
  

    Labcontrol.execute_controller();
    std::string answer;
    std::cout << "Do you want to play again?\n 1.Yes \t 2.No" << std::endl;
    std::cin >> answer;
    if(answer == "1"){
        Labcontrol.~Labcontroller();
        goto Start;
    }
    else{
        return 0;
    }



    // Query query;
    // query.init_question();

    // query.print();

}
