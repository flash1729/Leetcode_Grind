# LeetCode_Grind

## Table of Contents
1. [205. Isomorphic Strings](#205-isomorphic-strings)
2. [3264. Final Array State After K Multiplication Operations I](#3264-final-array-state-after-k-multiplication-operations-i)
3. [1903. Largest Odd Number in String](#1903-largest-odd-number-in-string)
4. [14. Longest Common Prefix](#14-longest-common-prefix)
5. [242. Valid Anagram](https://leetcode.com/problems/valid-anagram)

---
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
