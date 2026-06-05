<h2><a href="https://leetcode.com/problems/minimum-operations-to-make-a-rotated-palindrome">4350. Minimum Operations to Make a Rotated Palindrome</a></h2><h3>Medium</h3><hr><p>You are given a string <code>s</code> consisting of lowercase English letters.</p>

<p>You can perform the following operations any number of times(including zero) and in any order:</p>

<ul>
	<li><strong>Increment</strong>: Choose any index <code>i</code> and replace <code>s[i]</code> with the next lowercase English letter <strong>cyclically.</strong></li>
	<li><strong>Left rotate</strong>: Move the first character of the string to the end.</li>
</ul>

<p>Return the <strong>minimum</strong> number of operations required to make <code>s</code> a <strong>palindrome</strong>.</p>
A <strong>palindrome</strong> is a string that reads the same forward and backward.
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;abc&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Left rotate the string: <code>&quot;abc&quot; -&gt; &quot;bca&quot;</code>.</li>
	<li>Increment <code>&#39;a&#39;</code> to <code>&#39;b&#39;</code>: <code>&quot;bca&quot; -&gt; &quot;bcb&quot;</code>.</li>
	<li><code>&quot;bcb&quot;</code> is a palindrome. Thus, the answer is 2.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;yb&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Increment the first character three times: <code>&quot;yb&quot; -&gt; &quot;zb&quot; -&gt; &quot;ab&quot; -&gt; &quot;bb&quot;</code>.</li>
	<li><code>&quot;bb&quot;</code> is a palindrome. Thus, the answer is 3.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s​​​​​​​​​​​​​​</code> consists only of lowercase English letters.</li>
</ul>

<p>&nbsp;</p>
<style type="text/css">.spoilerbutton {display:block; border:dashed; padding: 0px 0px; margin:10px 0px; font-size:150%; font-weight: bold; color:#000000; background-color:cyan; outline:0; 
}
.spoiler {overflow:hidden;}
.spoiler > div {-webkit-transition: all 0s ease;-moz-transition: margin 0s ease;-o-transition: all 0s ease;transition: margin 0s ease;}
.spoilerbutton[value="Show Message"] + .spoiler > div {margin-top:-500%;}
.spoilerbutton[value="Hide Message"] + .spoiler {padding:5px;}
</style>
<input class="spoilerbutton" onclick="this.value=this.value=='Show Message'?'Hide Message':'Show Message';" type="button" value="Show Message" />
<div class="spoiler">
<div>Model: O(N), TLE: O(N^2)
<p><!-- Please add your message here. --></p>

<pre style="margin-top:-1em; max-height:400px; overflow-y:auto;">
#generator
#absolute-mess

import random
def pr(s):       
    file.write(f&#39;&quot;{s}&quot;\n&#39;)
    
def generate_tests(n):
    s = &#39;&#39;.join(random.choice(&#39;abcdefghijklmnopqrstuvxyz&#39;) for _ in range(n))
    return s

def examples():
    pr(&quot;abc&quot;)
    pr(&quot;yb&quot;)

def hiddenCases():
    pr(&quot;aa&quot;); pr(&quot;az&quot;); pr(&quot;za&quot;); pr(&quot;ba&quot;); 
    pr(&quot;bcbaa&quot;); pr(&quot;bcdedcbaa&quot;); pr(&quot;dcbaabcdd&quot;)
    pr(&quot;k&quot;*1000); pr(&quot;i&quot;*999); pr(&quot;az&quot;*500); pr(&quot;kl&quot;*500)
    pr(&quot;abccba&quot;); pr(&quot;abcba&quot;); pr(&quot;a&quot;+&quot;b&quot;*998+&quot;a&quot;)
    pr(&quot;abcdefghijklmnopqrstuvwxyz&quot;*38)
    pr(&quot;aw&quot;+&quot;a&quot;*998); pr(&quot;wwwwww&quot;)

test_cases = []
def testCases(ranges):
    for a, b, cnt in ranges:
        for _ in range(cnt):
            test_cases.append(generate_tests(random.randint(a, b)))
    

with open(&#39;test.txt&#39;, &#39;w&#39;) as file:
    random.seed(2024+9+8)
    examples()
    testCases([
        (2, 10, 325),
        (11, 20, 250),
        (21, 50, 200),
        (50, 100, 150),
        (101, 300, 30),
        (301, 500, 15),
        (100, 1000, 10)
    ])
    test_cases.sort(key=lambda x: len(x))
    for s in test_cases:
        pr(s)
    hiddenCases()

</pre>
</div>
</div>
