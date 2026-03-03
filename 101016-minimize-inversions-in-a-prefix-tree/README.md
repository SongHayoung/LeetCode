<h2><a href="https://leetcode.com/problems/minimize-inversions-in-a-prefix-tree">4254. Minimize Inversions in a Prefix Tree</a></h2><h3>Hard</h3><hr><p>You are given an array <code>words</code> of <code>n</code> <strong>unique</strong> strings consisting of lowercase English letters, and an integer array <code>target</code> of length <code>n</code>, where <code>target</code> is a <strong>permutation</strong> of the numbers in the range <code>[0..n - 1]</code>.</p>

<p>Define a rooted tree <code>T</code> as follows:</p>

<ul>
	<li>Each node corresponds to a <strong>prefix</strong> shared by <strong>at least</strong> one string in <code>words</code>.</li>
	<li>For any <strong>prefix</strong> <code>p</code> and character <code>c</code>, there is an <strong>edge</strong> from <code>p</code> to <code>p + c</code> if <strong>at least</strong> one string in <code>words</code> has prefix <code>p + c</code>.</li>
	<li>Each string <code>words[i]</code> corresponds to <strong>exactly one</strong> node in <code>T</code>. During traversal, record every node that represents a complete string, regardless of whether it is a leaf.</li>
</ul>

<p>For any node that has children, the order of its children may be <strong>rearranged arbitrarily</strong>.</p>

<p>For any choice of child orderings, consider the sequence of leaf nodes obtained by traversing the tree, visiting each node&#39;s children from left to right. This produces a permutation <code>traversal_order</code> of the indices <code>0..n - 1</code>.</p>

<p>An <strong>inversion</strong> is a pair <code>(i, j)</code> such that:</p>

<ul>
	<li><code>i &lt; j</code>, and</li>
	<li>the position of <code>traversal_order[i]</code> in <code>target</code> is <strong>greater</strong> than the position of <code>traversal_order[j]</code> in <code>target</code>.</li>
</ul>

<p>Return the <strong>minimum</strong> possible number of inversions over all valid reorderings of children at every node.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">words = [&quot;cat&quot;,&quot;car&quot;,&quot;dog&quot;,&quot;doc&quot;], target = [3,1,0,2]</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong>​​​​​​​</p>

<ul>
	<li>The words can be grouped into two main branches: <code>&quot;cat&quot;</code> and <code>&quot;car&quot;</code> in one group, <code>&quot;dog&quot;</code> and <code>&quot;doc&quot;</code> in another.</li>
	<li>One optimal ordering places the second group first, then the first group, with each group internally ordered as <code>[3, 2]</code> and <code>[1, 0]</code>.</li>
	<li>The resulting visit sequence of indices is <code>[3, 2, 1, 0]</code>.</li>
	<li>Mapping each index to its position in <code>target</code> produces <code>[0, 3, 1, 2]</code> (<code>3 &rarr; 0, 2 &rarr; 3, 1 &rarr; 1, 0 &rarr; 2</code>).</li>
	<li>The pairs <code>(3, 1)</code> and <code>(3, 2)</code> are inversions. Thus, the total number of inversions is 2, which is minimal.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">words = [&quot;ab&quot;,&quot;ac&quot;,&quot;ba&quot;,&quot;bc&quot;], target = [0,3,1,2]</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>The words form two groups: <code>&quot;ab&quot;</code> and <code>&quot;ac&quot;</code> in one group, <code>&quot;ba&quot;</code> and <code>&quot;bc&quot;</code> in another.</li>
	<li>One optimal ordering keeps the first group first, then the second group, with internal orders <code>[0, 1]</code> and <code>[3, 2]</code>.</li>
	<li>The resulting visit sequence of indices is <code>[0, 1, 3, 2]</code>.</li>
	<li>Mapping each index to its position in <code>target</code> produces <code>[0, 2, 1, 3]</code> (<code>0 &rarr; 0, 1 &rarr; 2, 3 &rarr; 1, 2 &rarr; 3</code>).</li>
	<li>The pair <code>(2, 1)</code> is an inversion. Thus, the total number of inversions is 1, which is minimal.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n == words.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= words[i].length &lt;= 20</code></li>
	<li><code>words[i]</code> contains only lowercase English letters</li>
	<li>All <code>words[i]</code> are <strong>unique</strong></li>
	<li><code>0 &lt;= target[i] &lt;= n - 1</code></li>
	<li><code>target</code> is a permutation of integers from 0 to <code>n - 1</code></li>
</ul>

<p>&nbsp;</p>
<style type="text/css">.spoilerbutton {display:block; border:dashed; padding: 0px 0px; margin:10px 0px; font-size:150%; font-weight: bold; color:#000000; background-color:cyan; outline:0;
}
.spoiler {overflow:hidden;}
.spoiler > div {-webkit-transition: all 0s ease;-moz-transition: margin 0s ease;-o-transition: all 0s ease;transition: margin 0s ease;}
.spoilerbutton[value="Show Message"] + .spoiler > div {margin-top:-2000%;}
.spoilerbutton[value="Hide Message"] + .spoiler {padding:5px;}
</style>
<input class="spoilerbutton" onclick="this.value=this.value=='Show Message'?'Hide Message':'Show Message';" type="button" value="Show Message" />
<div class="spoiler">
<div>
<p><strong>FOR TESTING ONLY. WILL BE DELETED LATER.</strong></p>
Model solution in O(N). Solutions like N^2 and above must TLE.

<pre>
#generator
#absolute-mess

import random

def pr(n, pos, k, file):
    file.write(f&quot;{n}\n&quot;)
    file.write(f&quot;{pos}\n&quot;)
    file.write(f&quot;{k}\n&quot;)

def generate_tests(n):
    k = random.randint(0, n - 1)
    pos = random.randint(0, n - 1)
    return (n, pos, k)

def examples(file):
    pr(3, 1, 0, file)
    pr(3, 2, 1, file)
    pr(1, 0, 0, file)

def hiddenCases(file):
    pr(100000,0,49999,file)
    pr(100000,50000,50000,file)
    pr(100000, 0, 0, file)
    pr(100000, 0, 99999, file)
    pr(100000, 99999, 99999, file)
    pr(100000, 50000, 99999, file)
    pr(100000, 50000, 0, file)
    pr(100000, 1, 99998, file)
    pr(100000, 99998, 1, file)
    pr(2, 0, 1, file)
    pr(100000,50000,49999,file)
    pr(100000,12345,50000,file)

test_cases = []
def testCases(ranges):
    for min_len, max_len, numCases in ranges:
        for _ in range(numCases):
            n = random.randint(min_len, max_len)
            test_cases.append(generate_tests(n))

with open(&#39;test.txt&#39;, &#39;w&#39;) as file:
    random.seed(9 + 8 + 2024)
    examples(file)

    ranges = [
        (2, 20, 300),
        (21, 100, 250),
        (101, 1000, 200),
        (1001, 5000, 130),
        (5001, 10000, 75),
        (10001, 50000, 20),
        (50000, 100000, 9)
    ]
    testCases(ranges)
    test_cases.sort(key=lambda x: x[0])
    for n, pos, k in test_cases:
        pr(n, pos, k, file)
    hiddenCases(file)

</pre>
</div>
</div>
