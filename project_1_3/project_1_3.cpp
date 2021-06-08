#include <iostream>
#include <vector>

std::vector<double> readInVector(std::string s) {
  int prev_location = 0;
  int next_location = 0;
  std::vector<double> result;
  while(s.find(',', prev_location) != std::string::npos) {
    next_location = s.find(',', prev_location);
    //std::cout << "prev_location: " << prev_location << std::endl;
    //std::cout << "next_location: " << next_location << std::endl;
    // substr [,]
    //std::cout << s.substr(prev_location, next_location - prev_location) << std::endl;
    result.push_back(std::stod(s.substr(prev_location, next_location - prev_location)));
    next_location++;
    prev_location = next_location;
  }
  result.push_back(std::stod(s.substr(prev_location, std::string::npos)));
  return result;
}

void printVector(std::vector<double> vector, std::string name) {
  if (name.size() != 0) {
    std::cout << name << ": ";
  }
  std::cout << "{";
  
  for (int i = 0; i < vector.size(); i++) {
    std::cout << vector[i];
    if (i != vector.size() - 1) {
      std::cout << ", ";
    }
  }
  std::cout << "}" << std::endl;
}


std::vector<double> convolveIt(std::vector<double> x, std::vector<double> w, bool pack_with_zeros) {
  std::vector<double> y;
  int offset = w.size() / 2;
  for (int i = 0; i < x.size(); i++) { // start convolve
    int wIndex = 0;
    double sum = 0;
    for (int j = i - offset; wIndex < w.size(); j++) {
      double xElement;
      if (j < 0 | j > x.size() - 1) {
        if (pack_with_zeros) {
          xElement = 0;
        } else {
          if (j < 0) {
            xElement = x[0];
          } else {
            xElement = x[x.size() - 1];
          }
        }
      } else {
        xElement = x[j];
      }

      double wElement = w[wIndex];
      sum += xElement * wElement;
      wIndex++;
    }
    y.push_back(sum);
  }
  return y;
}

int main() {
  std::vector<double> x;
  std::vector<double> w;
  std::vector<double> y;
  bool pack_with_zeros = true;

  std::string s;
  std::cin >> s;
  if(s == "false") {
    pack_with_zeros = false;
  }
  std::cin >> s;
  x = readInVector(s);
  std::cin >> s;
  w = readInVector(s);

  // TODO write your code here
  // =========== START =========
  printVector(x, "x");
  printVector(w, "w");
  //printVector(y, "y");
  
  y = convolveIt(x, w, pack_with_zeros);
  printVector(y, "");
  // =========== END ===========

  return 0;
}

