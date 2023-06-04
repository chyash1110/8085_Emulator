#include<bits/stdc++.h>
#include<fstream>
#include<iomanip>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<vector>
#include<functional>
#include<iostream>
#include<sstream>
#include<string>
#include<limits.h>
using namespace std;

int number_of_lines=0,memregflag=0,pc,line_number=1, break_point=INT_MAX,dp,sp=1000;
string program_counter,start_address;
vector<string> memoryLocationsUsed;
map<string,string> RAM;
map<char,int> registers;
map<string,int> commands;
map<char,int> flag;
map<string,int> memory;
map<string,int> inst_size;
