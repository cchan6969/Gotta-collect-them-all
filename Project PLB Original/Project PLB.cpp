#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<Windows.h>
#include<stdio.h>
using namespace std;
void option();
void signUp();
void createCardFile(string usern);
void login();
void checkStatus();
void borrowBooks(string usern);
void updateUserBooks(string usern);
void numOfCard(string usern);
void drawcards(string usern);
void updateCard(string usern, string pokemon);
void mainMenu(string usern);
void checknumbooks(string usern);
void logOut();
void Requim(string usern);
void charlesDarwin(int row1, int row2, string poki, string usern);
int titleScream();

int main() //Mutasim
{
	cout << "**********************************************************" << endl
		 << "         * Welcome to Singapore National Library! *         " << endl
		 << "**********************************************************" << endl;
	option();
	return 0;
}

void option() //Mutasim
{
	string usern, passd, inuser, inpass;
	int no;
	fstream Usersfile;
	char found = 'N';
	bool match = false;

	cout << "\n1) Sign up" << endl
		<< "2) Login into your account" << endl;

	cout << "\nPlease select one of the options above: ";

	while (!(cin >> no) || (no < 1 || no>2))
	{
		// Keeps prompting the user to key in the correct option
		cout << "\nInvalid option. Please try again: ";
		cin.clear();
		cin.ignore(123, '\n');
	}

	if (no == 1)
	{
		system("cls");
		signUp();
	}

	else if (no == 2)
	{
		system("cls");
		login();
	}
}

void signUp() //Mutasim
{
	string usern, passd, accuser, filename, name = "NewUsersAcc";
	ofstream newUser;
	int nobooks = 0;
	fstream Usersfile;
	bool match = false;

	while (!match)
	{
		cout << "\nPlease key in your username (Student Admin Number) and password" << endl;

		cout << "\nUsername: ";
		cin >> usern;

		cout << "Password: ";
		cin >> passd;

		cout << "\n**********   Loading   **********" << endl;
		Sleep(5000);
		if (usern.length() != 8 || usern.substr(0, 1) != "P")
		{
			system("cls");
			cout << "\nInvalid Username. Please ensure the length is 8 characters long and starts with a letter P" << endl;
		}

		else
		{
			match = true;
		}
	}

	if (match)
	{
		Usersfile.open("User details.txt", fstream::app);
		if (!Usersfile)
			cout << "Error\n";

		else
		{
			system("cls");
			Usersfile << endl << usern << " " << passd << endl;
			cout << endl << "\nYour account has been successfully created!\n";

			// Add the new usernames and password in the User Details txt file
			accuser = usern;
			newUser.open("User Books.txt", fstream::app);
			newUser << endl << accuser << " " << nobooks << endl;
			newUser.close();

			createCardFile(usern);
			mainMenu(usern);
		}
	}
	Usersfile.close();
}

void login() //Mutasim
{
	string usern, passd, inuser, inpass;
	fstream Usersfile;
	char found = 'N';
	bool match = false;

	cout << "\nPlease key in your username and password." << endl;

	while (!match)
	{
		cout << "\nUsername: ";
		cin >> usern;

		cout << "Password: ";
		cin >> passd;

		system("cls");
		cout << "\n**********   Loading   **********";
		Sleep(5000);
		Usersfile.open("User details.txt");
		if (!Usersfile)
			cout << "Error, cannot open txt file" << endl;
		else
		{
			while (!Usersfile.eof())
			{
				Usersfile >> inuser >> inpass;
				if (Usersfile.fail())break;

				if (usern == inuser && passd == inpass)
				{
					match = true;
				}

				if (match)
				{
					system("cls");
					found = 'Y';
					cout << endl << "\nYou have successfully log in!\n";
					mainMenu(usern);
					break;
				}
			}
			if (found == 'N')
			{
				system("cls");
				cout << "\nInvalid Username or Password. Please try again." << endl;
			}
		}
		Usersfile.close();
	}
}
void mainMenu(string usern) //Mutasim //Rakesh
{
	int choice = 0;
	string leave;
	while (choice != 7)
	{
		choice = titleScream();
		if (choice == 1)
		{
			system("cls");
			checkStatus();
		}
		else if (choice == 2)
		{
			system("cls");
			borrowBooks(usern);
		}
		else if (choice == 3)
		{
			system("cls");
			checknumbooks(usern);
		}
		else if (choice == 4)
		{
			system("cls");
			numOfCard(usern);
		}
		else if (choice == 5)
		{
			system("cls");
			drawcards(usern);
		}
		else if (choice == 6)
		{
			system("cls");
			Requim(usern);
		}
		else if (choice == 7)
		{
			system("cls");
			logOut();
		}
		Sleep(500);
		cout << "\nPress any key and then Enter to continue: ";
		cin >> leave;
		system("cls");
	}
}

