# Address-Book-using-C
Address Book Management System is a console-based application developed in C to store and manage contact details efficiently. It allows users to add, search, update, delete, and list contacts using structures and file handling for permanent storage in CSV File.
The Address Book Management System is a console-based application developed using C programming to efficiently store and manage personal contact information. The system provides a user-friendly, menu-driven interface that allows users to perform essential operations such as adding, searching, updating, deleting, and listing contact records.

The application uses structures to organize contact details and file handling techniques to store data permanently in a CSV file. This ensures that all records remain available even after the program is terminated, making the system reliable and practical for everyday use.

🎯 Objectives

To design a simple contact management system using C

To understand and apply file handling for permanent data storage

To implement CRUD operations on structured data

To strengthen fundamental C programming concepts

⚙️ Features

Add new contact details

Search contacts by name

Edit existing contact information

Delete contact records

Display all stored contacts

Menu-driven and user-friendly interface

Permanent storage using file handling

🛠️ Technologies & Concepts Used

C Programming

Structures

Functions and Pointers

File Handling (CSV format)

Conditional statements and loops

📂 Project Structure
Address-Book-Using-C/
│── main.c            # Program execution starts here
│── addressbook.c     # Core functionality implementation
│── addressbook.h     # Structure definitions and function declarations
│── database.csv      # Stores contact records
│── README.md         # Project documentation

 How to Run and Test
Compile the Program
gcc main.c addressbook.c -o addressbook

Run the Program
./addressbook

Testing

Choose menu options to add, search, edit, delete, or list contacts

Verify that contact details are saved in database.csv

Exit and restart the program to confirm data persistence

Sample Output

After execution, the program displays a menu allowing the user to interact with the address book. Stored contacts are displayed with Name, Mobile Number, and Email ID, confirming successful file operations
