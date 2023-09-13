from abc import ABC, abstractmethod
from datetime import datetime, timedelta

# Super Class representing a person
class Person:
    def __init__(self, name, age, ID):
        """
        Initialize a person with their name, age, and ID.

        Args:
            name (str): The name of the person.
            age (int): The age of the person.
            ID (str): The unique ID of the person.
        """
        self.name = name
        self.age = age
        self.ID = ID

    def get_details(self):
        """
        Get details of the person, including ID, name, and age.
        """
        print("ID: {}\nName: {}\nAge: {}".format(self.ID, self.name, self.age))


# Sub Class of Person representing a student
class Student(Person):
    def __init__(self, name, age, ID, student_ID):
        """
        Initialize a student with additional attributes.

        Args:
            name (str): The name of the student.
            age (int): The age of the student.
            ID (str): The unique ID of the student.
            student_ID (str): The student's unique identification code.
        """
        super().__init__(name, age, ID)
        self.student_ID = student_ID
        self.issued_books = []  # List of books issued to the student
        self.borrowed_books = []  # List of books currently borrowed by the student

    def borrow_book(self, book):
        """
        Allow the student to borrow a book if not exceeding the borrowing limit.

        Args:
            book (LibraryItem): The book to be borrowed.
        """
        if len(self.borrowed_books) < 3:  # Student can borrow up to 3 books
            self.borrowed_books.append(book)
            book.checkout(self)
        else:
            print("You have reached the borrowing limit.")

    def return_book(self, book):
        """
        Allow the student to return a borrowed book.

        Args:
            book (LibraryItem): The book to be returned.
        """
        if book in self.borrowed_books:
            self.borrowed_books.remove(book)
            book.return_item(self)
        else:
            print("You did not borrow this book.")

    def get_details(self):
        """
        Get details of the student, including ID, name, age, student ID, and issued books.
        """
        super().get_details()
        print("Student ID: {}".format(self.student_ID))
        print("Issued Books: {}".format(", ".join(book.title for book in self.issued_books)))


# SubClass of Person representing a staff member
class Staff(Person):
    def __init__(self, name, age, ID, staff_id, designation):
        """
        Initialize a staff member with additional attributes.

        Args:
            name (str): The name of the staff member.
            age (int): The age of the staff member.
            ID (str): The unique ID of the staff member.
            staff_id (str): The staff member's unique identification code.
            designation (str): The job designation of the staff member.
        """
        super().__init__(name, age, ID)
        self.staff_id = staff_id
        self.designation = designation
        self.issued_books = []  # List of books issued to the staff member
        self.borrowed_books = []  # List of books currently borrowed by the staff member

    def borrow_book(self, book):
        """
        Allow the staff member to borrow a book if not exceeding the borrowing limit.

        Args:
            book (LibraryItem): The book to be borrowed.
        """
        if len(self.borrowed_books) < 5:  # Staff can borrow up to 5 books
            self.borrowed_books.append(book)
            book.checkout(self)
        else:
            print("You have reached the borrowing limit.")

    def return_book(self, book):
        """
        Allow the staff member to return a borrowed book.

        Args:
            book (LibraryItem): The book to be returned.
        """
        if book in self.borrowed_books:
            self.borrowed_books.remove(book)
            book.return_item(self)
        else:
            print("You did not borrow this book.")

    def get_details(self):
        """
        Get details of the staff member, including ID, name, age, staff ID, and designation.
        """
        super().get_details()
        print("Staff ID: {}".format(self.staff_id))
        print("Designation: {}".format(self.designation))


# Abstract Class representing a library item
class LibraryItem(ABC):
    def __init__(self, book_ID, title, author):
        """
        Initialize a library item with its unique ID, title, and author.

        Args:
            book_ID (int): The unique ID of the library item.
            title (str): The title of the library item.
            author (str): The author of the library item.
        """
        self.book_ID = book_ID
        self.title = title
        self.author = author
        self.borrowed_by = None  # Reference to the person who borrowed the item

    # Abstract method for checking out an item
    @abstractmethod
    def checkout(self, person):
        pass

    # Abstract method for returning an item
    @abstractmethod
    def return_item(self, person):
        pass


# Sub class of Library Item representing a physical book
# Static Class
class Book(LibraryItem):
    def checkout(self, person):
        """
        Allow a person to check out a physical book if it's available.

        Args:
            person (Person): The person who wants to check out the book.
        """
        if not self.borrowed_by:
            self.borrowed_by = person
            person.issued_books.append(self)
            print(f"Checking out the book: {self.title} by {self.author}")
            due_date = datetime.now() + timedelta(days=14)  # Due date is set to 14 days from now
            print("Due Date: {}".format(due_date.strftime('%Y-%m-%d')))
        else:
            print("This book is already borrowed by {}.".format(self.borrowed_by.name))

    def return_item(self, person):
        """
        Allow a person to return a borrowed physical book.

        Args:
            person (Person): The person who wants to return the book.
        """
        if self.borrowed_by == person:
            self.borrowed_by = None
            person.issued_books.remove(self)
            print("Returning the book: {} by {}".format(self.title, self.author))
        else:
            print("You did not borrow this book or it was borrowed by someone else.")

    def read(self):
        """
        Simulate reading a physical book.
        """
        print("Reading the book: {} by {}".format(self.title, self.author))


