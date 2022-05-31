<h2><a href="https://leetcode.com/problems/push-dominoes/">838. Push Dominoes</a></h2><h3>Medium</h3><hr><div><p><font papago-translate="cached" papago-id="15">There are </font><code>n</code><font papago-translate="cached" papago-id="16"> dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.</font></p>

<p papago-id="17" papago-translate="translated">After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.</p>

<p papago-id="18" papago-translate="translated">When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.</p>

<p papago-id="19" papago-translate="translated">For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.</p>

<p><font papago-translate="cached" papago-id="20">You are given a string </font><code>dominoes</code><font papago-translate="cached" papago-id="21"> representing the initial state where:</font></p>

<ul>
	<li><code>dominoes[i] = 'L'</code><font papago-translate="cached" papago-id="22">, if the </font><code>i<sup>th</sup></code><font papago-translate="cached" papago-id="23"> domino has been pushed to the left,</font></li>
	<li><code>dominoes[i] = 'R'</code><font papago-translate="cached" papago-id="24">, if the </font><code>i<sup>th</sup></code><font papago-translate="cached" papago-id="25"> domino has been pushed to the right, and</font></li>
	<li><code>dominoes[i] = '.'</code><font papago-translate="cached" papago-id="26">, if the </font><code>i<sup>th</sup></code><font papago-translate="cached" papago-id="27"> domino has not been pushed.</font></li>
</ul>

<p papago-id="28" papago-translate="cached">Return <em papago-id="28-1">a string representing the final state</em>.</p>

<p>&nbsp;</p>
<p><strong papago-id="29" papago-translate="translated">Example 1:</strong></p>

<pre papago-id="30" papago-translate="cached"><strong papago-id="30-0">Input:</strong> dominoes = "RR.L"
<strong papago-id="30-2">Output:</strong> "RR.L"
<strong papago-id="30-4">Explanation:</strong> The first domino expends no additional force on the second domino.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/05/18/domino.png" style="height: 196px; width: 512px;">
<pre><strong>Input:</strong> dominoes = ".L.R...LR..L.."
<strong>Output:</strong> "LL.RR.LLRRLL.."
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == dominoes.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>dominoes[i]</code><font papago-translate="translated" papago-id="10"> is either </font><code>'L'</code><font papago-translate="translated" papago-id="11">, </font><code>'R'</code><font papago-translate="translated" papago-id="12">, or </font><code>'.'</code><font papago-translate="translated" papago-id="13">.</font></li>
</ul>
</div>