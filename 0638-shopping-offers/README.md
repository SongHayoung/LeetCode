<h2><a href="https://leetcode.com/problems/shopping-offers/">638. Shopping Offers</a></h2><h3>Medium</h3><hr><div><p><font papago-translate="splitted">In LeetCode Store, there are </font><code>n</code><font papago-translate="splitted"> items to sell. Each item has a price. However, there are some special offers, and a special offer consists of one or more different kinds of items with a sale price.</font></p>

<p><font papago-translate="splitted">You are given an integer array </font><code>price</code><font papago-translate="splitted"> where </font><code>price[i]</code><font papago-translate="splitted"> is the price of the </font><code>i<sup>th</sup></code><font papago-translate="splitted"> item, and an integer array </font><code>needs</code><font papago-translate="splitted"> where </font><code>needs[i]</code><font papago-translate="splitted"> is the number of pieces of the </font><code>i<sup>th</sup></code><font papago-translate="splitted"> item you want to buy.</font></p>

<p><font papago-translate="splitted">You are also given an array </font><code>special</code><font papago-translate="splitted"> where </font><code>special[i]</code><font papago-translate="splitted"> is of size </font><code>n + 1</code><font papago-translate="splitted"> where </font><code>special[i][j]</code><font papago-translate="splitted"> is the number of pieces of the </font><code>j<sup>th</sup></code><font papago-translate="splitted"> item in the </font><code>i<sup>th</sup></code><font papago-translate="splitted"> offer and </font><code>special[i][n]</code><font papago-translate="splitted"> (i.e., the last integer in the array) is the price of the </font><code>i<sup>th</sup></code><font papago-translate="splitted"> offer.</font></p>

<p>Return <em>the lowest price you have to pay for exactly certain items as given, where you could make optimal use of the special offers</em>. You are not allowed to buy more items than you want, even if that would lower the overall price. You could use any of the special offers as many times as you want.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> price = [2,5], special = [[3,0,5],[1,2,10]], needs = [3,2]
<strong>Output:</strong> 14
<strong>Explanation:</strong> There are two kinds of items, A and B. Their prices are $2 and $5 respectively. 
In special offer 1, you can pay $5 for 3A and 0B
In special offer 2, you can pay $10 for 1A and 2B. 
You need to buy 3A and 2B, so you may pay $10 for 1A and 2B (special offer #2), and $4 for 2A.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> price = [2,3,4], special = [[1,1,0,4],[2,2,1,9]], needs = [1,2,1]
<strong>Output:</strong> 11
<strong>Explanation:</strong> The price of A is $2, and $3 for B, $4 for C. 
You may pay $4 for 1A and 1B, and $9 for 2A ,2B and 1C. 
You need to buy 1A ,2B and 1C, so you may pay $4 for 1A and 1B (special offer #1), and $3 for 1B, $4 for 1C. 
You cannot add more items, though only $9 for 2A ,2B and 1C.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == price.length == needs.length</code></li>
	<li><code>1 &lt;= n &lt;= 6</code></li>
	<li><code>0 &lt;= price[i], needs[i] &lt;= 10</code></li>
	<li><code>1 &lt;= special.length &lt;= 100</code></li>
	<li><code>special[i].length == n + 1</code></li>
	<li><code>0 &lt;= special[i][j] &lt;= 50</code></li>
</ul>
</div>