class Solution {
	public:
		    int concatenatedBinary(int n) {
			            long long int result = 0, MOD = 1e9+7, shift_len=0;
				            
				            for(int i=1; i<=n; ++i) {
						                if((i&(i-1)) == 0) ++shift_len;
								            result = ((result<<shift_len) + i) % MOD;
									            }
					            
					            return result % MOD;
						        }
};

auto speedup = []() {
	    std::ios::sync_with_stdio(false);
	        cin.tie(nullptr);
		    cout.tie(nullptr);
		        return nullptr;
}();
