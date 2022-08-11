<h2><a href="https://leetcode.com/problems/simple-bank-system/">2043. Simple Bank System</a></h2><h3>Medium</h3><hr><div><p><font papago-translate="translated" papago-id="0">You have been tasked with writing a program for a popular bank that will automate all its incoming transactions (transfer, deposit, and withdraw). The bank has </font><code>n</code><font papago-translate="translated" papago-id="1"> accounts numbered from </font><code>1</code><font papago-translate="translated" papago-id="2"> to </font><code>n</code><font papago-translate="cached" papago-id="3">. The initial balance of each account is stored in a <strong papago-id="3-1">0-indexed</strong> integer array </font><code>balance</code><font papago-translate="translated" papago-id="4">, with the </font><code>(i + 1)<sup>th</sup></code><font papago-translate="translated" papago-id="5"> account having an initial balance of </font><code>balance[i]</code><font papago-translate="translated" papago-id="6">.</font></p>

<p papago-id="11" papago-translate="cached">Execute all the <strong papago-id="11-1">valid</strong> transactions. A transaction is <strong papago-id="11-3">valid</strong> if:</p>

<ul>
	<li><font papago-translate="cached" papago-id="12">The given account number(s) are between </font><code>1</code><font papago-translate="cached" papago-id="13"> and </font><code>n</code><font papago-translate="cached" papago-id="14">, and</font></li>
	<li papago-id="15" papago-translate="cached">The amount of money withdrawn or transferred from is <strong papago-id="15-1">less than or equal</strong> to the balance of the account.</li>
</ul>

<p><font papago-translate="cached" papago-id="16">Implement the </font><code>Bank</code><font papago-translate="cached" papago-id="17"> class:</font></p>

<ul>
	<li><code>Bank(long[] balance)</code><code>balance</code><font papago-translate="cached" papago-id="19">.</font></li>
	<li><code>boolean transfer(int account1, int account2, long money)</code><font papago-translate="cached" papago-id="20"> Transfers </font><code>money</code><font papago-translate="cached" papago-id="21"> dollars from the account numbered </font><code>account1</code><font papago-translate="cached" papago-id="22"> to the account numbered </font><code>account2</code><font papago-translate="cached" papago-id="23">. Return </font><code>true</code><font papago-translate="cached" papago-id="24"> if the transaction was successful, </font><code>false</code><font papago-translate="cached" papago-id="25"> otherwise.</font></li>
	<li><code>boolean deposit(int account, long money)</code><font papago-translate="cached" papago-id="26"> Deposit </font><code>money</code><font papago-translate="cached" papago-id="27"> dollars into the account numbered </font><code>account</code><font papago-translate="cached" papago-id="28">. Return </font><code>true</code><font papago-translate="cached" papago-id="29"> if the transaction was successful, </font><code>false</code><font papago-translate="cached" papago-id="30"> otherwise.</font></li>
	<li><code>boolean withdraw(int account, long money)</code><font papago-translate="cached" papago-id="31"> Withdraw </font><code>money</code><font papago-translate="cached" papago-id="32"> dollars from the account numbered </font><code>account</code><font papago-translate="cached" papago-id="33">. Return </font><code>true</code><font papago-translate="cached" papago-id="34"> if the transaction was successful, </font><code>false</code><font papago-translate="cached" papago-id="35"> otherwise.</font></li>
</ul>

<p>&nbsp;</p>
<p><strong papago-id="36" papago-translate="translated">Example 1:</strong></p>

<pre papago-id="37" papago-translate="cached"><strong papago-id="37-0">Input</strong>
["Bank", "withdraw", "transfer", "deposit", "transfer", "withdraw"]
[[[10, 100, 20, 50, 30]], [3, 10], [5, 1, 20], [5, 20], [3, 4, 15], [10, 50]]
<strong papago-id="37-2">Output</strong>
[null, true, true, true, false, false]

<strong papago-id="37-4">Explanation</strong>
Bank bank = new Bank([10, 100, 20, 50, 30]);
bank.withdraw(3, 10);    // return true, account 3 has a balance of $20, so it is valid to withdraw $10.
                         // Account 3 has $20 - $10 = $10.
bank.transfer(5, 1, 20); // return true, account 5 has a balance of $30, so it is valid to transfer $20.
                         // Account 5 has $30 - $20 = $10, and account 1 has $10 + $20 = $30.
bank.deposit(5, 20);     // return true, it is valid to deposit $20 to account 5.
                         // Account 5 has $10 + $20 = $30.
bank.transfer(3, 4, 15); // return false, the current balance of account 3 is $10,
                         // so it is invalid to transfer $15 from it.
bank.withdraw(10, 50);   // return false, it is invalid because account 10 does not exist.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == balance.length</code></li>
	<li><code>1 &lt;= n, account, account1, account2 &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= balance[i], money &lt;= 10<sup>12</sup></code></li>
	<li><font papago-translate="translated" papago-id="30">At most </font><code>10<sup>4</sup></code><font papago-translate="cached" papago-id="31"> calls will be made to <strong papago-id="31-1">each</strong> function </font><code>transfer</code><font papago-translate="translated" papago-id="32">, </font><code>deposit</code><font papago-translate="translated" papago-id="33">, </font><code>withdraw</code><font papago-translate="translated" papago-id="34">.</font></li>
</ul>
</div>