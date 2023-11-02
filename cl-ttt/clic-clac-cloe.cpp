#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include "clic-clac-cloe.hpp"
using namespace std;


void TTT::set_p1(string p1_name) {
    p1 = p1_name;
}

string TTT::get_p1() {
    return p1;
}

void TTT::set_p2(string p2_name) {
    p2 = p2_name;
}

string TTT::get_p2() {
    return p2;
}