class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        double a = sides[0];
        double b = sides[1];
        double c = sides[2];

        if(a+b<=c || b+c<=a || c+a<=b){
            return {};
        }
        double pi = acos(-1);

        auto deg = [&] (double x){
            return x*180/pi;
        };

        auto clamp = [](double x){
            return max(-1.0,min(1.0,x));
        };
        double A = deg(acos(clamp((b*b+c*c-a*a)/(2*b*c))));
        double B = deg(acos(clamp((c*c+a*a-b*b)/(2*a*c))));
        double C = deg(acos(clamp((b*b+a*a-c*c)/(2*b*a))));   

        vector<double> ans = {A,B,C};
        sort(ans.begin(),ans.end());
        return ans;
    }
};
