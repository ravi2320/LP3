// SPDX-License-Identifier: MIT
pragma solidity ^0.8.19;

contract ProductInventory {
    address public owner;

    struct Product {
        uint id;
        string name;
        uint quantity;
        uint price; // in wei
    }

    mapping(uint => Product) public products;
    uint public productCount;

    modifier onlyOwner() {
        require(msg.sender == owner, "Only the owner can perform this action");
        _;
    }

    constructor() {
        owner = msg.sender;
    }

    // Receive (add) a new product to the inventory
    function receiveProduct(string memory _name, uint _quantity, uint _price) public onlyOwner {
        productCount++;
        products[productCount] = Product(productCount, _name, _quantity, _price);
    }

    // Sell a product from the inventory
    function sellProduct(uint _id, uint _quantity) public payable {
        require(_id > 0 && _id <= productCount, "Product does not exist");
        Product storage product = products[_id];
        require(product.quantity >= _quantity, "Not enough product in stock");
        require(msg.value == _quantity * product.price, "Incorrect amount of Ether sent");
        
        product.quantity -= _quantity;
        payable(owner).transfer(msg.value);
    }

    // Display the stock of a specific product
    function displayStock(uint _id) public view returns (uint) {
        require(_id > 0 && _id <= productCount, "Product does not exist");
        return products[_id].quantity;
    }

    // Get product details
    function getProduct(uint _id) public view returns (uint, string memory, uint, uint) {
        require(_id > 0 && _id <= productCount, "Product does not exist");
        Product memory product = products[_id];
        return (product.id, product.name, product.quantity, product.price);
    }
}
