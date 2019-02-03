#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>


#include <unistd.h>


using namespace std;

string query(string url) {


    FILE *f = popen(("curl -s -k \"" + url + "\"").c_str(), "r");

    if (f == NULL) {
        perror("error!");
    }
    char buf[1024];
    string res;
    while (!feof(f)) {
        if (fgets(buf, 1024, f) == NULL) break;
        res += (string)(buf);
    }

#ifdef _MSC_VER
    _pclose(f);
#else
    pclose(f);
#endif

    return res;
}
void randam_8(string &empty_str){
    srand(time(NULL));
    for(int i=0;i<8;i++){
        empty_str.push_back((rand() % 4) + 'A');
    }
}

int main() {
    string token  = "gxZ767dYSF9Kjzh5wATc4hJ2t49hpRdy";
    for(int ll = 0; ll < 10; ll++){
    string str = "";
    int max_score = 0;
    int score;
    int count = 0;
/*
    while(count < 6){
        string empty_string="";
        randam_8(empty_string);
        
        string url    = "https://runner.team-lab.com/q?token=" + token + "&str=" + empty_string;
        string result = query(url);
        //cout << result << ":";
        score = stoi(result);
        if(score > 120 - count * 12) {
            cout << empty_string << " ";
            cout << result << ":";
            str += empty_string; 
            count++; 
            cout << "USED" << endl;
        }
        sleep(1);
    }
*/
    {
    /*
    srand(time(NULL));
    str.push_back((rand() % 4)+ 'A');
    str.push_back((rand() % 4)+ 'A');
    */
    str = "CCCADDCADBACACCBADBCBCCBBBABAABDBDDDAADDDBCCDDACDB";
    cout << str << " ";
    string url    = "https://runner.team-lab.com/q?token=" + token + "&str=" + str;
    string result = query(url);
    cout << result << endl;
    score = stoi(result);
    max_score = score;
    sleep(1);
    }
    // str = "CCCADDCADBACACCBADBCBCCBBCCDDDABDAADABDDBDAACDADDD";
    // max_score = 2000;
    
    int counting = 0;
    for (int itr = 0; itr < 280; itr++) {

        char tem[12];
        int idx[12];
        srand(time(NULL));
        int change_num = rand() % 11 + 1;
        if(itr > 20) change_num = rand() % 8 + 1;
        if(itr > 30) change_num = rand() % 6 + 1;
        if(itr > 40) change_num = rand() % 5 + 1;
        if(itr > 60) change_num = rand() % 4 + 1;
        if(itr > 90) change_num = rand() % 3 + 1;
        if(itr > 130) change_num = rand() % 2 + 1;
        if(itr > 200) change_num = 1;
        srand(time(NULL));
        for(int i=0;i<change_num;i++) idx[i] = (rand() % 50);
        srand(time(NULL));
        for(int i=0;i<change_num;i++) tem[i] = (rand() % 4) + 'A';
        srand(time(NULL));
        for(int i=0;i<change_num;i++){
            while(str[idx[i]] == tem[i]) tem[i] = (rand() % 4)+ 'A';
            char st = str[idx[i]];
            str[idx[i]] = tem[i];
            tem[i] = st;
        }
        cout << str << " ";
        string url    = "https://runner.team-lab.com/q?token=" + token + "&str=" + str;
        string result = query(url);
        cout << result;
    
        score = stoi(result);
        if(score > max_score){ 
            max_score = score; 
            cout << ": new score!" << endl;
            counting++;
        }else{        
            for(int i=0;i<change_num;i++) swap(str[idx[i]], tem[i]);
            cout << endl;
            counting = 0;
        }
        if(counting > 50) break;
        //for(int i=0;i<change_num;i++) str[idx[i]]= tem[i];
        sleep(1);
        if(itr > 200 && max_score < 1200) break;
    }
    cout << "Result:" << endl;
    cout << str << endl;
    cout << max_score << endl;
    }
    return 0;
}
