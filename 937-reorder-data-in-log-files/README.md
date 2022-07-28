<h2><a href="https://leetcode.com/problems/reorder-data-in-log-files/">937. Reorder Data in Log Files</a></h2><h3>Medium</h3><hr><div><p><font papago-id="1" papago-translate="translated">You are given an array of </font><code>logs</code></p>

<p papago-id="0" papago-translate="translated">There are two types of logs:</p>

<ul>
	<li papago-id="11" papago-translate="cached"><b papago-id="11-0">Letter-logs</b>: All words (except the identifier) consist of lowercase English letters.</li>
	<li papago-id="12" papago-translate="cached"><strong papago-id="12-0">Digit-logs</strong>: All words (except the identifier) consist of digits.</li>
</ul>

<p papago-id="13" papago-translate="translated">Reorder these logs so that:</p>

<ol>
	<li papago-id="14" papago-translate="cached">The <strong papago-id="14-1">letter-logs</strong> come before all <strong papago-id="14-3">digit-logs</strong>.</li>
	<li papago-id="15" papago-translate="cached">The <strong papago-id="15-1">letter-logs</strong> are sorted lexicographically by their contents. If their contents are the same, then sort them lexicographically by their identifiers.</li>
	<li papago-id="16" papago-translate="cached">The <strong papago-id="16-1">digit-logs</strong> maintain their relative ordering.</li>
</ol>

<p papago-id="17" papago-translate="cached">Return <em papago-id="17-1">the final order of the logs</em>.</p>

<p>&nbsp;</p>
<p><strong papago-id="18" papago-translate="translated">Example 1:</strong></p>

<pre papago-id="19" papago-translate="cached"><strong papago-id="19-0">Input:</strong> logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
<strong papago-id="19-2">Output:</strong> ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
<strong papago-id="19-4">Explanation:</strong>
The letter-log contents are all different, so their ordering is "art can", "art zero", "own kit dig".
The digit-logs have a relative order of "dig1 8 1 5 1", "dig2 3 6".
</pre>

<p><strong papago-id="20" papago-translate="translated">Example 2:</strong></p>

<pre papago-id="0" papago-translate="cached"><strong papago-id="0-0">Input:</strong> logs = ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
<strong papago-id="0-2">Output:</strong> ["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= logs.length &lt;= 100</code></li>
	<li><code>3 &lt;= logs[i].length &lt;= 100</code></li>
	<li><font>All the tokens of </font><code>logs[i]</code><font> are separated by a <strong papago-id="3-1">single</strong> space.</font></li>
	<li><code>logs[i]</code><font> is guaranteed to have an identifier and at least one word after the identifier.</font></li>
</ul>
</div>