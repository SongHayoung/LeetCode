<h2><a href="https://leetcode.com/problems/iterator-for-combination/">1286. Iterator for Combination</a></h2><h3>Medium</h3><hr><div><p><font papago-translate="cached" papago-id="15">Design the </font><code>CombinationIterator</code><font papago-translate="cached" papago-id="16"> class:</font></p>

<ul>
	<li><code>CombinationIterator(string characters, int combinationLength)</code><font papago-translate="cached" papago-id="17"> Initializes the object with a string </font><code>characters</code><code>combinationLength</code><font papago-translate="cached" papago-id="19"> as arguments.</font></li>
	<li><code>next()</code><font papago-translate="cached" papago-id="20"> Returns the next combination of length </font><code>combinationLength</code></li>
	<li><code>hasNext()</code><font papago-translate="cached" papago-id="22"> Returns </font><code>true</code><font papago-translate="cached" papago-id="23"> if and only if there exists a next combination.</font></li>
</ul>

<p>&nbsp;</p>
<p><strong papago-id="24" papago-translate="translated">Example 1:</strong></p>

<pre papago-id="25" papago-translate="cached"><strong papago-id="25-0">Input</strong>
["CombinationIterator", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[["abc", 2], [], [], [], [], [], []]
<strong papago-id="25-2">Output</strong>
[null, "ab", true, "ac", true, "bc", false]

<strong papago-id="25-4">Explanation</strong>
CombinationIterator itr = new CombinationIterator("abc", 2);
itr.next();    // return "ab"
itr.hasNext(); // return True
itr.next();    // return "ac"
itr.hasNext(); // return True
itr.next();    // return "bc"
itr.hasNext(); // return False
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= combinationLength &lt;= characters.length &lt;= 15</code></li>
	<li><font papago-translate="translated" papago-id="9">All the characters of </font><code>characters</code><font papago-translate="cached" papago-id="10"> are <strong papago-id="10-1">unique</strong>.</font></li>
	<li><font papago-translate="translated" papago-id="11">At most </font><code>10<sup>4</sup></code><font papago-translate="translated" papago-id="12"> calls will be made to </font><code>next</code><font papago-translate="translated" papago-id="13"> and </font><code>hasNext</code><font papago-translate="translated" papago-id="14">.</font></li>
	<li><font papago-translate="translated" papago-id="15">It is guaranteed that all calls of the function </font><code>next</code><font papago-translate="translated" papago-id="16"> are valid.</font></li>
</ul>
</div>