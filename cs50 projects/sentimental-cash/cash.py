# TODO
from cs50 import get_float

change = 0.00
quarters = 0
dimes = 0
pennies = 0
nickels = 0

while change <= 0.00:
    change = get_float("Enter Change: ")

change = (int)(change*100.0+0.5)/100.0
changeI = (int)(change * 100)
quarter = 25
dime = 10
nickle = 5

quarters = (int)(changeI/quarter)


changeI = changeI - (quarters * quarter)
dimes = (int)(changeI/dime)


changeI = changeI - (dimes * dime)
nickels = (int)(changeI/nickle)


changeI = changeI - (nickels * nickle)


print("Total coins: ", quarters + dimes + nickels + changeI)
