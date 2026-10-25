
# File Handling

# Writing data to a file
file = open("sample.txt", "w")
file.write("Hello, Python!\n")
file.write("This is file handling.")
file.close()

print("Data written successfully.")

# Reading data from a file
file = open("sample.txt", "r")
data = file.read()
print("File Content:")
print(data)
file.close()


# Exception Handling

try:
    a = int(input("Enter first number: "))
    b = int(input("Enter second number: "))
    result = a / b
    print("Result:", result)

except ZeroDivisionError:
    print("Error: Division by zero is not allowed.")

except ValueError:
    print("Error: Please enter valid numbers.")

finally:
    print("Program completed.")

