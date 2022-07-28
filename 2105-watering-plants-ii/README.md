<h2><a href="https://leetcode.com/problems/watering-plants-ii/">2105. Watering Plants II</a></h2><h3>Medium</h3><hr><div><p><font papago-translate="cached" papago-id="15">Alice and Bob want to water </font><code>n</code><font papago-translate="cached" papago-id="16"> plants in their garden. The plants are arranged in a row and are labeled from </font><code>0</code><font papago-translate="cached" papago-id="17"> to </font><code>n - 1</code><font papago-translate="cached" papago-id="18"> from left to right where the </font><code>i<sup>th</sup></code><font papago-translate="cached" papago-id="19"> plant is located at </font><code>x = i</code><font papago-translate="cached" papago-id="20">.</font></p>

<p papago-id="21" papago-translate="cached">Each plant needs a specific amount of water. Alice and Bob have a watering can each, <strong papago-id="21-1">initially full</strong>. They water the plants in the following way:</p>

<ul>
	<li><code>0<sup>th</sup></code><code>(n - 1)<sup>th</sup></code></li>
	<li papago-id="25" papago-translate="translated">It takes the same amount of time to water each plant regardless of how much water it needs.</li>
	<li papago-id="26" papago-translate="cached">Alice/Bob <strong papago-id="26-1">must</strong> water the plant if they have enough in their can to <strong papago-id="26-3">fully</strong> water it. Otherwise, they <strong papago-id="26-5">first</strong> refill their can (instantaneously) then water the plant.</li>
	<li papago-id="27" papago-translate="cached">In case both Alice and Bob reach the same plant, the one with <strong papago-id="27-1">more</strong> water currently in his/her watering can should water this plant. If they have the same amount of water, then Alice should water this plant.</li>
</ul>

<p><code>plants</code><font papago-translate="cached" papago-id="29"> of </font><code>n</code><font papago-translate="cached" papago-id="30"> integers, where </font><code>plants[i]</code><font papago-translate="cached" papago-id="31"> is the amount of water the </font><code>i<sup>th</sup></code><font papago-translate="cached" papago-id="32"> plant needs, and two integers </font><code>capacityA</code><font papago-translate="cached" papago-id="33"> and </font><code>capacityB</code></p>

<p>&nbsp;</p>
<p><strong papago-id="0" papago-translate="translated">Example 1:</strong></p>

<pre papago-id="1" papago-translate="cached"><strong papago-id="1-0">Input:</strong> plants = [2,2,3,3], capacityA = 5, capacityB = 5
<strong papago-id="1-2">Output:</strong> 1
<strong papago-id="1-4">Explanation:</strong>
- Initially, Alice and Bob have 5 units of water each in their watering cans.
- Alice waters plant 0, Bob waters plant 3.
- Alice and Bob now have 3 units and 2 units of water respectively.
- Alice has enough water for plant 1, so she waters it. Bob does not have enough water for plant 2, so he refills his can then waters it.
So, the total number of times they have to refill to water all the plants is 0 + 0 + 1 + 0 = 1.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> plants = [2,2,3,3], capacityA = 3, capacityB = 4
<strong>Output:</strong> 2
<strong>Explanation:</strong>
- Initially, Alice and Bob have 3 units and 4 units of water in their watering cans respectively.
- Alice waters plant 0, Bob waters plant 3.
- Alice and Bob now have 1 unit of water each, and need to water plants 1 and 2 respectively.
- Since neither of them have enough water for their current plants, they refill their cans and then water the plants.
So, the total number of times they have to refill to water all the plants is 0 + 1 + 1 + 0 = 2.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> plants = [5], capacityA = 10, capacityB = 8
<strong>Output:</strong> 0
<strong>Explanation:</strong>
- There is only one plant.
- Alice's watering can has 10 units of water, whereas Bob's can has 8 units. Since Alice has more water in her can, she waters this plant.
So, the total number of times they have to refill is 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == plants.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= plants[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>max(plants[i]) &lt;= capacityA, capacityB &lt;= 10<sup>9</sup></code></li>
</ul>
</div>