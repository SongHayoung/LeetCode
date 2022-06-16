<h2><a href="https://leetcode.com/problems/swap-for-longest-repeated-character-substring/">1156. Swap For Longest Repeated Character Substring</a></h2><h3>Medium</h3><hr><div><p><font papago-translate="cached" papago-id="15">You are given a string </font><code>text</code><font papago-translate="cached" papago-id="16">. You can swap two of the characters in the </font><code>text</code><font papago-translate="cached" papago-id="17">.</font></p>

<p papago-id="18" papago-translate="cached">Return <em papago-id="18-1">the length of the longest substring with repeated characters</em>.</p>

<p>&nbsp;</p>
<p><strong papago-id="19" papago-translate="translated">Example 1:</strong></p>

<pre papago-id="20" papago-translate="cached"><strong papago-id="20-0">Input:</strong> text = "ababa"
<strong papago-id="20-2">Output:</strong> 3
<strong papago-id="20-4">Explanation:</strong> We can swap the first 'b' with the last 'a', or the last 'b' with the first 'a'. Then, the longest repeated character substring is "aaa" with length 3.
</pre>

<p><strong papago-id="21" papago-translate="translated">Example 2:</strong></p>

<pre papago-id="22" papago-translate="cached"><strong papago-id="22-0">Input:</strong> text = "aaabaaa"
<strong papago-id="22-2">Output:</strong> 6
<strong papago-id="22-4">Explanation:</strong> Swap 'b' with the last 'a' (or the first 'a'), and we get longest repeated character substring "aaaaaa" with length 6.
</pre>

<p><strong papago-id="23" papago-translate="translated">Example 3:</strong></p>

<pre papago-id="24" papago-translate="cached"><strong papago-id="24-0">Input:</strong> text = "aaaaa"
<strong papago-id="24-2">Output:</strong> 5
<strong papago-id="24-4">Explanation:</strong> No need to swap, longest repeated character substring is "aaaaa" with length is 5.
</pre>

<p>&nbsp;</p>
<p><strong papago-id="0" papago-translate="translated">Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= text.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>text</code><font papago-translate="translated" papago-id="3"> consist of lowercase English characters only.</font></li>
</ul>
</div>