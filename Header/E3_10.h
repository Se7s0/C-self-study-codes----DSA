#pragma once
#include <string>

using namespace std;

class Invoice {

	public:

		Invoice(string partNumber, string partDescription, int quantity, int pricePerItem)
			: partNumber{ partNumber }, partDescription{ partDescription }
		{
		
			if (quantity > 0) {
				this->quantity = quantity;
			}

			if (pricePerItem > 0) {
				this->pricePerItem = pricePerItem;
			}

		}

		void setPartNumber(string partNumber) {
			this->partNumber = partNumber;
		}

		void setPartDescription(string partDescription) {
			this->partDescription = partDescription;
		}

		void setQuantity(int quantity) {
			this->quantity = quantity;
		}	

		void setPricePerItem(int pricePerItem) {
			this->pricePerItem = pricePerItem;
		}	

		string getPartNumber() {
			return partNumber;
		}

		string getPartDescription() {
			return partDescription;
		}

		int getQuantity() {
			return quantity;
		}

		int getPricePerItem() {
			return pricePerItem;
		}

		int getInvoiceAmount() {
			return quantity * pricePerItem;
		}

	private:

		string partNumber;
		string partDescription;
		int quantity{0};
		int pricePerItem{0};
};
