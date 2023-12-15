from random import shuffle
user_input = input("Enter a number: ")
try:
    number = int(user_input)
    l = list(range(1, number + 1))
    shuffle(l)
    print("Shuffled list:", " ".join([str(x) for x in l]))
except ValueError:
    print("Error: Please enter a valid integer.")
