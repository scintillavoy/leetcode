class Solution {
 public:
  int maximum69Number(int num) {
    int num_to_be_added = 0;
    int multiplier = 1;
    int current_num = num;
    while (current_num > 0) {
      if (current_num % 10 == 6) {
        num_to_be_added = 3 * multiplier;
      }
      multiplier *= 10;
      current_num /= 10;
    }
    return num + num_to_be_added;
  }
};