void createCardFile(string usern) //Lei Lei
{
	// To create individual txt files for new users
	string fileName;
	ofstream newFile;
	fileName = usern + ".txt"; 
	newFile.open(fileName.c_str(), fstream::app);
	newFile << "Bulbasaur 0\nVenusaur 0\nCharmander 0\nCharizard 0\nSquirtle  0\nBlastoise 0\nPikachu 0\nSlowpoke 0\nMewtwo 0\nMew 0";
	newFile.close();
}

int titleScream() //carl
{
	int choice;
	cout << "\nWelcome!" << endl
		<< "\n**********" << " " << "Main Menu" << " " << "**********" << endl
		<< "\n1) Book status" << endl
		<< "2) Borrow books" << endl
		<< "3) Check number of books borrowed" << endl
		<< "4) Check number of cards in deck" << endl
		<< "5) Draw cards" << endl
		<< "6) Evolution" << endl
		<< "7) Logout" << endl
		<< "\nPlease enter your choice: ";
	cin >> choice;
	while (!(choice >= 1 || choice <= 8))
	{
		cout << "\nInvalid choice. Please try again: ";
		cin.clear();
		cin.ignore(123, '\n');
	}
	return choice;
}

void checkStatus() //Mutasim
{
	string isbn, status;
	ifstream libooks;

	libooks.open("Library Books.txt");
	if (!libooks)
	{
		cout << "Unable to open file" << endl;
	}

	else
	{
		cout << endl;
		cout << left << setw(20) << "Book number" << setw(20) << "Status" << endl;

		while (!libooks.eof())
		{
			libooks >> isbn >> status;
			if (libooks.fail()) break;

			cout << left << setw(20) << isbn << setw(20) << status << endl;
		}
	}
	libooks.close();

}

void borrowBooks(string usern) //Mutasim
{
	char found = 'N';
	bool match = false;
	string isbn, isbnc, statusc, opinion;
	fstream checkBook;
	ofstream changebooks;

	cout << "\nWould you like to borrow a book? Yes or No: ";

	while (!(cin >> opinion) || (opinion != "Yes" && opinion != "No"))
	{
		cout << "\nInvalid Opinion. Please try again: ";
		cin.clear();
		cin.ignore(123, '\n');
	}

	while (opinion != "No")
	{
		cout << "\nPlease key in book ID: ";

		while (!(cin >> isbn) || (isbn.length() != 8 || isbn.substr(0, 4) != "ISBN"))
		{
			cout << "\nBook ID does not exist. Please key in a valid Book ID: ";
			cin.clear();
			cin.ignore(123, '\n');
		}

		while (!match)
		{
			checkBook.open("Library Books.txt");
			changebooks.open("Temporary.txt");
			if ((!checkBook) && (!changebooks))
				cout << "Error, cannot open txt file" << endl;

			else
			{
				while (!checkBook.eof())
				{
					checkBook >> isbnc >> statusc;
					if (checkBook.fail())break;

					if (isbn == isbnc)
					{
						match = true;
					}

					else
					{
						match = false;
						changebooks << isbnc << " " << statusc << endl;
					}

					if (match)
					{
						found = 'Y';

						if (statusc == "Available")
						{
							cout << "\nYou have successfully borrow a book." << endl;
							statusc = "Unavailable";
							changebooks << isbnc << " " << statusc << endl;
							updateUserBooks(usern);
						}

						else if (statusc == "Unavailable")
						{
							cout << "\nThis book is currently unavailable." << endl;
							statusc = statusc;
							changebooks << isbnc << " " << statusc << endl;
						}
					}
				}
			}
			checkBook.close();
			changebooks.close();
			remove("Library Books.txt");
			rename("Temporary.txt", "Library Books.txt");
			break;
		}

		cout << "\nWould you like to borrow a book? Yes or No: ";

		while (!(cin >> opinion) || (opinion != "Yes" && opinion != "No"))
		{
			cout << "\nInvalid Opinion. Please try again: ";
			cin.clear();
			cin.ignore(123, '\n');
		}

	}
	
	if (opinion == "No")
	{
		cout << "\nSee you next time!" << endl;
	}
}

