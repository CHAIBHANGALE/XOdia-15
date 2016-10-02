'''
WHENEVER ACCESSING arr PLEASE SWAP X <-> Y!
OTHERWISE ALL FUNCTIONS, METHODS AND TUPLES ASSUME FIRST ARG AS x AND NEXT AS y
'''
c_map_dir = {0:8, 1:7, 2:6, 3:1, 4:5, 5:2, 6:3, 7:4}

import textwrap
BOUND = 20

class Move:
	def __init__(self, r, c, d, pr, pc):
		self.r=r
		self.c=c
		self.d=d
		self.pr=pr
		self.pc=pc
		self.ts=()
	def score(self):
		if (self.r, self.c) in enleafset:
			return -1
		else:
			if arr[self.r][self.c][0]=='0':
				return len(self.ts)+self.r+self.c
			else:
				return .5*len(self.ts)+self.r+self.c

	def __str__(self):
		return "[%d,%d] -> [%d,%d] (d%d)" % (self.pr, self.pc, self.r, self.c, self.d)

def isbounded(ptr, ptc):
	return ptr>=0 and ptr<BOUND and ptc>=0 and ptc<BOUND

def getMoveActions(ptr, ptc): #returns a list of Move objects which are valid
	actions = []
	count=0
	for dc in range (-1,2):
		for dr in range(-1, 2):
			if not (dr == 0 and dc == 0):
				if isbounded(ptr+dr, ptc+dc) and arr[ptr+dr][ptc+dc][c_map_dir[count]] != '1':
					actions.append(Move(ptr+dr, ptc+dc, dr+dc+2, ptr, ptc))
				count += 1
	return actions

def getSetActions(ptr, ptc): #returns a list of coordinate tuples which are valid "newLeaves"
	actions = []
	count=0
	for dc in range (-1,2):
		for dr in range(-1, 2):
			if not (dr == 0 and dc == 0):
				if isbounded(ptr+dr, ptc+dc) and arr[ptr+dr][ptc+dc][0] in "01" and arr[ptr][ptc][c_map_dir[count]] != '1':
					actions.append((ptr+dr, ptc+dc))
				count += 1
	return actions

string=str(raw_input())
a=textwrap.wrap(string,9)
arr=[['000000000'for i in range(BOUND)]for j in range(BOUND)]
for i in range(BOUND):
	for j in range(BOUND):
		arr[i][j]=a[i*BOUND+j]

myleaves = []
enleaves = []
enleafset = set()
mymoves = []
NUMITEMS = 0
for r in range(BOUND):
	for c in range(BOUND):
		'''
		WHENEVER ACCESSING arr PLEASE SWAP X <-> Y!
		OTHERWISE ALL FUNCTIONS, METHODS AND TUPLES ASSUME FIRST ARG AS x AND NEXT AS y
		'''
		NUMITEMS += arr[r][c][0] != '0'
		if arr[r][c][0] == '1':
			myleaves.append((r, c))
			for action in getMoveActions(r, c):
				mymoves.append(action)
		elif arr[r][c][0] == '2':
			enleaves.append((r, c))
			for action in getMoveActions(r, c):
				enleafset.add((action.r, action.c))

#for first move
if NUMITEMS <= 2:
	print "%d,%d,%d,%d" % (0,0,1,1)
else:
	#print enleafset

	for move in mymoves:
		threat_set = []
		#print "checking move:", move, not (move.x, move.y) in enleafset
		if (not (move.r, move.c) in enleafset) and (not arr[move.r][move.c][0] in "34"): #not threatened and not a node
			web = getSetActions(move.r, move.c)
			for paw in web:
				#does it threaten? find how many u threaten
				if paw in enleafset:
					threat_set.append(paw)
		#this move threatens threat_set.
		move.ts = tuple(threat_set)
	#sort for max threat -> diag down

	mantle=sorted(mymoves, key=lambda move: move.score(), reverse=True)

	topleaf = None
	toprating = 0
	for leaf in myleaves:
		best_move = []
		for move in mantle:
			if leaf[0] ==  move.pr and leaf[1] == move.pc:
				best_move.append(move)
			if len(best_move) == 2:
				rating = best_move[0].score()+best_move[1].score()
				break
		if len(best_move)==2 and rating>toprating:
			toprating = rating
			topleaf = (leaf, best_move)

	#print 'TOPLEAF', topleaf[0], toprating
	m1, m2 = topleaf[1]
	print "%d,%d,%d,%d,%d,%d" % (topleaf[0][0],topleaf[0][1],m1.r,m1.c,m2.r,m2.c)
	'''
	for x in mantle:
		print x, x.score(), x.ts
	'''
