<h2><a href="https://leetcode.com/problems/number-of-unique-categories/">2782. Number of Unique Categories</a></h2><h3>Medium</h3><hr><div><p><font papago-translate="splitted">You are given an integer </font><code>n</code><font papago-translate="splitted"> and an object </font><code>categoryHandler</code><font papago-translate="splitted"> of class </font><code>CategoryHandler</code><font papago-translate="splitted">.</font></p>

<p><font papago-translate="splitted">There are </font><code>n&nbsp;</code><font papago-translate="splitted">elements, numbered from </font><code>0</code><font papago-translate="splitted"> to </font><code>n - 1</code><font papago-translate="splitted">. Each element has a category, and your task is to find the number of unique categories.</font></p>

<p><font papago-translate="splitted">The class </font><code>CategoryHandler</code><font papago-translate="splitted"> contains the following function, which may help you:</font></p>

<ul>
	<li><code>boolean haveSameCategory(integer a, integer b)</code><font papago-translate="splitted">: Returns </font><code>true</code><font papago-translate="splitted"> if </font><code>a</code><font papago-translate="splitted"> and </font><code>b</code><font papago-translate="splitted"> are in the same category and </font><code>false</code><font papago-translate="splitted"> otherwise. Also, if either </font><code>a</code><font papago-translate="splitted"> or </font><code>b</code><font papago-translate="splitted"> is not a valid number (i.e. it's greater than or equal to </font><code>n</code><font papago-translate="splitted">or less than </font><code>0</code><font papago-translate="splitted">), it returns </font><code>false</code><font papago-translate="splitted">.</font></li>
</ul>

<p>Return <em>the number of unique categories.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> n = 6, categoryHandler = [1,1,2,2,3,3]
<strong>Output:</strong> 3
<strong>Explanation:</strong> There are 6 elements in this example. The first two elements belong to category 1, the second two belong to category 2, and the last two elements belong to category 3. So there are 3 unique categories.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> n = 5, categoryHandler = [1,2,3,4,5]
<strong>Output:</strong> 5
<strong>Explanation:</strong> There are 5 elements in this example. Each element belongs to a unique category. So there are 5 unique categories.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> n = 3, categoryHandler = [1,1,1]
<strong>Output:</strong> 1
<strong>Explanation:</strong> There are 3 elements in this example. All of them belong to one category. So there is only 1 unique category.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
</ul>
</div>