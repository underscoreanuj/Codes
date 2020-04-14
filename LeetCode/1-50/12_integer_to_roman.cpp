class Solution
{
public:
    string intToRoman(int num)
    {
        vector<string> THOUSANDS = {"", "M", "MM", "MMM"};
        vector<string> HUNDREDS = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> TENS = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> ONES = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

        int thousands = num / 1000;
        num %= 1000;
        int hundreds = num / 100;
        num %= 100;
        int tens = num / 10;
        num %= 10;
        int ones = num;

        return THOUSANDS[thousands] + HUNDREDS[hundreds] + TENS[tens] + ONES[ones];
    }
};