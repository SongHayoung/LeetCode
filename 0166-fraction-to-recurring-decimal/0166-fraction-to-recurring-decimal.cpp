class Solution {
public:
    string calculateRemainder(long long remainder, long long d) {
  string fractional = "";
  unordered_map<long long, int> seen;

  while(true) {
    if(seen.count(remainder)) {
      int seenIndex = seen[remainder];
      string result = "";
      for(int i = 0; i < seenIndex; i++) {
        result.push_back(fractional[i]);
      }
      
      result.push_back('(');
      for(int i = seenIndex; i < fractional.size(); i++) {
        result.push_back(fractional[i]);
      }
      result.push_back(')');

      return result;
    } else {
      int qutinent = remainder / d;
      long long nextRemainder = remainder % d;
      int currentIndex = fractional.size();

      fractional.push_back(qutinent + '0');

      if(nextRemainder == 0) {
        return fractional;
      }


      seen[remainder] = currentIndex;
      remainder = nextRemainder * 10;
    }  
  }


  return fractional;
}

string fractionToDecimal(long long n, long long d) {
  long long qutinent = abs(n / d);
  long long remiander = abs(n % d);
  string number = to_string(qutinent);
  if((n < 0 and d > 0) or (n > 0 and d < 0)) {
    number = "-" + number;
  }
  remiander = abs(remiander);
  d = abs(d);
  if(remiander == 0) {
    return number;
  }

  number.push_back('.');
  
  number += calculateRemainder(remiander * 10, d);
  
  return number;
}

};