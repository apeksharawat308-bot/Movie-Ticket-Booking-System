# 🎬 Movie Ticket Booking System

A console-based **Movie Ticket Booking System** developed in **C++** using **Object-Oriented Programming (OOP)** and **System Design principles**.

This project was developed as part of the **TCS-504 System Design coursework** and demonstrates how real-world requirements can be converted into a modular software design.



## 📌 Project Overview

The Movie Ticket Booking System allows customers to:

- 🎥 View available movies
- 🎭 Select a movie show
- 🖥️ Select a screen
- 💺 View and select available seats
- 🎟️ Book movie tickets
- 💰 Calculate ticket prices based on seat type
- 💳 Make payments using different payment methods
- 🧾 Generate booking/ticket details
- ❌ Cancel bookings
- 🔄 Release seats after cancellation or unsuccessful payment

The system is designed using separate classes to keep the application modular, maintainable, and easy to understand.

---

## ✨ Features

### 🎥 Movie Management
- Store movie information
- Display available movies
- Select a movie for booking

### 🕐 Show Management
- Manage movie show timings
- Associate movies with screens
- Display available shows

### 💺 Seat Management
- Manage different seat types
- Check seat availability
- Book available seats
- Release seats after cancellation

### 💰 Price Calculation
Ticket prices are calculated according to the selected seat type.

Example:

| Seat Type | Price |
|-----------|-------|
| Silver | ₹150 |
| Gold | ₹200 |
| Premium | ₹250 |

### 💳 Multiple Payment Methods

The system supports:

- UPI
- Card
- Cash

Payment methods are implemented using inheritance and runtime polymorphism.

### 🎟️ Booking Management
- Generate unique booking IDs
- Confirm bookings after successful payment
- Display booking details
- Cancel existing bookings
- Release booked seats after cancellation

### ⚠️ Edge Case Handling
The system handles situations such as:

- Selecting an unavailable seat
- Invalid movie/show selection
- Invalid seat selection
- Payment failure
- Cancelling a booking
- Attempting to book an already booked seat



## 🛠️ Technologies Used

- **Language:** C++
- **Standard:** C++17
- **Concepts:** Object-Oriented Programming
- **IDE:** Visual Studio Code
- **Compiler:** g++


## 🧩 OOP Concepts Used

### 1. Encapsulation

Data and related functions are grouped inside classes.

Examples:

- `Movie`
- `Seat`
- `Customer`
- `Booking`
- `Cinema`



### 2. Abstraction

The `Payment` class provides a common interface for payment operations while hiding the implementation details of individual payment methods.



### 3. Inheritance

Different payment classes inherit from the base `Payment` class.


             Payment
            /   |   \
           /    |    \
        UPI    Card   Cash 
