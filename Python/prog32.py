import csv

data = [
    {"Name": "Arshith", "Age": 23},
    {"Name": "Aswin", "Age": 22}
]

# Write data to CSV
with open("data.csv", "w", newline="") as f:
    writer = csv.writer(f)
    writer.writerow(["Name", "Age"])
    for row in data:
        writer.writerow([row["Name"], row["Age"]])

# Read and print the CSV content
with open("data.csv", "r") as f:
    reader = csv.reader(f)
    for row in reader:
        print(row)
