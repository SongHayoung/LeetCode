<h2><a href="https://leetcode.com/problems/good-subsequence-queries/">4215. Good Subsequence Queries</a></h2><h3>Hard</h3><hr><p>You are given an integer array <code>nums</code> of length <code>n</code> and an integer <code>p</code>.</p>

<p>A <strong>non-empty subsequence</strong> of <code>nums</code> is called <strong>good</strong> if:</p>

<ul>
	<li>Its length is <strong>strictly less</strong> than <code>n</code>.</li>
	<li>The <strong>greatest common divisor (GCD)</strong> of its elements is <strong>exactly</strong> <code>p</code>.</li>
</ul>

<p>You are also given a 2D integer array <code>queries</code> of length <code>q</code>, where each <code>queries[i] = [ind<sub>i</sub>, val<sub>i</sub>]</code> indicates that you should set <code>nums[ind<sub>i</sub>]</code> to <code>val<sub>i</sub></code>.</p>

<p>After each query, determine whether there exists <strong>any good subsequence</strong> in the current array.</p>

<p>Return the <strong>number</strong> of queries for which a <strong>good subsequence</strong> exists.</p>

<p>A <strong>subsequence</strong> is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.</p>
The term <code>gcd(a, b)</code> denotes the <strong>greatest common divisor</strong> of <code>a</code> and <code>b</code>.
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [4,8,12,16], p = 2, queries = [[0,3],[2,6]]</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<table border="1" bordercolor="#ccc" cellpadding="5" cellspacing="0" style="border-collapse:collapse;">
	<thead>
		<tr>
			<th>i</th>
			<th><code>[ind<sub>i</sub>, val<sub>i</sub>]</code></th>
			<th>Operation</th>
			<th>Updated <code>nums</code></th>
			<th>Any good Subsequence</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>0</td>
			<td><code>[0, 3]</code></td>
			<td>Replace <code>nums[0]</code> with <code>3</code></td>
			<td><code>[3, 8, 12, 16]</code></td>
			<td>No, as no subsequence has GCD exactly <code>p = 2</code></td>
		</tr>
		<tr>
			<td>1</td>
			<td><code>[2, 6]</code></td>
			<td>Replace <code>nums[2]</code> with <code>6</code></td>
			<td><code>[3, 8, 6, 16]</code></td>
			<td>Yes, subsequence <code>[8, 6]</code> has GCD exactly <code>p = 2</code></td>
		</tr>
	</tbody>
</table>

<p>Thus, the answer is 1.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [4,5,7,8], p = 3, queries = [[0,6],[1,9],[2,3]]</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<table border="1" bordercolor="#ccc" cellpadding="5" cellspacing="0" style="border-collapse:collapse;">
	<thead>
		<tr>
			<th>i</th>
			<th><code>[ind<sub>i</sub>, val<sub>i</sub>]</code></th>
			<th>Operation</th>
			<th>Updated <code>nums</code></th>
			<th>Any good Subsequence</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>0</td>
			<td><code>[0, 6]</code></td>
			<td>Replace <code>nums[0]</code> with <code>6</code></td>
			<td><code>[6, 5, 7, 8]</code></td>
			<td>No, as no subsequence has GCD exactly <code>p = 3</code></td>
		</tr>
		<tr>
			<td>1</td>
			<td><code>[1, 9]</code></td>
			<td>Replace <code>nums[1]</code> with <code>9</code></td>
			<td><code>[6, 9, 7, 8]</code></td>
			<td>Yes, subsequence <code>[6, 9]</code> has GCD exactly <code>p = 3</code></td>
		</tr>
		<tr>
			<td>2</td>
			<td><code>[2, 3]</code></td>
			<td>Replace <code>nums[2]</code> with <code>3</code></td>
			<td><code>[6, 9, 3, 8]</code></td>
			<td>Yes, subsequence <code>[6, 9, 3]</code> has GCD exactly <code>p = 3</code></td>
		</tr>
	</tbody>
</table>

<p>Thus, the answer is 2.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [5,7,9], p = 2, queries = [[1,4],[2,8]]</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<table border="1" bordercolor="#ccc" cellpadding="5" cellspacing="0" style="border-collapse:collapse;">
	<thead>
		<tr>
			<th>i</th>
			<th><code>[ind<sub>i</sub>, val<sub>i</sub>]</code></th>
			<th>Operation</th>
			<th>Updated <code>nums</code></th>
			<th>Any good Subsequence</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>0</td>
			<td><code>[1, 4]</code></td>
			<td>Replace <code>nums[1]</code> with <code>4</code></td>
			<td><code>[5, 4, 9]</code></td>
			<td>No, as no subsequence has GCD exactly <code>p = 2</code></td>
		</tr>
		<tr>
			<td>1</td>
			<td><code>[2, 8]</code></td>
			<td>Replace <code>nums[2]</code> with <code>8</code></td>
			<td><code>[5, 4, 8]</code></td>
			<td>No, as no subsequence has GCD exactly <code>p = 2</code></td>
		</tr>
	</tbody>
</table>

<p>Thus, the answer is 0.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n == nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>queries[i] = [ind<sub>i</sub>, val<sub>i</sub>]</code></li>
	<li><code>1 &lt;= val<sub>i</sub>, p &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= ind<sub>i</sub> &lt;= n - 1</code></li>
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
Model: N+Q log N, TLE : Q x N

<pre>
#generator
#absolute-mess

import random

