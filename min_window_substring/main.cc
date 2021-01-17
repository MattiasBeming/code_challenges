//https://coderbyte.com/editor/Min%20Window%20Substring:Cpp

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

// https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
// Function to print permutations of string 
// This function takes three parameters: 
// 1. String 
// 2. Starting index of the string
// 3. Ending index of the string.
void permute(std::string a, int l, int r, std::vector<std::string>& res) {
    // Base case
    if (l == r) {
        res.push_back(a);
    }
    else {
        // Permutations made
        for (int i = l; i <= r; i++) {
            // Swapping done
            std::swap(a[l], a[i]);
            // Recursion called
            permute(a, l+1, r, res);
            //backtrack
            std::swap(a[l], a[i]);
        }
    }
}

// Finds the biggest substring in str(strArr[0]) with the characters in t(strArr[1])
std::string biggestSubstring(std::string strArr[]) {
    std::string str{strArr[0]};
    std::string t{strArr[1]};

    std::vector<std::string> res{};
    permute(t, 0, t.size()-1, res);
    while(t.size() >= 1) {
        for (auto&& substring : res) {
            if (std::size_t f = str.find(substring); f != std::string::npos) {
                //Found substring
                return substring;
            }
        }
        res = {};
        //Remove last character
        t = t.substr(0, t.size()-1);
        permute(t, 0, t.size()-1, res);
    }
    return "";
}

/*
    Improvement to be made: Ignore the same case, for example 'jefaa' and 'jefaa'.

    Other improvements: Don't read the task incorrectly and implement the correct thing!
    ---- 
    The code looks for permutations of 'jefaa' ->
    'jeafa', 'jeaaf', 'jfeaa', etc. 
    and if that word is in the input as a substring, return that, else
    check all permutations of 'jefaa' minus the last character -> permute('jefa') and 
    so on until a substring is found.
*/

int main(void) {
    std::string A[] = {"ahffaksfajeeubsne", "jefaa"};
    // Output: faje
    // Note: Did not do the task on the website.

    std::cout << biggestSubstring(A) << std::endl;
    return 0;
}

