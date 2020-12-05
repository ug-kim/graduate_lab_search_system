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
    
    Labcontroller Labcontrol;
    
    Labcontrol.readfile("E3", Labcontrol);
    Labcontrol.readfile("E5", Labcontrol);  

    while (true) {
        Labcontrol.start_query();
        Labcontrol.execute_controller();
        std::cout << "FINISH" << std::endl;
        std::string answer;
        std::cout << "Do you want to play again?\n 1.Yes \t 2.No" << std::endl;
        std::cin >> answer;
        if (answer == "2") {
            break;
        }
    }

    return 0;

    // Query query;
    // query.init_question();

    // query.print();

}
