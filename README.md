# Primer Portfolio

## Section 1 - Primer Challenges
### Primer 1 - Fahrenheit / Centigrade Conversion
This challenge requires us to allow a user to enter a value before selecting whether to convert it from Fahrenheit to Centigrade or Centigrade to Fahrenheit.  As part of the initial design the conversion algorithms were needed for both calculations. 

To help complete this challenge I needed to break the overall problem down into the following main tasks: 
* Get data from the user
* Verify the data is in a suitable format
* Create a method to convert F->C
* Create a method to convert C->F
 
#### Reflection (as well as issues, challenges & resolutions)
The biggest issue was related to testing the areas my solution failed, originally, I tested to see if it worked - however, it wasn’t until I tried to break it that I found some of the more serious issues with my design and implementation.  For example, when a user didn't enter C or F, the program would for some reason, go into an infinite loop. To fix this, I added an if statement to only let the user enter those two letters. However, then if a user was to enter 'c' or 'f' (lower case) then, again, it would break so I had to include an or operator to deal with this.

### Primer 2 - Self-service Checkout
This challenge requires us to ask the user to enter a quantity for an item and then prompt the user consecutively for the price of that item. These two steps would keep occurring until the user decided to exit the program by pressing 0.

To complete this challenge, I broke down the task into the following steps:
* Ask the user for a quantity and assign it to a variable
* Straight after, ask the user for a price of that item
* Do this continuously until the user presses 0
* Once I have all the information I need, work out the total cost of the list
* Then apply the tax to this final cost

#### Reflection
One of the problems I had when trying to complete this challenge was trying to get a quantity and a price off the user until they pressed 0. In the end, I overcame this problem by setting a flag to 1. Then, for the user to break out of the loop, if they enter 0, there would be a conditional statement that says if that flag is 0, exit the code.  

### Primer 3 - Password strength checker

This challenge required us to take a password from the user and calculate wether said password would come under a weak, moderate, strong or very strong state.

The tasks needed to complete the primer were:
* Get a password from a user
* Search for letters, numbers and special characters within the password
* Calculate a score dependant on how many of each were in the password
* Output the password and the score to the user

#### Reflection
The main problem which I had in this challenge was detecting whether a character was a number, letter or special character. At first, I had a two main ideas and since C++ was new to me this week, it was hard to decide which one was going to be easier for me to complete it. The two options were to create 3 helper functions and to see how many of each type of character were in the password or to use regex. After debating the two options and browsing the internet, I decided to go with helper functions as I found that C++ had pre-built functions that detected for digits, letters and special characters so this was going to be super helpful when it came to completing the primer. 

### Primer 4 - Employee list removal
For this challenge, we had a list of employees. We then had to ask the user for an employee to remove and then output the list without that employee. 

The tasks which were involved were:
* Finding a way to store the employees
* Ask a user for input
* Dictate whether the input matches any name in the list
* If it does, remove that employee from the list
* Output the updated list

#### Reflection
The main problem with doing this primer for me was the very first task. In C++, from the lectures and combined research, there were 3 main ways to store the employees. They were a list, an array and a vector. At first, I used an array as I thought it would be similar to remove something from an array as it is in JavaScript. Howver, this was not the case. After researching, I decided to go with a list as with a list, it has a remove method that takes all the hard work away if you were to do it manually.

### Primer 5 - Phone Directory
This primer was to store a range of people and their contact numbers in a csv file. Then a user would input a name for the contact to be output. The function also had to get the amount of contacts in the file.

The tasks which were required to complete this task were:
* Get a way to get everyone from the csv file
* Ask the user for a name or number
* Get the amount of contacts
* Return the contact's name and number

#### Reflection

One of the main problems I had with this primer was creating the function to read from a CSV file. As we got both primers at once, I also read ahead and we had to read from another csv in the next primer aswell. So, for the first primer, I made it typically hard for myself to complete because I wanted to create a reusable function that would make my life easier for the 6th primer. I have read from a CSV file in the past but never in C++. I found this quite challenging as from looking on the internet, there were several ways to do this. However, as C++ has been out since 1985 a lot of the answers were outdated and some of the methods that people suggested using did not work on the current version of repl.it. It took me a while to search the official C++ website for the method that worked for me but I knew that it would make the next primer easier and maybe even used in the future.

