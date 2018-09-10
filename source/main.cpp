#include <iostream>
#include <string>
using namespace std;

#include "Lab1Tests.hpp"


string get_status_str(bool status)
{
    return status ? "TEST PASSED" : "TEST FAILED";
}

int main()
{
    SequentialListTest seq_test;
    DoublyLinkedListTest linked_test;

	string seq_test_descriptions[] = {
      "Test1: New empty list is valid",
      "Test2: insert_front() and insert_back() on zero-element list",
      "Test3: select() and search() work properly",
      "Test4: select() and search() work properly",
      "Test5: select() and search() work properly",
      "Test6: select() and search() work properly",
      "Test7: select() and search() work properly",
      "Test8: select() and search() work properly",
      "Test9: select() and search() work properly",
	  "Test10: select() and search() work properly"
	};
	
	bool seq_test_results[10];
    seq_test_results[0] = seq_test.test1();
    seq_test_results[1] = seq_test.test2();
    seq_test_results[2] = seq_test.test3();
    seq_test_results[3] = seq_test.test4();
	seq_test_results[4] = seq_test.test5();
	seq_test_results[5] = seq_test.test6();
	seq_test_results[6] = seq_test.test7();
	seq_test_results[7] = seq_test.test8();
	seq_test_results[8] = seq_test.test9();
	seq_test_results[9] = seq_test.test10();
	
	cout << "SEQUENTIAL LIST TESTING RESULTS \n";
	cout << "******************************* \n";
	for (int i = 0; i < 10; ++i) {
    	cout << seq_test_descriptions[i] << endl << get_status_str(seq_test_results[i]) << endl;
	}
	cout << endl;

	string linked_test_descriptions[] = {
      "Test1: New empty list is valid",
      "Test2: insert_front() and insert_back() on zero-element list",
      "Test3: select() and search() work properly",
      "Test4: New empty list is valid",
      "Test5: insert_front() and insert_back() on zero-element list",
      "Test6: select() and search() work properly",
      "Test7: New empty list is valid",
      "Test8: insert_front() and insert_back() on zero-element list",
      "Test9: select() and search() work properly",
	  "Test10: xxxx"
	};

	
	bool linked_test_results[10];
    linked_test_results[0] = linked_test.test1();
    linked_test_results[1] = linked_test.test2();
    linked_test_results[2] = linked_test.test3();
    linked_test_results[3] = linked_test.test4();
    linked_test_results[4] = linked_test.test5();
    linked_test_results[5] = linked_test.test6();
    linked_test_results[6] = linked_test.test7();
    linked_test_results[7] = linked_test.test8();
    linked_test_results[8] = linked_test.test9();
    linked_test_results[9] = linked_test.test10();


	cout << "DOUBLY LINKED LIST TESTING RESULTS \n";
	cout << "********************************** \n";
	for (int i = 0; i < 10; ++i) {
    	cout << linked_test_descriptions[i] << endl << get_status_str(linked_test_results[i]) << endl;
	}
	cout << endl;
}
