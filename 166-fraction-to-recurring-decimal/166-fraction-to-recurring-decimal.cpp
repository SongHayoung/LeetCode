struct DecimalNumber{
    string decimal;
    optional<int> repeatedRemainder;

    DecimalNumber(string decimal, optional<int> repeatedRemainder) : decimal(decimal), repeatedRemainder(repeatedRemainder) {}
};
class Solution {
private:
    string stringToNum(long num) {
        string ret;
        if (num == 0) { return "0"; }
        long N = num, rev, count = 0;
        rev = N;
        while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
        rev = 0;
        while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
        while (rev != 0) { ret += (rev % 10 | 0b110000); rev /= 10;}
        while (count--) ret += '0';

        return ret;
    }

    string getDecimalNumber(long numerator, long denominator) {
        if(numerator == 0)
            return "";
        set<pair<long, long>> remainder;
        return "." + calculateDecimalNumber(numerator * 10, denominator, remainder).decimal;
    }

    DecimalNumber calculateDecimalNumber(long numerator, long denominator, set<pair<long, long>> &remainder) {
        if(numerator == 0)
            return DecimalNumber("", std::nullopt);
        int quotient = numerator / denominator;
        numerator %= denominator;
        if(remainder.find(make_pair(numerator + denominator * quotient, numerator)) != remainder.end()) {
            return DecimalNumber(")", numerator);
        }

        remainder.insert(make_pair(numerator + denominator * quotient, numerator));
        auto decimalNumber = calculateDecimalNumber(numerator * 10, denominator, remainder);
        return decimalNumber.repeatedRemainder.value_or(-1) == numerator ?
        DecimalNumber("(" + stringToNum(quotient) + decimalNumber.decimal, std::nullopt) :
        DecimalNumber(stringToNum(quotient) + decimalNumber.decimal, decimalNumber.repeatedRemainder);
    }
public:
    string fractionToDecimal(int numerator, int denominator) {
        string solution = (numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0) ? "-" : "";
        long n = numerator <= 0 ? (long)(numerator) * -1 : numerator;
        long d = denominator <= 0 ? (long)(denominator) * -1 : denominator;

        solution += stringToNum(n / d);
        n %= d;

        return solution + getDecimalNumber(n, d);
    }
};
