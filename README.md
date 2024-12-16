# Leetcode_Grind

<h2><a href="https://leetcode.com/problems/isomorphic-strings">205. Isomorphic Strings</a></h2> <img src='https://img.shields.io/badge/Difficulty-Easy-brightgreen' alt='Difficulty: Easy' /><hr><p>Given two strings <code>s</code> and <code>t</code>, <em>determine if they are isomorphic</em>.</p>

<p>Two strings <code>s</code> and <code>t</code> are isomorphic if the characters in <code>s</code> can be replaced to get <code>t</code>.</p>

<p>All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.</p>

```cpp
// This question can be done easily by doing 1-1 mappings
// Two unordered maps are required because we need to ensure 
// the same mapping is not assigned to different elements from the same string
unordered_map<char, char> s_t, t_s;

// Simply using the count function gives whether a particular key is present in the map or not
s_t.count(s[i]); // Returns a bool depending on availability

// Syntax to insert a key-value pair
s_t[key] = value;
```

<h2><a href="https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i">3264. Final Array State After K Multiplication Operations I</a></h2> <img src='https://img.shields.io/badge/Difficulty-Easy-brightgreen' alt='Difficulty: Easy' /><hr><p>You are given an integer array <code>nums</code>, an integer <code>k</code>, and an integer <code>multiplier</code>.</p>

<p>You need to perform <code>k</code> operations on <code>nums</code>. In each operation:</p>

<ul>
	<li>Find the <strong>minimum</strong> value <code>x</code> in <code>nums</code>. If there are multiple occurrences of the minimum value, select the one that appears <strong>first</strong>.</li>
	<li>Replace the selected minimum value <code>x</code> with <code>x * multiplier</code>.</li>
</ul>

<p>Return an integer array denoting the <em>final state</em> of <code>nums</code> after performing all <code>k</code> operations.</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [2,1,3,5,6], k = 5, multiplier = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">[8,4,6,5,6]</span></p>

In this one easily we have to create an priority queue of pairs of (value,index) pairs.
To make them pop out ascending we need to use a different comparater which goes something like this
```cpp
// Use such syntax for comparators lik greater (by defaults it pops out descending)
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        for (int i = 0; i < n; i++) {
            q.push(make_pair(nums[i],i));
        }

        for (int i = 0; i < k; i++) {
            int temp = q.top().first;
            int index = q.top().second;

            q.pop();
            temp = temp * multiplier;
            q.push(make_pair(temp,index));
            nums[index] = temp;
        }
```
<h2><a href="https://leetcode.com/problems/largest-odd-number-in-string">1903. Largest Odd Number in String</a></h2> <img src='https://img.shields.io/badge/Difficulty-Easy-brightgreen' alt='Difficulty: Easy' /><hr><p>You are given a string <code>num</code>, representing a large integer. Return <em>the <strong>largest-valued odd</strong> integer (as a string) that is a <strong>non-empty substring</strong> of </em><code>num</code><em>, or an empty string </em><code>&quot;&quot;</code><em> if no odd integer exists</em>.</p>

<p>A <strong>substring</strong> is a contiguous sequence of characters within a string.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> num = &quot;52&quot;
<strong>Output:</strong> &quot;5&quot;
<strong>Explanation:</strong> The only non-empty substrings are &quot;5&quot;, &quot;2&quot;, and &quot;52&quot;. &quot;5&quot; is the only odd number.
</pre>

```cpp
//Use this to compare for word in strings and also there is fucntions like atoi which are very handy as well...

string largestOddNumber(string num) {
        int n = num.length();
        for(int i = n-1;i >= 0;i--){
            if((num[i] - '0') % 2 == 1){
                return num.substr(0,i+1);
            }
        }
        return "";
    }
```


<h2><a href="https://leetcode.com/problems/longest-common-prefix">14. Longest Common Prefix</a></h2> <img src='https://img.shields.io/badge/Difficulty-Easy-brightgreen' alt='Difficulty: Easy' /><hr><p>Write a function to find the longest common prefix string amongst an array of strings.</p>

<p>If there is no common prefix, return an empty string <code>&quot;&quot;</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> strs = [&quot;flower&quot;,&quot;flow&quot;,&quot;flight&quot;]
<strong>Output:</strong> &quot;fl&quot;
</pre>

This one is about making the lexicographical sorting int he case of string arrays...
The given string array gets sorted lexicographically and then its not always the case that it will get sorted according to length.
### Lexicographical Sorting Note (C++ `std::sort`)

* **std::sort** with `std::string` arrays/orders lexicographically (dictionary order).
* **Implication:** Sorting by lexicographical order **does not** imply sorting by **string length**.
* **Dual Sorting Requirement:** For both lexicographical and length-based ordering, consider custom comparator.

```cpp
// This is for sorting using a compatator to sort according to length

std::sort(words.begin(), words.end(), 
        [](const std::string& a, const std::string& b) {
            return a.length() < b.length();
        }
    );

```
