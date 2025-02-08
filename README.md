# LeetCode_Grind

## Table of Contents
1. [205. Isomorphic Strings](#205-isomorphic-strings)
2. [3264. Final Array State After K Multiplication Operations I](#3264-final-array-state-after-k-multiplication-operations-i)
3. [1903. Largest Odd Number in String](#1903-largest-odd-number-in-string)
4. [14. Longest Common Prefix](#14-longest-common-prefix)
5. [242. Valid Anagram](https://leetcode.com/problems/valid-anagram)
6. [SET & MAP OPERATIONS QUICK REFERENCE](https://github.com/flash1729/Leetcode_Grind/edit/main/README.md#design-a-number-container-system-)

---

## <a href="https://leetcode.com/problems/design-a-number-container-system">Design a Number Container System</a> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' />

### Problem Statement 📜
Design a number container system that can do the following:

1. **change(index, number)**: Assign a given number to a specified index. If the index already had a number, update it.
2. **find(number)**: Return the **smallest index** where this number is stored. If the number does not exist, return `-1`.

### **Key Learnings 🎯**
- ✅ **Using `unordered_map` for fast lookups**  
  - `ncsys`: Maps `index → number`
  - `revmap`: Maps `number → sorted set of indices`
- ✅ **Using `set<int>` instead of `vector<int>`**  
  - **`set<int>` keeps elements sorted**
  - This makes it **easy to find the smallest index**
- ✅ **Using `.begin()` with `set`**  
  - `set<int>::begin()` gives the **smallest element in O(1)**
  - No need to sort manually 🎉
- ✅ **Handling previous values efficiently**  
  - **Check if index exists in `ncsys` before updating**
  - **Remove old index from `revmap[oldNumber]`**
  - **Use `.erase()` and `.empty()` to clean up unused sets**
- ✅ **New Functions Learned**  
  - `.find()`: Checks if a key exists in `unordered_map`
  - `.erase()`: Removes an element from `set` or `unordered_map`
  - `.empty()`: Checks if `set` is empty before deletion

```cpp
#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;

int main() {
    // Demonstrating set operations
    set<int> mySet = {5, 2, 8, 1, 9};
    
    // 1. .begin() - Returns iterator to smallest element
    // ----------------------------------------------
    // IMPORTANT: .begin() works in O(1) for sets because they're always sorted
    // Use case: When you need the smallest element quickly
    auto smallest = mySet.begin();  // Points to 1
    cout << "Smallest element: " << *smallest << endl;  // Use * to get the value
    
    // 2. .erase() - Removes elements from set
    // ----------------------------------------------
    // Method 1: Erase by value
    mySet.erase(5);  // Removes 5 from set
    // Method 2: Erase by iterator
    auto it = mySet.find(2);
    if (it != mySet.end()) {
        mySet.erase(it);  // Removes 2 from set
    }
    // IMPORTANT: After erasing, iterator becomes invalid
    // Don't use the iterator after erasing!
    
    // 3. .find() - Searches for element
    // ----------------------------------------------
    // Returns iterator to element if found, .end() if not found
    // IMPORTANT: Use find() before erase() to check existence
    auto findIt = mySet.find(8);
    if (findIt != mySet.end()) {
        cout << "Found: " << *findIt << endl;
    } else {
        cout << "Not found!" << endl;
    }
    
    // 4. .empty() - Checks if container has elements
    // ----------------------------------------------
    // Returns true if container has no elements
    // IMPORTANT: Always check empty() before accessing elements
    if (!mySet.empty()) {
        cout << "First element: " << *mySet.begin() << endl;
    }
    
    // PRACTICAL EXAMPLE: Managing a student's courses
    unordered_map<string, set<int>> studentCourses;  // student -> course IDs
    
    // Adding courses for a student
    studentCourses["Alice"].insert(101);
    studentCourses["Alice"].insert(102);
    
    // COMBINING ALL OPERATIONS:
    string student = "Alice";
    int courseToRemove = 101;
    
    // 1. First find if student exists
    auto studentIt = studentCourses.find(student);
    
    if (studentIt != studentCourses.end()) {
        // 2. Check if student has any courses
        if (!studentIt->second.empty()) {
            // 3. Try to find the specific course
            auto courseIt = studentIt->second.find(courseToRemove);
            
            if (courseIt != studentIt->second.end()) {
                // 4. Remove the course
                studentIt->second.erase(courseIt);
                
                // 5. If no courses left, remove student entry
                if (studentIt->second.empty()) {
                    studentCourses.erase(student);
                }
            }
        }
    }
    
    return 0;
}

/* Common Mistakes to Avoid:
1. .begin():
   ❌ Don't use without checking .empty()
   ✅ Always check !container.empty() before using .begin()
   
2. .erase():
   ❌ Don't use iterator after erasing
   ✅ Get new iterator if needed after erase
   
3. .find():
   ❌ Don't assume element exists
   ✅ Always check against .end()
   
4. .empty():
   ❌ Don't use container.size() == 0
   ✅ Use .empty() - it's more efficient
*/
```

---
### **Solution 💡**
```cpp
#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

class NumberContainers {
public:
    unordered_map<int, int> ncsys; // index -> number
    unordered_map<int, set<int>> revmap; // number -> sorted indices

    NumberContainers() {}

    void change(int index, int number) {
        if (ncsys.find(index) != ncsys.end()) {
            int oldNumber = ncsys[index];
            revmap[oldNumber].erase(index);
            if (revmap[oldNumber].empty()) {
                revmap.erase(oldNumber);
            }
        }
        ncsys[index] = number;
        revmap[number].insert(index);
    }

    int find(int number) {
        if (revmap.find(number) != revmap.end() && !revmap[number].empty()) {
            return *revmap[number].begin();
        }
        return -1;
    }
};

int main() {
    NumberContainers nc;
    nc.change(2, 10);
    nc.change(1, 10);
    nc.change(3, 10);
    nc.change(5, 20);

    cout << nc.find(10) << endl; // Expected: 1 (smallest index for 10)
    cout << nc.find(20) << endl; // Expected: 5
    cout << nc.find(30) << endl; // Expected: -1

    nc.change(1, 20); // Move index 1 to number 20
    cout << nc.find(10) << endl; // Expected: 2
    return 0;
}
```

### **Complexity Analysis 📊**
| Operation | Complexity |
|-----------|------------|
| `change(index, number)` | **O(log n)** (due to `set<int>`) |
| `find(number)` | **O(1)** (direct access to `.begin()`) |
| **Total worst case** | **O(log n)** |

---
### **Example Output 🖥️**
```
1
5
-1
2
```

This solution ensures **fast lookups and updates**! 🚀
<h2><a href="https://leetcode.com/problems/sort-characters-by-frequency">Sort Characters By Frequency</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>Given a string <code>s</code>, sort it in <strong>decreasing order</strong> based on the <strong>frequency</strong> of the characters. The <strong>frequency</strong> of a character is the number of times it appears in the string.</p>

<p>Return <em>the sorted string</em>. If there are multiple answers, return <em>any of them</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;tree&quot;
<strong>Output:</strong> &quot;eert&quot;
<strong>Explanation:</strong> &#39;e&#39; appears twice while &#39;r&#39; and &#39;t&#39; both appear once.
So &#39;e&#39; must appear before both &#39;r&#39; and &#39;t&#39;. Therefore &quot;eetr&quot; is also a valid answer.
</pre>

### Key Learnings 🎯
- ✅ **How we can use unordered_maps**
    this is a nice data structure...
- ✅ **Learnt the uses of comparators and of auto**
- ✅ **priority_queue<Type, Container, Comparator>**
    this is the way a prioroty queue is defined and according we can manage to make it min or max heap...

```cpp
string frequencySort(string s) {
    // Step 1: Make a map<char, int> freq to store frequencies
    unordered_map<char, int> freq;

    // Increment the value for each character in the map
    // If the character is already in the map, the value will increase
    // If the character is not present, it starts from 0 -> 1
    for (char ch : s) {
        freq[ch]++;
    }

    // Step 2: Define a custom comparator for priority_queue
    // This will sort pairs based on the second value (frequency) in descending order
    auto cmp = [](const pair<char, int>& a, const pair<char, int>& b) {
        return a.second < b.second; // Higher frequency comes first
    };

    // Step 3: Make a priority_queue with modified parameters
    // Priority queue stores {character, frequency} pairs
    // It uses the custom comparator defined above
    priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(cmp);

    // Push all elements from the map into the priority queue
    for (const auto& [ch, count] : freq) {
        pq.push({ch, count});
    }

    // Step 4: Build the result string
    string result;
    // Loop through the priority queue until it is empty
    while (!pq.empty()) {
        // Get the top element (character with the highest frequency)
        auto [ch, count] = pq.top();
        pq.pop();

        // Append the character 'count' times to the result string
        result.append(count, ch);
    }

    // Return the final sorted string
    return result;
}
```
## 242. Valid Anagram

### Problem Details 📝
- **Title:** [242. Valid Anagram](https://leetcode.com/problems/valid-anagram)
- **Difficulty:** Easy

### Description 📖
Given two strings `s` and `t`, return `true` if `t` is an **anagram** of `s`, and `false` otherwise.  
An anagram is a word formed by rearranging the letters of a different word, using all the original letters exactly once.

---

### Key Learnings 🎯
- ✅ **Simple Array Structure:**  
  Use a fixed **26-element array** to track character frequencies for lowercase English letters.
- ✅ **unordered_map Comparison:**  
  **unordered_map** objects in C++ can be directly compared using the `==` operator.
- ✅ **Sorting:**  
  By sorting both strings and comparing, an anagram can be easily detected.

---

### Complexity Analysis 📊
1. **Array-Based Approach:**
   - **Time Complexity:** O(n), where `n` is the length of the string.  
     One pass to count characters and another to validate frequencies.
   - **Space Complexity:** O(1), as the array size is fixed at 26.
2. **unordered_map Approach:**
   - **Time Complexity:** O(n), as insertions and lookups in unordered_map are O(1) on average.
   - **Space Complexity:** O(1) for constant-sized map of letters.
3. **Sorting-Based Approach:**
   - **Time Complexity:** O(n log n), due to sorting both strings.
   - **Space Complexity:** O(1) if sorting in place, O(n) otherwise.

---

### Code Implementations 💻

#### Array-Based Solution
```cpp
bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    vector<int> count(26, 0);
    for (int i = 0; i < s.size(); i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }
    for (int c : count) {
        if (c != 0) return false;
    }
    return true;
}

//Soln 2 using maps -- Maps can be directly compared using == operator
bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    unordered_map<char, int> freq_s, freq_t;
    for (char c : s) freq_s[c]++;
    for (char c : t) freq_t[c]++;
    return freq_s == freq_t;
}
```

## 205. Isomorphic Strings

### Problem Details 📝
- **Title:** [205. Isomorphic Strings](https://leetcode.com/problems/isomorphic-strings/)
- **Difficulty:** Easy

### Description 📖
Check if two strings `s` and `t` are isomorphic. Two strings are isomorphic if the characters in `s` can be replaced to get `t`. All occurrences of a character must be replaced with the same character.

### Key Learnings 🎯
- ✅ Learned about **unordered_map** for maintaining **1-to-1 mappings** between characters.
- ✅ Understood the importance of checking **both forward and reverse mappings** for consistency.

### Complexity Analysis 📊
- **Time Complexity:** O(n) where `n` is the length of the string.
  - Iterating through `s` and `t` takes O(n).
  - Lookup and insert operations in an unordered map are O(1) on average.
- **Space Complexity:** O(n) for storing mappings in two `unordered_map`.

### Code Implementation 💻
<details>
  <summary>Click to View Code</summary>

```cpp
bool isIsomorphic(string s, string t) {
    unordered_map<char, char> s_t, t_s;
    for (int i = 0; i < s.size(); i++) {
        if ((s_t.count(s[i]) && s_t[s[i]] != t[i]) ||
            (t_s.count(t[i]) && t_s[t[i]] != s[i])) {
            return false;
        }
        s_t[s[i]] = t[i];
        t_s[t[i]] = s[i];
    }
    return true;
}
```

</details>

### Example Walkthrough 📖
- **Input:** `s = "egg"`, `t = "add"`
  - Map `e -> a`, `g -> d`. ✅ Result: True.
- **Input:** `s = "foo"`, `t = "bar"`
  - Map fails: `o` maps inconsistently to both `a` and `r`. ❌ Result: False.
- **Edge Case:** Empty strings -> Return True.

### Common Pitfalls 🧩
- ❌ Forgetting to ensure mappings are consistent in **both directions**.
- ❌ Skipping the `count` check before inserting a new character.

---

## 3264. Final Array State After K Multiplication Operations I

### Problem Details 📝
- **Title:** [3264. Final Array State](https://leetcode.com/problems/final-array-state-after-k-operations/)
- **Difficulty:** Medium

### Description 📖
Given an array `nums` and `k` operations, multiply any element in the array by `-1` to maximize the sum of the array. Return the final array state after all operations.

### Key Learnings 🎯
- ✅ Using a **priority queue** (min-heap) for greedy element selection.
- ✅ Learned the importance of **custom comparators** in STL priority queues.

### Complexity Analysis 📊
- **Time Complexity:** O(k log n)
  - Each insertion/removal in a priority queue takes O(log n).
  - `k` operations result in O(k log n).
- **Space Complexity:** O(n) for storing the priority queue.

### Code Implementation 💻
<details>
  <summary>Click to View Code</summary>

```cpp
vector<int> finalArrayState(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
    while (k--) {
        int smallest = pq.top(); pq.pop();
        pq.push(-smallest);
    }
    vector<int> result;
    while (!pq.empty()) {
        result.push_back(pq.top()); pq.pop();
    }
    return result;
}
```

</details>

### Example Walkthrough 📖
- **Input:** `nums = [-2, 5, -1], k = 2`
  - Iteration 1: Flip `-2` to `2`.
  - Iteration 2: Flip `-1` to `1`.
  - Final Array: `[1, 2, 5]`. ✅
- **Edge Case:** If all elements are positive, no flips needed.

### Common Pitfalls 🧩
- ❌ Forgetting to reinsert flipped elements into the priority queue.
- ❌ Not accounting for cases where `k` exceeds the number of negative numbers.

---

## 1903. Largest Odd Number in String

### Problem Details 📝
- **Title:** [1903. Largest Odd Number in String](https://leetcode.com/problems/largest-odd-number-in-string/)
- **Difficulty:** Easy

### Description 📖
Find the largest odd number that can be formed as a substring of the given string `num`.

### Key Learnings 🎯
- ✅ Explored **substring operations** in strings.
- ✅ Learned to identify the **last odd digit** for efficient solutions.

### Complexity Analysis 📊
- **Time Complexity:** O(n)
  - Single iteration through the string.
- **Space Complexity:** O(1)
  - No additional space required apart from input.

### Code Implementation 💻
<details>
  <summary>Click to View Code</summary>

```cpp
string largestOddNumber(string num) {
    for (int i = num.size() - 1; i >= 0; i--) {
        if ((num[i] - '0') % 2 != 0) {
            return num.substr(0, i + 1);
        }
    }
    return "";
}
```

</details>

### Example Walkthrough 📖
- **Input:** `num = "4206"`
  - Iteration: Last odd digit not found. ✅ Output: `""`.
- **Input:** `num = "35427"`
  - Iteration: Last odd digit is `7`. ✅ Output: `"35427"`.

### Common Pitfalls 🧩
- ❌ Forgetting to handle cases where no odd digits exist.

---

## 14. Longest Common Prefix

### Problem Details 📝
- **Title:** [14. Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/)
- **Difficulty:** Easy

### Description 📖
Find the longest common prefix among a given array of strings.

### Key Learnings 🎯
- ✅ Learned to use **lexicographical sorting** for prefix matching.
- ✅ Explored **substring comparisons** for efficiency.

### Complexity Analysis 📊
- **Time Complexity:** O(n * log n + m)
  - Sorting takes O(n log n), and prefix comparison takes O(m).
- **Space Complexity:** O(1).

### Code Implementation 💻
<details>
  <summary>Click to View Code</summary>

```cpp
string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    sort(strs.begin(), strs.end());
    string first = strs[0], last = strs.back();
    int i = 0;
    while (i < first.size() && first[i] == last[i]) i++;
    return first.substr(0, i);
}
```

</details>

### Example Walkthrough 📖
- **Input:** `strs = ["flower", "flow", "flight"]`
  - Sorted: `"flight", "flow", "flower"`.
  - Compare `"flight"` and `"flower"`. ✅ Result: `"fl"`.
- **Edge Case:** Empty array -> Return "".

### Common Pitfalls 🧩
- ❌ Forgetting to sort strings before comparison.

## Progress Tracker 
| Problem Title                              | Difficulty | Syntax Used                            | Notes                               |
|-------------------------------------------|------------|---------------------------------------|-------------------------------------|
| 205. Isomorphic Strings                   | Easy       | `unordered_map<char, char>`          | Learned about unordered_map usage. |
| 3264. Final Array State After K Operations | Medium     | `priority_queue<int, vector<int>, greater<int>>` | Used priority_queue effectively.   |
| 1903. Largest Odd Number in String        | Easy       | `string::substr`, `stoi`              | Explored substrings in strings.    |
| 14. Longest Common Prefix                 | Easy       | `sort(vector<string>::begin(), ...)` | Sorting strings lexicographically. |

## Useful Links 🔗
- [C++ STL Documentation](https://cplusplus.com/reference/stl/)
- [Priority Queue Explanation (GeeksforGeeks)](https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/)
- [Lexicographical Sorting (StackOverflow)](https://stackoverflow.com/)

---
