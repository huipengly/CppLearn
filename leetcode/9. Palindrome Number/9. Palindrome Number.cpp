class Solution {
public:
    bool isPalindrome(int x) {
		auto str = to_string(x), str2 = str;
		std::reverse(str.begin(), str.end());
        return str == str2;
    }
};

class Solution_2 {
public:
    bool isPalindrome(int x) {
        int half = 0;
        if (x > 0 && x < 10)
            return true;
        if (x % 10 == 0)
            return false;
        while (x > 0)
        {
            if (half == x || half == x / 10)
                return true;
            half = half * 10 + x % 10;
            x /= 10;
        }

        return false;
    }
};