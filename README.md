# Leetcode_Grind
Collection of LeetCode questions to ace the coding interview!

<h2><a href="https://leetcode.com/problems/largest-odd-number-in-string">1903. Largest Odd Number in String</a></h2> <img src='https://img.shields.io/badge/Difficulty-Easy-brightgreen' alt='Difficulty: Easy' /><hr><p>You are given a string <code>num</code>, representing a large integer. Return <em>the <strong>largest-valued odd</strong> integer (as a string) that is a <strong>non-empty substring</strong> of </em><code>num</code><em>, or an empty string </em><code>&quot;&quot;</code><em> if no odd integer exists</em>.</p>

<p>A <strong>substring</strong> is a contiguous sequence of characters within a string.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> num = &quot;52&quot;
<strong>Output:</strong> &quot;5&quot;
<strong>Explanation:</strong> The only non-empty substrings are &quot;5&quot;, &quot;2&quot;, and &quot;52&quot;. &quot;5&quot; is the only odd number.
</pre>

```
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

```
// This is for sorting using a compatator to sort according to length

std::sort(words.begin(), words.end(), 
        [](const std::string& a, const std::string& b) {
            return a.length() < b.length();
        }
    );

```
