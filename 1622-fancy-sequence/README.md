<h2><a href="https://leetcode.com/problems/fancy-sequence/">1622. Fancy Sequence</a></h2><h3>Hard</h3><hr><div><p><font papago-translate="cached" papago-id="0">Write an API that generates fancy sequences using the </font><code>append</code><font papago-translate="cached" papago-id="1">, </font><code>addAll</code><font papago-translate="cached" papago-id="2">, and </font><code>multAll</code><font papago-translate="cached" papago-id="3"> operations.</font></p>

<p><font papago-translate="cached" papago-id="4">Implement the </font><code>Fancy</code><font papago-translate="cached" papago-id="5"> class:</font></p>

<ul>
	<li><code>Fancy()</code><font papago-translate="cached" papago-id="6"> Initializes the object with an empty sequence.</font></li>
	<li><code>void append(val)</code><font papago-translate="cached" papago-id="7"> Appends an integer </font><code>val</code><font papago-translate="cached" papago-id="8"> to the end of the sequence.</font></li>
	<li><code>void addAll(inc)</code><font papago-translate="cached" papago-id="9"> Increments all existing values in the sequence by an integer </font><code>inc</code><font papago-translate="cached" papago-id="10">.</font></li>
	<li><code>void multAll(m)</code><font papago-translate="cached" papago-id="11"> Multiplies all existing values in the sequence by an integer </font><code>m</code><font papago-translate="cached" papago-id="12">.</font></li>
	<li><code>int getIndex(idx)</code><font papago-translate="cached" papago-id="13"> Gets the current value at index </font><code>idx</code> <code>10<sup>9</sup> + 7</code><font papago-translate="cached" papago-id="15">. If the index is greater or equal than the length of the sequence, return </font><code>-1</code><font papago-translate="cached" papago-id="16">.</font></li>
</ul>

<p>&nbsp;</p>
<p><strong papago-id="28" papago-translate="translated">Example 1:</strong></p>

<pre papago-id="29" papago-translate="cached"><strong papago-id="29-0">Input</strong>
["Fancy", "append", "addAll", "append", "multAll", "getIndex", "addAll", "append", "multAll", "getIndex", "getIndex", "getIndex"]
[[], [2], [3], [7], [2], [0], [3], [10], [2], [0], [1], [2]]
<strong papago-id="29-2">Output</strong>
[null, null, null, null, null, 10, null, null, null, 26, 34, 20]

<strong papago-id="29-4">Explanation</strong>
Fancy fancy = new Fancy();
fancy.append(2);   // fancy sequence: [2]
fancy.addAll(3);   // fancy sequence: [2+3] -&gt; [5]
fancy.append(7);   // fancy sequence: [5, 7]
fancy.multAll(2);  // fancy sequence: [5*2, 7*2] -&gt; [10, 14]
fancy.getIndex(0); // return 10
fancy.addAll(3);   // fancy sequence: [10+3, 14+3] -&gt; [13, 17]
fancy.append(10);  // fancy sequence: [13, 17, 10]
fancy.multAll(2);  // fancy sequence: [13*2, 17*2, 10*2] -&gt; [26, 34, 20]
fancy.getIndex(0); // return 26
fancy.getIndex(1); // return 34
fancy.getIndex(2); // return 20
</pre>

<p>&nbsp;</p>
<p><strong papago-id="30" papago-translate="translated">Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= val, inc, m &lt;= 100</code></li>
	<li><code>0 &lt;= idx &lt;= 10<sup>5</sup></code></li>
	<li><font papago-translate="cached" papago-id="17">At most </font><code>10<sup>5</sup></code><font papago-translate="cached" papago-id="18"> calls total will be made to </font><code>append</code><font papago-translate="cached" papago-id="19">, </font><code>addAll</code><font papago-translate="cached" papago-id="20">, </font><code>multAll</code><font papago-translate="cached" papago-id="21">, and </font><code>getIndex</code><font papago-translate="cached" papago-id="22">.</font></li>
</ul>
</div>