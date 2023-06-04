#include "Debugger.h"
int main(int argc, char** argv)
{
    int pc;
    char ch,f,c;
    dp = 0;
    set_instructions_size();
    string line="";
    cout<<"\n********Welcome To 8085 Microprocessor Emulator******\t\n\n";
    cout<<"Press:\n1 To use Emulator\n2 to Exit\n\n";
    do
    {
        cin>>ch;
        fflush(stdin);
        if(!(ch=='1'||ch=='2' ))
        {
            cout<<"Invalid Input. Try Again !\n";
        }
    }while(!(ch=='1' || ch=='2'));
    if(ch=='2')
    {
        cout<<"\nThank You for using 8085 Emulator!!\n";
        return 0;
    }
    if(ch=='1')//INPUT FROM CONSOLE
    {
        cout<<"Enter starting address:\n";
        remove("previousConsoleCode.txt");
        ofstream code;
        code.open("previousConsoleCode.txt",ios::out);
        fflush(stdin);
        getline(cin,start_address);
        code<<start_address<<endl;
        program_counter = start_address;
        do
        {
            ++number_of_lines;
            cout<<program_counter<<": ";
            getline(cin,line);
            if(!check0(line))
            {
                if(inst_size[line.substr(0,indexOf(line,' '))] == 0)
                {
                    --number_of_lines;
                }
            }
            RAM[program_counter] = line;
            code<<line<<endl;
            pc = hextodec(program_counter);
            if(line.size()==3 || line.size()==4 || line.size()==2)
            {
                pc += inst_size[line];
            }
            else
            {
                pc += inst_size[line.substr(0,indexOf(line,' '))];
            }
            program_counter = dectohex(pc);
        }while(line!="HLT" && line!="EOF");
        ++number_of_lines;
        code.close();
    }
    do
    {
        cout<<"\nDebugger:\n1) ON\n2) OFF\n";
        cin>>f;
        if(f!='1' && f!='2')
        {
            cout<<"\nInvalid Option! Try Again!\n";
        }
    }while(f!='1' && f!='2');
    if(f=='2')
    {
        set_instructions();
        reset_flags();
        reset_registers();
        program_counter = start_address;
        stepORrun(2);
        return 0;
    }
    debugger(int(ch-'0'));
    return 0;
}