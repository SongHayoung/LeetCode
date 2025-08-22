<h2><a href="https://leetcode.com/problems/minimum-operations-to-equalize-array">3998. Minimum Operations to Equalize Array</a></h2><h3>Easy</h3><hr><p>You are given an integer array <code>nums</code> of length <code>n</code>.</p>

<p>In one operation, choose any subarray <code>nums[l...r]</code> (<code>0 &lt;= l &lt;= r &lt; n</code>) and <strong>replace</strong> each element in that subarray with the <strong>bitwise AND</strong> of all elements.</p>

<p>Return the <strong>minimum</strong> number of operations required to make all elements of <code>nums</code> equal.</p>
A <strong>subarray</strong> is a contiguous <b>non-empty</b> sequence of elements within an array.
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,2]</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<p>Choose <code>nums[0...1]</code>: <code>(1 &amp; 2) = 0</code>, so the array becomes <code>[0, 0]</code> and all elements are equal in 1 operation.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [5,5,5]</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<p><code>nums</code> is already <code>[5, 5, 5]</code> with all elements equal, so 0 operations are required.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n == nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<p>&nbsp;</p>
<a href="https://leetcode.feishu.cn/share/base/form/shrcnGykvpLudhbbC5KtR3podyb?prefill_Internal+Contest+ID=463&amp;prefill_Library+ID=4315&amp;prefill_Question=Q1&amp;prefill_Points=3">Feedback Form</a>
<style type="text/css">.spoilerbutton {display:block; border:dashed; padding: 0px 0px; margin:10px 0px; font-size:150%; font-weight: bold; color:#000000; background-color:cyan; outline:0;
}
.spoiler {overflow:hidden;}
.spoiler > div {-webkit-transition: all 0s ease;-moz-transition: margin 0s ease;-o-transition: all 0s ease;transition: margin 0s ease;}
.spoilerbutton[value="Show Message"] + .spoiler > div {margin-top:-2000%;}
.spoilerbutton[value="Hide Message"] + .spoiler {padding:5px;}
</style>
<input class="spoilerbutton" onclick="this.value=this.value=='Show Message'?'Hide Message':'Show Message';" type="button" value="Show Message" />
<div class="spoiler">
<div>
<p><strong>FOR TESTING ONLY. WILL BE DELETED LATER.</strong></p>
Not a performance problem.</div>
</div>
