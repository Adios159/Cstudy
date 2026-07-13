#include <iostream>
#include <string>
using namespace std;

class Conveter {
    private:
        string srcUnit, destUnit;
    protected:
        double ratio;
        virtual double convert(double src) { return 0.0; }
    public:
        Conveter(string sUnit, string dUnit, double ratio) {
            srcUnit = sUnit;
            destUnit = dUnit;
            this->ratio = ratio;
        }
        void run() {
            cout << srcUnit << " to " << destUnit << endl;
            cout << "input that you want to convert: ";
            double src;
            cin >> src;
            cout << convert(src) << destUnit << endl;
        }
};

class Won2Dollar : public Conveter {
    public:
        Won2Dollar(string sUnit, string dUnit, double ratio) : Conveter(sUnit, dUnit, ratio) {

        }
        double convert(double src) {
            return src / ratio;
        }
};

int main() {
    Won2Dollar w2d("won", "dollar", 1450);
    w2d.run();

    return 0;
}