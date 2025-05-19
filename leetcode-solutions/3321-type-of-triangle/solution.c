const char* triangleType(int* nums, int numsSize) {
    int a = nums[0], b = nums[1], c = nums[2];

    if (numsSize != 3) return "none"; // optional safety check

    if (a + b <= c || a + c <= b || b + c <= a) {
        return "none";
    }

    if (a == b && b == c) {
        return "equilateral";
    } else if (a == b || a == c || b == c) {
        return "isosceles";
    } else {
        return "scalene";
    }
}

