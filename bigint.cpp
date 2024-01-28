#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#define MAX_DIGIT 6
#define MAX_DIGIT_NUMBER 1000000

using namespace std;

class bigint
{
private:
    vector<int> arr;
    bool positive = true;
    int length;

public:
    // Constructor
    bigint(){ clear(); }
    bigint(const char *str) { read((string)str); }
    bigint(const string &str) { read(str); }
    bigint(int ll) { readbyinteger((long long)ll); }
    bigint(long ll) { readbyinteger((long long)ll); }
    bigint(long long ll) { readbyinteger(ll); }
    bigint(float fl) { readbyinteger((long long)fl); }
    bigint(double db) { readbyinteger((long long)db); }

    // Function
private:
    void clear(){
        this->positive = true;
        arr.clear();
        arr.shrink_to_fit();
        arr.push_back(0);
    }

    void readbyinteger(long long ll)
    {
        if (ll < 0)
        {
            this->positive = false;
            ll *= -1;
        }
        else if (!ll)
        {
            clear();
            return;
        }
        while (ll)
        {
            this->arr.push_back(ll % MAX_DIGIT_NUMBER);
            ll /= MAX_DIGIT_NUMBER;
        }
    }

public:
    void read(const string &str)
    {
        char front = str.front();
        int index;
        string dostr;

        if (!((front >= '0' && front <= '9') || front == '+' || front == '-'))
            return;

        if (front == '-')
            this->positive = false;

        if (front >= '0' && front <= '9')
            dostr.push_back(front);

        for (int i = 1; i < str.length(); i++)
            if (str[i] >= '0' && str[i] <= '9')
                dostr.push_back(str[i]);
            else
                break;

        if (dostr.length() == 0)
            clear();
        
        index = dostr.length() - 1;

        while (true)
        {
            if (index >= (MAX_DIGIT - 1))
            {
                this->arr.push_back(stoi(dostr.substr(index - (MAX_DIGIT - 1), MAX_DIGIT)));
                index -= MAX_DIGIT;
                continue;
            }
            else if (index >= 0)
            {
                this->arr.push_back(stoi(dostr.substr(0, index + 1)));
                break;
            }
            break;
        }
    }

    void print()
    {
        cout << *this;
    }

    int getdigit(){
        int result = (this->arr.size() - 1) * 6;

    }

    int compare(const bigint &cp1)
    {
        if ((this->positive) ^ (cp1.positive))
        {
            /* code */
        }
    }

    // Operator
    void operator=(long long ll)
    {
        if (ll < 0)
        {
            this->positive = false;
            ll *= -1;
        }
        this->arr.clear();
        while (ll)
        {
            this->arr.push_back(ll % MAX_DIGIT_NUMBER);
            ll /= MAX_DIGIT_NUMBER;
        }
    }

    bool operator>(const bigint &bi)
    {

    }

    bool operator<(const bigint &bi)
    {
    }

    friend istream &operator>>(istream &stream, bigint &bi)
    {
        string s;
        stream >> s;
        bi.read(s);
        return stream;
    }

    friend ostream &operator<<(ostream &stream, const bigint &bi)
    {
        if (!bi.positive)
            stream << '-';
        int i = bi.arr.size() - 1;
        for (; i >= 0; i--)
        {
            if (bi.arr[i] || i == 0)
            {
                stream << bi.arr[i--];
                break;
            }
        }
        for (; i >= 0; i--)
            stream << setw(MAX_DIGIT) << setfill('0') << bi.arr[i];

        return stream;
    }

    // Destructor
    ~bigint()
    {
        arr.clear();
        arr.shrink_to_fit();
    }
};

int main()
{
    // string str = "+1";
    // cout << stoi(str) << endl;
    bigint a = -20000000000;
    bigint b = "-s20000000000";
    bigint c = 1.3;
    bigint d = "0";
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
    return 0;
}