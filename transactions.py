class Transactions:
    def __init__(self):
        self.amount = 0
        self.file_path = ""
        self.total = 0
        self.month = 0
        self.day = 0
        self.year = 0
        self.choice = 0

    def display_menu(self):
        print("\n-----------------------------\nMENU:\n1) See yearly transaction total \n2) See monthly transaction total \n3) See daily transaction total \n4) Add a new transaction \n5) Delete a transaction \n6) Quit program \n-----------------------------\n")
        self.choice = input("Select a menu item (1-6): ")
        
        # switch/case for menu
        if self.choice == 1:
            pass

    def view_total(self, timeframe):
        # search the file for the timeframe column
        # if each value == self.<timeframe>
        # add it's amount to self.total
        # display total
        # display menu
        pass        

    def add_transaction(self):
        self.amount = int(input("Please enter the amount spent: $"))
        self.month = input("Please enter the month (1-12): ")
        # switch/case for days of the month
        self.day = input("Please enter the day ()")

        self.write_to_file()

    def write_to_file(self):
        # new line in a csv file
        # values: year, month, day, amount
        pass

    def read_from_file(self):
        pass

def main():
    t = Transactions()
    t.add_transaction()
    while t.choice != 6:
        t.display_menu()

if __name__ == "__main__":
    main()
