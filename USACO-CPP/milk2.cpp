   /*
   ID: bliscos1
   TASK: milk2
   LANG: C++
   */
   /* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;



class Interval {
public:
    int inicio;
    int fim;
    Interval(int inicio, int fim) {
        this->inicio = inicio;
        this->fim = fim;
    }
};

class Compare {
public:
    bool operator()(Interval a, Interval b) {
        return a.inicio < b.inicio;
    }
};

int mainMILK() {
    ofstream fout("milk2.out");
    ifstream fin("milk2.in");
    int n;
    fin >> n;
    vector<Interval> v, v2;
    for (int i = 0; i < n; i++) {
        int inicio, fim;
        fin >> inicio >> fim;
        bool find = false;
        Interval* inter = new Interval(inicio, fim);
        v.push_back(*inter);

        //cout << "LOOP" << endl;
        //for (Interval inte : v) {
        //    cout << inte.inicio << " " << inte.fim << endl;
        //}


    }

    sort(v.begin(), v.end(), Compare());

    for (int i = 0; i < n; i++) {
        int inicio, fim;
        inicio = v[i].inicio;
        fim = v[i].fim;
        bool find = false;
        //verify is there is something already in the range
        for (int j = 0; j < v2.size(); j++) {
            if (inicio >= v2[j].inicio && inicio <= v2[j].fim) {
                v2[j].inicio = min(v2[j].inicio, inicio);
                v2[j].fim = max(v2[j].fim, fim);
                find = true;
                //cout << "AT1: " << v[j].inicio << " " << v[j].fim << endl;
            }
            else if (fim >= v2[j].inicio && fim <= v2[j].fim) {
                v2[j].inicio = min(v2[j].inicio, inicio);
                v2[j].fim = max(v2[j].fim, fim);
                find = true;
                //cout << "AT2: " << v[j].inicio << " " << v[j].fim << endl;
            }
        }
        if (!find) {
            Interval* inter = new Interval(inicio, fim);
            v2.push_back(*inter);

        }


        //cout << "LOOP" << endl;
        //for (Interval inte : v) {
        //    cout << inte.inicio << " " << inte.fim << endl;
        //}


    }


    int long_milk = 0, long_idle = 0;
    sort(v2.begin(), v2.end(), Compare());
    for (int i = 0; i < v2.size(); i++) {
        long_milk = max(v2[i].fim - v2[i].inicio, long_milk);
    }
    for (int i = 1; i < v2.size(); i++) {
        long_idle = max(v2[i].inicio - v2[i - 1].fim, long_idle);
        //cout << i << " " << v[i - 1].fim << " ";
    }

    fout << long_milk << " " << long_idle << endl;

    return 0;
}




/*


  > Run 3: Execution error: Your program did not produce an answer
        that was judged as correct. The program stopped at 0.004 seconds;
        it used 1348 KB of memory. At character number 4, your answer says
        '1' while the correct answer says '0'.

        Here are the respective outputs:
        ----- our output ---------
        19_0
        ---- your output ---------
        19_1
        --------------------------

        ------ Data for Run 3 [length=54 bytes] ------
        10
        2 3
        4 5
        6 7
        8 9
        10 11
        12 13
        14 15
        16 17
        18 19
        1 20 
        
*/