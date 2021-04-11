#include <iostream>
#include <list>
using namespace std;

void list_print(list<int> *lst) {
	list<int>::iterator iter;
	for (iter = lst->begin(); iter != lst->end(); iter++)
		cout << *iter << "->";
	cout << "NULL" << endl << endl;
}

int main() {
	int choice, index, value, i;
	list<int> *lst = new list<int>();
	list<int>::iterator iter;
	do {
		cout << "MENU:" << endl <<
				"0. Exit" << endl <<
				"1. Add item" << endl <<
				"2. Del item" << endl <<
				"3. Get item" << endl <<
				"4. Set item" << endl <<
				"Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Enter value: ";
			cin >> value;
			lst->push_back(value);
			break;
		case 2:
			cout << "Enter list index: ";
			cin >> index;
			for (iter = lst->begin(), i = 0; iter != lst->end() && i < index; i++)
				iter++;
			if (iter != lst->end())
				lst->erase(iter);
			break;
		case 3:
			cout << "Enter list index: ";
			cin >> index;
			for (iter = lst->begin(), i = 0; iter != lst->end() && i < index; i++)
				iter++;
			if (iter != lst->end())
				cout << index << " item = " << *iter << endl;
			break;
		case 4:
			cout << "Enter list index: ";
			cin >> index;
			cout << "Enter value: ";
			cin >> value;
			for (iter = lst->begin(), i = 0; iter != lst->end() && i < index; i++)
				iter++;
			if (iter != lst->end())
				*iter = value;
			break;
		}
		cout << endl << lst->size() << " items:" << endl;
		list_print(lst);
	} while (choice);
	delete lst;
	return 0;
}
