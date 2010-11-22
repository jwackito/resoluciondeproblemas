#http://www.spoj.pl/problems/JULKA/
import sys

for i in range(0,10):
	apples = int(sys.stdin.readline())
	more = int(sys.stdin.readline())
	klaudia = (apples - more)/2 + more
	natalia = (apples - more)/2
	print klaudia
	print natalia
