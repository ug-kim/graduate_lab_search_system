#pragma once

#include "Lab.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

class Labcontroller{
    private:
      std::vector<E3_ICE*> E3_list;
      std::vector<E5_ROBOT*> E5_list;
    public:
        Labcontroller();
        void E3_sync_lab(std::vector<std::string> information);
        
        void E5_sync_lab(std::vector<std::string> information);

        void add_lab(std::string major, std::string lab_name, std::string professor_name);

        void sub_lab();

        int get_size();

        void show_lab(Lab* lab);
};