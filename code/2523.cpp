class Solution {
private:
    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
    
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> primes;
        // Find all prime numbers in the range
        for (int i = left; i <= right; i++) {
            if (isPrime(i)) {
                primes.push_back(i);
            }
        }
        
        // If we found less than 2 primes, return [-1, -1]
        if (primes.size() < 2) {
            return {-1, -1};
        }
        
        // Find the minimum gap between consecutive primes
        int minGap = INT_MAX;
        int num1 = -1, num2 = -1;
        for (int i = 0; i < primes.size() - 1; i++) {
            int gap = primes[i + 1] - primes[i];
            if (gap < minGap) {
                minGap = gap;
                num1 = primes[i];
                num2 = primes[i + 1];
            }
        }
        
        return {num1, num2};
    }
};