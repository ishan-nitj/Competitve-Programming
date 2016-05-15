#include<iostream>
#include<fstream>
using namespace std;
int main(){
int a,b;
ofstream outf;
outf.open("C:\\Users\\user\\Desktop\\Majors\\oops\\new.txt");
////outf.seekp(2,ios::beg);
//outf<<'m';outf<<'p';
//outf.seekp(2,ios::beg);
//outf<<'s';
//outf.seekp(-1,ios::end);
//outf<<'q';
//
////outf.seekp(1,ios::cur);
////outf<<'m';
////cout<<outf.tellp();
outf.close();
}
