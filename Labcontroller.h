#pragma once

#include "Lab.h"
#include "query.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

class Labcontroller : public Query {
    private:
      std::vector<Lab*> E3_list;
      std::vector<Lab*> E5_list;

      std::vector<Lab*> whole_list;

    public:
        Labcontroller();
        void E3_sync_lab(std::vector<std::string> information);
        
        void E5_sync_lab(std::vector<std::string> information);

        void add_lab(std::string major, std::string lab_name, std::string professor_name);

        void sub_lab();

        void show_lab(Lab* lab);

        void sort_lab(std::vector<Lab*>& input_list);

        void execute_controller();
};