import textwrap
import os
import random

class Coord(object):
	def __init__(self, x, y):
		self.x = x
		self.y = y
	def distance_to(self, x, y):
		return (self.x - x)**2 + (self.y - y)**2

class Move(object):
	def __init__(self, root, toA, toB):
		self.root = root
		self.toA = toA
		self.toB = toB
	def format(self):
		return ','.join(map(str,[self.root.y, self.root.x, self.toA.y, self.toA.x, self.toB.y, self.toB.x]))
		

NOTHING = '0'
ME_LEAF = '1'
HIM_LEAF = '2'
ME_NODE = '3'
HIM_NODE = '4'
ME_FROZEN = '5'
HIM_FROZEN = '6'

N = 1
NE = 2
E = 3
SE = 4
S = 5
SW = 6
W = 7
NW = 8

DIRECTIONS = [N, NE, E, SE, S, SW, W ,NW]
OFFSET = {
	N: Coord(0, -1),
	NE: Coord(1, -1),
	E: Coord(1, 0),
	SE: Coord(1, 1),
	S: Coord(0, 1),
	SW: Coord(-1, 1),
	W: Coord(-1, 0),
	NW: Coord(-1, -1)
}

class Game(object):
	def __init__(self, a):
		self.grid = [['000000000' for i in range(20)] for j in range(20)]
		self.first_move = True
		for i in range(20):
			for j in range(20):
				d = a[i * 20 + j]
				self.grid[i][j] = d
				if (d[0] != NOTHING and d[0] != HIM_LEAF and d[0] != HIM_NODE):
					self.first_move = False
	def get_possible_moves(self):
		moves = []
		for x in range(20):
			for y in range(20):
				cell = self.grid[y][x]
				if cell[0] == ME_LEAF:
					neighbours = []
					for i in DIRECTIONS:
						if cell[i] == '0':
							d = OFFSET[i]
							nx = x + d.x
							ny = y + d.y
							if (nx >= 0 and nx < 20 and ny >= 0 and ny < 20 ):
								neighbour = self.grid[ny][nx]
								if self.isFree(neighbour):
									neighbours.append(Coord(nx, ny))
					if (len(neighbours) >= 2):
						here = Coord(x,y)
						perms = Game.get_permutations(neighbours)
						for p in perms:
							moves.append(Move(here, p[0], p[1]))
		return moves
	def get_score(self, move):
		closestA = 20*20
		closestB = 20*20
		for x in range(20):
			for y in range(20):
				cell = self.grid[y][x]
				if (cell[0] == HIM_LEAF):
					dA = move.toA.distance_to(x,y)
					dB = move.toB.distance_to(x,y)
					if dA < closestA:
						closestA = dA
					if dB < closestB:
						closestB = dB
		return (20*20+20*20) - (closestA + closestB)

	def get_permutations(coords):
		perms = []
		for i in range(len(coords)-1):
			coord = coords[i]
			for j in range(i + 1, len(coords)):
				next = coords[j]
				perms.append([coord, next])
		return perms
	def isFree(self, cell):
		return cell[0] in [NOTHING, ME_LEAF, HIM_LEAF]


#def input():
#	empty = '0'*(9*20*20)
#	return empty[:900] + '1' + empty[901:]

def main():
	string = input()
	a = textwrap.wrap(string,9)
	game = Game(a)

	if game.first_move:
		k=random.randint(3,16)
		print('{0},{1},{2},{3}'.format(k, 0, k, 1))
	else:
		poss = game.get_possible_moves()
		bests = [poss[0]]
		highest = 0
		for p in poss:
			score = game.get_score(p)
			if score > highest:
				bests = [p]
				highest = score
			elif score == highest:
				bests.append(p)
		print(random.choice(bests).format())
if __name__ == '__main__':
	main()