def pr(nums, p, queries):
    file.write(f&quot;{str(nums).replace(&#39; &#39;, &#39;&#39;)}\n&quot;)
    file.write(f&quot;{p}\n&quot;)
    file.write(f&quot;{str(queries).replace(&#39; &#39;, &#39;&#39;)}\n&quot;)

def generate_tests(n, q):
    nums = [random.randint(1, min(n*n+5, 10**5)) for i in range(n)]
    p = random.randint(1, min(n*n+5, 10**5))
    queries = []
    for i in range(q):
        ind = random.randint(0, n - 1)
        val = random.randint(1, min(n*n+5, 10**5))
        queries.append([ind, val])
    return (nums, p, queries)

def examples():
    pr([4, 8, 12, 16], 2, [[0, 3], [2, 6]])
    pr([4,5,7,8],3,[[0, 6], [1, 9], [2, 3]])
    pr([5, 7, 9], 2, [[1,4],[2,8]])

def hiddenCases():
    pr([2] * 100000, 1, [[i, 2] for i in range(100000)])
    pr([2,3],1,[[0,4],[1,6]])
    pr([6,10,15],1,[[0,30]])
    pr([1],1,[[0,2],[0,3]])
    pr([100000,100000],100000,[[0,100000]])
    pr([60,29,99,19,55,21], 2, [[4,40],[2,49],[2,62],[4,29],[2,83],[5,25],[0,93],[4,29],[0,59],[2,32],[4,47],[5,10],[5,42],[2,5],[2,22],[2,60],[0,9],[0,41],[0,59],[1,27],[0,56],[1,82],[4,54],[0,57],[4,13],[1,87],[2,45],[3,91],[1,56],[4,44],[0,27],[2,49],[3,89],[2,67],[3,80],[4,27],[3,17],[1,86],[1,27],[0,79],[4,41],[3,99],[3,94],[4,29],[4,16],[4,77],[0,21],[0,74],[3,21],[2,41],[5,32],[2,63],[2,31],[1,31],[4,98],[3,39],[4,12],[5,66],[4,8],[5,21],[4,41],[5,95],[0,43],[0,88],[3,15],[3,10],[1,17],[4,55],[1,100],[1,87],[3,19],[0,71],[5,21],[0,60],[1,13],[2,99],[1,29]])
    pr([1] * 49999 + [3], 1, [[49999,1] for _ in range(50000)])
    n = 50000
    queries = [[i, 99982] for i in range(n-1)]
    queries.append([0, 49991])        
    pr([10, 15], 5, [[0, 10]])
    pr([5, 10], 5, [[0, 10]])

    N = 80000
    Q = 80000
    p = 7
    nums = [p * random.randint(1, 1000) for _ in range(N)]
    queries = [[random.randint(0, N-1), p * random.randint(1, 1000)] for _ in range(Q)]
    pr(nums, p, queries)
    
    pr([31], 93,[[0,86],[0,20],[0,61],[0,100],[0,51],[0,7],[0,53],[0,62],[0,2],[0,82],[0,81],[0,10],[0,70],[0,16],[0,36],[0,69],[0,52],[0,87],[0,74],[0,83],[0,86],[0,83],[0,96],[0,26],[0,46],[0,5],[0,68],[0,21],[0,16],[0,66],[0,39],[0,41],[0,48],[0,51],[0,61],[0,57],[0,21],[0,31],[0,50],[0,1],[0,98],[0,47],[0,42],[0,81],[0,69],[0,56],[0,98],[0,65],[0,73],[0,74],[0,86],[0,23],[0,93],[0,11],[0,91],[0,16],[0,80],[0,60],[0,59],[0,95],[0,59],[0,95],[0,59],[0,7],[0,19],[0,66],[0,43]])
    pr([26,73,94,58], 3, [[3,32],[3,54],[2,61],[1,52],[2,74],[1,55],[3,89],[1,94],[3,45],[3,95],[0,47],[2,72],[3,87],[3,66],[1,5],[0,15],[3,96],[3,45],[0,30],[0,95],[2,72],[2,9],[0,85],[1,26],[3,63],[0,42],[3,85],[2,37],[3,35],[3,85],[0,41],[2,89],[3,11],[1,82],[2,24],[1,28],[0,91],[3,45],[2,95],[2,81],[3,71],[3,62],[3,44],[0,75],[1,92],[3,31],[0,26],[1,31],[1,9],[0,31],[0,66],[1,88],[1,40],[0,90],[1,35],[1,33],[1,33],[3,17],[1,92],[0,67],[2,65],[3,19],[2,43],[3,5],[0,85],[0,85],[3,66],[0,17],[3,100],[1,51],[3,85],[2,55],[3,58],[2,64],[2,39],[2,94],[1,73],[0,26]])

test_cases = []

def testCases(ranges):
    for min_n, max_n, numCases in ranges:
        for _ in range(numCases):
            n = random.randint(min_n, max_n)
            q = random.randint(1, min(n//2, min(n+10, 5*10**4)))
            test_cases.append(generate_tests(n, q))

with open(&#39;test.txt&#39;, &#39;w&#39;) as file:
    random.seed(9 + 8 + 2024)
    examples()
    ranges = [
        (2, 10, 300),
        (11, 20, 250),
        (21, 50, 200),
        (51, 100, 150),
        (5, 100, 40),
        (101, 500, 20),
        (501, 1000, 10),
        (1001, 10000, 10),
        (10001, 30000, 3),
        (30000, 50000, 2)
    ]
    testCases(ranges)
    test_cases.sort(key=lambda x: x[0])
    for nums, p, queries in test_cases:
        pr(nums, p, queries)
    hiddenCases()

</pre>
</div>
</div>
