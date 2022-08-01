<h2><a href="https://leetcode.com/problems/tag-validator/">591. Tag Validator</a></h2><h3>Hard</h3><hr><div><p>Given a string representing a code snippet, implement a tag validator to parse the code and return whether it is valid.</p>

<p>A code snippet is valid if all the following rules hold:</p>

<ol>
	<li>The code must be wrapped in a <b>valid closed tag</b>. Otherwise, the code is invalid.</li>
	<li><font papago-translate="cached" papago-id="0">A <b papago-id="0-1">closed tag</b> (not necessarily valid) has exactly the following format : </font><code>&lt;TAG_NAME&gt;TAG_CONTENT&lt;/TAG_NAME&gt;</code><font papago-translate="cached" papago-id="11">. Among them, </font><code>&lt;TAG_NAME&gt;</code><font papago-translate="cached" papago-id="12"> is the start tag, and </font><code>&lt;/TAG_NAME&gt;</code></li>
	<li> <code>TAG_NAME</code><code>TAG_NAME</code></li>
	<li> <code>TAG_CONTENT</code><code>&lt;</code><font papago-translate="cached" papago-id="19">, unmatched start and end tag, and unmatched or closed tags with invalid TAG_NAME. Otherwise, the </font><code>TAG_CONTENT</code></li>
	<li papago-id="21" papago-translate="translated">A start tag is unmatched if no end tag exists with the same TAG_NAME, and vice versa. However, you also need to consider the issue of unbalanced when tags are nested.</li>
	<li><font papago-translate="splited">A </font><code>&lt;</code><font papago-translate="cached" papago-id="22"> is unmatched if you cannot find a subsequent </font><code>&gt;</code><font papago-translate="cached" papago-id="23">. And when you find a </font><code>&lt;</code><font papago-translate="cached" papago-id="24"> or </font><code>&lt;/</code><font papago-translate="cached" papago-id="25">, all the subsequent characters until the next </font><code>&gt;</code><font papago-translate="cached" papago-id="26"> should be parsed as TAG_NAME (not necessarily valid).</font></li>
	<li><font papago-translate="cached" papago-id="27">The cdata has the following format : </font><code>&lt;![CDATA[CDATA_CONTENT]]&gt;</code><font papago-translate="cached" papago-id="28">. The range of </font><code>CDATA_CONTENT</code><font papago-translate="cached" papago-id="29"> is defined as the characters between </font><code>&lt;![CDATA[</code> <code>]]&gt;</code><font papago-translate="cached" papago-id="31">.</font></li>
	<li><code>CDATA_CONTENT</code><code>CDATA_CONTENT</code></li>
</ol>

<p>&nbsp;</p>
<p><strong papago-id="34" papago-translate="translated">Example 1:</strong></p>

<pre><strong>Input:</strong> code = "&lt;DIV&gt;This is the first line &lt;![CDATA[&lt;div&gt;]]&gt;&lt;/DIV&gt;"
<strong>Output:</strong> true
<strong>Explanation:</strong> 
The code is wrapped in a closed tag : &lt;DIV&gt; and &lt;/DIV&gt;. 
The TAG_NAME is valid, the TAG_CONTENT consists of some characters and cdata. 
Although CDATA_CONTENT has an unmatched start tag with invalid TAG_NAME, it should be considered as plain text, not parsed as a tag.
So TAG_CONTENT is valid, and then the code is valid. Thus return true.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> code = "&lt;DIV&gt;&gt;&gt;  ![cdata[]] &lt;![CDATA[&lt;div&gt;]&gt;]]&gt;]]&gt;&gt;]&lt;/DIV&gt;"
<strong>Output:</strong> true
<strong>Explanation:</strong>
We first separate the code into : start_tag|tag_content|end_tag.
start_tag -&gt; <b>"&lt;DIV&gt;"</b>
end_tag -&gt; <b>"&lt;/DIV&gt;"</b>
tag_content could also be separated into : text1|cdata|text2.
text1 -&gt; <b>"&gt;&gt;  ![cdata[]] "</b>
cdata -&gt; <b>"&lt;![CDATA[&lt;div&gt;]&gt;]]&gt;"</b>, where the CDATA_CONTENT is <b>"&lt;div&gt;]&gt;"</b>
text2 -&gt; <b>"]]&gt;&gt;]"</b>
The reason why start_tag is NOT <b>"&lt;DIV&gt;&gt;&gt;"</b> is because of the rule 6.
The reason why cdata is NOT <b>"&lt;![CDATA[&lt;div&gt;]&gt;]]&gt;]]&gt;"</b> is because of the rule 7.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> code = "&lt;A&gt;  &lt;B&gt; &lt;/A&gt;   &lt;/B&gt;"
<strong>Output:</strong> false
<strong>Explanation:</strong> Unbalanced. If "&lt;A&gt;" is closed, then "&lt;B&gt;" must be unmatched, and vice versa.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= code.length &lt;= 500</code></li>
	<li><code>code</code><font papago-translate="translated" papago-id="23"> consists of English letters, digits, </font><code>'&lt;'</code><font papago-translate="translated" papago-id="24">, </font><code>'&gt;'</code><font papago-translate="translated" papago-id="25">, </font><code>'/'</code><font papago-translate="translated" papago-id="26">, </font><code>'!'</code><font papago-translate="translated" papago-id="27">, </font><code>'['</code><font papago-translate="translated" papago-id="28">, </font><code>']'</code><font papago-translate="translated" papago-id="29">, </font><code>'.'</code><font papago-translate="translated" papago-id="30">, and </font><code>' '</code><font papago-translate="translated" papago-id="31">.</font></li>
</ul>
</div>