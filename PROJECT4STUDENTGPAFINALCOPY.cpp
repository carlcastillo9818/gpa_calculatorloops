/*
Name: Carlos Castillo
Date : 13 April 2019
Class : CIS 160
Program Name:  PCCC Student GPA Calculator System
Program explanation : This program asks for a student name, ID number, and the number
of courses he/she is taking.  For each course, it asks for the course number, course credits,
and grade received for the course.  Then it calculates the students GPA average by dividing
the total grade points by the total course credits.  It displays the students name,
their ID number, the total number of semester credits, their GPA and a warning/congratulary
message depending on their GPA number. Finally, it asks the user if they
want to run the program again for another student.
*/


#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

//Function prototypes

void set_student_info(string &, int &, int &);

void set_course_info(int, string &, int &, char &, int &, float &);

float calc_gpa(int, float, string &);

void display_results(string, int, int, float, string);

void receive_next_student(char &choice);

int main()
{
	// defined string variables here
	string student_name;
	string course_number;
	string special_message;
	
	// defined int variables here
	int id_number;
	int total_courses;
	int course_credits;
	int total_credits;

	// defined char variables here
	char grade_received;
	char next_student_choice;

	// defined float variables here
	float total_points;
	float student_gpa;
	
	// CALL FUNCTIONS INSIDE DO WHILE LOOP
	do
	{
		// call the set_student_info function first to get input
		set_student_info(student_name, id_number, total_courses);
		// next, call the set_course_info function to get more input and accumulate total credits/points 
		set_course_info(total_courses, course_number, course_credits, grade_received, total_credits, total_points);
		
		// next, call the calc_gpa function to calculate the gpa and return the value to student_gpa
		student_gpa = calc_gpa(total_credits, total_points, special_message);
		
		// next, call the display results function to display the student information
		display_results(student_name, id_number, total_credits, student_gpa, special_message);

		// finally, call the repeat_choice function to ask the user if they want to create another student GPA report
		receive_next_student(next_student_choice);
	}while (next_student_choice != 'N');
	
	

	return 0;	
}

/*
This function accepts inputs for name, ID number, total number of courses being taken.
This function holds three parameters (one string type, two int types) and they are all 
passed by reference.  This function is a void type because 
it does not return a value. 
*/
void set_student_info(string &name, int &id_num, int &tot_courses)
{


	// asks for the students name
	cout << "Enter student's name here : ";
	getline(cin,name);
	

	// asks for student ID number
	cout << "\nEnter the student ID number here : ";
	cin >> id_num;
	
	// while loop that is true if the id number is less than 0 or greater than 9999
	while (id_num < 0 || id_num > 9999)
	{
		// displays a message that tells the user to enter a number between 0 to 9999
		cout << "Valid ID numbers are 0 to 9999 only!\n";
		// then it asks the user to enter a student id number again
		cout << "Enter the student ID number here : "; cin >> id_num;
	}
	
	// asks for the number of courses being taken
	cout << "\nEnter the number of courses being taken this semester : ";
	cin >> tot_courses;
	
	// this condition is true if the total courses being taken is 0	
	if (tot_courses == 0)
	{
		// displays an advice message
		cout << "\nIf you are taking 0 courses then you should pick a different college!\n";
		// exits the program
		exit(0);
	}
	// while loop is true if total courses is outside the range of 0-5.  
	while (tot_courses < 0 || tot_courses > 5)
	{
		// displays a message alerting the user to enter a number between 0 to 5
		cout << "Valid number of courses are 0 to 5 only!\n";
		// asks the user to enter the number of courses being taken again
		cout << "Enter the number of courses being taken this semester : "; cin >> tot_courses;	
	}
	
	
}