void updateUserBooks(string usern) //Lei Lei
{
	char found = 'N';
	bool match = false;
	string userid;
	int nobooks;
	ifstream checknumbooks;
	ofstream changenumbooks;

	while (!match)
	{
		// To add on the number of books everytime a user borrow a book
		checknumbooks.open("User Books.txt");
		changenumbooks.open("Temp.txt");
		if ((!checknumbooks) && (!changenumbooks))
			cout << "Error, cannot open txt file" << endl;
		else
		{
			while (!checknumbooks.eof())
			{
				checknumbooks >> userid >> nobooks;
				if (checknumbooks.fail())break;

				if (usern == userid)
				{
					match = true;
				}

				else
				{
					match = false;
					changenumbooks << userid << " " << nobooks << endl;
				}

				if (match)
				{
					found = 'Y';
					nobooks++;
					changenumbooks << userid << " " << nobooks << endl;
				}

			}
			if (found == 'N') //This is for the case when the system is unable to find the username of the users in the txt file.
				cout << "Invalid username. Please try again. " << endl;
		}
		break;
	}
	checknumbooks.close();
	changenumbooks.close();
	remove("User Books.txt");
	rename("Temp.txt", "User Books.txt");
}

void checknumbooks(string usern) //Zhi Hao
{
	//To check nuber of books borrowed by the user
	string userid;
	int nobooks;
	char found = 'N';
	bool match = false;
	ifstream checknumbooks;

	while (!match)
	{
		checknumbooks.open("User Books.txt");
		if (!checknumbooks)
			cout << "Error, cannot open txt file" << endl;
		else
		{
			while (!checknumbooks.eof())
			{
				checknumbooks >> userid >> nobooks;
				if (checknumbooks.fail())break;

				if (usern == userid)
				{
					match = true;
				}

				if (match)
				{
					found = 'Y';
					cout << "\nYou currently have borrowed " << nobooks << " books." << endl;
					break;
				}
			}
			if (found == 'N') //This is for the case when the system is unable to find the username of the users in the txt file.
				cout << "Invalid username. Please try again. " << endl;
		}
	}
	checknumbooks.close();
}

void numOfCard(string usern) //Lei Lei
{
	//To display the number of cards the user have in their deck
	string filename, card;
	int S = 0, A = 0, B = 0, total, num;
	unsigned char type, dash = 247;

	filename = usern + ".txt";
	ifstream countCard;
	countCard.open(filename.c_str());

	if (!countCard)
		cout << "Error" << endl;
	else
	{
		cout << left << endl << setw(40) << "Card name" << setw(40) << "Card type" << "No. of cards" << endl
			<< setw(40) << "------------------------------------------------------------------------------------------------"
			<< endl;

		while (!countCard.eof())
		{
			countCard >> card >> num;
			if (countCard.fail()) break;

			if (card == "Mewtwo" || card == "Mew")
			{
				type = 'S';
				S += num;
			}
			else
				if (card == "Charizard" || card == "Blastoise" || card == "Venusaur")
				{
					type = 'A';
					A += num;
				}
				else
				{
					type = 'B';
					B += num;
				}
			if (num > 0)
			{
				cout << setw(40) << card << setw(40) << type << num << endl;
			}
		}
	}

	cout << endl;
	for (int i = 0; i < 100; i++)
		cout << dash;
	cout << endl << endl << setw(25) << "No. of S cards"
		<< setw(25) << "No. of A cards" << setw(25) << "No. of B cards"
		<< "Total no. of cards" << endl << setw(40)
		<< "------------------------------------------------------------------------------------------------" << endl;
	total = S + A + B;
	cout << setw(25) << S << setw(25) << A << setw(25) << B << total << endl;
}

void updateCard(string usern, string pokemon) //Lei Lei
{
	// To update the individual users card file everytime a new card is drawn out
	int num;
	string filename, cardName;
	ifstream infile;
	ofstream outfile;

	filename = usern + ".txt";
	infile.open(filename.c_str());
	outfile.open("temp.txt");
	if (!infile || !outfile)  cout << "Cannot open file" << endl;
	else
	{
		while (!infile.eof())
		{
			infile >> cardName >> num;
			if (infile.fail()) break;

			if (cardName == pokemon) // Update num of card by card name
			{
				num++;
			}
			outfile << cardName << " " << num << endl;
		}
	}
	infile.close();
	outfile.close();
	remove(filename.c_str());
	rename("temp.txt", filename.c_str());
}

