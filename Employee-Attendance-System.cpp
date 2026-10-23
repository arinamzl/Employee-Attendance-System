#include <iostream>
#include <iomanip>
#include<string>
using namespace std;

const int START_WORK = 8;
const int END_WORK = 17;

class Time {
private:
    int h, m, s;
    bool isPresent;
public:
    Time();
    void inputTime();
    void displayTime();
    void showLateTime();
    void showOvertime() const;
    void Status();
};
Time::Time() {
    h = m = s = 0;
    isPresent = true;
}
void Time::inputTime() {
    do {
        cout << "hour (0-23): ";
        cin >> h;

        cout << "minute (0-59): ";
        cin >> m;

        cout << "second (0-59): ";
        cin >> s;

        if (h < 0 || h > 23 ||
            m < 0 || m > 59 ||
            s < 0 || s > 59) {
            cout << "Invalid time! Please enter again.\n";
        }

    } while (h < 0 || h > 23 ||
        m < 0 || m > 59 ||
        s < 0 || s > 59);
}

void Time::displayTime() {
    cout << setw(2) << h << ":" << setw(2) << m << ":" << setw(2) << s;
}
void Time::showLateTime() {
    if (h == 0 && m == 0 && s == 0) {
        cout << "--:--:--";
        return;
    }

    int totalSeconds = h * 3600 + m * 60 + s;
    int startSeconds = START_WORK * 3600;

    if (totalSeconds > startSeconds) {
        int late = totalSeconds - startSeconds;

        int lh = late / 3600;
        int lm = (late % 3600) / 60;
        int ls = late % 60;

        cout << setw(2) << setfill('0') << lh << ":"
            << setw(2) << lm << ":"
            << setw(2) << ls;

        cout << setfill(' ');
    }
    else {
        cout << "00:00:00";
    }
}
void Time::showOvertime() const{
    if (h == 0 && m == 0 && s == 0) {
        cout << "--:--:--";
        return;
    }

    int totalSeconds = h * 3600 + m * 60 + s;
    int endSeconds = END_WORK * 3600;

    if (totalSeconds > endSeconds) {
        int overtime = totalSeconds - endSeconds;

        int oh = overtime / 3600;
        int om = (overtime % 3600) / 60;
        int os = overtime % 60;

        cout << "includes ( ";
        cout << setw(2) << setfill('0') << oh << ":"
            << setw(2) << om << ":"
            << setw(2) << os;
        cout << " ) extra pay";
        cout << setfill(' ');
    }
    else {
        cout << "00:00:00 no extra pay";
    }
}

void Time::Status() {
    if (h == 0 && m == 0 && s == 0) {
        isPresent = false;
    }
    else {
        isPresent = true;
    }
    if (!isPresent) {
        cout << "Absent";
    }
    else {
        cout << "present";
    }
}


int main()
{
    const int users = 10;
    const int days = 31;
    string names[users];
    Time Enter[users][days];
    Time Exit[users][days];
    for (int i = 0; i < users; i++) {
        cout << "enter first and last name of employee" << i + 1 << ": ";
        getline(cin >> ws, names[i]);
        cout << "entering data for " << names[i] << "\n";

        for (int j = 0; j < days; j++) {
            cout << "Day " << j + 1 << " entering time:\n";
            Enter[i][j].inputTime();

            cout << "day " << j + 1 << "exit time:\n";
            Exit[i][j].inputTime();
            cout << endl;

        }

    }
    cout << "\nTHE MONTHLY REPORT";
    for (int i = 0; i < users; i++) {
        cout << "\nmonthly report for employee " << names[i] << "\n";
        cout << "Day    \tenter     \texit      \tlate      \tovertime      \t\t\tstatus\n";
        for (int j = 0; j < days; j++) {
            cout << j + 1 << "\t";
            Enter[i][j].displayTime();   cout << "\t";
            Exit[i][j].displayTime();   cout << "\t";
            Enter[i][j].showLateTime();   cout << "\t";
            Exit[i][j].showOvertime();   cout << "\t";
            cout << "\t";
            Enter[i][j].Status();
            cout << endl;
        }

    }
    cin.ignore();
    cin.get();
    return 0;
}