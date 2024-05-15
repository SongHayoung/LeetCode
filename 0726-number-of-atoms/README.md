<h2><a href="https://leetcode.com/problems/number-of-atoms/">726. Number of Atoms</a></h2><h3>Hard</h3><hr><div><p><font papago-translate="splitted">Given a string </font><code>formula</code></p>

<p>The atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.</p>

<p><font papago-translate="splitted">One or more digits representing that element's count may follow if the count is greater than </font><code>1</code><font papago-translate="splitted">. If the count is </font><code>1</code><font papago-translate="splitted">, no digits will follow.</font></p>

<ul>
	<li><font papago-translate="splitted">For example, </font><code>"H2O"</code><font papago-translate="splitted"> and </font><code>"H2O2"</code><font papago-translate="splitted"> are possible, but </font><code>"H1O2"</code><font papago-translate="splitted"> is impossible.</font></li>
</ul>

<p>Two formulas are concatenated together to produce another formula.</p>

<ul>
	<li><font papago-translate="splitted">For example, </font><code>"H2O2He3Mg4"</code><font papago-translate="splitted"> is also a formula.</font></li>
</ul>

<p>A formula placed in parentheses, and a count (optionally added) is also a formula.</p>

<ul>
	<li><font papago-translate="splitted">For example, </font><code>"(H2O2)"</code><font papago-translate="splitted"> and </font><code>"(H2O2)3"</code><font papago-translate="splitted"> are formulas.</font></li>
</ul>

<p><font papago-translate="splitted">Return the count of all elements as a string in the following form: the first name (in sorted order), followed by its count (if that count is more than </font><code>1</code><font papago-translate="splitted">), followed by the second name (in sorted order), followed by its count (if that count is more than </font><code>1</code><font papago-translate="splitted">), and so on.</font></p>

<p>The test cases are generated so that all the values in the output fit in a <strong>32-bit</strong> integer.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> formula = "H2O"
<strong>Output:</strong> "H2O"
<strong>Explanation:</strong> The count of elements are {'H': 2, 'O': 1}.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> formula = "Mg(OH)2"
<strong>Output:</strong> "H2MgO2"
<strong>Explanation:</strong> The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> formula = "K4(ON(SO3)2)2"
<strong>Output:</strong> "K4N2O14S4"
<strong>Explanation:</strong> The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= formula.length &lt;= 1000</code></li>
	<li><code>formula</code><font papago-translate="splitted"> consists of English letters, digits, </font><code>'('</code><font papago-translate="splitted">, and </font><code>')'</code><font papago-translate="splitted">.</font></li>
	<li><code>formula</code><font papago-translate="splitted"> is always valid.</font></li>
</ul>
</div>