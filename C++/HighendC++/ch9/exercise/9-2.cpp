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

class Inch2Centi : public Conveter {
    public:
        Inch2Centi(string sUnit, string dUnit, double ratio) : Conveter(sUnit, dUnit, ratio) {}
        double convert(double src) {
            return src * ratio;
        }
};

int main() {
    Inch2Centi i2c("inch", "cm", 2.54);
    i2c.run();

    return 0;
}