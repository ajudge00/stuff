#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
//#include <windows.h>
//#pragma execution_character_set("utf-8")

using namespace std;

struct Dictionary{
    string wordEng;
    string wordHun;
    string wordSpa;
};

void readOnly(vector<Dictionary> &v);
void fileRead(vector<Dictionary> &v);
void fileWrite(vector<Dictionary> &v);

int main()
{
    //SetConsoleOutputCP(1250);

    int userChoice=0;
    string userWord;
    vector<Dictionary> v;
    cout<<"Udvozol a Super-Szotar 2000(R)! \nMit szeretnel csinalni?"<<endl;        //cringe
    cout<<endl<<"(1) Szokereses \n(2) Uj szo rogzitese"<<endl;
    cin>>userChoice;

    readOnly(v);

    system("cls");
    if(userChoice==1){
        fileRead(v);
    }else{
        fileWrite(v);
    }
    return 0;
}

void readOnly(vector<Dictionary> &v){
    ifstream dict("dict.txt");
        while(!dict.eof()){
            Dictionary tmp;
            dict>>tmp.wordHun;
            dict>>tmp.wordEng;
            dict>>tmp.wordSpa;
            v.push_back(tmp);
        }
    dict.close();
}

void fileRead(vector<Dictionary> &v){
    string userWord;
    cout<<"Ird be a keresendo szot!"<<endl;
    cin>>userWord;

    bool wordFound;
    for(int i=0; i<v.size(); i++){
        if(userWord==v[i].wordHun){
            wordFound=1;
            cout<<"A(z) '"<<userWord<<"' szo angolul: "<<v[i].wordEng<<endl;
            cout<<"Es spanyolul: "<<v[i].wordSpa<<endl;
        }else if(userWord==v[i].wordEng){
            wordFound=1;
            cout<<"A(z) '"<<userWord<<"' szo magyarul: "<<v[i].wordHun<<endl;
            cout<<"Es spanyolul: "<<v[i].wordSpa<<endl;
        }else if(userWord==v[i].wordSpa){
            wordFound=1;
            cout<<"A(z) '"<<userWord<<"' szo magyarul: "<<v[i].wordHun<<endl;
            cout<<"Es angolul: "<<v[i].wordEng<<endl;
        }
    }

    char wordAdd;
    if(wordFound!=1){
        cout<<"A szo nem talalhato az adatbazisban."<<endl;
        cin>>wordAdd;
    }
}

void fileWrite(vector<Dictionary> &v){
    char moreWords;
    vector<string> newHun;
    vector<string> newEng;
    vector<string> newSpa;
    do{
        string userWordAdd;
        cout<<"Milyen szot szeretnel hozzaadni? "<<endl;
        cin>>userWordAdd;

        bool votma=0;
        for(int i=0; i<v.size(); i++){
            if(userWordAdd==v[i].wordEng){
                cout<<"Ez a szo mar szerepel az adatbazisban angol nyelven!"<<endl;
                votma=1;
            }else if(userWordAdd==v[i].wordHun){
                cout<<"Ez a szo mar szerepel az adatbazisban magyar nyelven!"<<endl;
                votma=1;
            }else if(userWordAdd==v[i].wordSpa){
                cout<<"Ez a szo mar szerepel az adatbazisban spanyol nyelven!"<<endl;
                votma=1;
            }
        }

        if(votma!=1){
            char addLang;

            cout<<"Milyen nyelvu ez a szo? (a/m/s)"<<endl;
            cin>>addLang;


            if(addLang=='a'){
                string meaningHun;
                cout<<"Es mit jelent ez magyarul? Ha nem tudod, irj *-ot!"<<endl;
                cin>>meaningHun;
                newHun.push_back(meaningHun);

                string meaningSpa;
                cout<<"Es spanyolul? Ha nem tudod, irj *-ot!"<<endl;
                cin>>meaningSpa;
                newSpa.push_back(meaningSpa);
            }
            else if(addLang=='m'){
                string meaningEng;
                cout<<"Es mit jelent ez angolul? Ha nem tudod, irj *-ot!"<<endl;
                cin>>meaningEng;
                newEng.push_back(meaningEng);

                string meaningSpa;
                cout<<"Es spanyolul? Ha nem tudod, irj *-ot!"<<endl;
                cin>>meaningSpa;
                newSpa.push_back(meaningSpa);
            }
            else if (addLang=='s'){
                string meaningEng;
                cout<<"Es mit jelent ez angolul? Ha nem tudod, irj *-ot!"<<endl;
                cin>>meaningEng;
                newEng.push_back(meaningEng);

                string meaningHun;
                cout<<"Es magyarul? Ha nem tudod, irj *-ot!"<<endl;
                cin>>meaningHun;
                newHun.push_back(meaningHun);
            }
        }
        cout<<"Szeretnel meg szot hozzaadni? (y/n)"<<endl;
        cin>>moreWords;
    }while(moreWords=='y');

    ofstream dict2("dict.txt");
    for(int i=0; i<v.size(); i++){
        dict2<<v[i].wordHun<<" "<<v[i].wordEng<<" "<<v[i].wordSpa<<endl;
    }
    for(int i=0; i<newEng.size(); i++){
        dict2<<newHun[i]<<" "<<newEng[i]<<" "<<newSpa[i]<<endl;
    }
    dict2.close();
}
