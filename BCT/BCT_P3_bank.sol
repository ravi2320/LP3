// SPDX-License-Identifier: MIT
pragma solidity ^0.8.19;

contract BankAccount {
    address public owner;
    mapping(address => uint) private balances;

    constructor() {
        owner = msg.sender;
    }

    // Deposit money into the bank account
    function deposit() public payable {
        require(msg.value > 0, "Deposit amount must be greater than zero");
        balances[msg.sender] += msg.value;
    }

    // Withdraw money from the bank account
    function withdraw(uint _amount) public {
        require(balances[msg.sender] >= _amount, "Insufficient balance");
        payable(msg.sender).transfer(_amount);
        balances[msg.sender] -= _amount;
    }

    // Show the balance of the bank account
    function showBalance() public view returns (uint) {
        return balances[msg.sender];
    }
}
