<h2><a href="https://leetcode.com/problems/remove-duplicates-from-sorted-array/">26. Remove Duplicates from Sorted Array</a></h2><h3>Easy</h3><hr><div><p><font papago-translate="translated" papago-id="0">Given an integer array </font><code>nums</code><font papago-translate="cached" papago-id="1"> sorted in <strong papago-id="1-1">non-decreasing order</strong>, remove the duplicates <a href="https://en.wikipedia.org/wiki/In-place_algorithm" target="_blank" papago-id="1-3"><strong papago-id="1-3-0">in-place</strong></a> such that each unique element appears only <strong papago-id="1-5">once</strong>. The <strong papago-id="1-7">relative order</strong> of the elements should be kept the <strong papago-id="1-9">same</strong>.</font></p>

<p><font papago-translate="cached" papago-id="2">Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the <strong papago-id="2-1">first part</strong> of the array </font><code>nums</code><font papago-translate="translated" papago-id="3">. More formally, if there are </font><code>k</code><font papago-translate="translated" papago-id="4"> elements after removing the duplicates, then the first </font><code>k</code><font papago-translate="translated" papago-id="5"> elements of </font><code>nums</code><font papago-translate="cached" papago-id="11">&nbsp;should hold the final result. It does not matter what you leave beyond the first&nbsp;</font><code>k</code><font papago-translate="cached" papago-id="12">&nbsp;elements.</font></p>

<p><font papago-translate="cached" papago-id="13">Return </font><code>k</code><font papago-translate="splited"><em papago-id="9" papago-translate="translated"> after placing the final result in the first </em></font><code>k</code><font papago-translate="splited"><em papago-id="10" papago-translate="translated"> slots of </em></font><code>nums</code><font papago-translate="cached" papago-id="14">.</font></p>

<p papago-id="15" papago-translate="cached">Do <strong papago-id="15-1">not</strong> allocate extra space for another array. You must do this by <strong papago-id="15-3">modifying the input array <a href="https://en.wikipedia.org/wiki/In-place_algorithm" papago-id="15-3-1" target="_blank">in-place</a></strong> with O(1) extra memory.</p>

<p><strong papago-id="16" papago-translate="translated">Custom Judge:</strong></p>

<p papago-id="17" papago-translate="translated">The judge will test your solution with the following code:</p>

<pre papago-id="18" papago-translate="translated">int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i &lt; k; i++) {
    assert nums[i] == expectedNums[i];
}
</pre>

<p papago-id="19" papago-translate="cached">If all assertions pass, then your solution will be <strong papago-id="19-1">accepted</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example" papago-id="0" papago-translate="translated">Example 1:</strong></p>

<pre papago-id="1" papago-translate="cached"><strong papago-id="1-0">Input:</strong> nums = [1,1,2]
<strong papago-id="1-2">Output:</strong> 2, nums = [1,2,_]
<strong papago-id="1-4">Explanation:</strong> Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [0,0,1,1,1,2,2,3,3,4]
<strong>Output:</strong> 5, nums = [0,1,2,3,4,_,_,_,_,_]
<strong>Explanation:</strong> Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>-100 &lt;= nums[i] &lt;= 100</code></li>
	<li><code>nums</code><font papago-translate="cached" papago-id="12"> is sorted in <strong papago-id="12-1">non-decreasing</strong> order.</font></li>
</ul>
</div>