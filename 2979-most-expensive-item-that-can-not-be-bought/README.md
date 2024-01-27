<h2><a href="https://leetcode.com/problems/most-expensive-item-that-can-not-be-bought/">2979. Most Expensive Item That Can Not Be Bought</a></h2><h3>Medium</h3><hr><div><p> <code>primeOne</code><font papago-translate="splitted"> and </font><code>primeTwo</code><font papago-translate="splitted">.</font></p>

<p><code>x</code><font papago-translate="splitted"> there exists an item whose price is </font><code>x</code><code>primeOne</code><font papago-translate="splitted"> and </font><code>primeTwo</code></p>

<p>Return <em>the price of the <strong>most expensive</strong> item which Alice can not gift to Bob</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> primeOne = 2, primeTwo = 5
<strong>Output:</strong> 3
<strong>Explanation:</strong> The prices of items which cannot be bought are [1,3]. It can be shown that all items with a price greater than 3 can be bought using a combination of coins of denominations 2 and 5.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> primeOne = 5, primeTwo = 7
<strong>Output:</strong> 23
<strong>Explanation:</strong> The prices of items which cannot be bought are [1,2,3,4,6,8,9,11,13,16,18,23]. It can be shown that all items with a price greater than 23 can be bought.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt; primeOne, primeTwo &lt; 10<sup>4</sup></code></li>
	<li><code>primeOne</code><font papago-translate="splitted">, </font><code>primeTwo</code><font papago-translate="splitted"> are prime numbers.</font></li>
	<li><code>primeOne * primeTwo &lt; 10<sup>5</sup></code></li>
</ul>
</div>