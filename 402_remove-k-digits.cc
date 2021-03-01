/**
 * 3 7 4 6 1 3
 *      i
 * i-1     i+1
 * 
 * use stack (or deque for reconstruction)
 * for (i=0; i<num.size(); ++i) {
 *     if (num[i] > num[i+1]) {
 *         remove num[i];
 *     }
 * }
 * if there remain digits to be removed, remove from the rightmost digit
 * 
 * O(n)
 */
