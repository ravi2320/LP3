// SPDX-License-Identifier: MIT
pragma solidity ^0.8.19;

contract StudentData {

    // Define the Student structure
    struct Student {
        string name;
        uint age;
        string grade;
    }

    // Array to store students
    Student[] public students;

    // Function to add a new student
    function addStudent(string memory _name, uint _age, string memory _grade) public {
        // Create a new student and add it to the students array
        students.push(Student(_name, _age, _grade));
    }

    // Function to get the total number of students
    function getTotalStudents() public view returns (uint) {
        return students.length;
    }

    // Function to get student details by index
    function getStudent(uint index) public view returns (string memory, uint, string memory) {
        require(index < students.length, "Student not found");
        Student memory student = students[index];
        return (student.name, student.age, student.grade);
    }
}
