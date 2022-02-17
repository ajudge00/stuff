#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

struct Dictionary{
    string wordEng;
    string wordHun;
    string wordSpa;
};

void fileRead(vector<Dictionary> &v);
void fileWrite();

int main()
{
    setlocale(LC_ALL, "");

    int userChoice=0;
    string userWord;
    vector<Dictionary> v;
    cout<<"Üdvözöl a Super-Szótár 2000(R)! \nMit szeretnél csinálni?"<<endl;        //cringe
    cout<<endl<<"(1) Szókeresés \n(2) Új szó rögzítése"<<endl;
    cin>>userChoice;

    if(userChoice==1){
        fileRead(v);
    }else{
        fileWrite();
    }
    return 0;
}

void fileRead(vector<Dictionary> &v){
    string userWord;
    cout<<"Írd be a keresendõ szót!"<<endl;
    cin>>userWord;

    string temp;
    ifstream fileEng("angol.txt");
    while(!fileEng.eof()){
        Dictionary tmp;
        getline(fileEng,tmp.wordEng);
        v.push_back(tmp);
    }
    fileEng.close();


    ifstream fileHun("magyar.txt");
    while(!fileHun.eof()){
        Dictionary tmp;
        getline(fileHun,tmp.wordHun);
        v.push_back(tmp);
    }
    fileHun.close();


    ifstream fileSpa("spanyol.txt");
    while(!fileSpa.eof()){
        Dictionary tmp;
        getline(fileSpa,tmp.wordSpa);
        v.push_back(tmp);
    }
    fileSpa.close();

    for(int i=0; i<v.size(); i++){
        cout<<v[i].wordHun<<endl;
    }
}

void fileWrite(){

}
