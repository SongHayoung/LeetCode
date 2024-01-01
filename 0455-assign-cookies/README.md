<h2><a href="https://leetcode.com/problems/assign-cookies/">455. Assign Cookies</a></h2><h3>Easy</h3><hr><div><p>Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.</p>

<p><font papago-translate="splitted">Each child </font><code>i</code><font papago-translate="splitted"> has a greed factor </font><code>g[i]</code><font papago-translate="splitted">, which is the minimum size of a cookie that the child will be content with; and each cookie </font><code>j</code><font papago-translate="splitted"> has a size </font><code>s[j]</code><font papago-translate="splitted">. If </font><code>s[j] &gt;= g[i]</code><font papago-translate="splitted">, we can assign the cookie </font><code>j</code><font papago-translate="splitted"> to the child </font><code>i</code><font papago-translate="splitted">, and the child </font><code>i</code><font papago-translate="splitted"> will be content. Your goal is to maximize the number of your content children and output the maximum number.</font></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> g = [1,2,3], s = [1,1]
<strong>Output:</strong> 1
<strong>Explanation:</strong> You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> g = [1,2], s = [1,2,3]
<strong>Output:</strong> 2
<strong>Explanation:</strong> You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2. 
You have 3 cookies and their sizes are big enough to gratify all of the children, 
You need to output 2.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= g.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= s.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= g[i], s[j] &lt;= 2<sup>31</sup> - 1</code></li>
</ul>
</div>