/*
This function accepts inputs for course number, course credits, and course grade.  The function
also accumulates the credits for each course and accumulates the grade points for each course.  This function
holds four parameters (three int types, one string type, one char type, and one float type).  The tot_courses parameter
is passed by value and the rest of the parameters are passed by reference.
This function is a void type because it does not return a value.
*/
void set_course_info(int tot_courses, string &course_num, int &credits, char &grade, int &tot_credits, float &tot_points)
{
	// five int type constants that are the points for each letter grade
	const float A_POINTS = 4;
	const float B_POINTS = 3;
	const float C_POINTS = 2;
	const float D_POINTS = 1;
	const float F_POINTS = 0;
	
	//defined a int type variable called course_count which is the counter for the loop
	int course_count;
	
	// defined a float type variable called grade_points
	float grade_points;
	
	// set the first accumulator, tot_credits, to 0
	tot_credits = 0;
	
	// set the second accumulator, tot_points, to 0 
	tot_points = 0;
	
	// this for loop is true as long as course_count is less than or equal to total number of courses
	for (course_count = 1; course_count <= tot_courses;course_count++)
	{
		cin.ignore();
		// asks user to enter the course number for the current course
		cout << "\nEnter the course number for course " << course_count << " : " << endl; 
		getline(cin,course_num);
		
		// asks user to enter the course credits for the current course
		cout << "Enter the credits for course " << course_count << " : " << endl;
		cin >> credits;
		
		//adds the credits for the current course to the accumulator tot_credits
		tot_credits += credits;
		
		// asks user to enter the grade received for the current course
		cout << "Enter the grade received for course " << course_count << " : " << endl;
		cin >> grade;
		
		// converts grade input to upper case letters
		grade = toupper(grade);
		
		// while loop is true as long as grade is not equal to A,B,C,D,or F.  
		while (!(grade == 'A' || grade == 'B' || grade == 'C' || grade == 'D' || grade == 'F'))
		{
			// asks user to enter a valid grade received for the current course
			cout << "Valid grade letters are only A,B,C,D, or F!\n";
			cout << "Enter the grade received for course " << course_count << " : " << endl;
			cin >> grade;
			
			// converts grade input to upper case letters
			grade = toupper(grade);

		}
		
		// the switch checks the grade input
		switch(grade)
		{
			// this case executes if grade input was A
			case 'A':
				// grade points is equal to A_POINTS multiplied by the course credits
				grade_points = A_POINTS * credits;
				// tot_points gets grade points added to it
				tot_points += grade_points;
				break;
			// this case executes if grade input was B
			case 'B':
				// grade points is equal to B_POINTS multiplied by the course credits
				grade_points = B_POINTS * credits;
				// tot_points gets grade points added to it
				tot_points += grade_points;
				break;
			// this case executes if grade input was C
			case 'C':
				// grade points is equal to C_POINTS multiplied by the course credits
				grade_points = C_POINTS * credits;
				// tot_points gets grade points added to it
				tot_points += grade_points;
				break;
			// this case executes if grade input was D
			case 'D':
				// grade points is equal to D_POINTS multiplied by the course credits
				grade_points = D_POINTS * credits;
				// tot_points gets grade points added to it
				tot_points += grade_points;
				break;
			// this case executes if grade input was F
			case 'F':	
				// grade points is equal to F_POINTS multiplied by the course credits
				grade_points = F_POINTS * credits;
				// tot_points gets grade points added to it
				tot_points += grade_points;
				break;	
		}
	}
}


/*
This function calculates the GPA by dividing the total course credits by the total number of grade points.  This function
also includes a message if the GPA is below 2.0, equal to or above 3.0, or in between.  This function holds three
parameters (two int types and one string type).  The tot_credits and tot_points are passed by value and the 
sp_msg is passed by reference.  This function is a float type because it returns a float value.
*/ 
float calc_gpa(int tot_credits, float tot_points, string &sp_msg)
{
	// defined float variable called gpa here
	float gpa;
	

	// gpa is assigned the value of the total points divided by the total credits
	gpa = (tot_points / tot_credits);
	
	// this if statement is true if the gpa is less than 2.0
	if (gpa < 2.0)
	{
		// sp_msg is assigned a warning message
		sp_msg = "Warning! The student GPA is less than 2.0!  You need to do better!";
	}
	// this else executes if the first if condition was false
	else
		// this if statement is true if the gpa is greater than or equal to 3.0
		if (gpa >= 3.0)
		{
			// the sp_msg is assigned a congratulatory message
			sp_msg = "Congrats! The student GPA is 3.0 or above! Keep up the good work!";
		}
	// this else executes if the first and second conditions above were false	
	else
	{
		// the sp_msg is assigned an average message.
		sp_msg = "The student GPA is average! Not bad! Not excellent either!";
	}
	
	// returns the gpa value to main
	return gpa;
}


/*This function 
displays the students name, the students ID number, the total number of credits they took for the semester,
their GPA, and a special mesage that accompanies the GPA. This function holds 5 parameters and it is a void type 
because it doesn't return a value.  
*/
void display_results(string name, int id_num, int tot_credits, float gpa, string sp_msg)
{
	// clears the screen of previous text
	system("cls");
	
	// defined string variable called header
	string header;
	
	// defined string variable called separator
	string separator;
	
	// header is assigned a string message
	header = "\tPASSAIC COUNTY COMMUNITY COLLEGE\t\t\n\t\t\n\t\tTERM GPA REPORT\t\t\n";
	
	// separator is assigned one character multiple times
	separator.assign(60,'=');
	
	// displays header
	cout << header << endl;
	// displays separator
	cout << separator << endl;
	// modifies number outputs
	cout << fixed << showpoint << setprecision(2);
	// displays the students name
	cout << "Student Name : " << name << endl << endl;
	// displays the student id number
	cout << "Student ID Number : " << id_num << endl << endl;
	// displays total semester credits
	cout << "Total Semester Credits: " << tot_credits << endl << endl;
	// displays students gpa
	cout << "Student GPA : " << gpa << endl << endl;
	// displays a certain message depending on the students gpa number
	cout << sp_msg << endl;
	// displays the separator again
	cout << separator << endl;
	
}

/*
This function asks for the users choice if they want to
input another students information.  If they type Y, then the screen will be cleared of 
previous text and the entire program will loop again.  If they type 
any other character then the program will end.
This function only has one parameter (one char type) which is passed by reference.
This function is void because it does not return any values.
*/ 
void receive_next_student(char &choice)
{
	// asks the user to input their choice to the question (Y/N)
	cout << "\nDo you want to enter another students information? (Y/N) "; cin >> choice;
	choice = toupper(choice);
	cin.ignore();
	
	if (choice == 'Y')
	{
		// clears the screen of previous text before going to the next iteration of the do while loop
		system("cls");	

	}
	else
		if (choice == 'N')
		{
			// displays a thank you message
			cout << "Okay, thank you for using my program!\n";
			// exits the program after user types in N
			exit(0);
		}
		else
		{
			// exits the program if any other character is inputted
			exit(0);
		}
}

	
