class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        long long vol = 1LL * length * width * height;

        bool bulky = (length >= 10000 || width >= 10000 || height >= 10000 || vol >= 1000000000);
        bool heavy = (mass >= 100);

        if (bulky && heavy) return "Both";
        if (bulky) return "Bulky";
        if (heavy) return "Heavy";
        return "Neither";
    }
};
