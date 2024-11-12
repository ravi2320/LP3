// SPDX-License-Identifier: MIT
pragma solidity ^0.8.19;

contract CustomerData {
    // Define a structure to store customer details
    struct Customer {
        uint id;
        string name;
        string email;
    }

    // Array to store customers
    Customer[] public customers;
    uint public customerCount;

    // Event to emit when a new customer is added
    event CustomerAdded(uint id, string name, string email);

    // Function to add a new customer
    function addCustomer(string memory _name, string memory _email) public {
        customerCount++;
        customers.push(Customer(customerCount, _name, _email));
        emit CustomerAdded(customerCount, _name, _email);
    }

    // Function to get a customer's details by their ID
    function getCustomer(uint _id) public view returns (uint, string memory, string memory) {
        require(_id > 0 && _id <= customerCount, "Customer does not exist");
        Customer memory customer = customers[_id - 1];
        return (customer.id, customer.name, customer.email);
    }

    // Fallback function to handle non-existent function calls or direct payments to the contract
    fallback() external payable {
        // Optionally handle fallback logic here, such as logging or triggering another function
    }

    // Function to receive Ether (to make the contract payable)
    receive() external payable {}
}
