<h2><a href="https://leetcode.com/problems/clumsy-factorial/">1006. Clumsy Factorial</a></h2><h3>Medium</h3><hr><div><p><code>n</code><font> is the product of all positive integers less than or equal to </font><code>n</code><font>.</font></p>

<ul>
	<li><font>For example, </font><code>factorial(10) = 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1</code><font>.</font></li>
</ul>

<p><code>'*'</code><font>, divide </font><code>'/'</code><font>, add </font><code>'+'</code><font>, and subtract </font><code>'-'</code><font> in this order.</font></p>

<ul>
	<li><font papago-id="11" papago-translate="translated">For example, </font><code>clumsy(10) = 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1</code><font papago-id="12" papago-translate="translated">.</font></li>
</ul>

<p papago-id="13" papago-translate="translated">However, these operations are still applied using the usual order of operations of arithmetic. We do all multiplication and division steps before any addition or subtraction steps, and multiplication and division steps are processed left to right.</p>

<p><font papago-id="14" papago-translate="translated">Additionally, the division that we use is floor division such that </font><code>10 * 9 / 8 = 90 / 8 = 11</code><font papago-id="15" papago-translate="translated">.</font></p>

<p><font papago-id="16" papago-translate="translated">Given an integer </font><code>n</code><code>n</code><font papago-id="17" papago-translate="translated">.</font></p>

<p>&nbsp;</p>
<p><strong papago-id="18" papago-translate="translated">Example 1:</strong></p>

<pre papago-id="19" papago-translate="cached"><strong papago-id="19-0">Input:</strong> n = 4
<strong papago-id="19-2">Output:</strong> 7
<strong papago-id="19-4">Explanation:</strong> 7 = 4 * 3 / 2 + 1
</pre>

<p><strong papago-id="20" papago-translate="translated">Example 2:</strong></p>

<pre papago-id="21" papago-translate="cached"><strong papago-id="21-0">Input:</strong> n = 10
<strong papago-id="21-2">Output:</strong> 12
<strong papago-id="21-4">Explanation:</strong> 12 = 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1
</pre>

<p>&nbsp;</p>
<p><strong papago-id="22" papago-translate="translated">Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
</ul>
</div>