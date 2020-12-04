#pragma once

#include "Lab.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

class Labcontroller{
    private:
      std::vector<Lab*> list;
    public:
        Labcontroller();
        void sync_lab(std::vector<std::string> information);
        void add_lab(std::string major, std::string lab_name, std::string professor_name);

        void sub_lab();

        int get_size();

        void show_lab();
};