### Primer 6 - Data File Parser
This primer was again, to read from a csv with 3 columns (First name, surname and salary) this time and to output and format this data into a table. No user input was needed for this primer. 

The tasks which I worked from were:
* Reuse the CSV function to get all lines
* Create headings for the table
* Get only the first initial of the first name
* Make it so the length of the table column was one dash longer than longest surname in the csv
* Format the salary column so it prepends a £ at the Straight

One problem I had with this was accessing the way I had stored my data. As I was calling the CSV function, it was returning a nested vector of strings. As I had never worked with vectors before in any language let alone a language I have never worked in before, this was quite difficult. Throughout this primer, I found myself on the internet asking questions on how to access, how to output a vector. I had to use a vector because a list would not work for this vector. Also, with an array, you have to define the length before you intialise it. With a vector, they can be resized and since we would not know how many records were in the CSV file, this would be useful as we don't have to define a length for it.

### Primer 7 - Sleep timer

For this challenge, I had to create a program that would block further execution when a integer value is passed into the function.

The tasks needed for this to work were:
* convert the seconds parameter to milliseconds
* Use the this_thread prebuilt function
* Pass the milliseconds into the this_thread as a parameter

### Reflection

I found this primer very enjoyable to get a feel as to what threads are all about. Given the function in the brief to use, I found this primer quite easy to complete apart from when using the milliseconds in the parameter of the this_thread function. It was giving me an error when passing the milliseconds straight into the this_thread function as it would not recognise that milliseconds was a valid parameter. This was causing a few issues and slowing the process of completion. In the end, I had to wrap the milliseconds in std::chrono() which under the hood, converted it to a type that the this_thread function accepted.

### Primer 8 - Joining and detaching threads
For this challenge, I had to initialise two threads, each thread calls a unique function and gets passed two global defined variables. We then had to display the start and end of each thread. 

The tasks involved in this task were:
* Define two global variables. One called timer1 and one called timer 2.
* Create two unique functions that took each variable as a parameter.
* Make the function create two threads, call the sleep function to block any executions for a specified amount of time
* Output to the console once each thread had been executed

#### Reflection

For this challenge, I had to create two threads and obtain their id's. Then, I had to call the sleep timer from primer 7 to block any executions for the passed time and then output when the threads were detached. This was interesting as it allowed me to see a practical example of how the sleep function is used.

### Primer 9 - Car Class
This primer challnged us to instansiate an instance of a car class. It had to include private and public attributes. When called the primer would display the cars status. This consisted of the colour, the make, whether the engine was running or not and whether it was locked or not. A user would then pick a number from the menu to either turn the car engine on or off and lock or unlock the car

The tasks involved in this primer were as follows:
* Decide whether variables are going to be public or private
* Creating a constructor and destructor for the class
* How to instansiate the car class and where to store the status
* Do we need any default values in case no variables gets passed to the instantiation
* Create a menu for the user to pick a number and complete the action
* What would happen if a user wants to turn the car off and it is already off?
* Create a menu option for the user to exit the function

#### Reflection
I liked this primer as I have worked with classes before in other lanaguages, so it was quite familiar and it was interesting to see how it differed from different languages. One problem in which I faced with this primer was trying to counter for the possibility when a user try and unlock a car if it was already locked and vice versa. For this, I had to create two more variables and then create a function that has a conditional statement to account for this.

### Primer 10 - Area of

For this we had to create a class called AreaOf and then within this class, we had to define 3 functions all called size. These took in parameters and worked out the areas of three different shapes.

The tasks involved were:
* How to create three functions without there being an error
* Creating a constructor and destructor for the class
* Output the results of the class
* How to store PI as a constant and if it should be public or private

### Reflection

