#include <iostream>

#include "query.h"

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;

    Query query;
    query.init_question();

    query.print();

}