# SubClass of LibraryItem representing an eBook
class Ebook(LibraryItem):
    def __init__(self, book_ID, title, author, file_size, format):
        """
        Initialize an eBook with additional attributes.

        Args:
            book_ID (int): The unique ID of the eBook.
            title (str): The title of the eBook.
            author (str): The author of the eBook.
            file_size (int): The size of the eBook file in megabytes.
            format (str): The format of the eBook (e.g., PDF, EPUB).
        """
        super().__init__(book_ID, title, author)
        self.file_size = file_size
        self.format = format

    def checkout(self, person):
        """
        Allow a person to check out an eBook if it's available.

        Args:
            person (Person): The person who wants to check out the eBook.
        """
        if not self.borrowed_by:
            self.borrowed_by = person
            person.issued_books.append(self)
            print(f"Checking out the eBook: {self.title} by {self.author}")
            print(f"File Size: {self.file_size} MB")
            print(f"Format: {self.format}")
            due_date = datetime.now() + timedelta(days=7)  # Due date is set to 7 days from now for eBooks
            print("Due Date: {}".format(due_date.strftime('%Y-%m-%d')))
        else:
            print(f"This eBook is already borrowed by {self.borrowed_by.name}.")

    def return_item(self, person):
        """
        Allow a person to return a borrowed eBook.

        Args:
            person (Person): The person who wants to return the eBook.
        """
        if self.borrowed_by == person:
            self.borrowed_by = None
            person.issued_books.remove(self)
            print("Returning the eBook: {} by {}".format(self.title, self.author))
        else:
            print("You did not borrow this eBook or it was borrowed by someone else.")

    def read(self):
        """
        Simulate reading an eBook.
        """
        print("Reading the eBook: {} by {}".format(self.title, self.author))
        print("File Size: {} MB".format(self.file_size))
        print("Format: {}".format(self.format))


class Library:
    def __init__(self):
        self.books = []  # List of physical books in the library
        self.ebooks = []  # List of eBooks in the library
        self.members = []  # List of library members (students and staff)

    def add_book(self, book):
        """
        Add a physical book to the library.

        Args:
            book (Book): The physical book to be added.
        """
        self.books.append(book)

    def add_ebook(self, ebook):
        """
        Add an eBook to the library.

        Args:
            ebook (Ebook): The eBook to be added.
        """
        self.ebooks.append(ebook)

    def add_member(self, member):
        """
        Add a library member (student or staff) to the library.

        Args:
            member (Person): The library member to be added.
        """
        self.members.append(member)

    def search_book_by_title(self, title):
        """
        Search for books in the library by title by List Comprehension.

        Args:
            title (str): The title of the book to search for.

        Returns:
            list: A list of matching books.
        """
        matching_books = [book for book in self.books if title.lower() in book.title.lower()]
        return matching_books

    def search_book_by_author(self, author):
        """
        Search for books in the library by author by List Comprehension.

        Args:
            author (str): The author of the book to search for.

        Returns:
            list: A list of matching books.
        """
        matching_books = [book for book in self.books if author.lower() in book.author.lower()]
        return matching_books

    def search_book_by_id(self, book_id):
        """
        Search for a book in the library by its unique ID by List Comprehension.

        Args:
            book_id (int): The unique ID of the book to search for.

        Returns:
            list: A list containing the matching book or an empty list if not found.
        """
        matching_books = [book for book in self.books if book.book_ID == book_id]
        return matching_books

    def list_all_books(self):
        """
        List all physical books in the library.
        """
        for book in self.books:
            print("Book ID: {}\nTitle: {}\nAuthor: {}\n".format(book.book_ID, book.title, book.author))

    def list_all_issued_books(self):
        """
        List all books issued by library members.
        """
        for member in self.members:
            print(f"{member.name}'s Issued Books:")
            for book in member.issued_books:
                print("Title: {}\nAuthor: {}\n".format(book.title, book.author))

    def list_all_members(self):
        """
        List all library members along with their details.
        """
        print("Library Members:")
        for member in self.members:
            member.get_details()
            print("\n")

    def download_ebook(self, ebook):
        print(f"Downloading {ebook.title}.")

# Usage example:
# Created instances of Person, Student, Staff, Book, Ebook, and Library classes and perform operations.
p1 = Person("Hassan", 21, "029")
p2 = Person("Hamza", 20, "214")

# Created Book objects
b1 = Book(1, "The Kite Runner", "Khaled Hosseini")
b2 = Book(2, "The Apocalypse", "Unknown Author")

# Created Ebook objects
e1 = Ebook(3, "Python Programming", "John Smith", 5, "PDF")
e2 = Ebook(4, "Data Science Essentials", "Alice Johnson", 3, "EPUB")

# Created Student object and perform operations
s1 = Student("Hassan", 21, "029", "CT-21121")
s1.borrow_book(b1)
s1.borrow_book(b2)

# Created Staff object and perform operations
staff1 = Staff("Alice", 30, "123", "STF-001", "Librarian")
staff1.borrow_book(e1)
staff1.borrow_book(e2)

# Created Library object and add books, ebooks, and members
library = Library()
library.add_book(b1)
library.add_book(b2)
library.add_ebook(e1)
library.add_ebook(e2)
library.add_member(s1)
library.add_member(staff1)

library.search_book_by_title("The")
library.list_all_issued_books()
library.list_all_members()