For this challenge, I would say this was the one that made me think the most as the fact we had to create three functions all with the same name stumped me. However, on the internet, I found that you can call a function the same name as long as it takes a different number of parameters each time. So, for my example, I did the area of a circle, Rectangle and a trapezium. A circle takes 1 number in order to work out the area, a rectangle takes 2 and a trapezium needs 3. So, calling each function with a different number of parameters does not cause any error to occur.

## Section 2 - Programming Paradigms
### Programming Paradigms
Simply put, a programming paradigm, for example, procedural, object-oriented, functional, structured, declarative, imperative and event driven can be described as a specific approach used when trying to solve a problem.  Although many programming languages can (and do) support multiple paradigms this discussion will focus more specifically on the possible benefits with examples of the potential differences and similarities of five from the above list. The ones I will be focusing on is object-orientated, procedural, imperative, event driven and functional. 

### Object orientated programming
When we talk about object orientated programming, it is generally focused around messages being sent and received from objects. Objects respond by activating behaviours. Objects can hold data and code. Data in the form of fields and and code in the form of procedures. Some languages include Java, C++, JavaScript and PHP

#### Procedural Programming
Procedural programming is derived from imperative programing, based on the concept of the procedure call. Procedures simply contain a series of computational steps to be carried out. Programs are composed of sequences of instructions. Minimal abstraction is present between the code and the machine. Procedural programming gives the computer step by step instructions in order to get to the designated result. Some lanaguages which use procedural programming are Dart, Clojure, Ruby and Swift.

### Imperative programming
Imperative programming is formed by instructions which are given to the computer to be executed in a step by step method. They describe explicitly which steps are to be performed in what order to obtain the desired solution at the end.

### Event driven programming
Event-driven programming is the dominant paradigm used in graphical user interfaces and other applications (e.g. JavaScript web applications) that are centered on performing certain actions in response to user input. Event driven programming is based on events such as user inputs and actions whihc is why is it used widely in web applications. Users often have to click or hover over some elements on a webpage and once they complete an action, some other action happens under the hood, for example, direct the user to another webpage, change colour of an element. Some languages which incorporate event dirven programming is Visual Basic, Visual C++ and Java Script.

### Functional programming
Functional programming focuses on composing pure functions, avoiding shared state, avoiding mutable data and avoiding side effects. A pure function is a function where if you were to give a function the same parameter 1, 5, 10 or even 100 times, it would always return the same value. An impure function would be a random function as the value which is returned would be different every time you call it. Programming languages that use functional programming is C++, C# and PHP and many more.

### Object-orientated vs procedural
When we compare both procedural and object orientated. Them seem very far different from each other. Object orientated programming, the program is divided into objects, hence the name, however, procedural programming is split into functions. Object orientated follows a bottom-up approach whereas procedural follows a top-down approach. By these approaches, when a file gets executed for example, procedural will start from the top of the file and read down whereas, object orientated does the opposite. Another difference between the two types of paradigms is that object orientated programming offers data encapsulation so that data is more secure whereas procedural doesn't. When talking about data encapsulation or data hiding  this is the process of the mechanism whereby the implementation details of a class are kept hidden from the user.

---
## Section 3 - Continued Professional Development
### Benefits of becoming a Polyglot Programmer
One benefit of being a polyglot programmer is that the knowledge of several languages. This allows a programmer to use different languages in different situations. For example, one language might be easier to solve a problem in C++ rather than another language. Or one problem might be better in one language because it takes less time to execute. For example, if a programmer had to reverse a string. In Java, it can take one line, wherever, in C++ it takes about 4/5. However, from this, the C++ code runs faster, due to Java being interpreted language, while C produces platform specific machine code and C++ being built on top of C. Often, developers are concerned that expanding into new technology stacks will spread their knowledge too thin. However, learning new technologies produces a stronger understanding of the underlying principles that apply to them all. The result is a more well-rounded, adaptable engineer. Some advantages of being a polyglot programmer are:
* Wider Job market and options to choose from. Hence you have multiple career path and opportunities
* You are not dedicated to a single language and hence you have a bigger tool-belt with a more appropriate solution for the problem at hand.
* You don’t have to worry about your favorite language dying out and you losing your job as you are not too invested in one ecosystem.
