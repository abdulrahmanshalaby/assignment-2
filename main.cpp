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
// parameterized constructor
    Player(string name="",int yearofbirth=0,int h=0,int ig=0,string nationality=""){
        this->name=name;
        year_of_birth=yearofbirth;
        height=h;
        int_goals=ig;
        this->nationality=nationality;
    }
    //setters
     void set_name(string n){
         name=n;
     }
    void set_yearofbirth(int n){
        year_of_birth=n;
    }
    void set_intgoals(int n){
         int_goals=n;
     }
    void set_height(int n){
        height=n;
    }
    void set_nationality(string n){
        nationality=n;
    }
    //getters
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

    int i=0;
Player players[18];
bool active[18]={false};
public:
    string country;
    NationalTeam(string country){
        this->country=country;
    }
    // adds player to players array and activating corresponding index in active array
bool addPlayer(const Player&obj){
        // when array is full returns false 
    if(i>18){
        cout<<"team full"<<endl;
        return false;
    }
    players[i]=obj;
    active[i]=true;
    cout<<"player number "<<i+1<<" added "<<endl;
    i++;
    return true;
}
// removes player(S) by their name by deactivating corresponding index in active array
bool removeplayer(string n){
    bool flag;
    for (int j = 0; j < 18; ++j) {
        if(players[j].get_name()==n){
            active[j]=false;
            flag=true;
        }

    }
    if(flag){
        cout<<"player(S) with name "<<n<<" where removed from team"<<endl;
        return true;}
    else {
        cout<<"No player with that name"<<endl;
        return false;}
}
int getNumOfPlayers(){
    int i=0;
    for (int j = 0; j < 18; ++j) {
        if(active[j])
            i++;
    }
    return i;
}
int AvgHeight(){
    int i=0;
    int k=0;
    for (int j = 0; j < 18; ++j) {
        if (active[j]) {
            i++;
        }
    }
        for (int l = 0; l < 18; ++l) {
            if (i==0)
                return i;
            k=k+(players[l].get_height()/i);
        }


    return k;
}
Player OldestPlayer(){
    int k=0;
    long long oldest=57857824758;
    for (int j = 0; j < 18; ++j) {
        if(active[j]){
        if(players[j].get_yearofbirth()<oldest) {
            oldest = players[j].get_yearofbirth();
            k = j;
        }
        }

    }
    return players[k];
}
Player YoungestPlayer(){
        int k=0;
        int oldest=0;
        for (int j = 0; j < 18; ++j) {
            if(active[j]){
                if(players[j].get_yearofbirth()>oldest) {
                    oldest = players[j].get_yearofbirth();
                    k = j;
                }
            }

        }
        return players[k];
    }
Player HighestIntGoals(){
    int k=0;
    int Hgoals=0;
    for (int j = 0; j < 18; ++j) {
        if(active[j]){
            if(players[j].get_intgoals()>Hgoals) {
                Hgoals = players[j].get_intgoals();
                k = j;
            }
        }

    }
    return players[k];
}
// friend function implemented outside class
 friend ostream& operator <<(ostream&os,NationalTeam& obj);
    // writes analysis report of team in file
    void writeStatistics(ofstream& ofs) {
        ofs << "Team Country: " << country << endl;
        ofs << "Number of players: " << getNumOfPlayers() << endl;
        ofs << "Average height of players: " << AvgHeight() << endl;
        Player oldest = OldestPlayer();
        ofs << "oldest player: " << oldest.get_name() << "           Age: " << (2024 - oldest.get_yearofbirth()) << endl;

        Player youngest = YoungestPlayer();
        ofs << "youngest player: " << youngest.get_name() << "       Age: " << (2024 - youngest.get_yearofbirth()) << endl;

        ofs << "Average number of international goals of players: " << AvgIntGoals() << endl;

        Player highestGoals =HighestIntGoals() ;
        ofs << "Player with the highest international goals: " << highestGoals.get_name() << "      goals: " << highestGoals.get_intgoals()  << endl;
    }
    int AvgIntGoals(){
        int i=0;
        int k=0;
        for (int j = 0; j < 18; ++j) {
            if (active[j]) {
                i++;
            }
        }
        for (int l = 0; l < 18; ++l) {
            if (i==0)
                return i;
            k=k+(players[l].get_intgoals()/i);
        }


        return k;
    }
};

// operator << function overloading
ostream& operator <<(ostream&os,NationalTeam& obj){
    os<<"team country: "<<" "<<obj.country<<endl;
    for (int i = 0; i < 18; ++i) {
        if(obj.active[i]){
            os<<"player "<<i+1<<" "<<"info:"<<endl;
            os<<obj.players[i].get_name()<<endl;
        }

    }
    return os;
}
//global read function returns Player array with info of file
vector<Player> readPlayersFromFile(ifstream& ifs)
{ int numPlayers;

    ifs>>numPlayers;
    ifs.ignore();
    vector<Player>players;
    for (int i = 0; i < numPlayers; ++i) {
        string name, nationality;
        int yearOfBirth, height, internationalGoals;
        getline(ifs, name);
        ifs >> yearOfBirth >> height >> internationalGoals;
        ifs.ignore();
        getline(ifs>>ws, nationality);
        players.push_back(Player(name, yearOfBirth, height, internationalGoals, nationality));
cout<<"players available: "<<players[i].get_name()<<endl;
    }
    return players;
}
int main() {
    int n;
    ifstream read("players.txt");
    vector<Player>players= readPlayersFromFile(read);
    cout<< "enter number of teams you want to create:  "<<" "<<endl;
    cin>>n;
    vector<NationalTeam> nationalteam;
    // vector carries all teams created
    for (int i = 0; i < n; ++i) {
        cout<<"enter team country: "<<" ";
       string m;
       cin>>m;
       NationalTeam f(m);
        nationalteam.push_back(f);

    }

    // printing all entred teams
    cout<<"your teams:  "<<" "<<endl;
    for (int i = 0; i < n; ++i) {
        cout<<nationalteam[i].country<<endl;
    }

    int t;
    cout<<"how many adds/removes you want to do? "<<endl;
    cin>>t;
    for (int i = 0; i < t; ++i) {
        int f;
        int r;
        int d;
       cout<<"enter 1 for add or 2 for remove. "<<endl;
        cin>>r;
        cout<<"choose team number: ";
        cin>>f;
        if(r==1){
            cout<<"choose player number";
            cin>>d;
            nationalteam[f-1].addPlayer(players[d-1]);
        }
        else{
            string name;
            cout<<"enter name of player to remove ";
            cin>>name;
            nationalteam[f-1].removeplayer(name);
        }
    }
    for (int i = 0; i <n ; ++i) {
        cout<<nationalteam[i];
    }
    ofstream write("statistics.txt",ios::app);
    for (int i = 0; i < n; ++i) {
        nationalteam[i].writeStatistics(write);
    }
}









