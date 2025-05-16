sequence = input("Enter original sequence: ")
sortedSequence = input("Enter sorted sequence: ")
sequenceSplit = sequence.split()
sortedSequenceSplit = sortedSequence.split()
sequenceSplitInt = list(map(int, sequenceSplit))
sortedSequenceSplitInt = list(map(int, sortedSequenceSplit))
if len(sequenceSplitInt) != len(sortedSequenceSplitInt):
	print("Incorrect length!")
	exit()
sequenceSplitInt.sort()
i = 0
while i < len(sequenceSplitInt):
	if (sortedSequenceSplitInt[i] != sequenceSplitInt[i]):
		print("Incorrect sort!")
		exit()
	i += 1
print("Correct sort!")