void drawcards(string usern) //Zhi Hao
{
	string userid, pokeID, pokemon, select, cardid;
	int lowrange, uprange, nobooks, randomnum;
	char found = 'N';
	bool match = false;

	ifstream check;
	while (!match)
	{
		check.open("User Books.txt");
		if (!check)
			cout << "Unable to open file" << endl;
		else
		{
			cout << "\nDo you want to make a draw? Yes or No : ";

			while (!(cin >> select) || (select != "Yes" && select != "No"))
			{
				cout << "\nInvalid option. Please try again: ";
				cin.clear();
				cin.ignore(123, '\n');
			}

			if (select == "Yes")
			{
				while (!check.eof())
				{
					check >> userid >> nobooks;
					if (check.fail())	break;
					if (usern == userid)
					{
						match = true;
					}
					if (match)
					{
						found = 'Y';
						if (nobooks >= 2)
						{
							ifstream range;
							range.open("range.txt");
							if (!range)
								cout << "Unable to open file" << endl;
							else
							{
								srand((unsigned int)time(NULL));
								randomnum = rand() % 100 + 1;
								cout << "\nThe number " << randomnum << " is chosen" << endl;

								while (!range.eof())
								{
									range >> lowrange >> uprange >> cardid >> pokemon;
									if (range.fail())	break;

									else if (randomnum >= lowrange && randomnum <= uprange)
									{
										cout << "\nCongratulations! You got " << cardid << " " << pokemon << "!" << endl;
										updateCard(usern, pokemon);
									}
								}
							}
							range.close();
						}
						else if (nobooks < 2)
							cout << "\nInsufficient number of books borrowed. Read and borrow more books!" << endl;
						break;
					}
				}
			}
			else if (select == "No")
			{
				cout << "\nSee you next time! " << endl;
				break;
			}
		}
	}
	check.close();
}

void charlesDarwin(int row1, int row2, string poki, string usern) //carl
{
	int num;
	string pokemon, requirm0;
	ifstream inFile;
	ofstream outFile;
	requirm0 = usern + ".txt";
	inFile.open(requirm0.c_str());
	outFile.open("temp.txt");
	if (!inFile || !outFile) cout << "Cannot open either usern file or temp";
	else
	{
		for (int row = 1; row <= 10; row++)
		{
			inFile >> pokemon >> num;
			if (inFile.fail())  break;
			if (row == row1)
			{
				if (num >= 3 && pokemon == poki)
				{
					//cout << "update pre evolutions successful\n\n";
					cout << "Your " << poki << " has successfully evolved into ";
					num -= 3;
					outFile << pokemon << " " << num << endl;
				}
				else
				{
					cout << "You have not enough " << pokemon << "s.\n";
					outFile << pokemon << " " << num << endl;
					row2 = 0;
				}
			}
			else if (row == row2)
			{
				cout << pokemon <<"!!!!\nCongratulations!!!!" <<endl;
				//cout << "update post evolutions successful\n\n";
				num++;
				outFile << pokemon << " " << num << endl;
			}
			else outFile << pokemon << " " << num << endl;
		}
		inFile.close();
		outFile.close();
		remove(requirm0.c_str());
		rename("temp.txt", requirm0.c_str());
	}
}

void Requim(string usern) //carl
{
	int row1, row2;
	string poki;
	cout << "Please input the Pokemon you want to evolve:";
	cin >> poki;
	if (poki == "Bulbasaur")
	{
		row1 = 1;
		row2 = 2;
		charlesDarwin(row1, row2, poki, usern);
	}
	else if (poki == "Charmander")
	{
		row1 = 3;
		row2 = 4;
		charlesDarwin(row1, row2, poki, usern);
	}
	else if (poki == "Squirtle")
	{
		row1 = 5;
		row2 = 6;
		charlesDarwin(row1, row2, poki, usern);
	}
	else cout << "Invalid evolution";
}

void logOut() //Mutasim
{
	cout << "\nYou have sucessfully logout of your account. See you next time!" << endl;
}
