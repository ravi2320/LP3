// SPDX-License-Identifier: MIT
pragma solidity ^0.8.19;

contract EmployeeData {
    
    // Structure to store employee information
    struct Employee {
        uint id;
        string name;
        uint salary;
        string designation;
    }

    // Array to store all employees
    Employee[] public employees;

    // Mapping from employee ID to the index of the employee in the array
    mapping(uint => uint) public employeeIndex;

    // Event to log when a new employee is added
    event EmployeeAdded(uint id, string name, uint salary, string designation);
    
    // Event to log when Ether is received
    event EtherReceived(address sender, uint amount);

    // Function to add employee data
    function addEmployee(uint _id, string memory _name, uint _salary, string memory _designation) public {
        // Create new employee and store it in the employees array
        Employee memory newEmployee = Employee({
            id: _id,
            name: _name,
            salary: _salary,
            designation: _designation
        });
        
        employees.push(newEmployee);
        employeeIndex[_id] = employees.length - 1; // Save the index of the employee

        emit EmployeeAdded(_id, _name, _salary, _designation); // Emit event
    }

    // Function to retrieve employee data by ID
    function getEmployeeById(uint _id) public view returns (uint, string memory, uint, string memory) {
        uint index = employeeIndex[_id];
        Employee memory emp = employees[index];
        
        return (emp.id, emp.name, emp.salary, emp.designation);
    }

    // Fallback function to accept Ether with data
    fallback() external payable {
        emit EtherReceived(msg.sender, msg.value); // Emit event when Ether is received
    }

    // Receive function to accept Ether without data (when called via send/transfer)
    receive() external payable {
        emit EtherReceived(msg.sender, msg.value); // Emit event when Ether is received
    }

    // Function to check the balance of the contract
    function getContractBalance() public view returns (uint) {
        return address(this).balance;
    }
}
