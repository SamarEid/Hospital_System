#include <bits/stdc++.h>
using namespace std;

int freq[21];
int main() {
    bool open = true;
    vector<deque<string>> de(21);
    while(open){
        int specialization , status;
        string name;
        cout << "Enter your choice: \n    1) Add new patient \n    "
                "2) Print all patients \n    3) Get next patient \n    "
                "4) Exit\n";
        int choice ;
        cin >> choice;
        if(choice == 1){
            cout << "Enter specialization(1-->20), name, status(1 urgent, 0 regular): ";
            cin >> specialization >> name >> status;
            if (freq[specialization] == 5){
                cout << "Sorry we can't add more patients for this specialization\n";
            }
            else{
                freq[specialization]++;
                if (status == 1){
                    string z = name+" urgent";
                    de[specialization].push_front(z);
                }
                else if (status == 0){
                    string z = name+" regular";
                    de[specialization].push_back(z);
                }
                else {
                    cout << "Invalid Input!!" << endl;
                }
            }
        }
        else if (choice == 2){
            for (int i = 1; i < 21; i++){
                if(freq[i] > 0){
                    cout << "There are " << de[i].size() << " patients in specialization " << i << endl;
                    for (int j = 0; j < de[i].size(); j++)
                        cout << de[i][j] << endl;
                }
            }
            cout << endl;
        }
        else if (choice == 3){
            cout << "Enter a specialization:" ;
            int spec;
            cin >> spec;
            if(freq[spec] == 0)
                cout << "No patients at the moment. Have rest, Dr\n" << endl;
            else{
                string x = de[spec].front();
                int y = x.find(' ');
                string str = x.substr(0,y);
                cout << str << " please go with the Dr\n" << endl;
                de[spec].pop_front();
                freq[spec]--;
            }
        }
        else if (choice == 4)
            open = false;
    }

    return 0;
}
