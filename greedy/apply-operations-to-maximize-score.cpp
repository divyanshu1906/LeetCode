class Solution {
public:
    const int MOD = 1e9 + 7;

    long long findPower(long long a, long long b){
        if(b==0) return 1;

        long long half = findPower(a, b/2);
        long long result = (half*half) % MOD;

        if(b%2 == 1) {
            result = (result*a) % MOD;
        }

        return result;
    }
    vector<int> getPrimes(int limit){
        vector<bool>isPrime(limit+1, true);
        vector<int>primes;

        for(int i=2; i*i <= limit; i++){
            if(isPrime[i]){
                for(int j=i*i; j<=limit; j+=i){
                    isPrime[j] = false;
                }
            }
        }

        for(int i=2; i<=limit; i++){
            if(isPrime[i]){
                primes.push_back(i);
            }
        }

        return primes;
    }

    vector<int> findPrimesScores(vector<int> &nums){
        int n = nums.size();
        vector<int>primesScores(n, 0);
        int maxElement = *max_element(begin(nums), end(nums));
        vector<int>primes = getPrimes(maxElement);

        for(int i=0; i<n; i++){
            int num = nums[i];

            for(int prime : primes){
                if(prime*prime > num){
                    break;
                }

                if(num%prime != 0){
                    continue;
                }

                primesScores[i]++;
                while(num % prime == 0){
                    num /= prime;
                }
            }
            if(num>1){
                primesScores[i]++;
            }
        }
        return primesScores;
    }

    vector<int> findNextGreater(vector<int> &primesScores){
        int n = primesScores.size();
        vector<int>nextGreater(n);
        stack<int>st;

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && primesScores[st.top()] <= primesScores[i]){
                st.pop();
            }

            nextGreater[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nextGreater;
    }

     vector<int> findPrevGreater(vector<int> &primesScores){
        int n = primesScores.size();
        vector<int>prevGreater(n);
        stack<int>st;

        for(int i=0; i<n; i++){
            while(!st.empty() && primesScores[st.top()] < primesScores[i]){
                st.pop();
            }

            prevGreater[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return prevGreater;
    }

    int maximumScore(vector<int>& nums, int k) {
        vector<int> primesScores = findPrimesScores(nums);
        vector<int> nextGreater = findNextGreater(primesScores);
        vector<int> prevGreater = findPrevGreater(primesScores);

        int n = nums.size();
        vector<long long>subarrays(n, 0);

        for(int i=0; i<n; i++){
            subarrays[i] = (long long) (nextGreater[i] - i) * (i-prevGreater[i]);
        }

        vector<pair<int, int>>sortedNums(n);
        for(int i=0; i<n; i++){
            sortedNums[i] = {nums[i], i};
        }

        sort(sortedNums.begin(), sortedNums.end(), greater<>());

        long long score = 1;

        int idx = 0;
        while(k>0){
            auto [num, i] = sortedNums[idx];
            long long operations = min((long long)k, subarrays[i]);
            score = (score*findPower(num, operations)) % MOD;
            k -= operations;
            idx++;
        }
        return score;
    }
};