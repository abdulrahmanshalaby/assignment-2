#include <iostream>
#include<fstream>
#include<vector>
#include<String>
using namespace std;
class Player{
    string name;
    int year_of_birth;
    int height;
    int int_goals;
    string nationality;
public:
     void set_name(string n){
         name=n;
     }
    void set_yearofbirth(int n){
        year_of_birth=n;
    }
    void set_intgoals(int n){
         int_goals-n;
     }
    void set_height(int n){
        height=n;
    }
    void set_nationality(string n){
        nationality=n;
    }
  string get_name(){
         return name;
     }
    int get_yearofbirth(){
        return year_of_birth;
    }
    int get_intgoals(){
        return int_goals;
    }
    int get_height(){
        return height;
    }
    string get_nationality(){
        return nationality;
    }
};
class NationalTeam{
Player players[18];
bool active[18]={false};

};
int main() {

}
