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

    public:
        Labcontroller();

        virtual ~Labcontroller(); //query destructor virtual 필요

        void readfile(std::string major);

        void E3_sync_lab(std::vector<std::string> information);
        
        void E5_sync_lab(std::vector<std::string> information);

        void add_lab(std::string major, std::string lab_name, std::string professor_name);

        void sub_lab();

        void delete_lab(std::vector<Lab*> list, std::string answer);

        void show_lab(Lab* lab);

        void sort_lab(std::vector<Lab*>& input_list); //goto start 쓰려면 sort할때 다른 컨테이너를 만들어야함.

        void execute_controller();

        void start_query();

        void restart_query();

        void init_lab_score(std::vector<Lab*> list);

};