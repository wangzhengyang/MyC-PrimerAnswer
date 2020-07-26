#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <fstream>

using namespace std;

void func(const string &in, const string &odd, const string &even)
{
    ifstream infile(in);
    istream_iterator<int> in_iter(infile), eof;
    ofstream oddfile(odd), evenfile(even);
    ostream_iterator<int> out_odd(oddfile, " "), out_even(evenfile, "\n");
    while(in_iter != eof){
        if(*in_iter % 2){
            *out_odd++ = *in_iter++;
        }else{
            *out_even++ = *in_iter++;
        }
    }
}

int main()
{
    func("infile.txt", "oddfile.txt", "evenfile.txt");
    return 0;
}