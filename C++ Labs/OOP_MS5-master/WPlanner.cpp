// MURAT ORTAK 125312157 11-12-2016
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iomanip>
#include<fstream>
#include<string>
#include "WPlanner.h"
#include "Good.h"
#include "OnShelf.h"
#include "CustomMade.h"

using namespace std;
namespace ict {

   WPlanner::WPlanner(const char* filename) {
	   strncpy(filename_, filename, 255);
	   for (int i = 0; i < MAX_NO_RECS; ++i) {
		   items_[i] = nullptr;
		}
	   noOfItems_ = 0;
	   loadRecs();
	   
   }
   void WPlanner::saveRecs() {
	   
	   datafile_.open(filename_, ios::out);
	   if (datafile_.is_open()) {
		   for (int i = 0; i < noOfItems_; ++i) {
			   items_[i]->store(datafile_, true);
			   
		   }
	   }
	   datafile_.close();
   }
   void WPlanner::loadRecs() {
	   int i = 0;
	   char id;
	   Good* g;
	   datafile_.open(filename_, ios::in);
	   if (datafile_.fail()) {
		   datafile_.clear();
		   datafile_.close();
		   datafile_.open(filename_, ios::out);
		   datafile_.close();
	   }
	   else {
		   while (!datafile_.fail()) {
			   
			   datafile_ >> id;
			  
			   if (id == 'C') {
				   
				   g = new CustomMade;
				   
				   
			   }
			   if (id == 'O') {
				   
					g = new OnShelf;
				   
				   
			   }
			   datafile_.ignore();
			   g->load(datafile_);
			   items_[i] = g; 
			   noOfItems_ = i;
			   
			   i++;
		   }
		   
		   
		   datafile_.close();
		   
	   }
	   

   }
   void WPlanner::getSku(char* sku) {
	   cout << "Please enter the SKU: ";
	   cin >> sku;
	  if (cin.fail()) {
		cin.clear();
		  cin.ignore();
	   }
	  
   }
   void WPlanner::deleteItem() {
      cout << "Not implemented!" << endl << endl;
	  Good* temp;
	  char* sku1;
	  int purc;
	  sku1 = new char[MAX_SKU_LEN + 1];

	  getSku(sku1);
	  int a = SearchItems(sku1);
	  if (a == -1)
	  {
		  cout << endl << "Not Found!" << endl;
	  }
	  else {
		  cout << "The following item will be deleted: ";
		  items_[a]->display(cout, false) << endl << endl;
		  cout << "Type (Y) to confirm or (N) to abort: " << endl;
		  char b;
		  cin >> b;
		  if (b == 'Y' || b == 'y') {
			  delete items_[a];
			  for(int i = a; i < noOfItems_; i++){
				 
			  items_[i] = items_[i+1];
			  }
			  noOfItems_--;
			 
			  items_[noOfItems_] = nullptr;
			  
			  saveRecs();
		  }
		  else {
			  cout << "Aborted!" << endl << endl;
		  }
		  
	  }


   }
   void WPlanner::updateQty() {
	   Good* temp;
	   char* sku1;
	   int purc;
	   sku1 = new char[MAX_SKU_LEN + 1];
	   
	   getSku(sku1);
		int a = SearchItems(sku1);
		if (a == -1)
		{
			cout << endl << "Not Found!" << endl;
		}
		else {
			items_[a]->display(cout, false);
			cout << endl;
			cout << "Please enter the number of purchased goods: " << endl;
			cin >> purc;
			if (cin.fail()) {
				cout << "Invalid Quantity value!" << endl;
			}
			else {
				int second = items_[a]->getqtyNeeded() - items_[a]->getquantity();
				if (purc <= second) {
					*items_[a] += purc;
					//saveRec()
				}
				else {
					*items_[a] += second;
					//saveRec();
					cout << "Too many purchased, only "<< second << " needed, please return the extra "<< purc - second << " ." << endl;
				}
				saveRecs();
				cout << endl << "Updated!"<< endl;
			}
		}
	
		

   }
   void WPlanner::listItems()const {

	   double d = 0.0;
	   double a = 0.0;
      cout << " Row | SKU | Good Name          | Cost  |Tax| QTY|Need| Delivery" << endl
         << "-----|-----|--------------------|-------|---|----|----|----------" << endl;
	  for (int i = 0; i < noOfItems_; i++) {
		  cout << right;
		  cout << setfill(' ');
		  cout << setw(4);
		  cout << i+1;
		  cout << " |  ";
		  cout << *items_[i] << endl;

		  d += *items_[i];
		  a = d + a;
	  }
	  

      cout << "-----+-----+--------------------+-------+---+----+----+----------" << endl;

	 
	  
	  cout << "Total cost of the wedding: $" << a << endl;
	 

	  

   }
   int WPlanner::SearchItems(const char* sku)const {
	   int temp = -1;
	   for (int i = 0; i < noOfItems_; ++i) {
		  
		   if (*items_[i] == sku) {
			   temp = i;
		   }
			
		  
	   }
	   return temp;
   }
   void WPlanner::addItem(bool isCustomMade) {
	   Good* g = nullptr; 
	   if (isCustomMade == true) {
		   g = new CustomMade;
		   g->conInput(cin);
		   if (cin.fail()) {
			   g->display(cout, true);
		   }
		   else {
			   
			  items_[noOfItems_] = g;
			  noOfItems_++;
			   saveRecs();
		   }
		  
	   }
	   else {
		   g = new OnShelf;
		   g->conInput(cin);
		   if (cin.fail()) {
			   g->display(cout, true);
			   
		   }
		   else {
			  items_[noOfItems_] = g;
			  noOfItems_++;
			  saveRecs();
		   }
	   }
	   
   }
   int WPlanner::menu() {
	   
      int selection = -1;
	  
	  cout << "Wedding Planner Management Program" << endl;
	  cout << "1 - List goods" << endl;
	  cout << "2 - Add On Shelf Good" << endl;
	  cout << "3 - Add Custome-Made Good" << endl;
	  cout << "4 - Update Good quantity" << endl;
	  cout << "5 - Delete" << endl;
	  cout << "0 - Exit program" << endl;
	  cout << ">";
	  
	  cout << endl;
	  int a = 0;
	  cin >> a;
	  if (a >= 0 || a < 6) {
		  selection = a;
	  }
	  return selection;
	  
	  
   }
   int WPlanner::run() {
      bool done = false;
	  
      while (!done) {
		  
         switch (menu()) {
         case 1:
			 listItems();
            break;
         case 2:
			 addItem(false);

            break;
         case 3:
			 addItem(true);

            break;
         case 4:
			 updateQty();

            break;
         case 5:
			 deleteItem();
            break;
         case 0:
            done = true;
            cout << "Goodbye!!" << endl << endl;
            break;
         case -1:
            cout << "===Invalid Selection, try again.===" <<endl;
            break;
         }
		
      }
      return 0;
   } 
}


/* outputs

Wedding Planner Management Program
1 - List goods
2 - Add On Shelf Good
3 - Add Custom-Made Good
4 - Update Good quantity
5 - Delete
0 - Exit program
>



Not found!

Please enter the number of purchased goods:

Too many purchased, only 5 needed, please return the extra 15.

Updated!

Not implemented!

*/