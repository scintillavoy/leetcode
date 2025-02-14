#include <vector>
using namespace std;

class ProductOfNumbers {
 public:
  ProductOfNumbers() { prefix_product.push_back(1); }

  void add(int num) {
    if (num == 0) {
      prefix_product = {1};
    } else {
      prefix_product.push_back(prefix_product.back() * num);
    }
  }

  int getProduct(int k) {
    if (k + 1 > prefix_product.size()) {
      return 0;
    }
    return prefix_product.back() /
           prefix_product[prefix_product.size() - k - 1];
  }

 private:
  vector<int> prefix_product;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
