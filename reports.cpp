#include <iomanip>
#include <iostream>

const int NUM_BOOKS = 100;
BookData book[NUM_BOOKS];

void reports()
{
	int choice = 0;

	while (choice != 7)
	{

		std::cout << "Serendipity Booksellers\n";
		std::cout << "\tReports\n\n";

		std::cout << "1. Inventory Listing\n";
		std::cout << "2. Inventory Wholesale Value\n";
		std::cout << "3. Inventory Retail Value\n";
		std::cout << "4. Listing by Quantity\n";
		std::cout << "5. Listing by Cost\n";
		std::cout << "6. Listing by Age\n";
		std::cout << "7. Return to the Main Menu\n\n";

		std::cout << "Enter Your Choice: ";
		std:: cin >> choice;

		//validate input
		while (choice < 1 || choice > 7)
		{
			std::cout << "\nPlease enter a number in the range 1 - 7\n";
			std::cout << "Enter your choice: ";
			std::cin >> choice;
		}
		switch (choice)
		{
		case 1:
			repListing();
			break;
		case 2:
			repWholesale();
			break;
		case 3:
			repRetail();
			break;
		case 4:
			repQty();
			break;
		case 5:
			repCost();
			break;
		case 6:
			repAge();
			break;
		case 7:
			std::cout << "\nYou selected item 7";
			break;
		}

		std::cout << std::endl;

	}//end while choice !=7
}

void repListing()
{
	char end[] = { '\0' };
	char date[8]; //todays date
	std::cout << "\n\nEnter Today's date: ";
	std::cin >> date;
	std::cout << std::endl;

	std::cout << "\n\n\t\tSerendipity Booksellers Inventory Report\n";
	std::cout << "Date: \t\t" << date;

	for (int i = 0; i < NUM_BOOKS; i++)
	{
		if (strcmp(book[i].isbn, end) != 0) //not printing empty records
		{
			std::cout << "\n_____________________________________________________";
			std::cout << "\n\n\Title:\t\t\t" << book[i].bookTitle;
			std::cout << "\nISBN:\t\t\t" << book[i].isbn;
			std::cout << "\nAuthor:\t\t\t" << book[i].author;
			std::cout << "\nPublisher:\t\t" << book[i].publisher;
			std::cout << "\nDate Added:\t\t" << book[i].dateAdded;
			std::cout << std::fixed << std::showpoint << std::setprecision(2);
			std::cout << "\nQuantity on Hand:\t" << book[i].qtyOnHand;
			std::cout << "\nWholesale Cost: \t\t$ " << book[i].wholesale;
			std::cout << "\nRetail Price:\t\t $" << book[i].retail;
		}
	}

	std::cout << "\n\n________________________________________________________";
	std::cout << "\n\nEnd of Inventory Report\n\n\n";

	//pause report on screen
	std::cout << "Press Enter to continue";
	std::cin.ignore();
	std::cin.get();
}
