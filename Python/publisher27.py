class publisher :
    def __init__(self,name):
        self.name=name
    def display_info(self):
        print(f"Publisher Name : {self.name}")

class Book(publisher):
    def __init__(self, name,title,author):
        super().__init__(name)
        self.title=title
        self.author=author
    def display_info(self):
        super().display_info()  
        print(f"Book Title : {self.title}")
        print(f"Author : {self.author}")

b1 = Book("Penguin Books","The Great","F-Scott")
b1.display_info()
                  