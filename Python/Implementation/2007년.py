# Baekjoon 1924

day = 0
month = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
date = ["SUN", "MON","TUE", "WED", "THU", "FRI", "SAT"]

str = input()
x, y = map(int, str.split())
 
for i in range(x-1):
    day = day + month[i]
day = (day + y) % 7
 
print(date[day])