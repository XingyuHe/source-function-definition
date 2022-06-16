#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    assert(argc <= 3);
    stringstream ss;
    string func_name;
    string src_dir = "./";

    switch (argc)
    {
    case 2:
        func_name = argv[2];
    case 3:
        src_dir = argv[1];
        func_name = argv[2];

    default:
        break;
    }

    string language = "scala";
    string fn_signature = "def ";

    ss << "find " << src_dir << " -name *." << language << "|xargs grep -Hin \'" << fn_signature << func_name << "\' ";
    string command = ss.str();
    system(command.c_str());
    
    cout << command << endl;

    return 0;
}
