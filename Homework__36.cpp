
#include <iostream>

using namespace std;

struct book
{
    string name;
    string author;
    string publisher;
    string genre;
};

void fillBookArray(book arr[], const int size);
void printBooks(book arr[], const int size);
void editBook(book arr[], const int size);
void searchBookByName(book arr[], const int size);
void searchBookByAuthor(book arr[], const int size);
void sortByName(book arr[], const int size);
void sortByAuthor(book arr[], const int size);
void sortByPublisher(book arr[], const int size);


int main()
{
        const int size = 10;
        int choise = 1;
        book arr[size];
        fillBookArray(arr, size);
        while (choise != 0)
        {
            cout << "Choose option:\n1 - print all books;\n2 - edit book;\n3 - search book by name;\
                     \n4 - search book by author;\n5 - sort books by name;\n6 - sort books by author;\
                     \n7 - sort books by publisher;\n0 - exit.\n";
            cin >> choise;
            if (choise == 1)
            {
                printBooks(arr, size);
            }
            else if (choise == 2)
            {
                editBook(arr, size);
            }
            else if (choise == 3)
            {
                searchBookByName(arr, size);
            }
            else if (choise == 4)
            {
                searchBookByAuthor(arr, size);
            }
            else if (choise == 5)
            {
                sortByName(arr, size);
            }
            else if (choise == 6)
            {
                sortByAuthor(arr, size);
            }
            else if (choise == 7)
            {
                sortByPublisher(arr, size);
            }
            else if (choise != 0)
            {
                cout << "ERROR: INVALID OPTION;";
            }
        }
}


void fillBookArray(book arr[], const int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << "Book:\n";
        cout << "Enter name of book:\n";
        cin >> arr[i].name;
        cout << "Enter author of book:\n";
        cin >> arr[i].author;
        cout << "Enter publisher of book:\n";
        cin >> arr[i].publisher;
        cout << "Enter genre of book:\n";
        cin >> arr[i].genre;
    }
}
void printBooks(book arr[], const int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << " - Name: " << arr[i].name << "; Author: " << arr[i].author << "; publisher: " << arr[i].publisher
            << "; genre: " << arr[i].genre << "\n";
    }
}
void editBook(book arr[], const int size)
{
    int choiseBook;
    int choiseOpt;
    while (true)
    {
        cout << "Choose book you want to edit:\n0 - exit\n";
        printBooks(arr, size);
        cin >> choiseBook;
        if (choiseBook> 0 && choiseBook < 11)
        {
            while (true)
            {
                cout << "Choose option you want to edit: 1 - name; 2 - author; 3 - publisher; 4 - genre; 0 - exit.\n";
                cin >> choiseOpt;
                if (choiseOpt == 1)
                {
                    cout << "Enter new name:\n";
                    cin >> arr[choiseBook - 1].name;
                    break;
                }
                else if (choiseOpt == 2)
                {
                    cout << "Enter new authorn:\n";
                    cin >> arr[choiseBook - 1].author;
                    break;
                }
                else if (choiseOpt == 3)
                {
                    cout << "Enter new publisher:\n";
                    cin >> arr[choiseBook - 1].publisher;
                    break;
                }
                else if (choiseOpt == 4)
                {
                    cout << "Enter new genre:\n";
                    cin >> arr[choiseBook - 1].genre;
                    break;
                }
                else if (choiseOpt == 0)
                {
                    break;
                }
                else
                {
                    cout << "ERROR: INVALID OPTION;";
                }
            }
        }
        else if (choiseBook == 0)
        {
            break;
        }
        else
        {
            cout << "ERROR: INVALID BOOK;";
        }
    }
}
void searchBookByName(book arr[], const int size)
{
    string nameToFind;
    cout << "Enter name of book:\n";
    cin >> nameToFind;
    for (int i = 0; i < size; i++)
    {
        if (nameToFind == arr[i].name)
        {
            cout << "Name: " << arr[i].name << "; Author: " << arr[i].author << "; Publisher: " << arr[i].publisher
                << "; Genre: " << arr[i].genre << ".\n";
            break;
        }
        else if (i == size - 1)
        {
            cout << "No books with this name in library\n";
        }
    }
}
void searchBookByAuthor(book arr[], const int size)
{
    string authorToFind;
    cout << "Enter author of book:\n";
    cin >> authorToFind;
    for (int i = 0; i < size; i++)
    {
        if (authorToFind == arr[i].author)
        {
            cout << "Name: " << arr[i].name << "; Author: " << arr[i].author << "; Publisher: " << arr[i].publisher
                << "; Genre: " << arr[i].genre << ".\n";
            break;
        }
        else if (i == size - 1)
        {
            cout << "No books by this author in library";
        }
    }
}
void sortByName(book arr[], const int size)
{
    book temple;
    for (int fLoop = 0; fLoop < size - 1; fLoop++)
    {
        for (int sLoop = 0; sLoop > size - 1 - fLoop; sLoop++)
        {
            if (arr[sLoop].name > arr[sLoop + 1].name)
            {
                temple = arr[sLoop + 1];
                arr[sLoop + 1] = arr[sLoop];
                arr[sLoop] = temple;
            }
        }
    }
}
void sortByAuthor(book arr[], const int size)
{
    book temple;
    for (int fLoop = 0; fLoop < size - 1; fLoop++)
    {
        for (int sLoop = 0; sLoop < size - 1 - fLoop; sLoop++)
        {
            if (arr[sLoop].author > arr[sLoop + 1].author)
            {
                temple = arr[sLoop + 1];
                arr[sLoop + 1] = arr[sLoop];
                arr[sLoop] = temple;
            }
        }
    }
}
void sortByPublisher(book arr[], const int size)
{
    book temple;
    for (int fLoop = 0; fLoop < size - 1; fLoop++)
    {
        for (int sLoop = 0; sLoop < size - 1 - fLoop; sLoop++)
        {
            if (arr[sLoop].publisher > arr[sLoop + 1].publisher)
            {
                temple = arr[sLoop + 1];
                arr[sLoop + 1] = arr[sLoop];
                arr[sLoop] = temple;
            }
        }
    }
}