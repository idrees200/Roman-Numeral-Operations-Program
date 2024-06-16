#include <iostream>
#include <string>
using namespace std;

class romanumbers {
private:
    int numbers;
public:
    romanumbers(string s) {
        numbers = 0;
        int k = 0;
        while (s[k]) {
            int v = this->value(s[k]);
            if (s[k + 1] == NULL) {
                numbers += v;
                break;
            }
            else {
                int k2 = this->value(s[k + 1]);
                if (v >= k2) {
                    numbers += v;
                }
                else {
                    numbers -= v;
                }
            }
            k++;
        }
    }
    romanumbers operator +(romanumbers k) {
        romanumbers a("0");
        a.numbers = this->numbers + k.numbers;
        return a;
    }
    romanumbers operator -(romanumbers k) {
        romanumbers a("0");
        a.numbers = this->numbers - k.numbers;
        return a;
    }
    romanumbers operator /(romanumbers k) {
        romanumbers a("0");
        a.numbers = this->numbers / k.numbers;
        return a;
    }
    romanumbers operator *(romanumbers k) {
        romanumbers a("0");
        a.numbers = this->numbers * k.numbers;
        return a;
    }
    romanumbers operator +(int k) {
        romanumbers a("0");
        a.numbers = this->numbers + k;
        return a;
    }
    romanumbers operator -(int k) {
        romanumbers a("0");
        a.numbers = this->numbers - k;
        return a;
    }
    romanumbers operator /(int k) {
        romanumbers a("0");
        a.numbers = this->numbers / k;
        return a;
    }
    romanumbers operator *(int k) {
        romanumbers a("0");
        a.numbers = this->numbers * k;
        return a;
    }
    int value(char k) {
        switch (k) {
        case 'I': return 1; break;
        case 'V': return 5; break;
        case 'X': return 10; break;
        case 'L': return 50; break;
        case 'C': return 100; break;
        case 'D': return 500; break;
        case 'M': return 1000; break;
        default: return -1; break;
        }
    }
    string show(int val) {
        string s;
        int mod = val % 10;
        if (mod == 10) {
            s = s + "X";
        }
        if (val >= 10 && val <= 50) {
            if (val / 10 != 0) {
                int k = val / 10;
                for (int l = 0; l < k; l++) {
                    s = s + "X";
                }
            }
        }
        if (val >= 5 && val <= 10) {
            s = s + "V";
        }
        val = val / 10;
        if (mod == 5) {
            s = s + "V";
        }
        else if (mod == 6) {
            s = s + "VI";
        }
        else if (mod == 9) {
            s = s + "IX";
        }
        else if (mod == 4) {
            s = s + "IV";
        }
        else if (mod > 5) {
            val = mod - 5;
        }
        else {
            val = mod;
        }
        if (val / 10 == 0) {
            if (val >= 1 && val <= 5) {
                for (int l = 0; l < val; l++) {
                    s = s + "I";
                }
            }
        }
        return s;
    }
    int getnumber() {
        return numbers;
    }
};

ostream& operator <<(ostream& out, romanumbers& i) {
    cout << "VALUE : ";
    out << i.getnumber() << endl;
    int n = i.getnumber();
    cout << "ROMAN : " << i.show(n) << endl;
    return out;
}

bool operator == (const romanumbers& i, const romanumbers& j) {
    return (i.getnumber() == j.getnumber());
}

bool operator != (const romanumbers& i, const romanumbers& j) {
    return (i.getnumber() != j.getnumber());
}

bool operator < (const romanumbers& i, const romanumbers& j) {
    return (i.getnumber() < j.getnumber());
}

bool operator > (const romanumbers& i, const romanumbers& j) {
    return (i.getnumber() > j.getnumber());
}

int main() {
    string s, s2;
    cout << "ENTER ROMAN NUMBER 1 (FORMAT: XII):" << endl;
    cin >> s;
    cout << "ENTER ROMAN NUMBER 2 (FORMAT: XII):" << endl;
    cin >> s2;

    romanumbers a(s), b(s2);

    cout << "FIRST ROMAN NO :" << endl;
    cout << a << endl;
    cout << "______________________________________" << endl;
    cout << "SECOND ROMAN NO :" << endl;
    cout << b << endl;
    cout << "______________________________________" << endl;

    romanumbers sum = a + b;
    cout << "SUM : " << sum << endl;
    cout << "______________________________________" << endl;

    romanumbers diff = a - b;
    cout << "DIFFERENCE : " << diff << endl;
    cout << "______________________________________" << endl;

    romanumbers div = a / b;
    cout << "DIV : " << div << endl;
    cout << "______________________________________" << endl;

    romanumbers prod = a * b;
    cout << "PRODUCT : " << prod << endl;
    cout << "______________________________________" << endl;

    if (a > b) {
        cout << "Roman Number 1 is greater." << endl;
    }
    else {
        cout << "Roman Number 2 is greater." << endl;
    }
    cout << "______________________________________" << endl;

    if (a == b) {
        cout << "Both Roman Numbers are equal." << endl;
    }
    else {
        cout << "Roman Numbers are not equal." << endl;
    }
    cout << "______________________________________" << endl;

    a++;
    cout << "POST INCREMENT ROMAN NUMBER 1 : " << endl;
    cout << a << endl;
    cout << "______________________________________" << endl;

    b++;
    cout << "POST INCREMENT ROMAN NUMBER 2 : " << endl;
    cout << b << endl;
    cout << "______________________________________" << endl;

    b--;
    cout << "POST DECREMENT ROMAN NUMBER 2 : " << endl;
    cout << b << endl;
    cout << "______________________________________" << endl;

    a--;
    cout << "POST DECREMENT ROMAN NUMBER 1 : " << endl;
    cout << a << endl;
    cout << "______________________________________" << endl;

    ++a;
    cout << "PRE INCREMENT ROMAN NUMBER 1 : " << endl;
    cout << a << endl;
    cout << "______________________________________" << endl;

    ++b;
    cout << "PRE INCREMENT ROMAN NUMBER 2 : " << endl;
    cout << b << endl;
    cout << "______________________________________" << endl;

    --b;
    cout << "PRE DECREMENT ROMAN NUMBER 2 : " << endl;
    cout << b << endl;
    cout << "______________________________________" << endl;

    --a;
    cout << "PRE DECREMENT ROMAN NUMBER 1 : " << endl;
    cout << a << endl;
    cout << "______________________________________" << endl;

    return 0;
}
