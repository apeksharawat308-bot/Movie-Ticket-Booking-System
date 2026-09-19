
MOVIE TICKET BOOKING SYSTEM
TCS-504 - System Design
C++ / VS Code

HOW TO RUN
-----------
1. Extract this folder.
2. Open the folder in VS Code.
3. Make sure MinGW/G++ is installed and available in PATH.
4. Open VS Code Terminal.
5. Run:

   g++ -std=c++17 main.cpp -o movie_booking

6. Run:

   Windows:
   movie_booking.exe

   PowerShell:
   .\movie_booking.exe

IMPORTANT
---------
The assignment asks for:
- One class per file
- No header files

Therefore each class is placed in its own .cpp file, and main.cpp includes
those .cpp files. This is suitable for the assignment's stated restriction.
In normal industry C++, header (.h/.hpp) files would usually be preferred.

OOP CONCEPTS
------------
1. Encapsulation:
   Private data members and controlled public methods.

2. Abstraction:
   Payment is an abstract class with pure virtual pay().

3. Inheritance:
   UpiPayment, CardPayment and CashPayment inherit Payment.

4. Runtime Polymorphism:
   Payment* points to different payment subclasses.

5. Compile-Time Polymorphism:
   Constructors are overloaded through default/parameterized forms.

6. Static Member:
   Booking::nextBookingId generates unique booking IDs.

7. this keyword:
   Constructors use member initialization; the classes are designed
   around object-specific data.

8. Composition:
   Cinema -> Screen, Screen -> Seat, Show -> ShowSeat.

9. Aggregation:
   Show -> Movie and Booking -> ShowSeat.

EDGE CASES
----------
- Already-booked seat is rejected.
- Invalid seat number is rejected.
- Duplicate seat selection is rejected.
- Failed payment releases selected seats.
- Successful payment confirms booking.
- Cancellation releases seats.
- Invalid menu input is handled without crashing.

UML / DESIGN
------------
The classes correspond to the UML class diagram and sequence flow created
for the assignment.
